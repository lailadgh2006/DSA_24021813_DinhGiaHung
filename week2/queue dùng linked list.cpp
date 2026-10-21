#include <iostream>
using namespace std;

// Cấu trúc một Node bên trong danh sách
struct Node {
    int data;
    Node* next;
};

// Danh sách liên kết: head + biến đếm n (để size() là O(1))
struct linkedList {
    Node* head;
    int n; // Số lượng phần tử hiện tại

    // Khởi tạo danh sách rỗng
    void init() {
        head = nullptr;
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

    // Thêm vào cuối danh sách (Dùng cho push của Queue)
    void insertTail(int val) {
        Node* newNode = createNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        n++;
    }

    // Xóa đầu danh sách, trả về phần tử vừa xóa (Dùng cho pop của Queue)
    int deleteHead() {
        if (head == nullptr) {
            cout << "Danh sach rong, khong the xoa!\n";
            return -1;
        }
        Node* temp = head;
        int v = temp->data;
        head = head->next;
        delete temp;
        n--;
        return v;
    }

    // Duyệt xuôi Linked List (từ Head đến Tail)
    void travF() {
        if (isEmpty()) {
            cout << "(Rong)";
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

    // Hàm phụ trợ đệ quy để duyệt ngược Linked List
    void travBHelper(Node* node) {
        if (node == nullptr) return;
        travBHelper(node->next);
        cout << node->data << " ";
    }

    // Duyệt ngược Linked List (từ Tail về Head)
    void travB() {
        if (isEmpty()) {
            cout << "(Rong)";
        } else {
            travBHelper(head);
        }
        cout << endl;
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

// ===================== QUEUE (dùng Linked List) =====================
// Quy ước: Đầu Queue (Front) = Head, Cuối Queue (Rear) = Tail
struct Queue {
    linkedList l;

    void init()          { l.init(); }                  // khởi tạo queue rỗng

    bool isEmpty()       { return l.isEmpty(); }        // O(1)

    void push(int item)  { l.insertTail(item); }        // Thêm vào cuối hàng (Tail)

    int  pop()           { return l.deleteHead(); }     // Xóa ở đầu hàng (Head)

    int  size()          { return l.size(); }           // O(1)

    int  front()         { return l.getAt(0); }         // Lấy phần tử ở đầu Queue O(1)

    void clear()         { l.clear(); }                 // giải phóng bộ nhớ

    // Duyệt xuôi Queue: Từ Đầu (Front) đến Cuối (Rear)
    void travF() {
        cout << "Queue (Front -> Rear): ";
        l.travF();
    }

    // Duyệt ngược Queue: Từ Cuối (Rear) về Đầu (Front)
    void travB() {
        cout << "Queue (Rear -> Front): ";
        l.travB();
    }
};

// ===================== CHƯƠNG TRÌNH CHẠY THỬ =====================
int main() {
    Queue q;
    q.init();

    q.push(10);
    q.push(20);
    q.push(30);

    q.travF(); // Out: Queue (Front -> Rear): 10 20 30 
    q.travB(); // Out: Queue (Rear -> Front): 30 20 10 

    cout << "Phan tu dau Queue (Front): " << q.front() << endl; // Out: 10

    cout << "Lay phan tu khoi Queue (Pop): " << q.pop() << endl; // Out: 10 (FIFO)
    q.travF(); // Out: Queue (Front -> Rear): 20 30 

    q.clear(); // Dọn dẹp bộ nhớ
    return 0;
}
