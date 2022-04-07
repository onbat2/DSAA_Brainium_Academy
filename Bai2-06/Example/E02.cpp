//Bài 2. Tìm n! với 0 <= n <= 20.

#include <iostream>
using namespace std;

//Top Down
unsigned long long factorialTD(unsigned long long* fa, int n){
    if(n == 0){
        return 1;
    }if(fa[n] == 0){
        fa[n] = n * factorialTD(fa, n - 1);
    }
    return fa[n];
}

//Botton Up
unsigned long long factorialBU(int n){
    unsigned long long fn = 1;
    for(int i = 1; i <= n; i++){
        fn *= i;
    }
    return fn;
}

int main(){
    const int MAX = 20;
    int n;
    unsigned long long* fa = new unsigned long long[MAX + 1]();
    cout << "Nhap n: ";
    cin >> n;
    if(n >= 0 && n <= 20){
        cout << "Top Down: " << n << "! = " << factorialTD(fa, n) << endl;
        cout << "Bottom Up: " << n << "! = " << factorialBU(n) << endl;
    }else{
        cout << "Nhap 0 <= n <= 20!" << endl;
    }
    return 0;
}
