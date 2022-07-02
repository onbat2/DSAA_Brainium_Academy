//Bài 8. Viết chương trình tìm ước chung lớn nhất của hai số nguyên dương.

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}

int main(){
    int a, b;
    cout << "Nhap 2 so nguyen a, b > 0: ";
    cin >> a >> b;
    if(a > 0 && b > 0){
        cout << "Uoc chung lon nhat cua 2 so la: "
             << gcd(a, b) << endl;
    }else{
        cout << "Nhap lai 2 so nguyen a, b > 0";
    }
}
