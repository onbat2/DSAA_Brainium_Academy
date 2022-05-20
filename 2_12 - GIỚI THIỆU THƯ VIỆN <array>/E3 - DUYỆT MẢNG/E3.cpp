/*
 * Cấu trúc for rút gọn:
 *
 * for(declare : expression) {
    // statement
}
 */

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
   const size_t SIZE = 10;
   // khởi tạo đầy đủ:
   array<int, SIZE> ages = { 2, 5, 6, 4, 8, 3, 78, 99, 10, 21 };

   // hiển thị giá trị các phần tử mảng ages:
   cout << "Mang goc ban dau: " << endl;
   for (auto item : ages)
   {
        cout << item << " ";
   }

   // update các phần tử của mảng:
   for (auto& item : ages) {
        item += 25; // cộng thêm cho mỗi phần tử giá trị 25
   }

   // hiển thị giá trị các phần tử mảng ages:
   cout << endl << "Mang sau khi update: " << endl;
   for (auto item : ages)
   {
        cout << item << " ";
   }

   return 0;
}
