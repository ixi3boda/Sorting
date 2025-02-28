#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// void bubbleSort(int arr[], int size);
// void insertionSort(int arr[], int size);
// void selectionSort(int arr[], int size);

// int* generateRandArray(int size);
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

void bubbleSort1(int arr[], int size) {
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

void insertionSort1(int arr[], int size) {
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

void selectionSort1(int arr[], int size) {
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

int* generateRandArray1(int size) {
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand();

    return arr;
}

vector <int> generateRandArray(int size) {
    vector <int> arr(size);
    for (int i = 0; i < size; i++)
        arr[i] = rand();

    return arr;
}

void bubbleSort(vector<int> arr, int size) {
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



void insertionSort(vector <int> arr, int size) {
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

void selectionSort(vector <int> arr, int size) {
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

void measureRuntime(int size) {
    clock_t start, end;
    double cpu_time_used;

    int* arr = generateRandArray1(size);
    int* arrCopy = new int[size];

    vector<int> arr2 = generateRandArray(size);

    // Bubble Sort
    // without copying taken into time measurement
    memcpy(arrCopy, arr, size * sizeof(int));
    start = clock();
    bubbleSort1(arrCopy, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Bubble Sort without copying is %f ms\n", cpu_time_used);
    // with copying taken into time measurement
    start = clock();
    bubbleSort(arr2, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Bubble Sort with copying is %f ms\n", cpu_time_used);

    // Insertion Sort
    // without copying taken into time measurement
    memcpy(arrCopy, arr, size * sizeof(int));
    start = clock();
    insertionSort1(arrCopy, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Insertion Sort without copying is %f ms\n", cpu_time_used);
    // with copying taken into time measurement
    start = clock();
    insertionSort(arr2, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Insertion Sort with copying is %f ms\n", cpu_time_used);

    // Selection Sort
    // without copying taken into time measurement
    memcpy(arrCopy, arr, size * sizeof(int));
    start = clock();
    selectionSort1(arrCopy, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Selection Sort without copying is %f ms\n", cpu_time_used);
    // with copying taken into time measurement
    start = clock();
    selectionSort(arr2, size);
    end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("Running time for Selection Sort with copying is %f ms\n", cpu_time_used);

    delete[] arr;
    delete[] arrCopy;
}
