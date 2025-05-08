#pragma once
#include "Check-Functions.hpp"
#include <bits/stdc++.h>

using namespace std;

string Nor_studentId(string studentId){
    string result = studentId;
    //viet hoa chu cai trong ma sinh vien 
    for(char &x : result){
        if(isalpha(x)) x = toupper(x);
    }
    return result;
}

//chuan hoa ho cua sinh vien
string Nor_lastName(string lastName){
    stringstream ss(lastName);
    string tmp = "", res = "";
    
    while(ss >> tmp){
        res += toupper(tmp[0]);
        for(int i = 1; i < tmp.size(); i++){
            res = res + (char)tolower(tmp[i]);
        }
        res += " ";
    }

    //Xoa khoang trang con thua o cuoi dong
    res.pop_back();

    return res;
}

string Nor_firstName(string firstName){
    string tmp = firstName;
    tmp[0] = toupper(tmp[0]);

    for(int i = 1; i < tmp.size(); i++){
        tmp[i] = tolower(tmp[i]);
    }

    return tmp;
}

string Nor_className(string className){
    string result = className;
    //viet hoa chu cai trong ma sinh vien 
    for(char &x : result){
        if(isalpha(x)) x = toupper(x);
    }
    return result;
}