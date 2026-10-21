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
 
    // Xóa cuối danh sách, trả về phần tử vừa xóa
    int deleteTail() {
        if (n <= 0) {
            cout << "Danh sach rong!\n";
            return -1;
        }
        return data[--n]; // giảm n rồi trả về phần tử cuối cũ
    }
 
    bool isEmpty() { return n == 0; }
    int size()     { return n; }
};
 
// ===================== STACK (dùng List mảng) =====================
// Đỉnh stack = CUỐI mảng
struct Stack {
    List l;
 
    void init()          { l.init(); }                      // khởi tạo stack rỗng
 
    bool isEmpty()       { return l.isEmpty(); }            // O(1)
 
    void push(int item)  { l.insertTail(item); }            // O(1)
 
    int  pop()           { return l.deleteTail(); }         // O(1)
 
    int  size()          { return l.size(); }               // O(1)
 
    int  top()           { return l.getAt(l.size() - 1); }  // O(1)
};
