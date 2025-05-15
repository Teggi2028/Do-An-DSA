#pragma once
#include "Check-Functions.hpp"
#include "Nomarlization-Functions.hpp"
#include "Sorting-Array.hpp"
#include "Comparator-Functions.hpp"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

//Khoi tao mang
extern vector<SinhVien> List;
extern char delimiter;
extern double min_grade_array, max_grade_array;


//========================================================================
bool isSort(bool (*cmp) (SinhVien, SinhVien)){
    if(!check_empty_array()){
        for(int i = 1; i < List.size(); i++){
            if(cmp(List[i], List[i - 1])) return false;
        }
        return true;
    }
    return false;
}

bool check_empty_array(){
    if(List.empty()){
        cout << "Danh Sach Sinh Vien rong !" << endl;
        return true;;
    }
    return false;
}

bool check_studentId_Trung_Lap(string studentId){
    for(SinhVien x : List){
        if(studentId == x.getstudentId()) return true;
    }
    return false;
}

void update_min_max_grade_array(){
    min_grade_array = 10.0;
    max_grade_array = 0.0;
    for(SinhVien sv : List){
        min_grade_array = min(min_grade_array, sv.getgrade());
        max_grade_array = max(max_grade_array, sv.getgrade());
    }
}

SinhVien search_studentId(string studentId){
    for(SinhVien x : List){
        if(x.getstudentId() == studentId) return x;
    }
    return SinhVien("", "", "", "", 0.0);
}

void output_array_SinhVien(SinhVien x){
    cout << x.getstudentId() << " " << x.getlastName() << " " << x.getfirstName() << " " << x.getclassName() << " " << fixed << setprecision(2) << x.getgrade() << endl;
}

void insertFile_array(){
    ifstream file;
    file.open("C:\\Users\\PHI LONG\\Downloads\\Do-An-DSA\\DSSV.txt");
    // file.open("DSSV.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file DSSV.txt!" << endl;
        return;
    }

    string tmp;
    bool check = true; //kiem tra neu co sai sot thi ngat luon

    while(getline(file, tmp)){
        if(!check){
            cout << "Tam dung cap nhat do co noi dung khong hop le !" << endl;
            break;
        }

        cout << "Doc dong: " << tmp << endl;
        stringstream ss(tmp);
        string id, ho, ten, lop, diemstr;
        double diem;

        getline(ss, id, delimiter);
        if(!check_studentId(id)){
            cout << "Ma sinh vien khong hop le !" << endl;
            check = false;
            continue;
        }

        id = Nor_studentId(id);
        if(check_studentId_Trung_Lap(id)){
            cout << "Ma sinh vien bi trung !" << endl;
            check = false;
            continue;
        }

        getline(ss, ho, delimiter);
        if(!check_lastName(ho)){
            cout << "Ho cua sinh vien khong hop le !" << endl;
            check = false;
            continue;
        }

        getline(ss, ten, delimiter);
        if(!check_firstName(ten)){
            cout << "Ten cua sinh vien khong hop le !" << endl;
            check = false;
            continue;
        }

        getline(ss, lop, delimiter);
        if(!check_className(lop)){
            cout << "Ten lop khong hop le !" << endl;
            check = false;
            continue;
        }

        getline(ss, diemstr);
        diem = stod(diemstr);
        if(!check_grade(diem)){
            cout << "Diem khong hop le !" << endl;
            check = false;
            continue;
        }
            List.push_back(SinhVien(Nor_studentId(id), Nor_lastName(ho), Nor_firstName(ten), Nor_className(lop), diem));
            update_min_max_grade_array();
        
    }

    file.close();
}

