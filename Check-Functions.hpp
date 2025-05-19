#pragma once

#include <bits/stdc++.h>

using namespace std;

class SinhVien{
    private:
        string studentId, lastName, firstName, className;
        double grade;
    public:
    // Default constructor
    SinhVien() : studentId(""), lastName(""), firstName(""), className(""), grade(0.0) {};

     //Constructor
     SinhVien(string id, string ho, string ten, string lop, double diem){
        studentId = id;
        lastName = ho;
        firstName = ten;
        className = lop;
        grade = diem;
    }
    
        string getstudentId(){
            return studentId;
        }

        string getlastName(){
            return lastName;
        }

        string getfirstName(){
            return firstName;
        }

        string getclassName(){
            return className;
        }
        double getgrade(){
            return grade;
        }
};

string trim(const string& str) {
    int first = 0;
    while (first < str.size() && isspace(str[first])) {
        ++first;
    }

    int last = str.size();
    while (last > first && isspace(str[last - 1])) {
        --last;
    }

    return str.substr(first, last - first);
}

bool cmp_SinhVien(SinhVien a, SinhVien b){
    return a.getstudentId() == b.getstudentId()
        && a.getlastName() == b.getlastName()
        && a.getfirstName() == b.getfirstName()
        && a.getclassName() == b.getclassName()
        && a.getgrade() == b.getgrade();
}

//Ham check am so Sinh Vien
bool check_studentId(string studentId){
    studentId = trim(studentId);
    //so luong ky tu cua ma sinh vien
    int charCount = studentId.size();
    
    //Kiem tra neu MSV co dung 10 ky tu
    if(charCount != 10) return false;

    //Kiem tra khoang trang dau cuoi
    if(studentId.find(' ') != string::npos) return false;

    // 0123456789 
    // N23DCCN171
    //Kiem tra xem tai vi tri 0, 3, 4 ,5 6 co phai la ky tu hay khong
    int check_char[] = {0, 3, 4, 5, 6};
    //Kiem tra xem tai vi tri 1, 2 ,7, 8, 9 co phai la chu so hay khong
    int check_digit[] = {1, 2, 7, 8, 9};
    for(int i = 0; i < 5; i++){
        if(!isdigit(studentId[check_digit[i]])) return false;
        if(!isalpha(studentId[check_char[i]])) return false;
    }

    return true;
}

//ham check ho cua sinh Vien
bool check_lastName(string lastName){
    lastName = trim(lastName);
    stringstream ss(lastName);
    string tmp = "", checked_lastName = "";

    while(ss >> tmp){
        for(int i = 0; i < tmp.size(); i++){
            if(!isalpha(tmp[i])) return false;
        }
    }

    return true;
}   

bool check_firstName(string firstName){
    firstName = trim(firstName);
    for(char c : firstName){
        if(!isalpha(c)) return false;
    }
    return true;
}

bool check_className(string className){
    className = trim(className);
    //so luong ky tu cua ten lop
    int charCount = className.size();
    
    //Kiem tra khoang trang 
    if(className.find(' ') != string::npos) return false;

    //Kiem tra neu MSV co dung 10 ky tu
    if( charCount < 9 || charCount > 11) return false;
    
    // 012345678 
    //  D23CQCN03
    //Kiem tra xem tai vi tri 0, 3, 4 ,5 6 co phai la ky tu hay khong
    vector<int> check_char = {0, 3, 4, 5, 6};
    for (int i = charCount - 9; i > 0; i--)
    {
        check_char.push_back(charCount - i - 2);
    }
    //Kiem tra xem tai vi tri 1, 2 ,7, 8, 9 co phai la chu so hay khong
    int check_digit[] = {1, 2, charCount - 2, charCount - 1};
    for(int i = 0; i < 4; i++) if(!isdigit(className[check_digit[i]])) return false;
    for(int i = 0; i < check_char.size(); i++) if(!isalpha(className[check_char[i]])) return false; 

    return true;
}

bool check_grade(double grade){
   return grade >= 0.0 && grade <= 10.0;
}