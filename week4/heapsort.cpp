#include <iostream>
#include <vector>

using namespace std;

// Hàm vun đống (Heapify) cho cây con tại chỉ số i
// n là kích thước của heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Khởi tạo largest là nút gốc
    int left = 2 * i + 1;  // Con trái = 2*i + 1
    int right = 2 * i + 2; // Con phải = 2*i + 2

    // Nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn nút lớn nhất hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu nút lớn nhất không phải là gốc
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Đệ quy heapify lại cây con bị ảnh hưởng
        heapify(arr, n, largest);
    }
}

// Hàm sắp xếp Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 1. Xây dựng Max-Heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 2. Trích xuất từng phần tử một từ heap
    for (int i = n - 1; i > 0; i--) {
        // Đưa phần tử gốc (lớn nhất) về cuối mảng
        swap(arr[0], arr[i]);

        // Gọi heapify trên heap đã giảm kích thước
        heapify(arr, i, 0);
    }
}

// Hàm in mảng
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Mang ban dau: ";
    printArray(arr);

    heapSort(arr);

    cout << "Mang sau khi sap xep (Heap Sort): ";
    printArray(arr);

    return 0;
}