void insert_array(){
    string id, ho, ten, lop;
    double diem;
    cout << "Nhap ma so sinh vien : "; getline(cin, id);
    if(!check_studentId(id)){
        cout << "Ma sinh vien khong hop le !" <<  endl;
        return;
    }
    if(check_studentId_Trung_Lap(id)){
        cout <<"Ma sinh vien bi trung lap !" << endl;
        return;
    }

    // cin.ignore();
    cout << "Nhap ho cua sinh vien : "; getline(cin, ho);
    if(!check_lastName(ho)){
        cout << "Ho cua sinh vien khong hop le !" << endl;
        return;
    }

    cout << "Nhap ten cua sinh vien : "; getline(cin, ten);
    if(!check_firstName(ten)){
        cout << "Ten cua sinh vien khong hop le ! " << endl;
        return;
    }

    cout << "Nhap lop cua sinh vien : "; getline(cin, lop);
    if(!check_className(lop)){
        cout << "Lop cua sinh vien nhap khong hop le ! " << endl;
        return;
    }

    cout << "Nhap diem cua sinh vien : "; cin >> diem;
    cin.ignore();
    if(!check_grade(diem)){
        cout << "Diem nhap vao khong hop le ! " << endl;
        return;
    }

    update_min_max_grade_array();
    List.push_back(SinhVien(Nor_studentId(id), Nor_lastName(ho), Nor_firstName(ten), Nor_className(lop), diem));
}

void output_array(){
    if(List.empty()){
        cout << "Danh sach rong !" << endl;
        return;
    }

    for(SinhVien x : List){
       output_array_SinhVien(x);
    }
}

void update_array(){
    cout << "Nhap vao ma sinh vien can thay doi thong tin : ";
    string studentID;  getline(cin, studentID);

    if(!check_studentId(studentID)){
        cout << "Ma sinh vien khong hop le" << endl;
        return;
    }

    studentID = Nor_studentId(studentID);

    if(!check_studentId_Trung_Lap(studentID)){
        cout << "Khong tim thay thong tin cua sinh vien " << studentID << endl;
        return;
    }

    SinhVien Sv = search_studentId(studentID);


    if(!cmp_SinhVien(Sv, SinhVien("", "", "", "", 0.0))){
        cout <<"CAP NHAT THONG TIN" << endl;
        string ho, ten, lop;
        double diem;

        cout << "Nhap ho sinh vien can cap nhat (hien tai : " << Sv.getlastName() << " )"; getline(cin, ho); 
        if(!check_lastName(ho)){
            cout << "Ho sinh vien khong hop le !" << endl;
            return;
        }
        ho = Nor_lastName(ho);

        cout << "Nhap ten sinh vien de cap nhat (hien tai : " << Sv.getfirstName() << " )"; getline(cin, ten);
        if(!check_firstName(ten)) {
            cout <<"Ten sinh vien khong hop le !" << endl;
            return;
        }
        ten = Nor_firstName(ten);

        cout << "Nhap lop sinh vien de cap nhat (hien tai : " << Sv.getclassName() << " )"; getline(cin, lop);
        if(!check_className(lop)){
            cout << "Lop sinh vien khong hop le !" << endl;
            return;
        }
        lop = Nor_className(lop);

        cout << "Nhap diem sinh vien de cap nhat (hien tai : " << Sv.getgrade() << " )"; cin >> diem;
        cin.ignore(); //======================================================================
        if(!check_grade(diem)){
            cout << "Diem sinh vien khong hop le !" << endl;
            return;
        }
        min_grade_array = min(min_grade_array, diem);
        max_grade_array = max(max_grade_array, diem);

        for(int i = 0; i < List.size(); i++){
            if(studentID == List[i].getstudentId()){
                List[i] = SinhVien(studentID,ho, ten, lop, diem);
                return;
            }
        }
    }
    else{
        cout << "Sinh Vien khong ton tai hoac khong trung ma so ! " << endl;
    }
    

}

void erase_array(){
    cout << "Nhap ma sinh vien co du lieu can xoa : " << endl;
    string id; getline(cin, id);
    if(!check_studentId(id)){
        cout << "Ma sinh vien khong hop le !" << endl;
        return;
    }
    id = Nor_studentId(id);

    int position = -1;
    for(int i = 0; i < List.size(); i++){
        if(List[i].getstudentId() == id){
            position = i;
            break;
        }
    }

    if(position != -1){
        cout << "Ban co chac chan muon xoa khong (Y/N) :" << endl;
        char conform; cin >> conform;
        if(conform != 'Y' && conform != 'y'){
            cout << "Huy khong xoa nua !" << endl;
            return;
        }
        cout << "Xac nhan xoa thong tin cua sinh vien " << id << endl;
        List.erase(List.begin() + position); 
        update_min_max_grade_array();
    } else{
        cout << "Khong tim thay thong tin cua sinh vien " << id << endl;
    }
}

