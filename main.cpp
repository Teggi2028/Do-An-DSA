#include <bits/stdc++.h>
#include "Array.hpp"
#include "Single-Linked-List.hpp"

using namespace std;

vector<SinhVien> List; // array
sNode* sHead = NULL;

double min_grade_array = 100, max_grade_array = -1;
double min_grade_SLL = 100, max_grade_SLL = -1;
char delimiter = '|'; //Ky tu ngan cach cach thong tin trong file

int main(){
    int luachon;
    while(1){
        cout << "Chon 1. De tuong tac voi mang " << endl; 
        cout << "Chon 2. De tuong tac voi DSLK don " << endl; 
        cin >> luachon;

        if(luachon == 1){
            menu_array();
        } 
        else if(luachon == 2){
            menu_single_linked_list();
        }
        else {
            return 0;
        }
    }
}