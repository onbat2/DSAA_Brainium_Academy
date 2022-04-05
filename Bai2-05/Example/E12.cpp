/*
Bài 12. Viết chương trình in ra ma trận xoắn ốc tăng dần từ trong ra ngoài cấp n x n
với n > 0  nhập vào từ bàn phím. Ví dụ với n = 5:
21 22 23 24 25
20 7 8 9 10
19 6 1 2 11
18 5 4 3 12
17 16 15 14 13
*/

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Hàm dùng để vẽ ma trận xoắn ốc cấp m x m.
 *
 * @param a       ma trận kết quả cấp m x m
 * @param rowPrev chỉ số hàng trên top
 * @param rowNext chỉ số hàng bottom
 * @param colPrev chỉ số cột left
 * @param colNext chỉ số cột right
 * @param value   giá trị để gán cho từng phần tử trong ma trận
 * @param bound   biên giới hạn giá trị gán cho phần tử ma trận xoắn ốc
 */
void createSpiralMatrix(int** a, int rowPrev, int rowNext,
    int colPrev, int colNext, int value, int bound, int row) {
    if (value >= bound) {
        return;
    }
    for (int i = colPrev + 1; i <= colNext; ++i) { // vẽ hàng top
        if (rowPrev >= 0 && i < row)
            a[rowPrev][i] = value++;
    }
    colPrev--;
    if (colNext < row) {
        for (int i = rowPrev + 1; i <= rowNext; ++i) { // vẽ cột right
            if (i < row)
                a[i][colNext] = value++;
        }
    }
    rowPrev--;
    if (rowNext < row) {
        for (int i = colNext - 1; i >= colPrev; --i) { // vẽ hàng bottom
            if (i >= 0)
                a[rowNext][i] = value++;
        }
    }
    colNext++;
    if (colPrev >= 0) {
        for (int i = rowNext - 1; i >= rowPrev; --i) { // vẽ cột left
            if (i >= 0)
                a[i][colPrev] = value++;
        }
    }
    rowNext++;
    createSpiralMatrix(a, rowPrev, rowNext, colPrev, colNext, value, bound, row);
}

void showResult(int** arr, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            cout << setw(5) << arr[i][j];
        }
        cout << endl << endl;
    }
}

int main() {
    int row, col;
    cout << "Nhap so hang: ";
    cin >> row;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[row];
    }
    int centerRowIndex = (row - 1) / 2;
    int centerColIndex = (row - 1) / 2;
    int rowNext = centerRowIndex + 1;
    int colNext = centerColIndex + 1;
    int rowPrev = centerRowIndex;
    int colPrev = centerColIndex;
    int value = 1;
    arr[centerColIndex][centerRowIndex] = value++;
    int bound = row * row;
    createSpiralMatrix(arr, rowPrev, rowNext, colPrev, colNext, value, bound, row);
    showResult(arr, row);
    // thu hồi bộ nhớ
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
