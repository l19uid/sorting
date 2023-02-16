#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>

void SelectionSort(int* arr, int numElements) {
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < numElements - 1; i++) { // Projde array až na poslední prvek.
        int minIndex = i; // Nastaví index nejmenšího prvku.
        for(int j = i + 1; j < numElements; j++) { // Projde array od i + 1 až na konec.
            if(arr[j] < arr[minIndex]) { // Pokud je prvek na pozici j menší než minIndex take je to nový minIndex.
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count() << "s" << std::endl;
}

void BubbleSort(int* arr, int numElements) {
    auto start = std::chrono::high_resolution_clock::now();
    bool isSorted = true;
    for(int i = 0; i < numElements - 1; i++) { // Projde array až na poslední prvek.
        for(int j = 0; j < numElements - i - 1; j++) {
            if(arr[j] > arr[j + 1]) { // Pokud je prvek na pozici j větší než prvek na pozici j + 1 tak je potřeba je prohodit.
                std::swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if(isSorted) { // Pokud je array seřazený tak se cyklus ukončí.
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count() << "s" << std::endl;
}

void InsertionSort(int* arr, int numElements)
{
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < numElements; i++) { // Projde array od druhého prvku až na konec.
        int j = i - 1; // Nastaví index na prvek před i.
        int key = arr[i]; // Nastaví klíč na prvek na pozici i.
        while(j >= 0 && arr[j] > key) { // Pokud je prvek na pozici j větší než klíč tak se posune na pozici j + 1.
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Nastaví klíč na pozici j + 1.
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count() << "s" << std::endl;
}

// Bogo sort nebo také Monkey sort.
void BogoSort(int* arr, int numElements) {
    while(!std::is_sorted(arr, arr + numElements)) {
        std::random_shuffle(arr, arr + numElements); //Jestli array není seřazený tak ho náhodně promícháme.
    }
}


void Down(int* arr, int last) {
    //Vytvoříme indexi.
    int child;
    int parent = 0;

    //Dokud není dítě poslední a je větší než rodič tak se budeme posouvat dolů.
    while (parent * 2 + 1 <= last) {
        //Vytvoříme dítě.
        child = parent * 2 + 1;
        //Vybereme větší ze dvou dětí.
        if ((child < last) && (arr[child] < arr[child + 1]))
            child++;
        //Jestli je dítě větší než rodič tak je potřeba je prohodit.
        if (arr[parent] < arr[child]) {
            //Prohodíme dítě a rodiče.
            std::swap(arr[parent], arr[child]);
            //Dítě se stává rodičem.
            parent = child;
        }
        else
            return;
    }
}

void Heapify(int *arr, int numElements)
{
    //Vytvoříme heap.
    for (int i = 1; i < numElements; i++) {
        //Vytvoříme indexi.
        int child = i;
        int parent;
        //Dokudnení dítě 0 a je větší než rodič tak se budeme posouvat nahoru.
        while (child != 0) {
            //Vytvoříme rodiče.
            parent = (child - 1) / 2;
            //Pokud je dítě větší než rodič tak je potřeba je prohodit.
            if (arr[parent] < arr[child]) {
                //Prohodíme dítě a rodiče.
                std::swap(arr[parent], arr[child]);
                //Dítě se stává rodičem.
                child = parent;
            }
            //Pokud není dítě větší než rodič tak se cyklus ukončí.
            else
                break;
        }
    }
}

void HeapSort(int *arr, int numElements)
{
    //Vytvoření heapu.
    Heapify(arr, numElements);
    //Nastavíme index na poslední prvek.
    int index = numElements - 1;
    //Cyklus se opakuje dokud je index větší než nula.
    while (index > 0) {
        //Prohodíme první a poslední prvek.
        std::swap(arr[0], arr[index]);
        //Zmenšíme index.
        index -= 1;
        //Projdeme heap ze zhora dolů.
        Down(arr, index);
    }
}

void CountingSort(int* arr,int numElements) {
    //Zjistíme maximální a minimální hodnotu.
    int max = *std::max_element(arr, arr + numElements);
    int min = *std::min_element(arr, arr + numElements);
    //Vypočítáme rozsah.
    int range = max - min + 1;
    //Vytvoříme pole pro počítání.
    int* count = new int[range]();
    //Vytvoříme pole pro výstup.
    int* output = new int[numElements]();
    //Pro každý prvek zvýšíme počet.
    for (int i = 0; i < numElements; i++)
        count[arr[i] - min]++;
    //Spočítáme počet prvků menších než aktuální.
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    //Vytvoříme výstup.
    for (int i = numElements - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    //Zkopírujeme výstup do pole.
    for (int i = 0; i < numElements; i++)
        arr[i] = output[i];
}

void Merge(int* arr, int* left, int* right, int numElements) {
    int x,y = 0;
    while ((x < numElements) && (y < numElements)) {
        if (left[x] < right[y]) {
            arr[x + y] = left[x];
            x++;
        }
        else {
            arr[x + y] = right[y];
            y++;
        }
    }
    if (x < numElements) {
        while (x < numElements) {
            arr[x + y] = left[x];
            x++;
        }
    }
    else {
        while (y < numElements) {
            arr[x + y] = right[y];
            y++;
        }
    }
}

void MergeSort(int* arr, int numElements) {
    // Pokud ma pole méně než 2 prvky, tak je již setříděné.
    if (numElements <= 1)
        return;
    int center = numElements / 2;
    int left[center];
    for (int i = 0; i < center; i++)
        left[i] = arr[i];
    int right[numElements - center];
    for (int i = center; i < numElements; i++)
        right[i - center] = arr[i];
    MergeSort(left, center);
    MergeSort(right,numElements - center);
    Merge(arr, left, right, center);
}

int Divide(int* list, int left, int right, int pivot) {
    //Prohodíme pivot s pravým indexem.
    std::swap(list[pivot], list[right]);
    //Nastavíme nový pivot.
    int i = left;
    //Projdeme pole.
    for (int j = left; j < right; j++) {
        //Pokud je vybrané pole menší než pivot tak se prohodí.
        if (list[j] < list[right]) {
            //Prohodíme prvky.
            std::swap(list[i], list[j]);
            //Zvýšíme index.
            i++;
        }
    }
    //Prohodíme pivot s pravým indexem.
    std::swap(list[i], list[right]);
    //Vrátíme nový pivot.
    return i;
}

void Quicksort(int* arr, int left, int right) {
    //Pokud je levý index menší než pravý tak se cyklus opakuje.
    if (right >= left) {
        //Nastavíme pivot na levý index.
        int pivot = left;
        //Nastavíme nový pivot.
        int newPivot = Divide(arr, left, right, pivot);
        //Zavoláme funkci pro levou a pravou část.
        Quicksort(arr, left, newPivot - 1);
        Quicksort(arr, newPivot + 1, right);
    }
}
