#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

//khai báo nguyên mẫu hàm
void printSubset(int*, int);
void generateSubsets(int*, int, int);
void subsetSum(int*, int, int*, int, int, int, int);

//phương thức in tất cả tập con có tổng == target
void generateSubsets(int* weights, int n, int target){
    int total = 0;
    int* subsets = new int[n];
    for(int i = 0; i < n; i++){
        total += weights[i];
    }
    if(weights[0] <= target && total >= target){
        subsetSum(weights, n, subsets, 0, 0, 0, target);
    }
}

/**
  * Phương thức tìm tổng tập con và hiển thị nó ra màn hình
  * @param weights tập đầu vào
  * @param subsets tập kết quả
  * @param subsetSize kích thước của tập kết quả
  * @param sum tổng hiện thời
  * @param current giá trị chỉ số đang xét hiện thời
  * @param target tổng mục tiêu
  */

void subsetSum(int* weights, int weightSize, int* subsets,
    int subsetSize, int sum, int current, int target){
    if(target == sum){ // nếu tổng hiện tại bằng tổng mục tiêu
        printSubset(subsets, subsetSize); // hiển thị tập kết quả
        //nếu chỉ số phần tử kế tiếp còn trong biên mảng tập đầu vào
        //và tổng hiện thời trừ phần tử đang xét + tổng phần tử kế tiếp nhỏ hơn tổng mục tiêu
        if(current + 1 < weightSize && sum - weights[current + 1] <= target){
            //tiếp tục đệ quy để tìm tập kết quả tiếp theo, loại bỏ phần tử hiện tại
            subsetSum(weights, weightSize, subsets,
                subsetSize - 1, sum - weights[current], current + 1, target);
        }
    }
    else{
        //kiểm tra ràng buộc chỉ số phần tử
        if(current < weightSize && sum + weights[current] <= target){
            //sinh các node dọc theo chiều rộng của mảng đầu vào
            for(int i = current; i < weightSize; i++){
                subsets[subsetSize] = weights[i];
                if(sum + weights[i] <= target){ // nếu tổng hiện thời với phần tử đang xét nhỏ hơn hoặc bằng mục tiêu
                    // xem xét tìm tổng tập con của level tireeps theo
                    subsetSum(weights, weightSize, subsets, subsetSize + 1,
                        sum + weights[i], i + 1, target);
                }
            }
        }
    }
}

void printSubset(int* subsets, int subsetSize){
    for(int i = 0; i < subsetSize; i++){
        cout << subsets[i] << " ";
    }
    cout << endl;
}

int main(){
    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;
    sort(begin(weights), end(weights)); // sắp xếp tăng dần tập đầu vào
    generateSubsets(weights, 8, target); // tìm tất cả tâpj con có tổng bằng target
    return 0;
}
