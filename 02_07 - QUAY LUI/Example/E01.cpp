/*
 *Bài 1. Bài toán N quân hậu: cho bàn cờ kích thước NxN.
 *Hãy đặt N quân hậu vào bàn cờ sao cho
 *chúng không tấn công lẫn nhau.
 *In ra một lời giải bạn tìm được.
 */

/*
 * @author Branium Academy
 * @version 2021.10
 * @website https://braniumacademy.net/
 */
#include <iostream>
#include <iomanip>
using namespace std;
const int N = 8;

bool isSafe(int board[N][N], int row, int col);
bool solveNQueen(int board[N][N], int col);
void showResult(int sol[N][N]);

/*
 * Phương thức xử lý việc đặt hậu và tìm lời giải của bài toán
 *
 * @param board ma trận để lưu kết quả
 * @param col   cột đang xem xét đặt quân hậu
 * @return true nếu việc đặt hậu dẫn tới lời giải và false nếu ngược lại
 */
bool solveNQueen(int board[N][N], int col) {
    if (col >= N) {
        return true;
    }
    // kiểm tra cột hiện tại và đặt hậu vào đúng vị trí
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // 1 == hậu được đặt tại vị trí đó
            if (solveNQueen(board, col + 1)) {
                return true;
            }
            else {
                board[i][col] = 0;
            }
        }
    }
    return false;
}

/*
 * Phương thức kiểm tra xem liệu việc đặt hậu tại vị trí (row, col) trên bàn cờ có
 * ok hay không. Do các quân hậu được đặt từ trái sang tính theo cột và đặt ngẫu nhiên
 * tính theo hàng. Chỉ cần xét các cột < col vì chúng đã có quân hậu được đặt.
 *
 * @param board bàn cờ 8*8
 * @param row   chỉ số hàng đang xem xét việc đặt hậu
 * @param col   chỉ số cột đang xem xét việc đặt hậu
 * @return true nếu có thể đặt hậu và false nếu không thể đặt hậu
 */
bool isSafe(int board[N][N], int row, int col) {
    // kiểm tra hàng hiện thời xem ở phía bên trái đã có quân hậu nào chưa?
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    // kiểm tra đường chéo trên của ô hiện thời xem có quân hậu nào chưa
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // kiểm tra đường chéo dưới của ô hiện thời xem có quân hậu nào chưa
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

/*
 * Phương thức hiển thị kết quả ma trận biểu diễn các vị trí đặt hậu(1) trên bàn cờ
 *
 * @param sol ma trận kết quả
 */
void showResult(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << sol[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int board[N][N] = { 0 };
    bool result = solveNQueen(board, 0);
    if (result) {
        cout << "Mot trong cac loi giai la: \n";
        showResult(board);
    }
    else {
        cout << "Khong tim duoc loi giai.\n";
    }
    return 0;
}
