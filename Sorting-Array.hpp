#pragma once
#include "Array.hpp"
#include "Comparator-Functions.hpp"

#include <bits/stdc++.h>

extern vector<SinhVien> List;
extern void output_array_SinhVien(SinhVien x);
extern void output_array();
extern bool check_empty_array();

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
    while(1){
        cout << "===================================================" << endl;
    cout << "| Chon 1. Bubble sort theo ma sinh vien           |" << endl;
    cout << "| Chon 2. Bubble sort theo ten                    |" << endl;
    cout << "| Chon 3. Bubble sort theo diem                   |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1){
        if(!check_empty_array()){
            bubleSort_array_studentId();
        }
    } 
    else if(lc == 2){
        if(!check_empty_array()){
            bubbleSort_array_firstName();
        }
    } 
    else if(lc == 3){
        if(!check_empty_array()){
            bubbleSort_array_grade();
        }
    }
    else  if(lc == 0) return;
    else return;
    }
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

    cout << "Danh sach sinh vien sau khi sap xep tang dan bang insertionSort theo tieu chi MA SINH VIEN : " << endl;
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

    cout << "Danh sach sinh vien sau khi sap xep tang dan bang insertionSort theo tieu chi TEN SINH VIEN : " << endl;
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

    cout << "Danh sach sinh vien sau khi sap xep tang dan bang insertionSort theo tieu chi DIEM : " << endl;
    output_array();
     //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_insertionSort_array(){
   while(1){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Insertion sort theo ma sinh vien        |" << endl;
    cout << "| Chon 2. Insertion sort theo ten                 |" << endl;
    cout << "| Chon 3. Insertion sort theo diem                |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1){
        if(!check_empty_array()){
            insertionSort_array_studentId();
        }
    }
    else if(lc == 2){
        if(!check_empty_array()){
            insertionSort_array_firstName();
        }  
    } 
    else if(lc == 3){
        if(!check_empty_array()){
            insertionSort_array_grade();
        }    
    }
    else  if(lc == 0) return;
   }
}
//=========================SELECTION SORT=================================

void selectionSort_array_studentId(){
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
    while(1){
        cout << "===================================================" << endl;
    cout << "| Chon 1. Selection sort theo ma sinh vien        |" << endl;
    cout << "| Chon 2. Selection sort theo ten                 |" << endl;
    cout << "| Chon 3. Selection sort theo diem                |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1){
        if(!check_empty_array()){
            selectionSort_array_studentId();
        }
    } 
    else if(lc == 2){
        if(!check_empty_array()){
            selectionSort_array_firstName();
        }
    }
    else if(lc == 3){
        if(!check_empty_array()){
            selectionSort_array_grade();
        }
    } 
    else  if(lc == 0) return;
    }
}

//=============================MERGE SORT====================================

void merge_array(vector<SinhVien> &List, int left, int mid, int right,bool (*cmp)(SinhVien, SinhVien)){
    vector<SinhVien> x(List.begin() + left, List.begin() + mid + 1);
    vector<SinhVien> y(List.begin() + mid + 1, List.begin() + right + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()){
        if(cmp(x[i],y[j])){
            List[left] = x[i]; ++left; ++i;
        } else{
            List[left] = y[j]; ++left; ++j;
        }
    }

    while(i < x.size()){
        List[left] = x[i]; ++left; ++i;
    }
    while(j < y.size()){
        List[left] = y[j]; ++left; ++j;
    }
}

void mergeSort_array(vector<SinhVien> &List, int left, int right, bool (*cmp)(SinhVien, SinhVien)){
    if(left >= right) return;
    int mid = (left + right) / 2;
    mergeSort_array(List, left, mid, cmp);
    mergeSort_array(List, mid + 1, right, cmp);
    merge_array(List, left, mid, right, cmp);
}

void menu_mergeSort_array(){
    while(1){
        cout << "===================================================" << endl;
    cout << "| Chon 1. Merge sort theo ma sinh vien            |" << endl;
    cout << "| Chon 2. Merge sort theo ten                     |" << endl;
    cout << "| Chon 3. Merge sort theo diem                    |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1) {
        if(!check_empty_array()){
              //bat dau tinh thoi gian
        auto start = steady_clock::now();
        
        mergeSort_array(List,0 , List.size() - 1, cmp_studentId);
        
        cout << "Danh sach sinh vien sau khi sap xep tang dan bang mergerSort theo tieu chi MA SINH VIEN : " << endl;
        output_array();
         //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
        }
    }
    else if(lc == 2){
        if(!check_empty_array()){
            //bat dau tinh thoi gian
         auto start = steady_clock::now();

         mergeSort_array(List, 0, List.size() - 1, cmp_firstName);
        
         cout << "Danh sach sinh vien sau khi sap xep tang dan bang mergeSort theo tieu chi TEN SINH VIEN : " << endl;
        output_array();
         //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
        }
         
    } 
    else if(lc == 3){
        if(!check_empty_array()){
             //bat dau tinh thoi gian
         auto start = steady_clock::now();

         mergeSort_array(List, 0, List.size() - 1, cmp_grade);
 
         cout << "Danh sach sinh vien sau khi sap xep tang dan bang mergeSort theo tieu chi DIEM : " << endl;
         output_array();
          //ket thuc tinh thoi gian 
         auto end = steady_clock::now();
         duration<double, std::milli> elapsed1 = end - start;
         std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
        }
        
    }
    else  if(lc == 0) return;
    else return;
    }
}

//=============================QUICK SORT====================================

