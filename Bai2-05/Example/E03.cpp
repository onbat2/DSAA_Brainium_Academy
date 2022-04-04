//Bài 3. Viết chương trình tính tổng các chữ số của một số nguyên dương n.

#include <iostream>

using namespace std;

int sumDigits(long long n){
    if(n < 10){
        return n;
    }else{
        return n % 10 + sumDigits(n / 10);
    }
}

int main(){
    long long n;
    cout << "Nhap so tu nhien n > 0: ";
    cin >> n;
    if(n > 0){
        cout << "Ket qua: " << sumDigits(n) << endl;
    }else{
        cout << "Nhap n > 0" << endl;
    }
    return 0;
}
