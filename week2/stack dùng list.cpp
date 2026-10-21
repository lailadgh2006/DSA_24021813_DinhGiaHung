#include <iostream>
using namespace std;

// Class List cũ của bạn (có bổ sung nhẹ 1-2 hàm phụ trợ như getSize, isEmpty, popTail)
class List {
private:
    int *arr;
    int cap;
    int size;

public:
    List(int k = 100) { // Đặt mặc định k = 100 để Stack dùng dễ dàng
        cap = k;
        size = 0;
        arr = new int[cap];
    }

    ~List() {        
        delete[] arr;
    }

    int getSize() { return size; }
    bool isEmpty() { return size == 0; }

    int get(int i) {
        if (i < 0 || i >= size) {
            cout << "Index error\n";
            return -1;
        }
        return arr[i];
    }

    void insertHead(int value) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        size++;
    }

    void insertTail(int value) {
        if (size >= cap) return;
        arr[size] = value;
        size++;
    }

    void insert(int value, int k) {
        if (k == 0) return insertHead(value);
        for (int i = size; i > k; i--) {
            arr[i] = arr[i-1];
        }
        arr[k] = value;
        size++;
    }

    void deleteHead() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void deleteTail() {
        if (size == 0) return;
        size--;
    }

    // Hàm bổ sung giúp lấy giá trị ra khi xóa cuối
    int popTail() {
        if (size == 0) return -1;
        int val = arr[size - 1];
        size--;
        return val;
    }

    void deletee(int k) {
        if (k == 0) return deleteHead();
        for (int i = k; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void travF() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void travB() {
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ===================== STACK (Khớp hoàn toàn với List trên) =====================
struct Stack {
    List l; // Khởi tạo List với dung lượng mặc định 100

    Stack(int capacity = 100) : l(capacity) {}

    bool isEmpty() {
        return l.isEmpty(); // O(1)
    }

    void push(int item) {
        l.insertTail(item); // O(1)
    }

    int pop() {
        return l.popTail(); // O(1)
    }

    int size() {
        return l.getSize(); // O(1)
    }

    int top() {
        return l.get(l.getSize() - 1); // O(1)
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // In ra 30
    cout << "Pop: " << st.pop() << endl; // In ra 30
    cout << "Top moi: " << st.top() << endl; // In ra 20

    return 0;
}
