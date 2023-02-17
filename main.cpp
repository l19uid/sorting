#include <iostream>
#include "Sorts.h"
#include "util.h"

int main() {
    std::cout << "Zadejte delku arraye: " << std::endl;
    int userInput = 1;
    std::cin >> userInput;
    int arr[userInput];
    int originalArr[userInput];
    std::cout << userInput << std::endl;

    GenerateRandomArray(arr, userInput);
    GenerateRandomArray(originalArr, userInput);
    WriteToConsole(arr,userInput);
    std::cout << "Vyberte sort type : "<< std::endl;
    std::cout << "0. All sorts"<< std::endl;
    std::cout << "1. Bubbele sort"<< std::endl;
    std::cout << "2. Selection sort"<< std::endl;
    std::cout << "3. Bogo sort"<< std::endl;
    std::cout << "4. Insertion sort"<< std::endl;
    std::cout << "5. Heap sort"<< std::endl;
    std::cout << "6. Merge sort"<< std::endl;
    std::cout << "7. Counting sort"<< std::endl;
    std::cout << "8. Quick sort"<< std::endl;
    int sortType = 0;
    std::cin >> sortType;
    GenerateRandomArray(arr, userInput);

    switch (sortType) {
        case 0:
            std::cout << std::endl << "Bubble Sort O(n^2)" << std::endl;
            BubbleSort(arr, userInput);
            WriteToConsole(arr, userInput);
            GenerateRandomArray(arr, userInput);

            std::cout << "Selection Sort O(n^2)" << std::endl;
            SelectionSort(arr, userInput);
            WriteToConsole(arr, userInput);

            GenerateRandomArray(arr, userInput);
            std::cout << std::endl << "Insertion Sort O(n^2)" << std::endl;
            InsertionSort(arr, userInput);
            WriteToConsole(arr, userInput);

            GenerateRandomArray(arr, userInput);
            std::cout << std::endl << "Heap Sort O(n * log(n))" << std::endl;
            HeapSort(arr, userInput);
            WriteToConsole(arr, userInput);

            //BOGO SORT ALWAYS LAST!!!
            GenerateRandomArray(arr, userInput);
            std::cout << std::endl << "Bogo Sort O(?)" << std::endl;
            BogoSort(arr, userInput);
            WriteToConsole(arr, userInput);
            break;
        case 1:
            std::cout << std::endl << "Bubble Sort O(n^2)" << std::endl;
            BubbleSort(arr, userInput);
            WriteToConsole(arr,userInput);
            break;
        case 2:
            std::cout << "Selection Sort O(n^2)" << std::endl;
            SelectionSort(arr, userInput);
            WriteToConsole(arr,userInput);
            break;
        case 3:
            std::cout << std::endl << "Bogo Sort O(?)" << std::endl;
            BogoSort(arr, userInput);
            WriteToConsole(arr,userInput);
            break;

            case 4:
            std::cout << std::endl << "Insertion Sort O(n^2)" << std::endl;
            InsertionSort(arr, userInput);
            WriteToConsole(arr,userInput);
            break;
        case 5:
            std::cout << std::endl << "Heap Sort O(n * log(n))" << std::endl;
            HeapSort(arr, userInput);
            WriteToConsole(arr,userInput);
            break;
        case 6:
            std::cout << std::endl << "Merge Sort O(n * log(n))" << std::endl;
            MergeSort(arr, 0,userInput-1);
            WriteToConsole(arr,userInput);
            break;
        case 7:
            std::cout << std::endl << "Counting Sort O(n * log(n))" << std::endl;
            CountingSort(arr, userInput);
            WriteToConsole(arr,userInput);
            break;
        case 8:
            std::cout << std::endl << "Quick Sort O(n * log(n))" << std::endl;
            Quicksort(arr, 0,userInput-1);
            WriteToConsole(arr,userInput);
            break;

        }
    system("pause");
}




