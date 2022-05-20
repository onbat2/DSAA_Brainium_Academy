#include <iostream>
using namespace std;

//hiển thị kết quả
static void output(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//sinh tổ hợp kế tiếp
bool nextCombination(int* arr, int n, int k){
    int i = k - 1;
    while(i >= 0 && arr[i] == n - k + i + 1){
        i--;
    }
    if(i >= 0){
        arr[i] = arr[i] + 1;
        for(int j = i + 1; j < k; j++){
            arr[j] = arr[i] + j - i;
        }
        return false;
    }else{
        return true; //cấu hình cuối cùng
    }
}


//thuật toán sinh toàn bộ cá tổ hợp chập k của n
void generate(int* arr, int n, int k){
    bool isFinalConfig = false;
    while(!isFinalConfig){
        output(arr, k);
        isFinalConfig = nextCombination(arr, n, k);
    }
}

int main(){
    int n;
    int k;
    cout << "Nhap vao 2 so nguyen n, k: ";
    cin >> n >> k;
    int* arr = new int[k];
    for(int i = 0; i < k; i++){
        arr[i] = i + 1;
    }
    cout << "Cac to hop C(" << k << ", " << n << "):" << endl;
    generate(arr, n, k);
    return 0;
}
