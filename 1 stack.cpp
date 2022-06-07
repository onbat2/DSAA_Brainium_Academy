#include<iostream>
#include<exception>
using namespace std;

template<class T> class Stack{
	T* data;
	int capacity;
	int currentSize;
public:
	Stack(int cap = 10){
		if(cap <= 0){
			capacity = 10;			
		}
		else{
			capacity = cap;
		}
		data = new T[capacity];
		currentSize = 0;
	}
	
	bool isEmpty(){
		return currentSize == 0;
	}		
	
	bool isFull(){
		return currentSize == capacity;
	}
	
	void push(T value){
		if(isFull()){
			cout << "Full Storage" << endl;
		}
		else{
			data[currentSize++] = value; 
		}
	}
	
	T pop(){
		if(isEmpty()){
			throw exception("Empty Stack");
		}
		else{
			currentSize--;
			return data[currentSize];
		}
	}
	
	T top(){
		if(isEmpty()){
			throw exception("Empty Stack");
		}
		else{
			return data[currentSize - 1];
		}
	}
	
	int size(){
		return currentSize;
	}
	
	~Stack(){
		delete[] data;
	}
};

int main(){
	Stack<int> stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	cout << "So phan tu hien co trong stack: " << stack.size() << endl;
	while(!stack.isEmpty()){
		cout << "Phan tu dau stack: " << stack.pop() << endl;
	}
	try{
		cout << "Phan tu dau stack: " << stack.pop() << endl;
	}
	catch(exception e){
		cout << "Ngoai le: " << e.what() << endl;
	}
	return 0;
}