void min_gradeArray(){
    cout << "Danh sach sinh vien co diem thap nhat (" << fixed << setprecision(2) << min_grade_array << ") la : " << endl; 
    for(SinhVien x : List){
        if(x.getgrade() == min_grade_array){
            output_array_SinhVien(x);
        }
    }
}

void max_gradeArray(){
    cout << "Danh sach sinh vien co diem cao nhat (" << fixed << setprecision(2) << max_grade_array << ") la : " << endl; 
    for(SinhVien x : List){
        if(x.getgrade() == max_grade_array){
            output_array_SinhVien(x);
        }
    }
}

void averge_gradeArray(){
    //Tao danh sach lop
    map<string, vector<SinhVien>> ClassList;
    for(SinhVien x : List){
        ClassList[x.getclassName()].push_back(x);
    }

    for(pair<string, vector<SinhVien>> x  : ClassList){
        string lop = x.first;
        vector<SinhVien> ClassMember = x.second;
        double av = 0.0;
        int Sv_count = ClassMember.size();

        for(SinhVien s : ClassMember){
            av += s.getgrade();
        }
        av = av / Sv_count;
        cout << "Diem trung binh cua lop " << lop << " la " << fixed << setprecision(2) << av << endl;
    }

}
//==================SEARCH===================

void output_reverseName_array_Red_Bold(SinhVien a){
    string fullName = a.getlastName() + a.getfirstName();
    string result = "";
    for(int i = fullName.size() - 1; i >= 0; i--){
        result += fullName[i];
    }

    cout << "\033[1;31m" 
    << a.getstudentId() << " "  
    << result << " " 
    << a.getclassName() << " " 
    << fixed << setprecision(2) << a.getgrade() 
    << "\033[0m" << endl;
}

void output_array_Red_Bold(SinhVien a){
    cout << "\033[1;31m" 
    << a.getstudentId() << " "  
    << a.getlastName() << " "
    << a.getfirstName() << " " 
    << a.getclassName() << " " 
    << fixed << setprecision(2) << a.getgrade() 
    << "\033[0m" << endl;
}

template <typename T>
int binary_search_array(vector<SinhVien>& List, int left, int right,T x, bool (*cmp_equal) (SinhVien, T), bool (*cmp_less) (SinhVien, T)){
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(cmp_equal(List[mid], x)){
        return mid;
    }
    else if(cmp_less(List[mid], x)){
        return binary_search_array(List, mid + 1, right, x, cmp_equal, cmp_less);
    }
    else return binary_search_array(List, left, mid - 1, x, cmp_equal, cmp_less);
}

int menu_output_search_array(){
    cout << "Chon 1. De in " << endl;
    cout << "Chon 2. De in nguoc" << endl;

    int tc; cin >> tc;
    if(tc == 1) return 1;
    else if(tc == 2) return 2;
    
    return 0;
}

//====================================================================================================

