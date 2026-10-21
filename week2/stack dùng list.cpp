#include <iostream>
using namespace std;

struct Node {
    int data;       
    Node* next;   

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
private:
    int *arr;
    int cap;
    int size;

public:
    List(int k){
        cap = k;
        size = 0;
        arr = new int[cap];
    }

    ~List(){        
        delete[] arr;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }

    int get(int i){
        if(i < 0 || i >= size){
            cout << "Index error\n";
            return 0;
        }
        return arr[i];
    }

    void insertHead(int value){
        if(isFull()){
            cout << "List full!\n";
            return;
        }
        for(int i = size; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        size++;
    }

    void insertTail(int value){
        if(isFull()){
            cout << "List full!\n";
            return;
        }
        arr[size] = value;
        size++;
    }

    void insert(int value, int k){
        if(isFull()){
            cout << "List full!\n";
            return;
        }
        if(k == 0) return insertHead(value);
        for(int i = size; i > k; i--){
            arr[i] = arr[i-1];
        }
        arr[k] = value;
        size++;
    }

    int deleteHead(){
        if(isEmpty()){
            cout << "List empty!\n";
            return -1;
        }
        int removed = arr[0];
        for(int i = 0; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
        size--;
        return removed;
    }

    int deleteTail(){
        if(isEmpty()){
            cout << "List empty!\n";
            return -1;
        }
        int removed = arr[size - 1];
        size--;
        return removed;
    }

    int deletee(int k){
        if(isEmpty()){
            cout << "List empty!\n";
            return -1;
        }
        if(k == 0) return deleteHead();
        int removed = arr[k];
        for(int i = k; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
        size--;
        return removed;
    }

    // Duyệt xuôi: In từ đầu mảng (chỉ số 0) đến cuối mảng
    void travF(){
        if(isEmpty()){
            cout << "(Rong)";
        } else {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    // Duyệt ngược: In từ cuối mảng (chỉ số size-1) về đầu mảng
    void travB() {
        if(isEmpty()){
            cout << "(Rong)";
        } else {
            for (int i = size - 1; i >= 0; i--) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

// ===================== LỚP STACK (LIFO) =====================
// Quy ước: Đỉnh Stack (Top) nằm ở CUỐI mảng List
class Stack {
private:
    List list;

public:
    Stack(int capacity) : list(capacity) {}

    bool isEmpty() {
        return list.isEmpty();
    }

    bool isFull() {
        return list.isFull();
    }

    int size() {
        return list.getSize();
    }

    // Thêm phần tử vào đỉnh Stack
    void push(int value) {
        list.insertTail(value);
    }

    // Lấy phần tử khỏi đỉnh Stack và xóa đi
    int pop() {
        return list.deleteTail();
    }

    // Xem giá trị ở đỉnh Stack (không xóa)
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return list.get(list.getSize() - 1);
    }

    // Duyệt xuôi Stack: Từ Đỉnh (Top) xuống Đáy (Bottom)
    void travF() {
        cout << "Stack (Top -> Bottom): ";
        list.travB(); // Đỉnh ở cuối mảng, nên duyệt xuôi Stack = duyệt ngược List
    }

    // Duyệt ngược Stack: Từ Đáy (Bottom) lên Đỉnh (Top)
    void travB() {
        cout << "Stack (Bottom -> Top): ";
        list.travF(); // Đáy ở đầu mảng, nên duyệt ngược Stack = duyệt xuôi List
    }
};

// ===================== CHƯƠNG TRÌNH MINH HỌA =====================
int main() {
    cout << "=== KIEM TRA STACK ===" << endl;
    Stack st(5); // Khởi tạo Stack có dung lượng tối đa 5

    st.push(10);
    st.push(20);
    st.push(30);

    st.travF(); // In ra: 30 20 10 (30 ở đỉnh)
    st.travB(); // In ra: 10 20 30 (10 ở đáy)

    cout << "Phan tu o dinh Stack (Top): " << st.top() << endl; // Output: 30

    cout << "Thuc hien Pop: " << st.pop() << endl; // Output: 30

    cout << "Sau khi Pop:" << endl;
    st.travF(); // In ra: 20 10

    return 0;
}
