#include <iostream>
#include <vector>
#include <algorithm>   // std::swap
using namespace std;

// ===================== 1. Selection Sort =====================
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Danh dau vi tri min
        int min_index = i;

        // Tim vi tri min
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Hoan doi vi tri min voi vi tri hien tai
        if (min_index != i)
            swap(arr[min_index], arr[i]);
    }
}

// ===================== 2. Bubble Sort =====================
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ===================== 3. Insertion Sort =====================
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ===================== 4. Merge Sort =====================
void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tao mang tam L[0..n1-1] va R[0..n2-1]
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// ===================== 5. Quick Sort =====================
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i = i + 1;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(int array[], int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}
// ===================== main =====================
int main()
{
    int n = 8;

    // 1. Selection Sort
    int a1[] = {64, 25, 12, 22, 11, 90, 5, 34};
    selectionSort(a1, n);
    cout << "Selection Sort: ";
    for (int i = 0; i < n; i++)
        cout << a1[i] << " ";
    cout << endl;

    // 2. Bubble Sort
    int a2[] = {64, 25, 12, 22, 11, 90, 5, 34};
    bubbleSort(a2, n);
    cout << "Bubble Sort: ";
    for (int i = 0; i < n; i++)
        cout << a2[i] << " ";
    cout << endl;

    // 3. Insertion Sort
    int a3[] = {64, 25, 12, 22, 11, 90, 5, 34};
    insertionSort(a3, n);
    cout << "Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << a3[i] << " ";
    cout << endl;

    // 4. Merge Sort
    int a4[] = {64, 25, 12, 22, 11, 90, 5, 34};
    mergeSort(a4, 0, n - 1);
    cout << "Merge Sort: ";
    for (int i = 0; i < n; i++)
        cout << a4[i] << " ";
    cout << endl;

    // 5. Quick Sort
    int a5[] = {64, 25, 12, 22, 11, 90, 5, 34};
    quickSort(a5, 0, n - 1);
    cout << "Quick Sort: ";
    for (int i = 0; i < n; i++)
        cout << a5[i] << " ";
    cout << endl;

    return 0;
}
