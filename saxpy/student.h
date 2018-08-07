#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<vector>

using namespace std;

void saxpy_parallel_static(vector<int> &y,
    vector<int> x,
    int a,
    size_t n);

void saxpy_parallel_dynamic(vector<int> &y,
    vector<int> x,
    int a,
    size_t n);

#endif
