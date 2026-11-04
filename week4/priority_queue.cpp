#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    // Vun lên (Sift-up / Heapify-up): Dùng khi thêm phần tử mới
    void shiftUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2; // Chuyển lên nút cha
        }
    }

    // Vun xuống (Sift-down / Heapify-down): Dùng khi xóa phần tử ưu tiên cao nhất
    void shiftDown(int i) {
        int maxIndex = i;
        int n = heap.size();
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[maxIndex])
            maxIndex = left;

        if (right < n && heap[right] > heap[maxIndex])
            maxIndex = right;

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            shiftDown(maxIndex);
        }
    }

public:
    // Kiểm tra hàng đợi có rỗng hay không
    bool empty() const {
        return heap.empty();
    }

    // Lấy kích thước hàng đợi
    int size() const {
        return heap.size();
    }

    // Thêm một phần tử vào Priority Queue
    void push(int val) {
        heap.push_back(val);
        shiftUp(heap.size() - 1);
    }

    // Lấy phần tử có độ ưu tiên cao nhất (gốc của Max-Heap)
    int top() const {
        if (empty()) {
            throw runtime_error("Priority Queue rong!");
        }
        return heap[0];
    }

    // Xóa phần tử có độ ưu tiên cao nhất
    void pop() {
        if (empty()) {
            throw runtime_error("Priority Queue rong!");
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!empty()) {
            shiftDown(0);
        }
    }
};

int main() {
    PriorityQueue pq;

    // Thêm các phần tử vào hàng đợi ưu tiên
    cout << "Them vao hang doi: 10, 30, 20, 5, 40\n";
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Phan tu co do uu tien cao nhat (top): " << pq.top() << endl; // Output: 40

    cout << "Lay lan luot cac phan tu ra khoi hang doi (giam dan):\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
