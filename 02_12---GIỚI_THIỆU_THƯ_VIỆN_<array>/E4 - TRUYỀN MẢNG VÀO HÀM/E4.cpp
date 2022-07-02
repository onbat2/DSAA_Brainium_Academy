#include <iostream>
#include <array>
#include <iomanip>

using namespace std;
const size_t SIZE = 10;

template<class T> void showArrayElements(array<T, SIZE> mArray) {
   for (auto item : mArray)
   {
        cout << item << " ";
   }
   cout << endl;
}

template<class T> void updateArrayElements(array<T, SIZE> mArray) {
   for (auto& item : mArray) {
        item += 25; // cộng thêm cho mỗi phần tử giá trị 25
   }
}

int main() {
   // khởi tạo đầy đủ:
   array<int, SIZE> ages = { 2, 5, 6, 4, 8, 3, 78, 99, 10, 21 };

   // hiển thị giá trị các phần tử mảng ages:
   cout << "Mang goc ban dau: " << endl;
   showArrayElements(ages);

   // update các phần tử của mảng:
   updateArrayElements(ages);

   // hiển thị giá trị các phần tử mảng ages:
   cout << endl << "Mang sau khi update: " << endl;
   showArrayElements(ages);

   return 0;
}
