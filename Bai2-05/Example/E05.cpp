//Bài 5. Viết chương trình đếm số các chữ số của một số nguyên dương n.

#include <iostream>
using namespace std;

int countDigits(long long n){
    if(n < 10){
        return 1;
    }else{
        return 1 + countDigits(n / 10);
    }
}

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    if(n > 0){
        cout << "So ban nhap co "
             << countDigits(n) << " chu so" << endl;
    }else{
        cout << "Nhap n > 0!";
    }
    return 0;
}
