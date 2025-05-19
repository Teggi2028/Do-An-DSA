#pragma once

#include "Check-Functions.hpp"
#include "Nomarlization-Functions.hpp"

extern char delimiter;
extern double min_grade_SLL, max_grade_SLL;

struct sNode{
    SinhVien data;
    sNode* next;
};

extern sNode* sHead;

//sNode = single (Linked list) node
//sHead = single (Linked list) node
// SLL = Single Linked List

//=============================Cac ham co ban cua danh sach lien ket don============================
sNode* makeNode_SLL(SinhVien x){
    sNode* newNode = new sNode();
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

void output_SinhVien_SLL(sNode* sHead){
    cout << sHead -> data.getstudentId() << " " << sHead -> data.getlastName() << " " << sHead -> data.getfirstName() << " " << sHead -> data.getclassName() << " " << sHead -> data.getgrade() << endl;
}

void output_SLL(sNode* sHead){
    if(sHead == NULL){
        cout << "Danh sach lien ket rong ! " << endl;
        return;
    }

    while(sHead != NULL){
        output_SinhVien_SLL(sHead);
        sHead = sHead -> next;
    }
}

void pushBack_SLL(sNode* &sHead, SinhVien x){
    sNode* tmp = sHead;
    sNode* newNode = makeNode_SLL(x);
    if(sHead == NULL){
        sHead = newNode;
        return;
    }
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}

bool check_studentId_Trung_Lap_SLL(sNode* sHead, string studentId){
    sNode* tmp = sHead;
    if(tmp == NULL) return false;

    while(tmp != NULL){
        if(tmp -> data.getstudentId() == studentId) return true;
        tmp = tmp -> next;
    }

    return false;
}

SinhVien search_studentId_SLL(sNode* sHead, string studentId){
    sNode* tmp = sHead;
    if(tmp == NULL) return SinhVien("", "", "", "", 0.0);

    while(tmp != NULL){
        if(tmp -> data.getstudentId() == studentId) return tmp -> data;
        tmp = tmp -> next;
    }

    return SinhVien("", "", "", "", 0.0);
}

void update_min_max_grade_SLL(sNode* sHead){
    min_grade_SLL = 10.0;
    max_grade_SLL = 0.0;
    if(sHead == NULL){
        min_grade_SLL = 0.0;
        max_grade_SLL = 0.0;
        return;
    }

    while(sHead != NULL){
        min_grade_SLL = min(min_grade_SLL, sHead -> data.getgrade());
        max_grade_SLL = max(max_grade_SLL, sHead -> data.getgrade());
        sHead = sHead -> next;
    }
}

void erase_SinhVien_SLL(sNode* &sHead, int k){
    sNode* tmp = sHead;
    if(sHead == NULL) return;

    if (k == 1) {
        sNode* tmp = sHead;
        sHead = sHead->next;
        delete tmp;
        return;
    }

    for(int i = 1; i <= k - 2; i++){
        tmp = tmp -> next;
    }
    sNode* pos = tmp -> next;
    tmp -> next = pos -> next;
    delete pos;

}

int size_SLL(sNode* sHead){
    int count = 0;
    while(sHead != 0){
        count++;
        sHead = sHead -> next;
    }

    return count;
}

void output_reverseName_SLL_Red_Bold(sNode* sHead){
    string fullName = sHead -> data.getlastName() + sHead -> data.getfirstName();
    string result = "";
    for(int i = fullName.size() - 1; i >= 0; i--){
        result += fullName[i];
    }

    cout << "\033[1;31m" 
    << sHead -> data.getstudentId() << " "  
    << result << " " 
    << sHead -> data.getclassName() << " " 
    << fixed << setprecision(2) << sHead -> data.getgrade() 
    << "\033[0m" << endl;
}

void output_SLL_Red_Bold(sNode* sHead){
    cout << "\033[1;31m" 
    << sHead -> data.getstudentId() << " "  
    << sHead -> data.getlastName() << " "
    << sHead -> data.getfirstName() << " " 
    << sHead -> data.getclassName() << " " 
    << fixed << setprecision(2) << sHead -> data.getgrade() 
    << "\033[0m" << endl;
}

//================================Import File csv===================================
void insertFile_SLL(sNode* &sHead){
    ifstream file;

    file.open("C:\\Users\\PHI LONG\\Downloads\\Do-An-DSA\\DSSV.txt");
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
        if(check_studentId_Trung_Lap_SLL(sHead, id)){
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
            pushBack_SLL(sHead, SinhVien(Nor_studentId(id), Nor_lastName(ho), Nor_firstName(ten), Nor_className(lop), diem));
            // update_min_max_grade_array();
        
    }
    update_min_max_grade_SLL(sHead);
    file.close();
}

//===============================Them moi sinh vien==================================
void insert_SLL(sNode*  &sHead){
    string id, ho, ten, lop;
    double diem;
    cout << "Nhap ma so sinh vien : "; getline(cin, id);
    if(!check_studentId(id)){
        cout << "Ma sinh vien khong hop le !" <<  endl;
        return;
    }
    if(check_studentId_Trung_Lap_SLL(sHead, id)){
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

    string tmp;
    cout << "Nhap diem cua sinh vien : "; getline(cin, tmp);
    for(char c : tmp){
        if(isalpha(c)){
             cout << "Diem nhap vao khong hop le ! " << endl;
            return;
        }
    }
    diem = stod(tmp);
    if(!check_grade(diem)){
        cout << "Diem nhap vao khong hop le ! " << endl;
        return;
    }

    pushBack_SLL(sHead, SinhVien(Nor_studentId(id), Nor_lastName(ho), Nor_firstName(ten), Nor_className(lop), diem));
    // update_min_max_grade_array();
    update_min_max_grade_SLL(sHead);
}

//=============================Cap nhat sinh vien theo ma sinh vien===================
void update_SLL(sNode* &sHead){
    cout << "Nhap vao ma sinh vien can thay doi thong tin : ";
    string studentID;  getline(cin, studentID);

    if(!check_studentId(studentID)){
        cout << "Ma sinh vien khong hop le" << endl;
        return;
    }

    studentID = Nor_studentId(studentID);

    if(!check_studentId_Trung_Lap_SLL(sHead, studentID)){
        cout << "Khong tim thay thong tin cua sinh vien " << studentID << endl;
        return;
    }

    SinhVien Sv = search_studentId_SLL(sHead, studentID);

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

        string tmp;
        cout << "Nhap diem sinh vien de cap nhat (hien tai : " << Sv.getgrade() << " )"; getline(cin, tmp);
        for(char c : tmp){
        if(isalpha(c)){
             cout << "Diem nhap vao khong hop le ! " << endl;
            return;
            }
        }
        diem = stod(tmp);
        if(!check_grade(diem)){
            cout << "Diem sinh vien khong hop le !" << endl;
            return;
        }
        // min_grade_array = min(min_grade_array, diem);
        // max_grade_array = max(max_grade_array, diem);
         
        sNode* temp = sHead;
        while(temp != NULL && temp -> data.getstudentId() != studentID){
            temp = temp -> next;
        }
        temp -> data = SinhVien(studentID, ho, ten, lop, diem);
        update_min_max_grade_SLL(sHead);
        cout << "Cap nhat thong tin sinh vien thanh cong !" << endl;
    }
    else{
        cout << "Sinh Vien khong ton tai hoac khong trung ma so ! " << endl;
    }
}

void erase_SLL(sNode* &sHead){
    cout << "Nhap ma sinh vien co du lieu can xoa : " << endl;
    string id; getline(cin, id);
    if(!check_studentId(id)){
        cout << "Ma sinh vien khong hop le !" << endl;
        return;
    }
    id = Nor_studentId(id);

    int position = -1;

    if(sHead == NULL){
        cout << "Danh sach rong !" << endl;
        return;
    }
    else{
        sNode* tmp = sHead;
        int count = 0;
        while(tmp != NULL){
            count++;
            if(tmp -> data.getstudentId() == id){
                position = count;
                break;
            }
            tmp = tmp -> next;
        }
    }
    
    // cout << position << " ";
    if(position != -1){
        cout << "Ban co chac chan muon xoa khong (Y/N) :" << endl;
        char conform; cin >> conform;
        cin.ignore();
        if(conform != 'Y' && conform != 'y'){
            cout << "Huy khong xoa nua !" << endl;
            return;
        }
        cout << "Xac nhan xoa thong tin cua sinh vien " << id << endl;
        erase_SinhVien_SLL(sHead, position);
        update_min_max_grade_SLL(sHead);
    }
    else{
        cout << "Khong tim thay thong tin cua sinh vien " << id << endl;

    }

}

//===========================In diem theo tieu chi====================================
void min_gradeSLL(sNode* sHead){
    if(sHead == NULL){
        cout << "Danh sach sinh vien rong !" << endl;
        return;
    }
    cout << "Danh sach sinh vien co diem thap nhat (" << fixed << setprecision(2) << min_grade_SLL << ") la : " << endl; 
    sNode* tmp = sHead;
    while(tmp != NULL){
        if(tmp -> data.getgrade() == min_grade_SLL) output_SinhVien_SLL(tmp);
        tmp = tmp -> next;
    }
}

void max_gradeSLL(sNode* sHead){
    if(sHead == NULL){
        cout << "Danh sach sinh vien rong !" << endl;
        return;
    }
    cout << "Danh sach sinh vien co diem thap nhat (" << fixed << setprecision(2) << max_grade_SLL << ") la : " << endl; 
    sNode* tmp = sHead;
    while(tmp != NULL){
        if(tmp -> data.getgrade() == max_grade_SLL) output_SinhVien_SLL(tmp);
        tmp = tmp -> next;
    }
}

void average_gradeSLL(sNode* sHead){
    if(sHead == NULL){
        cout << "Danh sach sinh vien rong !" << endl;
        return;
    }

    map<string, vector<SinhVien>> ClassList;
    sNode* tmp = sHead;

    while(tmp != NULL){
        ClassList[tmp -> data.getclassName()].push_back(tmp -> data);
        tmp = tmp -> next;
    }

    for(pair<string, vector<SinhVien>> x : ClassList){
        double av = 0.0;
        double Sv_count = x.second.size();
        for(SinhVien y : x.second){
            av += y.getgrade();
        }
        av = av / Sv_count;
        cout << "Diem trung binh cua lop " << x.first << " la " << fixed << setprecision(2) << av << endl;
    }
}

void menu_grade_SLL(sNode* sHead){
    while(1){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Sinh vien co diem thap nhat             |" << endl;
    cout << "| Chon 2. Sinh Vien co diem cao nhat              |" << endl;
    cout << "| Chon 3. Diem trung binh cua cac lop             |" << endl;
    cout << "| Chon 0. De tro lai menu DSLK don                |" << endl;
    cout << "===================================================" << endl;
    int tc; cin >> tc;
    
    if(tc == 1) min_gradeSLL(sHead);
    else if(tc == 2) max_gradeSLL(sHead);
    else if(tc == 3) average_gradeSLL(sHead);
    else if(tc == 0) return;
    else return;
    }
}

//===============================Sorting==================================

//===============================Bubble Sort===================================
void bubbleSort_SLL(sNode* &sHead, bool (*cmp) (SinhVien, SinhVien)){
    //bat dau tinh thoi gian
    auto start = steady_clock::now();

    if (sHead == NULL){
        cout << "Danh sach sinh vien rong !" << endl;
        return;
    }

    if(sHead -> next == NULL){
        cout << "Danh sach chi co 1 phan tu nen khong the sap xep !" << endl;
        return;
    }

    bool swapped;
    sNode* ptr1;
    sNode* lptr = NULL;
    do {
        swapped = false;
        ptr1 = sHead;

        while (ptr1->next != lptr) {
            if (cmp(ptr1->next->data, ptr1->data)) {
                //Thay doi data cua node
                SinhVien temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; 
    } while (swapped);

    sNode* tmp = sHead;
    output_SLL(tmp);
         //ket thuc tinh thoi gian 
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_bubbleSort_SLL(sNode* sHead){
    while(1){
        cout << "===================================================" << endl;
    cout << "| Chon 1. Bubble sort theo ma sinh vien           |" << endl;
    cout << "| Chon 2. Bubble sort theo ten                    |" << endl;
    cout << "| Chon 3. Bubble sort theo diem                   |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1){
        bubbleSort_SLL(sHead, cmp_studentId);
    } 
    else if(lc == 2){
        bubbleSort_SLL(sHead, cmp_firstName);
    } 
    else if(lc == 3){
        bubbleSort_SLL(sHead, cmp_grade);
    }
    else  if(lc == 0) return;
    else return;
    }
}

//==============================Insertion Sort=================================
void insertionSort_SLL(sNode* &sHead, bool (*cmp) (SinhVien a, SinhVien b)){
    // Bat dau tinh thoi gian
    auto start = steady_clock::now();

    if (sHead == NULL) {
        cout << "Danh sach sinh vien rong !" << endl;
        return;
    }

    if (sHead->next == NULL) {
        cout << "Danh sach chi co 1 phan tu nen khong the sap xep !" << endl;
        return;
    }

    // Danh sach lien ket moi de luu ket qua sau sap xep
    sNode* sorted = NULL;

    sNode* current = sHead;
    while (current != NULL) {
        sNode* next = current->next;

        if (sorted == NULL || cmp(current->data, sorted->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            sNode* temp = sorted;
            while (temp->next != NULL && !cmp(current->data, temp->next->data)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    sHead = sorted; // Cap nhat lai sHead

    sNode* tmp = sHead;
    output_SLL(tmp);

    // ket thuc chuong trinh
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_insertionSort_SLL(sNode* sHead){
   while(1){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Insertion sort theo ma sinh vien        |" << endl;
    cout << "| Chon 2. Insertion sort theo ten                 |" << endl;
    cout << "| Chon 3. Insertion sort theo diem                |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1){
        insertionSort_SLL(sHead, cmp_studentId);
    } 
    else if(lc == 2){
        insertionSort_SLL(sHead, cmp_firstName);
    } 
    else if(lc == 3){
        insertionSort_SLL(sHead, cmp_grade);
    }
    else  if(lc == 0) return;
    else return;
    } 
}

//=============================Selection Sort===================================
void selectionSort_SLL(sNode* &sHead, bool (*cmp) (SinhVien a, SinhVien b)){
    // Bat dau tinh thoi gian
    auto start = steady_clock::now();

    if (sHead == NULL) {
        cout << "Danh sach sinh vien rong !" << endl;
        return;
    }

    if (sHead->next == NULL) {
        cout << "Danh sach chi co 1 phan tu nen khong the sap xep !" << endl;
        return;
    }

    for (sNode* i = sHead; i != NULL; i = i->next) {
        sNode* minNode = i; //tim kiem node nho nhat de swap

        for (sNode* j = i->next; j != NULL; j = j->next) {
            if (cmp(j->data, minNode->data)) {
                minNode = j; 
            }
        }
        
        if (minNode != i) {
            SinhVien temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }

    sNode* tmp = sHead;
    output_SLL(tmp);

    // ket thuc chuong trinh
    auto end = steady_clock::now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_selectionSort_SLL(sNode* sHead){
   while(1){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Selection sort theo ma sinh vien        |" << endl;
    cout << "| Chon 2. Selection sort theo ten                 |" << endl;
    cout << "| Chon 3. Selection sort theo diem                |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1){
        selectionSort_SLL(sHead, cmp_studentId);
    } 
    else if(lc == 2){
        selectionSort_SLL(sHead, cmp_firstName);
    } 
    else if(lc == 3){
        selectionSort_SLL(sHead, cmp_grade);
    }
    else  if(lc == 0) return;
    else return;
    } 
}

//=============================Merge Sort=====================================
//Ham tach doi danh sach lien ket
sNode* split(sNode* &head) {
    sNode* slow = head;
    sNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    sNode* second = slow->next;
    slow->next = nullptr;
    return second;
}

// Tron 2 danh sach theo tieu chi cmp
sNode* merge_sorted(sNode* a, sNode* b, bool (*cmp)(SinhVien, SinhVien)) {
    if (!a) return b;
    if (!b) return a;

    if (cmp(a->data, b->data)) {
        a->next = merge_sorted(a->next, b, cmp);
        return a;
    } else {
        b->next = merge_sorted(a, b->next, cmp);
        return b;
    }
}

// Merge sort
sNode* merge_sort(sNode* &head, bool (*cmp)(SinhVien, SinhVien)) {
    if (!head || !head->next) return head;

    sNode* second = split(head);

    head = merge_sort(head, cmp);
    second = merge_sort(second, cmp);

    return merge_sorted(head, second, cmp);
}

// Goi ham merge Sort
void mergeSort_SLL(sNode* &sHead, bool (*cmp)(SinhVien, SinhVien)) {
    //bat dau tinh thoi gian
    auto start = steady_clock :: now();

    sHead = merge_sort(sHead, cmp);

    sNode* tmp = sHead;
    output_SLL(tmp);
    //ket thuc chuong trinh
    auto end = steady_clock :: now();
    duration<double, std::milli> elapsed1 = end - start;
    std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_mergeSort_SLL(sNode* sHead){
  while(1){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Merge sort theo ma sinh vien            |" << endl;
    cout << "| Chon 2. Merge sort theo ten                     |" << endl;
    cout << "| Chon 3. Merge sort theo diem                    |" << endl;
    cout << "| Chon 0. De tro lai menu sap xep                 |" << endl;
    cout << "===================================================" << endl;

    int lc; cin >> lc;
    if(lc == 1){
        mergeSort_SLL(sHead, cmp_studentId);
    } 
    else if(lc == 2){
        mergeSort_SLL(sHead, cmp_firstName);
    } 
    else if(lc == 3){
        mergeSort_SLL(sHead, cmp_grade);
    }
    else  if(lc == 0) return;
    else return;
    }      
}
//==============================Search=================================

void search_studentId_SLL(sNode* sHead){
    //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
    cout << "Nhap vao MA SINH VIEN :"; string studentId; cin >> studentId; //=============================
    if(!check_studentId(studentId)){ //======================================
        cout << "Ma sinh vien khong hop le !" << endl;//===============================
        return;
    }
    studentId = Nor_studentId(studentId); //======================================

    int check = menu_output_search();
    
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        sNode* tmp = sHead;

        while (tmp != nullptr) {
            if (tmp->data.getstudentId() == studentId) {
                if (check == 1) output_SLL_Red_Bold(tmp);
                else if (check == 2) output_reverseName_SLL_Red_Bold(tmp);
                ++count;
            }
            tmp = tmp->next;
        }

        if (count == 0) cout << "Khong tim thay thong tin can tim !" << endl;

        //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void search_lastName_SLL(sNode* sHead){
    //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
     cin.ignore();
    cout << "Nhap vao HO SINH VIEN :"; string lastName; getline(cin,lastName); //=============================
    if(!check_lastName(lastName)){ //======================================
        cout << "Ho sinh vien khong hop le !" << endl;//===============================
        return;
    }
    lastName = Nor_lastName(lastName); //======================================

    int check = menu_output_search();
    
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        sNode* tmp = sHead;

        while (tmp != nullptr) {
            if (tmp->data.getlastName() == lastName) {//========================
                if (check == 1) output_SLL_Red_Bold(tmp);
                else if (check == 2) output_reverseName_SLL_Red_Bold(tmp);
                ++count;
            }
            tmp = tmp->next;
        }

        if (count == 0) cout << "Khong tim thay thong tin can tim !" << endl;

        //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void search_firstName_SLL(sNode* sHead){
    //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
     cin.ignore();
    cout << "Nhap vao TEN SINH VIEN : "; string firstName; getline(cin,firstName); //=============================
    if(!check_firstName(firstName)){ //======================================
        cout << "Ten sinh vien khong hop le !" << endl;//===============================
        return;
    }
    firstName = Nor_firstName(firstName); //======================================

    int check = menu_output_search();
    
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        sNode* tmp = sHead;

        while (tmp != nullptr) {
            if (tmp->data.getfirstName() == firstName) {
                if (check == 1) output_SLL_Red_Bold(tmp);
                else if (check == 2) output_reverseName_SLL_Red_Bold(tmp);
                ++count;
            }
            tmp = tmp->next;
        }

        if (count == 0) cout << "Khong tim thay thong tin can tim !" << endl;

        //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void search_className_SLL(sNode* sHead){
    //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
     cin.ignore();
    cout << "Nhap vao LOP SINH VIEN : "; string className; getline(cin,className); //=============================
    if(!check_className(className)){ //======================================
        cout << "Lop sinh vien khong hop le !" << endl;//===============================
        return;
    }
    className = Nor_className(className); //======================================

    int check = menu_output_search();
    
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        sNode* tmp = sHead;

        while (tmp != nullptr) {
            if (tmp->data.getclassName() == className) {
                if (check == 1) output_SLL_Red_Bold(tmp);
                else if (check == 2) output_reverseName_SLL_Red_Bold(tmp);
                ++count;
            }
            tmp = tmp->next;
        }

        if (count == 0) cout << "Khong tim thay thong tin can tim !" << endl;

        //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void search_grade_SLL(sNode* sHead){
    //bat dau tinh thoi gian
     auto start = steady_clock::now();
    
     cin.ignore();
    cout << "Nhap vao DIEM SINH VIEN : "; string diem; getline(cin, diem); //=============================
    for(char c : diem){
        if(isalpha(c)){
             cout << "Diem sinh vien khong hop le !" << endl;//===============================
            return;
        }
    }
    
    double grade = stod(diem);
    if(!check_grade(grade)){ //======================================
        cout << "Diem sinh vien khong hop le !" << endl;//===============================
        return;
    }

    int check = menu_output_search();
    
        cout << "Ket qua tim kiem la : " << endl;
        int count = 0;
        sNode* tmp = sHead;

        while (tmp != nullptr) {
            if (tmp->data.getgrade() == grade) {
                if (check == 1) output_SLL_Red_Bold(tmp);
                else if (check == 2) output_reverseName_SLL_Red_Bold(tmp);
                ++count;
            }
            tmp = tmp->next;
        }

        if (count == 0) cout << "Khong tim thay thong tin can tim !" << endl;

        //ket thuc tinh thoi gian 
        auto end = steady_clock::now();
        duration<double, std::milli> elapsed1 = end - start;
        std::cout << "Thoi gian chuong trinh chay: " << elapsed1.count() << "ms\n";
}

void menu_search_SLL(sNode* sHead){
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
    
    if(tc == 1) search_studentId_SLL(sHead); 
    else if(tc == 2) search_lastName_SLL(sHead);
    else if(tc == 3) search_firstName_SLL(sHead);
    else if(tc == 4) search_className_SLL(sHead);
    else if(tc == 5) search_grade_SLL(sHead);
    else if(tc == 0) return;
    else return;
    }
}

//================================ Menu ============================
void menu_sorting_SLL(sNode* sHead){
    while(1){
    cout << "===================================================" << endl;
    cout << "| Chon 1. Bubble sort                             |" << endl;
    cout << "| Chon 2. Insertion sort                          |" << endl;
    cout << "| Chon 3. Selection sort                          |" << endl;
    cout << "| Chon 4. Merge sort                              |" << endl;
    cout << "| Chon 0. De tro lai menu mang                    |" << endl;
    cout << "===================================================" << endl;

    int tc; cin >> tc;
    cin.ignore(); 
    
    if(tc == 1) menu_bubbleSort_SLL(sHead);
    else if(tc == 2) menu_insertionSort_SLL(sHead);
    else if(tc == 3) menu_selectionSort_SLL(sHead);
    else if(tc == 4) menu_mergeSort_SLL(sHead);
    else if(tc == 0) return;
    else return;
    }
}

void menu_single_linked_list(){
    while(1){
        int testcase;
        cout << "============================================================" << endl;
        cout << "| Chon 1. De nhap them sinh vien tu trong file              |" << endl;
        cout << "| Chon 2. De them moi sinh vien vao trong DSLK don          |" << endl;
        cout << "| Chon 3. De in ra danh sach sinh vien cua DSLK Don         |" << endl;
        cout << "| Chon 4. De cap nhat thong tin theo ma sinh vien           |" << endl;
        cout << "| Chon 5. De xoa thong tin theo ma sinh vien                |" << endl;
        cout << "| Chon 6. De in thong tin theo tieu chi diem                |" << endl;
        cout << "| Chon 7. De sap xep tang dan                               |" << endl;
        cout << "| Chon 8. De tim kiem theo chi so                           |" << endl;
        cout << "| Chon 0. De lai menu tuong tac                             |" << endl;
        cout << "============================================================" << endl;
        cin >> testcase;
        cin.ignore();
        
        if( testcase == 1) insertFile_SLL(sHead);
        else if(testcase == 2) insert_SLL(sHead);
        else if(testcase == 3) output_SLL(sHead);
        else if(testcase == 4) update_SLL(sHead);
        else if(testcase == 5) erase_SLL(sHead); 
        else if(testcase == 6) menu_grade_SLL(sHead); 
        else if(testcase == 7) menu_sorting_SLL(sHead); 
        else if(testcase == 8) menu_search_SLL(sHead); 
        else if(testcase == 0) return;
        else return;

    }
}