void search_studentId_array(){ //======================================
     //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
    cout << "Nhap vao MA SINH VIEN :"; string studentId; cin >> studentId; //=============================
    if(!check_studentId(studentId)){ //======================================
        cout << "Ma sinh vien khong hop le !" << endl;//===============================
        return;
    }
    studentId = Nor_studentId(studentId); //======================================

    int check = menu_output_search_array();

    if(isSort(cmp_studentId)){ //=================================
        int pos = binary_search_array(List, 0, List.size() - 1, studentId, cmp_equal_studentId_array, cmp_less_studentId_array); //=========================
        if(pos != -1){
            int left = pos;
            while(left - 1 >= 0 && List[left - 1].getstudentId() == studentId) --left;//===========================

            int right = pos;
            while(right + 1 < List.size() && List[right  + 1].getstudentId() == studentId) ++right;//=====================

            cout << "Ket qua tim kiem nhi phan la : " << endl;
            for(int i = left; i <= right; i++){
                if(check == 1) output_array_Red_Bold(List[i]);
                else if(check == 2) output_reverseName_array_Red_Bold(List[i]);
            }
        }
    } else{
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        if(check == 1){
            for(SinhVien x : List){
            if(x.getstudentId() == studentId){//============================
                output_array_Red_Bold(x);
                ++count;
            }
        }
    }
    else if(check == 2){
        for(SinhVien x : List){
            if(x.getstudentId() == studentId){//========================
                output_reverseName_array_Red_Bold(x);
                ++count;
            }
        }
    }

    if(count == 0) cout << "Khong tim thay thong tin can tim !" << endl;

      //ket thuc tinh thoi gian 
     auto end = steady_clock::now();
     duration<double, std::milli> elapsed1 = end - start;
     std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}
}

