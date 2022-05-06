#include <iostream>
using namespace std;

//fibonacci top-down
unsigned long long fibonacciTopDown(unsigned long long* fibo, int n){
    if(n < 2){
        return fibo[n] = n;
    }
    if(fibo[n] == 0){
        fibo[n] = fibonacciTopDown(fibo, n - 1)
                  + fibonacciTopDown(fibo, n - 2);
    }
    return fibo[n];
}

//fibonacci bottom-up
unsigned long long fibonacciBottomUp(int n){
    if(n < 2){
        return n;
    }else{
        unsigned long long f0 = 0;
        unsigned long long f1 = 1;
        unsigned long long fn = 0;
        for(int i = 2; i <= n; i++){
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        return fn;
    }
}

int main(){
    const int MAX = 90;
    unsigned long long *fibo = new unsigned long long[MAX + 1]();
    cout << "F0 = " << fibonacciTopDown(fibo, 0) << endl;
    cout << "F1 = " << fibonacciTopDown(fibo, 1) << endl;
    cout << "F2 = " << fibonacciTopDown(fibo, 2) << endl;
    cout << "F3 = " << fibonacciTopDown(fibo, 3) << endl;
    cout << "F60 = " << fibonacciTopDown(fibo, 60) << endl;
    cout << "F61 = " << fibonacciBottomUp(61) << endl;
    cout << "F90 = " << fibonacciTopDown(fibo, 90) << endl;
    cout << "F91 = " << fibonacciBottomUp(91) << endl;
    return 0;
}




