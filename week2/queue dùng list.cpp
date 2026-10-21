include <iostream>
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
            return -1; // Giá trị báo lỗi
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
 
    // Xóa đầu danh sách, trả về phần tử vừa xóa
    int deleteHead() {
        if (n <= 0) {
            cout << "Danh sach rong!\n";
            return -1;
        }
        int v = data[0];
        for (int i = 0; i < n - 1; i++) {
            data[i] = data[i + 1]; // Dịch trái các phần tử
        }
        n--;
        return v;
    }
 
    bool isEmpty() { return n == 0; }
    int size()     { return n; }
};
 
// ===================== QUEUE (dùng List mảng) =====================
// Thêm ở CUỐI, lấy ở ĐẦU
struct Queue {
    List l;
 
    void init()            { l.init(); }                 // khởi tạo queue rỗng
 
    bool isEmpty()         { return l.isEmpty(); }       // O(1)
 
    void enqueue(int item) { l.insertTail(item); }       // O(1)
 
    int  dequeue()         { return l.deleteHead(); }    // O(n): dịch trái cả mảng
 
    int  size()            { return l.size(); }          // O(1)
 
    int  front()           { return l.getAt(0); }        // O(1)
};
