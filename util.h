#include <cstdlib>
#include <ctime>
#include <iostream>

const int MIN_VALUE = -20;
const int MAX_VALUE = 20;

// Jednoduchá funkce pro výpis arraye do konzole.
static void WriteToConsole(int arr[], int numElements) {
    for(int i = 0; i < numElements; i++) {
        std::cout << arr[i] << "|";
    }
    std::cout << std::endl;
}

// Přiřadí každému prvků pole náhodnou hodnotu.
static int GenerateRandomArray(int* arr, int numElements) {
    srand(time(0)); // C++ random generuje stejná čísla a tak mu měníme seed aby nevyšla všechna stejně.
    for(int i = 0; i < numElements; i++) {
        arr[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
    }
}

