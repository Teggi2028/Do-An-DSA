#pragma once
#include "Check-Functions.hpp"

#include <bits/stdc++.h>

bool cmp_studentId(SinhVien a, SinhVien b){
    return a.getstudentId() < b.getstudentId();
}

bool cmp_firstName(SinhVien a, SinhVien b){
    return a.getfirstName() < b.getfirstName();
}

bool cmp_lastName(SinhVien a, SinhVien b){
    return a.getlastName() < b.getlastName();
}

bool cmp_className(SinhVien a, SinhVien b){
    return a.getclassName() < b.getclassName();
}

bool cmp_grade(SinhVien a, SinhVien b){
    return a.getgrade() < b.getgrade();
}

bool cmp_equal_studentId_array(SinhVien a, string x){
    return a.getstudentId() == x;
}
bool cmp_less_studentId_array(SinhVien a, string x){
    return a.getstudentId() < x;
}

bool cmp_equal_lastName_array(SinhVien a, string x){
    return a.getlastName() == x;
}
bool cmp_less_lastName_array(SinhVien a, string x){
    return a.getlastName() < x;
}

bool cmp_equal_firstName_array(SinhVien a, string x){
    return a.getfirstName() == x;
}
bool cmp_less_firstName_array(SinhVien a, string x){
    return a.getfirstName() < x;
}

bool cmp_equal_className_array(SinhVien a, string x){
    return a.getclassName() == x;
}
bool cmp_less_className_array(SinhVien a, string x){
    return a.getclassName() < x;
}

bool cmp_equal_grade_array(SinhVien a, double x){
    return a.getgrade() == x;
}
bool cmp_less_grade_array(SinhVien a, double x){
    return a.getgrade() < x;
}