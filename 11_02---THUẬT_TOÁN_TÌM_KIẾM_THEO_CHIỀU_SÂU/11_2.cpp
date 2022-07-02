#include<iostream>
#include<stack>
using namespace std;

class Vertex{
public:
    string label;
    bool visited;

    Vertex(string label = "", bool visited = false){
        this->label = label;
        this->visited = visited;
    }
};

void addVertex(Vertex* vertices, string lable, int index){
    Vertex v(lable);
    vertices[index] = v;

}

void addEdges(bool** adjMatrix, int start, int end){
    adjMatrix[start][end] = true;
    adjMatrix[end][start] = true;
}

void displayVertex(const Vertex& v){
    cout << v.label << ' ';
}

void dfsRecursion(Vertex* vertices, bool** adjMatrix, int size, int index){
    vertices[index].visited = true;
    displayVertex(vertices[index]);
    for(int i = 0; i < size; i++){
        if(adjMatrix[index][i] && !vertices[i].visited){
            dfsRecursion(vertices, adjMatrix, size, i);
        }
    }
}

void dfsIteration(Vertex* vertices, bool** adjMatrix, int size, int index){
    stack<int> stack;
    stack.push(index);
    while (!stack.empty()){
        index = stack.top();
        stack.pop();
        if(!vertices[index].visited){
            vertices[index].visited = true;
            displayVertex(vertices[index]);
            for(int i = 0; i < size; i++){
                if(adjMatrix[index][i]){
                    stack.push(i);
                }
            }
        }
    }
}

void reset(Vertex* vertices, int n){
    for(int i = 0; i < n; i++){
        vertices[i].visited = false;
    }
}

int main(){
    int n;
    cout << "Nhap so luong dinh: ";
    cin >> n;
    //cấp phát động mảng 1, 2 chiều
    Vertex* vertices = new Vertex[n];
    for(int i = 0; i < n; i++){
        cout << "Ten dinh: ";
        string label;
        cin >> label;
        addVertex(vertices, label, i);
    }
    //nhập cạnh
    bool** adjMatrix = new bool*[n];
    for(int i = 0; i < n; i++){
        adjMatrix[i] = new bool[n]();
    }

    int start; int end;
    while(true){
        cout << "Nhap dinh dau, cuoi. Nhap -1 de ket thuc: ";
        cin >> start;
        if(start < 0){
            break;
        }
        cin >> end;
        addEdges(adjMatrix, start - 1, end - 1);
    }
    cout << "===========================\n";
    dfsIteration(vertices, adjMatrix, n, 0);
    reset(vertices, n);
    cout << "\n===========================\n";
    dfsRecursion(vertices, adjMatrix, n, 0);
    cout << endl;

    //thu hồi bộ nhớ cấp phát động với keyword new
    for(int i = 0; i < n; i++){
        delete[] adjMatrix[i];
    }

    delete[] adjMatrix;
    delete[] vertices;
    return 0;
}
