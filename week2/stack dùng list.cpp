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

    // Duyệt xuôi mảng (từ vị trí 0 đến n - 1)
    void travF() {
        if (isEmpty()) cout << "(Rong)";
        else {
            for (int i = 0; i < n; i++) cout << data[i] << " ";
        }
        cout << endl;
    }

    // Duyệt ngược mảng (từ vị trí n - 1 về 0)
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

// ===================== STACK (dùng List mảng) =====================
// Đỉnh stack = CUỐI mảng
struct Stack {
    List l;

    void init()          { l.init(); }                     // khởi tạo stack rỗng

    bool isEmpty()       { return l.isEmpty(); }            // O(1)

    void push(int item)  { l.insertTail(item); }            // O(1)

    int  pop()           { return l.deleteTail(); }         // O(1)

    int  size()          { return l.size(); }               // O(1)

    int  top()           { return l.getAt(l.size() - 1); }  // O(1)

    // Duyệt xuôi Stack: Từ Đỉnh (Top) xuống Đáy (Bottom)
    void travF() {
        cout << "Stack (Top -> Bottom): ";
        l.travB(); // Đỉnh nằm ở cuối mảng nên duyệt ngược List chính là từ Top -> Bottom
    }

    // Duyệt ngược Stack: Từ Đáy (Bottom) lên Đỉnh (Top)
    void travB() {
        cout << "Stack (Bottom -> Top): ";
        l.travF(); // Đáy nằm ở đầu mảng nên duyệt xuôi List chính là từ Bottom -> Top
    }
};

// ===================== CHƯƠNG TRÌNH MINH HỌA =====================
int main() {
    Stack st;
    st.init();

    st.push(10);
    st.push(20);
    st.push(30);

    st.travF(); // In ra: Stack (Top -> Bottom): 30 20 10 
    st.travB(); // In ra: Stack (Bottom -> Top): 10 20 30 

    cout << "Phan tu o dinh Stack (Top): " << st.top() << endl; // Out: 30

    cout << "Lay phan tu khoi Stack (Pop): " << st.pop() << endl; // Out: 30
    st.travF(); // In ra: Stack (Top -> Bottom): 20 10 

    return 0;
}
