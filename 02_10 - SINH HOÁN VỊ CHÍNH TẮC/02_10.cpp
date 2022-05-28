#include <iostream>
using namespace std;

//sinh hoán vị kế tiếp
bool nextPermutation(int* arr, int n){
    int i = n - 2;
    while(i >= 0 && arr[i] > arr[i + 1]){
        i--;
    }
    if(i >= 0){
        int k = n - 1;
        while (arr[i] > arr[k]){
            k--;
        }
        int tmp = arr[i];
        arr[i] = arr[k];
        arr[k] = tmp;
        int r = i + 1;
        int s = n - 1;
        while(r < s){
            int t = arr[r];
            arr[r] = arr[s];
            arr[s] = t;
            r++;
            s--;
        }
        return false;
    }else{
        return true; //cấu hình cuối cùng
    }
}

//hiển thị
void output(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//thuật toán sinh hoán bị chính tắc
void generatePermutation(int* arr, int n){
    bool isFinalConfig = false;
    while(!isFinalConfig){
        output(arr, n);
        isFinalConfig = nextPermutation(arr, n);
    }
}

int main(){
    int* arr;
    int n;
    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    generatePermutation(arr, n);
    return 0;
}
