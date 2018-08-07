#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#define SIZE 5000000

#include "helper.h"
#include "serial.h"
#include "student.h"

using namespace std;
using namespace chrono;

int main()
{
    vector<int> x(SIZE);
    vector<int> y(SIZE);
    int a;

    initialize(y, x, a);

    vector<int> y_omp(y);
    vector<int> y_dyn(y);

    steady_clock::time_point begin_serial = steady_clock::now();
    saxpy_serial(y, x, a, SIZE);
    steady_clock::time_point end_serial = steady_clock::now();

    cout << "Serial elapsed time: "
         << duration_cast<microseconds>(end_serial - begin_serial).count()
         << "us" << endl;

    steady_clock::time_point begin_parallel_static = steady_clock::now();
    saxpy_parallel_static(y_omp, x, a, SIZE);
    steady_clock::time_point end_parallel_static = steady_clock::now();

    cout << "Parallel static elapsed time: "
         << duration_cast<microseconds>(end_parallel_static - begin_parallel_static).count()
         << "us" << endl;

    validate(y, y_omp, SIZE);

    steady_clock::time_point begin_parallel = steady_clock::now();
    saxpy_parallel_dynamic(y_dyn, x, a, SIZE);
    steady_clock::time_point end_parallel = steady_clock::now();

    cout << "Parallel dynamic elapsed time: "
         << duration_cast<microseconds>(end_parallel - begin_parallel).count()
         << "us" << endl;

    validate(y, y_dyn, SIZE);

    exit(EXIT_SUCCESS);
}
