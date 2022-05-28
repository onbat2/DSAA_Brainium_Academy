#include <iostream>
using namespace std;

template<class T> class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data){
        next = nullptr;
        prev = nullptr;
        this->data = data;
    }
};

template<class T> class DoublyLinkedList{
    Node<T>* head;\
    Node<T>* tail;
public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void addHead(T data){
        Node<T>*p = new Node(data);
        if(isEmpty()){
            head = tail = p;
        }else{
            p->next = head;
            head->prev = p;
            head = p;
        }
    }

    void addTail(T data){
        Node<T>*p = new Node(data);
        if(isEmpty()){
            head = tail = p;
        }else{
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }

    void addAfterX(T data, T x){
        Node<T>*p = new Node(data);
        Node<T>*nodeX = head;
        while(nodeX != nullptr){
            if(nodeX->data == x){
                break;
            }
            nodeX = nodeX->next;
        }
        if(nodeX != nullptr){
            p->next = nodeX->next;
            p->prev = nodeX;
            if(nodeX->next != nullptr){
                p->next->prev = p;
            }
            nodeX->next = p;
        }else{
            cout << "ERROW" << endl;
        }
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void showNodes(){
        Node<T>*p = head;
        while(p != nullptr){
            cout << p->data << " ";
            p = p->next;
        }
    }

    void showNodesReverse(){
        Node<T>*p = tail;
        while(p != nullptr){
            cout << p->data << " ";
            p = p->prev;
        }
    }
};

int main(){
    DoublyLinkedList<string> list;
    list.addHead("Danny");
    list.addTail("Mavis");
    list.addTail("Lyly");
    list.addTail("Jack");
    list.addAfterX("Clara","Mavis");
    cout << "Thứ tự xuôi: ";
    list.showNodes();
    cout << endl;
    cout << "Thứ tự ngược: ";
    list.showNodesReverse();
    cout << endl;
    return 0;
}
