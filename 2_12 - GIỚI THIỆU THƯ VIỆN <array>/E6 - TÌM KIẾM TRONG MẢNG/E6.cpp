#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;
const size_t SIZE = 10;

template<class T> void showArrayElements(array<T, SIZE> mArray) {
   for (auto item : mArray)
   {
        cout << item << " ";
   }
   cout << endl;
}

int main() {
   // mảng chứa tuổi kiểu int
   array<int, SIZE> ages = { 2, 5, 6, 4, 8, 3, 78, 99, 10, 21 };
   // mảng chứa tên các màu kiểu string
   array<string, SIZE> colors = { "red", "blue", "green", "white", "pink",
     "purple", "gray", "silver", "orange", "magenta" };
   // sắp xếp phần tử mảng theo thứ tự tăng dần:
   sort(ages.begin(), ages.end());
   sort(colors.begin(), colors.end());

   // hiển thị giá trị các phần tử mảng ages và colors:
   cout << "Mang sau khi sap xep: " << endl;
   showArrayElements(ages);
   showArrayElements(colors);

   bool isFoundRed = binary_search(colors.begin(), colors.end(), "red");
   bool isFoundYellow = binary_search(colors.begin(), colors.end(), "yellow");

   cout << endl << "Search result: " << endl;
   cout << "red color " << (isFoundRed ? "was" : "was not")
        << " found in colors array" << endl;
   cout << "yellow color " << (isFoundYellow ? "was" : "was not")
        << " found in colors array" << endl;

   return 0;
}
