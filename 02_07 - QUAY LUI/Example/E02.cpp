/*
 * Bài toán quân mã đi tuần:
 * Cho một bàn cờ kích thước NxN
 * Một quân mã đặt tại vị trí ô đầu tiên trong bàn cờ.
 * Nhiệm vụ của bạn là cho quân mã di chuyển qua tất cả các ô trong bàn cờ,
 * mỗi ô chỉ được đi qua 1 lần. In ra kết quả lời giải tìm được.
 */

#include <iostream>
#include <iomanip>
using namespace std;
const int N = 8;

void showResult(int sol[N][N]);
bool solveKnightTour(int x, int y, int movestep, int sol[N][N], int xMove[N], int yMove[N]);
bool isSafe(int x, int y, int sol[N][N]);

int main(){
    int sol[N][N]; //mạng lưu các vị trí trên bàn cờ
        //khởi tạo giá trị mặc định cho mảng
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sol[i][j] = -1;
        }
    }
    //các cặp tọa độ mà quân mã có thể di chuyển từ vị trí hiện tại
    int xMove[] = {2, 1, -1, 2, -2, 1, -1, -2};
    int yMove[] = {1, -2, 2, -1, -1, 2, -2, 1};
    //giả sử quân mã bắt đầu từ ô đầu tiên tọa độ (0,0)
    sol[0][0] = 0;
    //tìm lời giải
    bool isSolved = solveKnightTour(0, 0, 1, sol, xMove, yMove);
    if(!isSolved){
        cout << "Khong tim duoc loi giai.\n";
    }else{
        showResult(sol);
    }
}

/**
 * Ph??ng th?c ki?m tra vi?c ??t quân mã ? v? trí x, y có th?a mãn hay không
 *
 * @param x   t?a ?? v? trí x t?i ?ó c?n ??t quân mã
 * @param y   t?a ?? v? trí y t?i ?ó c?n ??t quân mã
 * @param sol ma tr?n l?u k?t qu?
 * @return true n?u quân mã có th? ??t ???c t?i v? trí (x, y) trong ma tr?n sol
 */
bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N&& y >= 0 && y < N&& sol[x][y] == -1);
}

/**
 * Ph??ng th?c hi?n th? k?t qu?
 *
 * @param sol ma tr?n k?t qu?
 */
void showResult(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << sol[i][j];
        }
        cout << endl;
    }
}