void search_firstName_array(){ //======================================
     //bat dau tinh thoi gian
     auto start = steady_clock::now();

    cout << "Nhap vao TEN SINH VIEN :"; string firstName; cin >> firstName; //=============================
    if(!check_firstName(firstName)){ //======================================
        cout << "Ten sinh vien khong hop le !" << endl;//===============================
        return;
    }
    firstName = Nor_firstName(firstName); //======================================

    int check = menu_output_search_array();

    if(isSort(cmp_firstName)){ //=================================
        int pos = binary_search_array(List, 0, List.size() - 1, firstName, cmp_equal_firstName_array, cmp_less_firstName_array); //=========================
        if(pos != -1){
            int left = pos;
            while(left - 1 >= 0 && List[left - 1].getfirstName() == firstName) --left;//===========================

            int right = pos;
            while(right + 1 < List.size() && List[right  + 1].getfirstName() == firstName) ++right;//=====================

            cout << "Ket qua tim kiem nhi phan la : " << endl;
            for(int i = left; i <= right; i++){
                if(check == 1) output_array_Red_Bold(List[i]);
                else if(check == 2) output_reverseName_array_Red_Bold(List[i]);
            }
        }
    } else{
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        if(check == 1){
            for(SinhVien x : List){
            if(x.getfirstName() == firstName){//============================
                output_array_Red_Bold(x);
                ++count;
            }
        }
    }
    else if(check == 2){
        for(SinhVien x : List){
            if(x.getfirstName() == firstName){//========================
                output_reverseName_array_Red_Bold(x);
                ++count;
            }
        }
    }

    if(count == 0) cout << "Khong tim thay thong tin can tim !" << endl;
}

  //ket thuc tinh thoi gian 
     auto end = steady_clock::now();
     duration<double, std::milli> elapsed1 = end - start;
     std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void search_lastName_array(){ //======================================
     //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
    cout << "Nhap vao HO SINH VIEN :"; string lastName; cin.ignore(); getline(cin,lastName); //=============================
    if(!check_lastName(lastName)){ //======================================
        cout << "Ho sinh vien khong hop le !" << endl;//===============================
        return;
    }
    lastName = Nor_lastName(lastName); //======================================

    int check = menu_output_search_array();

    if(isSort(cmp_lastName)){ //=================================
        int pos = binary_search_array(List, 0, List.size() - 1, lastName, cmp_equal_lastName_array, cmp_less_lastName_array); //=========================
        if(pos != -1){
            int left = pos;
            while(left - 1 >= 0 && List[left - 1].getlastName() == lastName) --left;//===========================

            int right = pos;
            while(right + 1 < List.size() && List[right  + 1].getlastName() == lastName) ++right;//=====================

            cout << "Ket qua tim kiem nhi phan la : " << endl;
            for(int i = left; i <= right; i++){
                if(check == 1) output_array_Red_Bold(List[i]);
                else if(check == 2) output_reverseName_array_Red_Bold(List[i]);
            }
        }
    } else{
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        if(check == 1){
            for(SinhVien x : List){
            if(x.getlastName() == lastName){//============================
                output_array_Red_Bold(x);
                ++count;
            }
        }
    }
    else if(check == 2){
        for(SinhVien x : List){
            if(x.getlastName() == lastName){//========================
                output_reverseName_array_Red_Bold(x);
                ++count;
            }
        }
    }

    if(count == 0) cout << "Khong tim thay thong tin can tim !" << endl;
}

  //ket thuc tinh thoi gian 
     auto end = steady_clock::now();
     duration<double, std::milli> elapsed1 = end - start;
     std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void search_className_array(){ //======================================
     //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
    cout << "Nhap vao TEN LOP CUA SINH VIEN :"; string className; cin >> className; //=============================
    if(!check_className(className)){ //======================================
        cout << "Ten lop cua sinh vien khong hop le !" << endl;//===============================
        return;
    }
    className = Nor_className(className); //======================================

    int check = menu_output_search_array();

    if(isSort(cmp_className)){ //=================================
        int pos = binary_search_array(List, 0, List.size() - 1, className, cmp_equal_className_array, cmp_less_className_array); //=========================
        if(pos != -1){
            int left = pos;
            while(left - 1 >= 0 && List[left - 1].getclassName() == className) --left;//===========================

            int right = pos;
            while(right + 1 < List.size() && List[right  + 1].getclassName() == className) ++right;//=====================

            cout << "Ket qua tim kiem nhi phan la : " << endl;
            for(int i = left; i <= right; i++){
                if(check == 1) output_array_Red_Bold(List[i]);
                else if(check == 2) output_reverseName_array_Red_Bold(List[i]);
            }
        }
    } else{
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        if(check == 1){
            for(SinhVien x : List){
            if(x.getclassName() == className){//============================
                output_array_Red_Bold(x);
                ++count;
            }
        }
    }
    else if(check == 2){
        for(SinhVien x : List){
            if(x.getclassName() == className){//========================
                output_reverseName_array_Red_Bold(x);
                ++count;
            }
        }
    }

    if(count == 0) cout << "Khong tim thay thong tin can tim !" << endl;
}

  //ket thuc tinh thoi gian 
     auto end = steady_clock::now();
     duration<double, std::milli> elapsed1 = end - start;
     std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void search_grade_array(){ //======================================
     //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
    cout << "Nhap vao DIEM CUA SINH VIEN :"; double grade; cin >> grade; //=============================
    if(!check_grade(grade)){ //======================================
        cout << "Diem cua sinh vien khong hop le !" << endl;//===============================
        return;
    }
    
    int check = menu_output_search_array();

    if(isSort(cmp_grade)){ //=================================
        int pos = binary_search_array(List, 0, List.size() - 1, grade, cmp_equal_grade_array, cmp_less_grade_array); //=========================
        if(pos != -1){
            int left = pos;
            while(left - 1 >= 0 && List[left - 1].getgrade() == grade) --left;//===========================

            int right = pos;
            while(right + 1 < List.size() && List[right  + 1].getgrade() == grade) ++right;//=====================

            cout << "Ket qua tim kiem nhi phan la : " << endl;
            for(int i = left; i <= right; i++){
                if(check == 1) output_array_Red_Bold(List[i]);
                else if(check == 2) output_reverseName_array_Red_Bold(List[i]);
            }
        }
    } else{
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        if(check == 1){
            for(SinhVien x : List){
            if(x.getgrade() == grade){//============================
                output_array_Red_Bold(x);
                ++count;
            }
        }
    }
    else if(check == 2){
        for(SinhVien x : List){
            if(x.getgrade() == grade){//========================
                output_reverseName_array_Red_Bold(x);
                ++count;
            }
        }
    }

    if(count == 0) cout << "Khong tim thay thong tin can tim !" << endl;

      //ket thuc tinh thoi gian 
     auto end = steady_clock::now();
     duration<double, std::milli> elapsed1 = end - start;
     std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}
}


//================================MENU=================================
void menu_search_array(){
    while(1){
        cout << "===================================================" << endl;
    cout << "| Chon 1. Tim kiem theo MA SINH VIEN              |" << endl;
    cout << "| Chon 2. Tim kiem theo HO SINH VIEN              |" << endl;
    cout << "| Chon 3. Tim kiem theo TEN SINH VIEN             |" << endl;
    cout << "| Chon 4. Tim kiem theo LOP                       |" << endl;
    cout << "| Chon 5. Tim kiem theo DIEM                      |" << endl;
    cout << "| Chon 0. De tro lai menu mang                    |" << endl;
    cout << "===================================================" << endl;
    int tc; cin >> tc;
    
    if(tc == 1) search_studentId_array(); 
    else if(tc == 2) search_lastName_array();
    else if(tc == 3) search_firstName_array();
    else if(tc == 4) search_className_array();
    else if(tc == 5) search_grade_array();
    else if(tc == 0) return;
    else return;
    }
}
//Cau e
void menu_grade_array(){
    while(1){
        cout << "===================================================" << endl;
    cout << "| Chon 1. Sinh vien co diem thap nhat             |" << endl;
    cout << "| Chon 2. Sinh Vien co diem cao nhat              |" << endl;
    cout << "| Chon 3. Diem trung binh cua cac lop             |" << endl;
    cout << "| Chon 0. De tro lai menu mang                    |" << endl;
    cout << "===================================================" << endl;
    int tc; cin >> tc;
    
    if(tc == 1) min_gradeArray();
    else if(tc == 2) max_gradeArray();
    else if(tc == 3) averge_gradeArray();
    else if(tc == 0) return;
    else return;
    }
}

void menu_sorting_array(){
    while(1){
        cout << "===================================================" << endl;
    cout << "| Chon 1. Bubble sort                             |" << endl;
    cout << "| Chon 2. Insertion sort                          |" << endl;
    cout << "| Chon 3. Quick sort                              |" << endl;
    cout << "| Chon 4. Selection sort                          |" << endl;
    cout << "| Chon 5. Heap  sort                              |" << endl;
    cout << "| Chon 6. Merge sort                              |" << endl;
    cout << "| Chon 0. De tro lai menu mang                    |" << endl;
    cout << "===================================================" << endl;

    int tc; cin >> tc;

    if(tc == 1) menu_bubbleSort_array();
    else if(tc == 2) menu_insertionSort_array();
    else if(tc == 3) menu_quickSort_array();
    else if(tc == 4) menu_selectionSort_array();
    else if(tc == 5) menu_heapSort_array();
    else if(tc == 6) menu_mergeSort_array();
    else if(tc == 0) return;
    else return;
    }
}

void menu_array(){
    while(1){
        int testcase;
        cout << "===================================================" << endl;
        cout << "| Chon 1. De nhap them sinh vien tu trong file    |" << endl;
        cout << "| Chon 2. De them moi sinh vien vao trong mang    |" << endl;
        cout << "| Chon 3. De in ra danh sach sinh vien cua mang   |" << endl;
        cout << "| Chon 4. De cap nhat thong tin theo ma sinh vien |" << endl;
        cout << "| Chon 5. De xoa thong tin theo ma sinh vien      |" << endl;
        cout << "| Chon 6. De in thong tin theo tieu chi diem      |" << endl;
        cout << "| Chon 7. De sap xep tang dan                     |" << endl;
        cout << "| Chon 8. De tim kiem theo chi so                 |" << endl;
        cout << "| Chon 0. De lai menu tuong tac                   |" << endl;
        cout << "===================================================" << endl;
        cin >> testcase;
        cin.ignore();
        
        if( testcase == 1) insertFile_array();
        else if(testcase == 2) insert_array();
        else if(testcase == 3) output_array();
        else if(testcase == 4) update_array();
        else if(testcase == 5) erase_array();
        else if(testcase == 6) menu_grade_array();
        else if(testcase == 7) menu_sorting_array();
        else if(testcase == 8) menu_search_array();
        else if(testcase == 0) return;
        else return;

    }    
}



