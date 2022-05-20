//Cú pháp tổng quát: array<type, size> arrayName = { array elements };

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
   const size_t SIZE = 10;
   // khởi tạo đầy đủ:
   array<int, SIZE> ages = { 2, 5, 6, 4, 8, 3, 78, 99, 10, 21 };
   // khởi tạo không đầy đủ:
   array<int, SIZE> numbers = {50, 12, 37, 28};
   // khởi tạo thiếu hoàn toàn
   array<float, SIZE> grades = {};

   // hiển thị giá trị các phần tử mảng ages:
   cout << left << setw(8) << "Index" << setw(10) << "Value" << endl;
   for (size_t i = 0; i < SIZE; i++)
   {
        cout << left << setw(8) << i << setw(10) << ages[i] << endl;
   }

   // hiển thị giá trị các phần tử của mảng numbers:
   cout << endl;
   cout << left << setw(8) << "Index" << setw(10) << "Value" << endl;
   for (size_t i = 0; i < SIZE; i++)
   {
        cout << left << setw(8) << i << setw(10) << numbers[i] << endl;
   }

   return 0;
}
