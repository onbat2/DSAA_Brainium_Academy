#include <iostream>
using namespace std;

void output(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool nextBinaryString(int* arr, int n){
    int i = n - 1;
    while(i >= 0 && arr[i] != 0){
        arr[i] = 0;
        i--;
    }
    if(i >= 0){
        arr[i] = 1;
        return false;
    }else{
        return true;
    }
}

void generate(int* arr,int n){
    bool isFinal = false;
    while(!isFinal){
        output(arr, n);
        isFinal = nextBinaryString(arr, n);
    }
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int* arr = new int[n]();
    generate(arr, n);
    return 0;
}
