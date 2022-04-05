//Bài 7. Viết chương trình hiển thị chuỗi kí tự nhập vào từ bàn phím theo thứ tự ngược lại.

#include <iostream>
#include <string>
using namespace std;

void showRevert(string str, int pos){
    if(pos >= 0){
        cout << str.at(pos);
        showRevert(str, pos -1);
    }
}

int main(){
    string str;
    cout << "Nhap chuoi ky tu: ";
    getline(cin,str);
    cout << "Day ky tu dao nguoc la: ";
    showRevert(str, str.length() - 1);
    cout << "\n";
    return 0;
}
