//Bài 6. Viết chương trình tìm chữ số đầu tiên của số nguyên dương n.

#include <iostream>
using namespace std;

int firstDigit(long n){
    if(n < 10){
        return n;
    }else{
        return firstDigit(n / 10);
    }
}

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    if(n > 10){
        cout << firstDigit(n) << endl;
    }else{
        cout << "Nhap so nguyen n > 0!" << endl;
    }
}
