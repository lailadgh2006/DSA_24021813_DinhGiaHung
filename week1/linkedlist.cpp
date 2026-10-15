#include <iostream>
using namespace std;

class LinkedList{
private:
    class Node{
    public:
        int data;
        Node* next;
        
        Node(int val){
            data = val;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }

    ~LinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    int get(int k){
        Node* temp = head;
        int i = 0;
        while(i != k){
            temp = temp->next;
            i++;
        }
        return temp->data;
    }
    void insertHead(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
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
        size++;
    }
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
        temp->next = newNode;
        size++;
    }
    void deleteHead(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void deleteTail(){
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        size--;
    }
    void deletee(int k){
        if(k == 0) return deleteHead();
        Node* temp = head;
        int i = 0;
        while(i != k-1){
            temp = temp->next;
            i++;
        }
        Node* nodeDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeDelete;
        size--;
    }
    void travF(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void travB(){
        for(int i = size - 1; i >= 0; i--){
            Node* temp = head;
            for(int j = 0; j < i; j++){
                temp = temp->next;
            }
            cout << temp->data << " ";
        }
        cout << endl;
    }
};
