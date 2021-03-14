#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
	ZZ p, q;
	do
	{
		RandomPrime(p, 512, 10);
		while (p % 4 != 3) RandomPrime(p, 512, 10);
		RandomPrime(q, 512, 10);
		while (q % 4 != 3) RandomPrime(q, 512, 10);

	}while (GCD((p - 3) / 2, (q - 3) / 2) > 2);

	cout << "p= " << p << endl;
	cout << "q= " << q << endl;
	cout << "The gcd is " << GCD((p - 3) / 2, (q - 3) / 2) << endl;;
	ZZ s(4),M, current(s),previous;
	int numberOfBits,count0=0,count1=0;
	cout << "Select the number of random bits to be generated: "; cin >> numberOfBits;

	for (int i = 0; i < numberOfBits; i++)
		cout << 1 << ' ';
	cout << endl;

	M = p * q;
	while (numberOfBits>0)
	{
		previous = current;
		current = power(previous, 2) % M;
		cout << current % 2 << ' ';
		current % 2 == 0 ? count0++ : count1++;
		numberOfBits--;
	}
	cout << "\n0 appeared "<<count0<<" times and 1 appeared "<<count1<<" times\n";


	
}