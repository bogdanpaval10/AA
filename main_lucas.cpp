#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "lucas.h"

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

    auto before_lucas = std::chrono::high_resolution_clock::now();
    print_lucas(v, "./test.out");
    auto after_lucas = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::microseconds>
    (after_lucas - before_lucas);
    
    //cout << "   PASSED in " << time2.count() << " microsecunde" << endl;

    return 0;
}
