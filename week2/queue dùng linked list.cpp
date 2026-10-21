include <iostream>
using namespace std;
 
// Cấu trúc một Node bên trong danh sách
struct Node {
    int data;
    Node* next;
};
 
// Danh sách liên kết: head + tail + biến đếm n
struct List {
    Node* head;
    Node* tail; // trỏ tới node cuối, giúp insertTail chỉ còn O(1)
    int n;      // Số lượng phần tử hiện tại
 
    // Khởi tạo danh sách rỗng
    void init() {
        head = nullptr;
        tail = nullptr;
        n = 0;
    }
 
    // Hàm phụ trợ tạo một Node mới
    Node* createNode(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        return newNode;
    }
 
    // Trả về phần tử tại vị trí i
    int getAt(int i) {
        if (i < 0 || head == nullptr) {
            cout << "Loi: Vi tri khong hop le hoac danh sach rong!\n";
            return -1;
        }
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == i) return temp->data;
            count++;
            temp = temp->next;
        }
        cout << "Loi: Vi tri vuot qua kich thuoc danh sach!\n";
        return -1;
    }
 
    // Thêm vào cuối danh sách: O(1) nhờ có tail
    void insertTail(int val) {
        Node* newNode = createNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        n++;
    }
 
    // Xóa đầu danh sách, trả về phần tử vừa xóa
    int deleteHead() {
        if (head == nullptr) {
            cout << "Danh sach rong, khong the xoa!\n";
            return -1;
        }
        Node* temp = head;
        int v = temp->data;
        head = head->next;
        if (head == nullptr) tail = nullptr; // vừa xóa phần tử cuối cùng
        delete temp;
        n--;
        return v;
    }
 
    bool isEmpty() { return head == nullptr; }
    int size()     { return n; }
 
    // Giải phóng toàn bộ danh sách
    void clear() {
        while (head != nullptr) {
            deleteHead();
        }
    }
};
 
// ===================== QUEUE (dùng List liên kết) =====================
// Thêm ở CUỐI (nhờ tail), lấy ở ĐẦU
struct Queue {
    List l;
 
    void init()            { l.init(); }                 // khởi tạo queue rỗng
 
    bool isEmpty()         { return l.isEmpty(); }       // O(1)
 
    void enqueue(int item) { l.insertTail(item); }       // O(1) nhờ có tail
 
    int  dequeue()         { return l.deleteHead(); }    // O(1)
 
    int  size()            { return l.size(); }          // O(1)
 
    int  front()           { return l.getAt(0); }        // O(1)
 
    void clear()           { l.clear(); }                // giải phóng bộ nhớ
};
