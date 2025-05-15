#include <bits/stdc++.h>


using namespace std;

int a[205][205];
int dx[8] ={-2, -2, -1, -1, 1, 1,2 ,2};
int dy[8] ={-1, 1, -2, 2,-2, 2, -1, 1};
int k = 0, n; // k để đếm sô nước đi của con mã

//kiem tra xem con mã có đi hết bàn cờ hay không
bool check = false;

void loang(int u, int v){
    if(k == n*n) {
        check = true;
        return;
    }

    a[u][v] = 1; //Đánh dấu là đã thăm
    cout << "Con mã nước đi thứ " << ++k << " ở ô " << "(" << u << "," << v << ")." << endl;

    for(int z = 0; z < 8; z++){
        int u1 = u + dx[z];
        int v1 = v + dy[z];
        if(u1 >= 0 && u1 < n && v1 >= 0 && v1 < n && a[u1][v1] == 0){
            loang(u1, v1);
        }
    }
}

int main(){
    memset(a, 0, sizeof(a));
    cout << "Nhập vào kích thước của bàn cờ : " << endl;
    cin >> n;
    // Cho bàn cờ có kích thước n x n ô,  2 <=  n <= 200
    if(n < 2 || n > 200){
        cout << "Kích thước của bàn cờ phải nằm trong khoảng [2,200] !" << endl;
        return 0;
    }

    cout << "Nhập vào vị trí xuất phát của con mã : " << endl;
    int u, v; 
    // - vị trí xuất phát của con mã là ô (u,v) với u, v <= n-1
    cout << "Nhập vào vị trí hàng của con mã : " << endl; cin >> u;
    if(u < 0 || u >= n){
        cout << "Vị trí hàng của con mã phải nằm trong khoảng [0, " << n - 1 << "]";
        return 0;
    }
    cout << "Nhập vào vị trí cột của con mã : " << endl; cin >> v;
    if(v < 0 || v >= n){
        cout << "Vị trí cột của con mã phải nằm trong khoảng [0, " << n - 1 << "]";
        return 0;
    }

    //hàm loang chạy đến tất cả các ô mà con mã có thể đi tới được
    loang(u, v);    
    if(!check){
        cout << "Con mã không đi hết được bàn cờ " << n << "*" << n <<" từ vị trí" << "(" << u << "," << v << ")" << endl;
    }
}