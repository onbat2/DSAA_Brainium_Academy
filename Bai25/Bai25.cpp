#include<iostream>
using namespace std;

// n!

unsigned long long factorial(int n){
    if(n <= 1){
        return 1;
    }else{
        return n * factorial(n - 1);
    }
}

int main(){
    int n;
    cout << "Nhap n >= 0: ";
    cin >> n;
    auto result = factorial(n);
    cout << n << "! = " << result << endl;
}
