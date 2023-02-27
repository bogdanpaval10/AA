#include <iostream>
#include <fstream>
#include <vector>
#define MAX_ITERATIONS 100

using namespace std;

// functia realizeaza exponentiere binara
long long modulo(long long base, long long exponent, long long mod)
{
	long long x = 1;
	long long y = base;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			x = (x * y) % mod;
		y = (y * y) % mod;
		exponent = exponent / 2;
	}
	return x % mod;
}

// calculeaza jacobianul unui numar dat
int calculateJacobian(long long a, long long n)
{
	if (a == 0) // este cazul de nedeterminare 0 / n
		return 0;
	int ans = 1;
	if (a < 0)
	{
		a = -a; // este cazul a / n = (-a / n) * (-1 / n)
		if (n % 4 == 3)
			ans = -ans; // este cazul (-1 / n) = -1 daca n = 3 % 4
	}
	if (a == 1)
		return ans; // este cazul 1 / n = 1
    
	while (a != 0)
	{
		if (a < 0)
		{
			a = -a; // este cazul a / n = (-a / n) * (-1 / n)
			if (n % 4 == 3)
				ans = -ans; // este cazul (-1 / n) = -1 daca n = 3 % 4
		}
		while (a % 2 == 0)
		{
			a = a / 2;
			if (n % 8 == 3 || n % 8 == 5)
				ans = -ans;

		}
		swap(a, n);
		if (a % 4 == 3 && n % 4 == 3)
			ans = -ans;
		a = a % n;
		if (a > n / 2)
			a = a - n;
	}
	if (n == 1)
		return ans;
	return 0;
}

// functia realizeaza testul de primaritate Solovay-Strassen
bool solovayStrassen(long long p, int iterations)
{
	if (p < 2)
		return false;
	if (p != 2 && p % 2 == 0)
		return false;
    long long a, jacobian, mod;
	for (int i = 0; i < iterations; i++)
	{
        a = rand() % (p - 1) + 1;// genereaza un numar aleatoriu a
		jacobian = (p + calculateJacobian(a, p)) % p;
		mod = modulo(a, (p - 1) / 2, p);
		if (jacobian == 0 || mod != jacobian)
			return false;
	}
	return true;
}

// afiseaza in fieserele de iesire valorile care sunt prime
void print_solovay(vector<int> v, string name)
{
    vector<int> rez_primes;
    ofstream fout;
    fout.open(name);
    for (int i = 0; i < (int)v.size(); i++)
        if(solovayStrassen(v[i], MAX_ITERATIONS) != false)
            rez_primes.push_back(v[i]);
    fout << rez_primes.size() << endl;
    for (int i = 0; i < (int)rez_primes.size(); i++)
        fout << rez_primes[i] << "\n";
    fout.close();
}