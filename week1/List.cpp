#include <iostream>
using namespace std;

class List{
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

    ~List(){           //"~" tự động chạy khi ra khỏi khối
        delete[] arr;
    }

// Truy cap || O(1)
int get(int i){
    if(i < 0 || i >= size){
        cout << "Index error";
        return 0;
    }
    return arr[i];
}

//Chen phan tu vao dau || O(n)
void insertHead(int value){
    for(int i = size; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    size ++;
}

//Chen phan tu vao cuoi || O(n)
void insertTail(int value){
    arr[size] = value;
    size++;
}

//Chen phan tu vao vi tri k || O(n)
void insert(int value, int k){
    if(k == 0) return insertHead(value);
    for(int i = size; i > k; i--){
        arr[i] = arr[i-1];
    }
    arr[k] = value;
    size++;
}

//Xoa phan tu dau || O(n)
void deleteHead(){
    for(int i = 0; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

//Xoa phan tu cuoi || O(1)
void deleteTail(){
    size--;
}

//Xoa phan tu thu k || O(n)
void deletee(int k){
    if(k == 0) return deleteHead();
    for(int i = k; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

//Duyet xuoi || O(n)
void travF(){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Duyet nguoc || O(n)
void travB() {
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    }
};


int main(){
    
}
