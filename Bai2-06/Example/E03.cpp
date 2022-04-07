/*
Bài 3. Bài toán cái túi: một tên trộm đột nhập vào một cửa hàng trang sức thấy n mặt hàng có
trọng lượng và giá tiền khác nhau. Nhưng không may tên này chỉ mang theo đúng một cái túi có
sức chứa trọng lượng tối đa là M kg. Bạn hãy giúp tên trộm tính xem nên bỏ những món nào vào
túi với số lượng bao nhiêu để hắn có thể thu về tối đa lợi nhuận trong khả năng mà hắn có thể
mang đi được trước khi bị tóm.
- Input: cho trên nhiều dòng.
o Dòng đầu là số bộ test 0 < t <= 100.
o Mỗi bộ test gồm 4 dòng.
▪ Dòng thứ nhất chứa số lượng trang sức.
▪ Dòng thứ hai chứa giá tiền tính theo $US.
▪ Dòng thứ ba chứa trọng lượng tương ứng.
▪ Dòng cuối chứa giá trị M.

- Output: kết quả mỗi bộ test ghi trên 1 dòng với định dạng Test i: giá trị tối đa.
Ví dụ:

INPUT
1
120 60 100
30 20 10
50

OUTPUT
Test 1: 220.

Giải thích: túi có trọng lượng tối đa M = 50. Nếu ta chọn món đồ đầu tiên và thứ 3 thì tổng trọng
lượng là 40(thỏa mãn < 50) và có giá trị sử dụng cao nhất = 220$. Nếu chọn 2 món hàng đầu tiên
thì chỉ được 180$ nhưng đã đạt giới hạn khối lượng tối đa 50.
*/

#include <iostream>
using namespace std;

// trả về giá trị lớn nhất có thể bỏ vào túi giới hạn khối lượng W
// chiến lược bottom-up
int knapSack(int W, int* weight, int* value, int n) {
    int** result = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        result[i] = new int[W + 1];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                result[i][j] = 0;
            }
            else if (weight[i - 1] <= j) {
                result[i][j] = max(value[i - 1] + result[i - 1][j - weight[i - 1]], result[i - 1][j]);
            }
            else {
                result[i][j] = result[i - 1][j];
            }
        }
    }
    return result[n][W]; // trả về kết quả
}

int main()
{
    int* val = new int[4] { 60, 100, 120, 200 };
    int* weight = new int[4] { 10, 20, 30, 20 };
    int W = 50;
    int n = 4;
    cout << "Gia tri toi uu: " << knapSack(W, weight, val, n) << endl;
}



