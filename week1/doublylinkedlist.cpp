#include <iostream>
using namespace std;

class DoubleLinkedList{
private:
    class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        
        Node(int val){
            data = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    DoubleLinkedList(){
        head = nullptr;
        size = 0;
    }

    ~DoubleLinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

// Truy cap || O(n)
    int get(int k){
        Node* temp = head;
        int i = 0;
        while(i != k-1){
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

// Chen phan tu vao dau || O(1)
    void insertHead(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        if(head != nullptr){
            head->prev = newNode;
        }
        head = newNode;
        size++;
    }

// Chen phan tu vao cuoi || O(n)
    void insertTail(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            size++;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        size++;
    }

// Chen phan tu vao vi tri k || O(n)
    void insert(int value, int k){
        if(k == 0) return insertHead(value);
        Node* newNode = new Node(value);
        Node* temp = head;
        int i = 0;
        while(i != k - 1){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next != nullptr){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        size++;
    }

// Xoa phan tu dau || O(1)
    void deleteHead(){
        Node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

// Xoa phan tu cuoi || O(n)
    void deleteTail(){
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        if(temp->prev != nullptr){
            temp->prev->next = nullptr;
        }
        else{
            head = nullptr;
        }
        delete temp;
        size--;
    }

// Xoa phan tu thu k || O(n)
    void deletee(int k){
        if(k == 0) return deleteHead();
        Node* temp = head;
        int i = 0;
        while(i != k){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        if(temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
        delete temp;
        size--;
    }

// Duyet xuoi || O(n)
    void travF(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

// Duyet nguoc || O(n)
    void travB(){
        Node* temp = head;
        if(temp == nullptr) return;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
