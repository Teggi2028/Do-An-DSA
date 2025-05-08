#pragma once
#include "Array.hpp"

#include <bits/stdc++.h>

extern vector<SinhVien> List;
extern void output_array_SinhVien(SinhVien x);
extern void output_array();


using namespace std;
using namespace std::chrono;
using namespace std::literals::chrono_literals;

//===========================BUBBLE SORT=====================================
void bubleSort_array_studentId(){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();

    int Sv_count = List.size();
    for(int i = 0; i < Sv_count; i++){
        for(int j = 0; j < Sv_count - i - 1; j++){
            if(List[j].getstudentId() > List[j + 1].getstudentId()){
                swap(List[j], List[j + 1]);
            }
        }
    }
    cout << "Danh sach sinh vien sau khi sap xep tang dan bang bubbleSort theo tieu chi MA SINH VIEN : " << endl;
    output_array();
    //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    // lấy quãng thời gian end - start, tự động ép kiểu nó về kiểu giá trị số thực double,
    //kiểu đơn vị mili giây (std::milli hoặc std::ratio<1, 1000>)
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void bubbleSort_array_firstName(){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();
    int Sv_count = List.size();
    for(int i = 0; i < Sv_count; i++){
        for(int j = 0; j < Sv_count - i - 1; j++){
            if(List[j].getfirstName() > List[j + 1].getfirstName()){
                swap(List[j], List[j + 1]);
            }
        }
    }
    cout << "Danh sach sinh vien sau khi sap xep tang dan bang bubbleSort theo tieu chi TEN SINH VIEN : " << endl;
    output_array();
     //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void bubbleSort_array_grade(){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();

    int Sv_count = List.size();
    for(int i = 0; i < Sv_count; i++){
        for(int j = 0; j < Sv_count - i - 1; j++){
            if(List[j].getgrade() > List[j + 1].getgrade()){
                swap(List[j], List[j + 1]);
            }
        }
    }
    cout << "Danh sach sinh vien sau khi sap xep tang dan bang bubbleSort theo tieu chi DIEM : " << endl;
    output_array();
     //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_bubbleSort_array(){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Bubble sort theo ma sinh vien           |" << endl;
    cout << "| Chon 2. Bubble sort theo ten                    |" << endl;
    cout << "| Chon 3. Bubble sort theo diem                   |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1) bubleSort_array_studentId();
    else if(lc == 2) bubbleSort_array_firstName();
    else if(lc == 3) bubbleSort_array_grade();
    else  if(lc == 0) return;
}
//============================INSERTION SORT==============================
void insertionSort_array_studentId(){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();

    int Sv_count = List.size();
    
    for(int i = 1; i < Sv_count; i++){
        SinhVien Sv = List[i]; 
        int position = i - 1;
        while(position >= 0 && Sv.getstudentId() < List[position].getstudentId()){
            List[position + 1] = List[position];
            --position;
        }
        List[position + 1] = Sv;
    }

    cout << "Danh sach sinh vien sau khi sap xep tang dan bang isertionSort theo tieu chi MA SINH VIEN : " << endl;
    output_array();
     //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void insertionSort_array_firstName(){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();

    int Sv_count = List.size();
    
    for(int i = 1; i < Sv_count; i++){
        SinhVien Sv = List[i]; 
        int position = i - 1;
        while(position >= 0 && Sv.getfirstName() < List[position].getfirstName()){
            List[position + 1] = List[position];
            --position;
        }
        List[position + 1] = Sv;
    }

    cout << "Danh sach sinh vien sau khi sap xep tang dan bang isertionSort theo tieu chi TEN SINH VIEN : " << endl;
    output_array();
     //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void insertionSort_array_grade(){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();

    int Sv_count = List.size();
    
    for(int i = 1; i < Sv_count; i++){
        SinhVien Sv = List[i]; 
        int position = i - 1;
        while(position >= 0 && Sv.getgrade() < List[position].getgrade()){
            List[position + 1] = List[position];
            --position;
        }
        List[position + 1] = Sv;
    }

    cout << "Danh sach sinh vien sau khi sap xep tang dan bang isertionSort theo tieu chi DIEM : " << endl;
    output_array();
     //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_insertionSort_array(){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Insertion sort theo ma sinh vien        |" << endl;
    cout << "| Chon 2. Insertion sort theo ten                 |" << endl;
    cout << "| Chon 3. Insertion sort theo diem                |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1) insertionSort_array_studentId();
    else if(lc == 2) insertionSort_array_firstName();
    else if(lc == 3) insertionSort_array_grade();
    else  if(lc == 0) return;
}
//=========================SELECTION SORT================================

void selectionSort_array_studenId(){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();

    int Sv_count = List.size();
    
    for(int i = 0; i < Sv_count - 1; i++){
        int min_pos = i;
        for(int j = i + 1; j < Sv_count; j++){
            if(List[j].getstudentId() < List[min_pos].getstudentId()) min_pos = j;
        }
        swap(List[i], List[min_pos]);
    }

    cout << "Danh sach sinh vien sau khi sap xep tang dan bang isertionSort theo tieu chi MA SINH VIEN : " << endl;
    output_array();
     //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void selectionSort_array_firstName(){
     //bat dau tinh thoi gian
     auto start = steady_clock::now();

     int Sv_count = List.size();
     
     for(int i = 0; i < Sv_count - 1; i++){
         int min_pos = i;
         for(int j = i + 1; j < Sv_count; j++){
             if(List[j].getfirstName() < List[min_pos].getfirstName()) min_pos = j;
         }
         swap(List[i], List[min_pos]);
     }
 
     cout << "Danh sach sinh vien sau khi sap xep tang dan bang isertionSort theo tieu chi TEN SINH VIEN : " << endl;
     output_array();
      //ket thuc tinh thoi gian 
     auto end = steady_clock::now();
     duration<double, std::milli> elapsed1 = end - start;
     std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void selectionSort_array_grade(){
     //bat dau tinh thoi gian
     auto start = steady_clock::now();

     int Sv_count = List.size();
     
     for(int i = 0; i < Sv_count - 1; i++){
         int min_pos = i;
         for(int j = i + 1; j < Sv_count; j++){
             if(List[j].getgrade() < List[min_pos].getgrade()) min_pos = j;
         }
         swap(List[i], List[min_pos]);
     }
 
     cout << "Danh sach sinh vien sau khi sap xep tang dan bang isertionSort theo tieu chi DIEM : " << endl;
     output_array();
      //ket thuc tinh thoi gian 
     auto end = steady_clock::now();
     duration<double, std::milli> elapsed1 = end - start;
     std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_selectionSort_array(){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Selection sort theo ma sinh vien        |" << endl;
    cout << "| Chon 2. Selection sort theo ten                 |" << endl;
    cout << "| Chon 3. Selection sort theo diem                |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1) selectionSort_array_studenId();
    else if(lc == 2) selectionSort_array_firstName();
    else if(lc == 3) selectionSort_array_grade();
    else  if(lc == 0) return;
}




