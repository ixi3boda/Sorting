#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

int* generateRandArray(int size);
void measureRuntime(int size);

int main() {
    // seed random number generator to get different random numbers each time
    srand(time(nullptr));

    int testSizes[] = {1000, 10000, 25000, 50000, 100000};

    for (int size : testSizes) {
        cout << "Testing size: " << size << endl;
        measureRuntime(size);
        cout << endl;
    }

    return 0;
}

void bubbleSort(int arr[], int size) {
    bool isSorted;
    for (int i = 0; i < size - 1; i++) {
        isSorted = true;
        for (int j = 0; j < size - 1 - i; j++) {
            // if value before is greater than after --> swap
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = false;
            }
        }
        if (isSorted) break;
    }
}


void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int* generateRandArray(int size) {
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand();

    return arr;
}

void measureRuntime(int size) {
    clock_t start, end;
    double cpu_time_used;

    int* arr = generateRandArray(size);
    int* arrCopy = new int[size];

    // Bubble Sort
    memcpy(arrCopy, arr, size * sizeof(int));
    start = clock();
    bubbleSort(arrCopy, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Bubble Sort is %f ms\n", cpu_time_used);

    // Selection Sort
    memcpy(arrCopy, arr, size * sizeof(int));
    start = clock();
    selectionSort(arrCopy, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Selection Sort is %f ms\n", cpu_time_used);

    // Insertion Sort
    memcpy(arrCopy, arr, size * sizeof(int));
    start = clock();
    insertionSort(arrCopy, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Insertion Sort is %f ms\n", cpu_time_used);

    delete[] arr;
    delete[] arrCopy;
}
