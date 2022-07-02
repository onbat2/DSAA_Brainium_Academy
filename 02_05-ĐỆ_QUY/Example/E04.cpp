//Bài 4. Viết chương trình in ra đảo ngược các chữ số của một số nguyên dương n.

#include <iostream>
using namespace std;

void printRevert(long long n){
    if(n > 0){
        cout << n % 10;
        return printRevert(n / 10);
    }
}

int main(){
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if(n > 0){
        printRevert(n);
    }else{
        cout << "Nhap n > 0!" << endl;
    }
    return 0;
}
