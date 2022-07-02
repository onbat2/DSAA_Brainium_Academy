#include <iostream>
using namespace std;
#define N 8

//hàm kiểm tra việc đặt hậu tại vị trí (x, y)
bool isSafe(int board[][N], int row, int col){
    //kiểm tra nếu bên trái có quân hậu chưa
    for(int i = 0; i < col; i++){
        if(board[row][i] == 1){
            return false;
        }
    }
    //kiểm tra nếu đường chéo trên có quân hậu chưa
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    //kiểm tra nếu đường chéo dưới có quân hậu chưa
    for(int i = row, j = col; i < N && j >= 0; i++, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    //ok
    return true;
}

bool solQueen(int board[][N], int col){
    if(col >= N){
        return true;
    }
    //xét từng cột trên bàn cờ, lần lượt theo thứ tự đặt hậu ở các hàng phù hợp
    for(int i = 0; i < N; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1; // đặt hậu ở vị trí (i, col)
            if(solQueen(board, col + 1)){ //đặt hậu ở cột tiếp theo dẫn tới 1 lời giải
                return true; //thông báo có lời giải
            }
            else{
                board[i][col] = 0; //quay lui
            }
        }
    }
    return false; //ko có lời giải
}

void showResult(int board[][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int board[N][N] = { 0 };
    bool result = solQueen(board, 0);
    if(result){
        cout << "Một trong các lời giải là: \n";
        showResult(board);
    }
    return 0;
}

