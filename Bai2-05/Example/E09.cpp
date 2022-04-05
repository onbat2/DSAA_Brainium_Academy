//Bài 9. Viết chương trình tính tổng từ 1 đến n. Trong đó n nguyên dương nhập vào từ bàn phím.

#include <iostream>
using namespace std;

int add(int n){
    if(n <= 0){
        return 0;
    }else{
        return n + add(n - 1);
    }
}

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    if(n > 0){
        cout << "SUM = " << add(n) << endl;
    }else{
        cout << "Nhap so nguyen n > 0!\n0";
    }
}
