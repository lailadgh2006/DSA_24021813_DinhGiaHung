#include <iostream>
using namespace std;

const int MAX = 100; // Kích thước tối đa của mảng

struct List {
    int data[MAX]; // Mảng tĩnh lưu trữ các phần tử
    int n;         // Số lượng phần tử hiện tại

    // Khởi tạo danh sách rỗng
    void init() {
        n = 0;
    }

    // Trả về phần tử tại vị trí i
    int getAt(int i) {
        if (i < 0 || i >= n) {
            cout << "Loi: Vi tri khong hop le!\n";
            return -1;
        }
        return data[i];
    }

    // Thêm vào cuối danh sách
    void insertTail(int val) {
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }
        data[n] = val;
        n++;
    }

    // Xóa đầu danh sách, trả về phần tử vừa xóa (Cần thiết cho Queue)
    int deleteHead() {
        if (n <= 0) {
            cout << "Danh sach rong!\n";
            return -1;
        }
        int removedVal = data[0];
        for (int i = 0; i < n - 1; i++) {
            data[i] = data[i + 1];
        }
        n--;
        return removedVal;
    }

    // Duyệt xuôi mảng (từ 0 đến n - 1)
    void travF() {
        if (isEmpty()) cout << "(Rong)";
        else {
            for (int i = 0; i < n; i++) cout << data[i] << " ";
        }
        cout << endl;
    }

    // Duyệt ngược mảng (từ n - 1 về 0)
    void travB() {
        if (isEmpty()) cout << "(Rong)";
        else {
            for (int i = n - 1; i >= 0; i--) cout << data[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() { return n == 0; }
    int size()     { return n; }
};

// ===================== QUEUE (dùng List mảng) =====================
// Quy ước: Đầu Queue (Front) = ĐẦU mảng, Cuối Queue (Rear) = CUỐI mảng
struct Queue {
    List l;

    void init()          { l.init(); }                     // Khởi tạo Queue rỗng

    bool isEmpty()       { return l.isEmpty(); }            // O(1)

    void push(int item)  { l.insertTail(item); }            // Thêm vào cuối hàng O(1)

    int  pop()           { return l.deleteHead(); }         // Xóa ở đầu hàng O(n)

    int  size()          { return l.size(); }               // O(1)

    int  front()         { return l.getAt(0); }             // Xem phần tử đầu hàng O(1)

    // Duyệt xuôi Queue: Từ Đầu (Front) đến Cuối (Rear)
    void travF() {
        cout << "Queue (Front -> Rear): ";
        l.travF(); // Đầu ở index 0, cuối ở index n-1 nên duyệt xuôi List
    }

    // Duyệt ngược Queue: Từ Cuối (Rear) về Đầu (Front)
    void travB() {
        cout << "Queue (Rear -> Front): ";
        l.travB(); // Từ cuối về đầu nên duyệt ngược List
    }
};

// ===================== CHƯƠNG TRÌNH MINH HỌA =====================
int main() {
    Queue q;
    q.init();

    q.push(10);
    q.push(20);
    q.push(30);

    q.travF(); // In ra: Queue (Front -> Rear): 10 20 30 
    q.travB(); // In ra: Queue (Rear -> Front): 30 20 10 

    cout << "Phan tu o dau Queue (Front): " << q.front() << endl; // Out: 10

    cout << "Lay phan tu khoi Queue (Pop): " << q.pop() << endl;  // Out: 10 (Vào trước ra trước)
    q.travF(); // In ra: Queue (Front -> Rear): 20 30 

    return 0;
}
