//Cú pháp khai báo: array<type, arraySize> arrayName;

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
   const size_t SIZE = 10;
   // khai báo mảng numbers với 10 phần tử tối đa
   array<int, SIZE> numbers;
   // gán các phần tử cho mảng:
   for (size_t i = 0; i < SIZE; i++)
   {
        numbers[i] = i * (i + 1);
   }
   // hiển thị giá trị các phần tử mảng:
   cout << left << setw(8) << "Index" << setw(10) << "Value" << endl;
   for (size_t i = 0; i < SIZE; i++)
   {
        cout << left << setw(8) << i << setw(10) << numbers[i] << endl;
   }

   return 0;
}
