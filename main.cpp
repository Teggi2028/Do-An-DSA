#include <bits/stdc++.h>
#include "Array.hpp"

using namespace std;

vector<SinhVien> List;
double min_grade_array = 100, max_grade_array = -1;
char delimiter = '|'; //Ky tu ngan cach cach thong tin trong file

int main(){
    int luachon;
    while(1){
        cout << "Chon 1. De tuong tac voi mang " << endl; 
        cin >> luachon;

        if(luachon == 1){
            menu_array();
        } 
        else {
            return 0;
        }
    }
}