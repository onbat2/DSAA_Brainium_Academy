/*
Bài 11. Viết chương trình in ra ma trận xoắn ốc tăng dần từ ngoài vào trong cấp m x n với m, n >
0 nhập vào từ bàn phím. Giá trị tăng bắt đầu từ 1. Ví dụ với m = n = 5:
 1  2  3  4  5
16 17 18 19  6
15 24 25 20  7
14 23 22 21  8
13 12 11 10  9
*/

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Phương thức dùng để vẽ ma trận xoắn ốc cấp m x n.
 * B1: khởi tạo các biến rowStart-chỉ số hàng đầu, rowEnd-chỉ số hàng cuối,
 * colStart-cột đầu, colEnd-cột cuối.
 * B2: Lặp chừng nào tất cả các cạnh cấu thành ma trận xoắn ốc được duyệt:
 * B2.1: in ra hàng đầu tiên trong vùng đang xét của ma trận, tăng rowStart lên 1.
 * B2.2: in ra cột cuối cùng trong vùng đang xét của ma trận, giảm colEnd đi 1.
 * B2.3: in ra hàng cuối cùng trong vùng đang xét của ma trận, giảm rowEnd đi 1.
 * B2.4: in ra cột đầu tiên trong vùng đang xét của ma trận, tăng colStart lên 1.
 *
 * @param a        ma trận kết quả cấp m x n
 * @param rowStart vị trí hàng bắt đầu của lần duyệt hiện tại
 * @param rowEnd   vị trí hàng cuối của lần duyệt hiện tại
 * @param colStart vị trí cột bắt đầu của lần duyệt hiện tại
 * @param colEnd   vị trí hàng cột cuối của lần duyệt hiện tại
 * @param value    giá trị của phần tử kế tiếp trong ma trận xoắn ốc
 */
void createSpiralMatrix(int** a, int rowStart, int rowEnd, int colStart, int colEnd, int value) {
    if (rowStart >= rowEnd || colStart >= colEnd) {
        return; // điểm dừng
    }
    // gán giá trị cho hàng đầu trong số các hàng còn lại
    for (int i = colStart; i < colEnd; ++i) { // c
        a[rowStart][i] = value++;
    }
    rowStart++; // chuyển đến hàng kế tiếp ở lần duyệt tới
    // gán giá trị cho cột cuối trong số các cột còn lại
    for (int i = rowStart; i < rowEnd; ++i) {
        a[i][colEnd - 1] = value++;
    }
    colEnd--; // chuyển tới cột liền trước ở lần duyệt tới
    // gán giá trị cho hàng cuối trong các hàng còn lại
    if (rowStart < rowEnd) {
        for (int i = colEnd - 1; i >= colStart; --i) {
            a[rowEnd - 1][i] = value++;
        }
        rowEnd--; // chuyển tới hàng liền trước ở lần duyệt tới
    }
    // gán giá trị cho cột đầu trong số các cột còn lại
    if (colStart < colEnd) {
        for (int i = rowEnd - 1; i >= rowStart; --i) {
            a[i][colStart] = value++;
        }
        colStart++; // chuyển đến cột kế tiếp ở lần duyệt tới
    }
    createSpiralMatrix(a, rowStart, rowEnd, colStart, colEnd, value);

}

void showResult(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(5) << arr[i][j];
        }
        cout << endl << endl;
    }
}

int main() {
    int row, col;
    cout << "Nhap so hang, cot: ";
    cin >> row >> col;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    int rowStart = 0, colStart = 0;
    int value = 1;
    /*  rowStart - starting row index
        rowEnd - ending row index
        colStart - starting column index
        colEnd - ending column index
    */
    createSpiralMatrix(arr, rowStart, row, colStart, col, value);
    showResult(arr, row, col);
    // thu hồi bộ nhớ
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
