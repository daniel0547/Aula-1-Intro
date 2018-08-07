#include<iostream>
#include<vector>

using namespace std;

void saxpy_parallel_static(vector<int> &y,
    vector<int> x,
    int a,
    size_t n)
{
    #pragma omp parallel for schedule(static, 1000)
    for (int i = 0; i < n; i++){
	y[i]+=a*x[i];
    }
}

void saxpy_parallel_dynamic(vector<int> &y,
    vector<int> x,
    int a,
    size_t n)
{
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < n; i++){
        y[i]+=a*x[i];
    }
}

