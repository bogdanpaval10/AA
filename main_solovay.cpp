#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "solovay.h"

using namespace std;

// functia deschide un fisier cu numele dat ca parametru
vector<int> open_test(string name)
{
    vector<int> v;
    ifstream fin;
    int aux;
    fin.open(name);
    fin >> aux;
    while (fin >> aux)
        v.push_back(aux);
    fin.close();
    return v;
}

int main()
{
    vector<int> v = open_test("./test.in");

    auto before_solovay = std::chrono::high_resolution_clock::now();
    print_solovay(v, "./test.out");
    auto after_solovay = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::microseconds>
    (after_solovay - before_solovay);
    
    //cout << "   PASSED in " << time1.count() << " microsecunde" << endl;

    return 0;
}