int partition_array(vector<SinhVien> &List, int left, int right, bool (*cmp) (SinhVien, SinhVien)){
    SinhVien pivot = List[right];
    int i = left - 1;
    for(int  j = left; j < right; j++){ //====================Note j = 1 --> left ==========================
        if(cmp(List[j], pivot)){
            ++i;
            swap(List[i], List[j]);
        }
    }
    //dua chot ve giua
    ++i;
    swap(List[i], List[right]);
    return i; // vi tri
}

void quickSort_array(vector<SinhVien> &List, int left, int right, bool (*cmp) (SinhVien, SinhVien)){
    if(left >= right) return;
    int p = partition_array(List, left, right, cmp);
    quickSort_array(List, left, p - 1, cmp);
    quickSort_array(List, p + 1, right, cmp);
}

void menu_quickSort_array(){
    while(1){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Quick sort theo ma sinh vien            |" << endl;
    cout << "| Chon 2. Quick sort theo ten                     |" << endl;
    cout << "| Chon 3. Quick sort theo diem                    |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1) {
        if(!check_empty_array()){
             //bat dau tinh thoi gian
        auto start = steady_clock::now();
        
        quickSort_array(List, 0, List.size() - 1, cmp_studentId);
        
        cout << "Danh sach sinh vien sau khi sap xep tang dan bang quickSort theo tieu chi MA SINH VIEN : " << endl;
        output_array();
         //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n"; 
        }
       
    }
    else if(lc == 2){
        if(!check_empty_array()){
             //bat dau tinh thoi gian
         auto start = steady_clock::now();

         quickSort_array(List, 0, List.size() - 1, cmp_firstName);
        
         cout << "Danh sach sinh vien sau khi sap xep tang dan bang quickSort theo tieu chi TEN SINH VIEN : " << endl;
        output_array();
         //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
        }
        
    } 
    else if(lc == 3){
        if(!check_empty_array()){
            //bat dau tinh thoi gian
         auto start = steady_clock::now();

         quickSort_array(List, 0, List.size() - 1, cmp_grade);

        cout << "Danh sach sinh vien sau khi sap xep tang dan bang quickSort theo tieu chi DIEM : " << endl;
        output_array();
         //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
        }
         
    }
    else  if(lc == 0) return;
    else return;
    }
}

//===============================HEAP SORT=====================================
// bool cmp_studentId_greater(SinhVien a, SinhVien b){
//     return a.getstudentId() > b.getstudentId();
// }

// bool cmp_firstName_greater(SinhVien a, SinhVien b){
//     return a.getfirstName() > b.getfirstName();
// }

// bool cmp_grade_greater(SinhVien a, SinhVien b){
//     return a.getgrade() > b.getgrade(   );
// }

void heapify_array(vector<SinhVien> &List, int n, int i, bool (*cmp) (SinhVien, SinhVien)){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if(left < n && cmp(List[left], List[largest])){ //==========NOTE=======
        largest = left;
    }
    if(right < n && cmp(List[right], List[largest])){ //=========NOTE=========
        largest = right;
    }

    if(largest != i){
        swap(List[i],List[largest]);
        heapify_array(List, n, largest, cmp);
    }
}

void heapSort_array(vector<SinhVien> &List, int n, bool (*cmp) (SinhVien, SinhVien)){
    // xay dung max heap
    for(int i = n / 2- 1; i >= 0; i--){
        heapify_array(List, n, i, cmp);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(List[i], List[0]);
        heapify_array(List, i, 0, cmp);
    }
}

void menu_heapSort_array(){
    while(1){
        cout << "===================================================" << endl;
        cout << "| Chon 1. Heap sort theo ma sinh vien             |" << endl;
        cout << "| Chon 2. Heap sort theo ten                      |" << endl;
        cout << "| Chon 3. Heap sort theo diem                     |" << endl;
        cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
        cout << "===================================================" << endl;
    
        int lc; cin >> lc;
        if(lc == 1) {
            if(!check_empty_array()){
                 //bat dau tinh thoi gian
            auto start = steady_clock::now();
            
            heapSort_array(List, List.size(), cmp_studentId_greater);
             
             cout << "Danh sach sinh vien sau khi sap xep tang dan bang heapSort theo tieu chi MA SINH VIEN : " << endl;
             output_array();
              //ket thuc tinh thoi gian 
             auto end = steady_clock::now();
             duration<double, std::milli> elapsed1 = end - start;
             std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
            }
            
        }
        else if(lc == 2){
            if(!check_empty_array()){
                //bat dau tinh thoi gian
             auto start = steady_clock::now();
    
             heapSort_array(List, List.size(), cmp_firstName_greater);
            
             cout << "Danh sach sinh vien sau khi sap xep tang dan bang heapSort theo tieu chi TEN SINH VIEN : " << endl;
            output_array();
             //ket thuc tinh thoi gian 
            auto end = steady_clock::now();
            duration<double, std::milli> elapsed1 = end - start;
            std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
            }
             
        } 
        else if(lc == 3){
            if(!check_empty_array()){
                //bat dau tinh thoi gian
             auto start = steady_clock::now();
    
             heapSort_array(List, List.size(), cmp_grade_greater);
    
            cout << "Danh sach sinh vien sau khi sap xep tang dan bang heapSort theo tieu chi DIEM : " << endl;
            output_array();
             //ket thuc tinh thoi gian 
            auto end = steady_clock::now();
            duration<double, std::milli> elapsed1 = end - start;
            std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
            }
             
        }
        else  if(lc == 0) return;
        else return;
        }
}
