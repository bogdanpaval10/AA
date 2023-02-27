#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long modulo(long long base, long long exponent, long long mod);

int calculateJacobian(long long a, long long n);

bool solovayStrassen(long long p, int iterations);

void print_solovay(vector<int> v, string name);