#include <iostream>
#include"AK_Vector.h"
using namespace std;
int main()
{
    AK_Vector<int>rs0(-100);
    int arr[5] = { 1,5,6,10,8 };
    int arr2[5] = { 6,7,8,9,10 };
    AK_Vector<int>rs1(10);
    cout << "------------test for function size & capcity -------" << endl;
    cout << "size is: " << rs1.size() << endl;
    cout << "capcity is: " << rs1.capacity() << endl;
    AK_Vector<int>rs2(arr, 3);
    cout << "--------------test for deep coping -----------" << endl;
    AK_Vector<int>rs3(rs2);
    cout << endl;
    AK_Vector<int>rs4;
    cout << "--------------test for assignment operator ------" << endl;
    rs4 = rs2;
    AK_Vector<int>rs5;
    cout << "----------------test for move assignmrnt operator-----" << endl;
    rs5 = move(rs4);
    cout << rs5 << endl;
    //cout << rs4 << endl;
    cout << "--------------------tests for iterator operator + , ++ , * ---------" << endl;
    try {
        AK_Vector<int>rs00(arr, 5);
        auto it = rs00.begin();
        cout << it << endl;
        cout << rs00.operator*(it) << endl;
//        cout << rs00.operator++() << endl;
//        cout << rs00.operator+(2) << endl;
//        cout << rs00.operator+(6) << endl;
    }
    catch (...) {
        cout << "input out of range" << endl;
    }
    cout << "---------------test for begin & end functions---------------" << endl;
    cout << rs5.begin() << endl;
    cout << *(rs5.begin()) << endl;
    cout << rs5.end() << endl;
    cout << *(rs5.end()) << endl;
    try {
        cout << "------------------test for erase by one input && erase by 2 inputs " << endl;
        rs5.erase(rs5.begin());
        cout << rs5 << endl;
        auto it5 = rs5.end();
        it5++;
        rs5.erase(it5);
    }
    catch (...) {
        cout << "invalid argument this input is out of range " << endl;
    }
    AK_Vector<int>rs10(arr, 4);
    // 1 5 6 10
    try {
        rs10.erase(rs10.begin() + 1, rs10.end() - 1);
        cout << rs10 << endl;
        rs10.erase(rs10.begin() + 1, rs10.end() +1);
        cout << rs10 << endl;
    }
    catch (...) {
        cout << "invalid argument this input is out of range " << endl;
    }
    cout << "-------------test for insert ----------------------------" << endl;
    try {
        AK_Vector<int>rs11(arr, 4);
        auto iter = rs11.begin();
        iter++;
        rs11.insert(iter, 500);
        cout << rs11 << endl;
        AK_Vector<int>rs006(arr, 4);
        auto iter2 = rs006.end();
        iter2++;
        rs006.insert(iter2, 500);
        cout << rs006 << endl;
    }
    catch (...) {
        cout << "invalid argument the input is out of range" << endl;
    }
    cout << "--------------test for push back and pop back ---------" << endl;
    AK_Vector<int>rs13(arr, 3);
    rs13.push_back(20);
    cout<<"the size after push_back"<<rs13<<endl;
    cout << rs13 << endl;
    try {
        rs13.pop_back();
        cout << rs13 << endl;
        AK_Vector<int>rs003;
        rs003.pop_back();
    }
    catch (...) {
        cout << "vector is empty cannot do pop" << endl;
    }
    try {
        cout << "--------------test for [] operator  ---------" << endl;
        AK_Vector<int>rs002(arr, 4);
        cout << rs002[0] << endl;
        cout << rs002[5] << endl;
    }
    catch (...) {
        cout << "invalid argument the input is out of range " << endl;
    }
    cout << "------------test for resize------------------------" << endl;
    AK_Vector<int>rs14(10);
    cout << rs14.size() << endl;
    rs14.resize();
    cout << rs14 << endl;
    cout << rs14.size() << endl;
    //clear  , empty
    cout << "---------tests for clear & empty functions---------" << endl;
    AK_Vector<int>rs15(arr, 3);
    cout << rs15 << endl;
    cout << rs15.empty() << endl;
    rs15.clear();
    cout << rs15 << endl;
    cout << rs15.empty() << endl;
    cout << "---------tests for comparison operations functions---------" << endl;
    //comparision operation
    AK_Vector<int>rs16(arr, 3);
    AK_Vector<int>rs17(arr, 3);
    cout << rs16.operator==(rs17) << endl;
    rs17.pop_back();
    cout << rs16.operator==(rs17) << endl;
    AK_Vector<int>rs18(arr2, 3);
    cout << rs16.operator<(rs18) << endl;
    cout << rs18.operator<(rs16) << endl;
}