//Bài 10. Viết chương trình tính tổng S = 1 + 1/2 + 1/3 + ... + 1/n với n nguyên dương.

#include <iostream>
using namespace std;

double add(int n){
    if(n == 1){
        return 1;
    }else{
        return 1.0/n + add(n - 1);
    }
}

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    if(n > 0){
        cout << "SUM = " << add(n) << endl;
    }else{
        cout << "Nhap so nguyen n > 0!\n";
    }
}
