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

    ~List(){        
        delete[] arr;
    }
int get(int i){
    if(i < 0 || i >= size){
        cout << "Index error";
        return 0;
    }
    return arr[i];
}

void insertHead(int value){
    for(int i = size; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    size ++;
}

void insertTail(int value){
    arr[size] = value;
    size++;
}

void insert(int value, int k){
    if(k == 0) return insertHead(value);
    for(int i = size; i > k; i--){
        arr[i] = arr[i-1];
    }
    arr[k] = value;
    size++;
}
void deleteHead(){
    for(int i = 0; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}
void deleteTail(){
    size--;
}
void deletee(int k){
    if(k == 0) return deleteHead();
    for(int i = k; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}
void travF(){
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


int main(){
    
}
