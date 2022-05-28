#include <iostream>
using namespace std;

template<class T> class Node{
public:
    T data;
    Node<T>* next;

    Node(T data){
        this->next = nullptr;
        this->data = data;
    }
};

template<class T> class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }

    void addHead(T data){
        Node<T>* p = new Node(data);
        if(isEmpty()){
            head = tail = p;
        }else{
            p->next = head;
            head = p;
        }
    }

    void addTail(T data){
        Node<T>* p = new Node(data);
        if(isEmpty()){
            head = tail = p;
        }else{
            tail->next = p;
            tail = p;
        }
    }

    void addAfterX(T data, T x){
        Node<T>* p= new Node(data);
        Node<T>* nodeX = head;
        while(nodeX != nullptr){
            if(nodeX->data == x){
                break;
            }
            nodeX = nodeX->next;
        }
        if(nodeX != nullptr){
            p->next = nodeX->next;
            nodeX->next = p;
        }else{
            cout << "ERROW" << endl;
        }
    }

    void showNodes(){
        Node<T>* p = head;
        while(p != nullptr){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;;
    }
};


int main(){
    LinkedList<string> list;
    list.addTail("John");
    list.addTail("Mike");
    list.addTail("David");
    list.addHead("Liz");
    list.addAfterX("Nickson","Mike");
    list.showNodes();
    return 0;
}
