#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
using namespace std;

template<class T> void showVector(vector<T> v){
    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
}

template<class T> void showVectorReverse(vector<T> v){
    for(auto i = v.rbegin(); i != v.rend(); i++){
        cout << *i << " ";
    }
}

int main(){
    const size_t SIZE = 10;
    array<int, SIZE> intArray = {1, 21, 33, 60, 102, 82, 73, 55, 92, 47};
    vector<int> vectorInt(intArray.begin(), intArray.end());
    vector<int> other(vectorInt.begin(), vectorInt.begin() + 5);

    //Biểu diễn vevtor(Cách 1)
    cout << "Biểu diễn vector: ";
    ostream_iterator<int> output(cout, " ");
    copy(vectorInt.begin(), vectorInt.end(), output);
    cout << endl;

    //Biểu diễn vector(Cách 2)
    cout << "Biểu diễn vector: ";
    showVector(vectorInt);
    cout << endl;

    //Đảo ngược Vector
    cout << "Đảo ngược Vector: ";
    showVectorReverse(vectorInt);
    cout << endl;

    //Sửa đổi thành phần trong vector
    vectorInt[1]= 150;
    vectorInt.at(3) = 369;
    vectorInt.insert(vectorInt.begin() + 0, 900); //Chèn giá trị
    vectorInt.push_back(800); //Thêm vào phần tử ở cuối
    vectorInt.push_back(600);
    vectorInt.pop_back(); //Xóa phần tử ở cuối
    cout << "Sửa đổi thành phần trong vector: ";
    showVector(vectorInt);
    cout << endl;

    //Sắp xếp
    sort(vectorInt.begin(), vectorInt.end());
    cout << "Sắp xếp tăng dần: ";
    showVector(vectorInt);
    cout << endl;
    sort(vectorInt.begin(), vectorInt.end(), greater());
    cout << "Sắp xếp giảm dần: ";
    showVector(vectorInt);
    cout << endl;

    //Trao đổi 2 vector
    other.swap(vectorInt);
    cout << "Trao đổi 2 vector: ";
    showVector(vectorInt);
    cout << endl;

    return 0;
}
