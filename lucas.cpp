#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// functia genereaza factorii primi ai lui n
vector<int> primeFactors(int n)
{
	vector<int> factors;
	if (n % 2 == 0) // daca 2 este unul dintre factori
		factors.push_back(2);
	while (n % 2 == 0)
		n = n / 2;
	
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			factors.push_back(i);
		while (n % i == 0)
			n = n / i;
	}
	if (n > 2)
        factors.push_back(n);
    return factors;
}

// aceasta functie este un "power" modulo
int power(int n, int r, int q)
{
	int total = n;
	for (int i = 1; i < r; i++)
		total = (total * n) % q;
	return total;
}

int lucasTest(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
		
	//se genereaza factorii lui n - 1
	vector<int> factors = primeFactors(n - 1);

	// vector random pentru a se verifica unicitatea numerelor
	int random[n - 3];
	for (int i = 0; i < n - 2; i++)
		random[i] = i + 2;
	
	random_shuffle(random, random + n - 3);

	// se testeaza fiecare numar generat random mai sus cu testul Lucas
	for (int i = 0; i < n - 2; i++) {
		int a = random[i];
		if (power(a, n - 1, n) != 1)
			return 0;

		// se verifica daca fiecare factor prim al lui n - 1 satisface conditia
		bool flag = true;
		for (int k = 0; k < (int)factors.size(); k++) {
			// daca a^((n-1)/q) = 1
			if (power(a, (n - 1) / factors[k], n) == 1) {
				flag = false;
				break;
			}
		}
		// daca toate conditiile anterioare sunt satisfacute
		if (flag != 0)
			return 1;
	}
	return 0;
}

// afiseaza in fieserele de iesire valorile care sunt prime
void print_lucas(vector<int> v, string name)
{
    vector<int> rez_primes;
    ofstream fout;
    fout.open(name);
    for (int i = 0; i < (int)v.size(); i++)
        if(lucasTest(v[i]))
            rez_primes.push_back(v[i]);
    fout << rez_primes.size() << endl;
    for (int i = 0; i < (int)rez_primes.size(); i++)
        fout << rez_primes[i] << "\n";
    fout.close();
}
