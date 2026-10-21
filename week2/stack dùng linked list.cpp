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

    // Thêm vào đầu danh sách
    void insertHead(int val) {
        Node* newNode = createNode(val);
        newNode->next = head;
        head = newNode;
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

// ===================== STACK (dùng Linked List) =====================
// Đỉnh stack = ĐẦU danh sách (head)
struct Stack {
    linkedList l;

    void init()          { l.init(); }                  // khởi tạo stack rỗng

    bool isEmpty()       { return l.isEmpty(); }        // O(1)

    void push(int item)  { l.insertHead(item); }        // O(1)

    int  pop()           { return l.deleteHead(); }     // O(1)

    int  size()          { return l.size(); }           // O(1)

    int  top()           { return l.getAt(0); }         // O(1)

    void clear()         { l.clear(); }                 // giải phóng bộ nhớ

    // Duyệt xuôi Stack: Từ Đỉnh (Top) xuống Đáy (Bottom)
    void travF() {
        cout << "Stack (Top -> Bottom): ";
        l.travF(); // Đỉnh ở Head nên duyệt xuôi Linked List chính là Top -> Bottom
    }

    // Duyệt ngược Stack: Từ Đáy (Bottom) lên Đỉnh (Top)
    void travB() {
        cout << "Stack (Bottom -> Top): ";
        l.travB(); // Đáy ở cuối nên duyệt ngược Linked List chính là Bottom -> Top
    }
};

// ===================== CHƯƠNG TRÌNH CHẠY THỬ =====================
int main() {
    Stack st;
    st.init();

    st.push(10);
    st.push(20);
    st.push(30);

    st.travF(); // Out: Stack (Top -> Bottom): 30 20 10 
    st.travB(); // Out: Stack (Bottom -> Top): 10 20 30 

    cout << "Phan tu dinh Stack (Top): " << st.top() << endl; // Out: 30

    cout << "Lay phan tu khoi Stack (Pop): " << st.pop() << endl; // Out: 30
    st.travF(); // Out: Stack (Top -> Bottom): 20 10 

    st.clear(); // Dọn dẹp bộ nhớ
    return 0;
}
