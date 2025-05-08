#pragma once
#include "Check-Functions.hpp"
#include "Nomarlization-Functions.hpp"
#include "Sorting-Array.hpp"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

//Khoi tao mang
extern vector<SinhVien> List;
extern char delimiter;
extern double min_grade_array, max_grade_array;

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

    while(getline(file, tmp)){
        cout << "Doc dong: " << tmp << endl;
        stringstream ss(tmp);
        string id, ho, ten, lop, diemstr;
        double diem;

        getline(ss, id, delimiter);
        if(!check_studentId(id)){
            cout << "Ma sinh vien khong hop le !" << endl;
            continue;;
        }

        if(check_studentId_Trung_Lap(id)){
            cout << "Ma sinh vien bi trung !" << endl;
            continue;;
        }

        getline(ss, ho, delimiter);
        if(!check_lastName(ho)){
            cout << "Ho cua sinh vien khong hop le !" << endl;
            continue;;
        }

        getline(ss, ten, delimiter);
        if(!check_firstName(ten)){
            cout << "Ten cua sinh vien khong hop le !" << endl;
            continue;
        }

        getline(ss, lop, delimiter);
        if(!check_className(lop)){
            cout << "Ten lop khong hop le !" << endl;
            continue;
        }

        getline(ss, diemstr);
        diem = stod(diemstr);
        if(!check_grade(diem)){
            cout << "Diem khong hop le !" << endl;
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
    double av = 0.0;
    int Sv_count = List.size();

    for(SinhVien x : List){
        av += x.getgrade();
    }
    av = av / Sv_count;

    cout << "Diem trung binh cua danh sach sinh vien la " << fixed << setprecision(2) << av << endl;
}
//Cau e
void menu_grade_array(){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Sinh vien co diem thap nhat             |" << endl;
    cout << "| Chon 2. Sinh Vien co diem cao nhat              |" << endl;
    cout << "| Chon 3. Diem trung binh cua danh sach sinh vien |" << endl;
    cout << "| Chon 0. De tro lai menu mang                    |" << endl;
    cout << "===================================================" << endl;
    int tc; cin >> tc;
    
    if(tc == 1) min_gradeArray();
    else if(tc == 2) max_gradeArray();
    else if(tc == 3) averge_gradeArray();
    else if(tc == 0) return;
    
}

void menu_sorting_array(){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Bubble sort                             |" << endl;
    cout << "| Chon 2. Insertion sort                          |" << endl;
    cout << "| Chon 3. Quick sort (Lock)                       |" << endl;
    cout << "| Chon 4. Selection sort                          |" << endl;
    cout << "| Chon 5. Heap  sort (Lock)                       |" << endl;
    cout << "| Chon 6. Merge sort  (Lock)                      |" << endl;
    cout << "| Chon 0. De tro lai menu mang (Lock)             |" << endl;
    cout << "===================================================" << endl;

    int tc; cin >> tc;

    if(tc == 1) menu_bubbleSort_array();
    else if(tc == 2) menu_insertionSort_array();
    else if(tc == 4) menu_selectionSort_array();
    else if(tc == 0) return;
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
        else if(testcase == 0) return;
        else return;

    }
    
}

