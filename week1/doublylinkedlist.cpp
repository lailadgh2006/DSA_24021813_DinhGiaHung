#include <iostream>
using namespace std;

struct DoublyLinkedList {
private:
    struct Node {
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
    DoublyLinkedList(){
        head = nullptr;
        size = 0;
    }

    ~DoublyLinkedList(){
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
        while(i != k-1 && temp != nullptr){
            temp = temp->next;
            i++;
        }
        if(temp == nullptr) return -1;
        return temp->data;
    }

    void insertHead(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        if(head != nullptr){
            head->prev = newNode;
        }
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
        newNode->prev = temp;
        size++;
    }

    void insert(int value, int k){
        if(k == 0) return insertHead(value);
        Node* newNode = new Node(value);
        Node* temp = head;
        int i = 0;
        while(i != k - 1 && temp != nullptr){
            temp = temp->next;
            i++;
        }
        if(temp == nullptr) {
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next != nullptr){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        size++;
    }

    void deleteHead(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteTail(){
        if(head == nullptr) return;
        Node* temp = head;
        while(temp->next != nullptr){
            temp->next; 
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

    void deletee(int k){
        if(k == 0) return deleteHead();
        Node* temp = head;
        int i = 0;
        while(i != k && temp != nullptr){
            temp = temp->next;
            i++;
        }
        if(temp == nullptr) return;
        temp->prev->next = temp->next;
        if(temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
        delete temp;
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
