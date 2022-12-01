#include <iostream>
using namespace std;

int fpow(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n%2 != 0)
	{
		return x * (fpow(x, n - 1));
	}
	return fpow(x, n / 2) * fpow(x, n / 2);
}

double newton(int x, int n) {
	double res, y, z;
	for (int i = 0; i < 10; i++) {
		if (i == 0) { res = 1; }
		y = pow(res, n) - x;
		z = n * (pow(res, n - 1));
		res = res - (y / z);
	}
	return res;
}

int main()
{
	cout << newton(25, 2) << endl;
	cout << newton(125, 3) << endl;
	cout << newton(10, 1) << endl;
	cout << newton(531610, 2) << " = " << sqrt(531610) << endl;
}
//funkcja potęga(x, n)
//jeżeli n = 0
//zwróć 1
//jeżeli n jest nieparzysta
//zwróć x · potęga(x, n - 1)
//w przeciwnym przypadku
//a = potęga(x, n / 2)
//zwróć a2

//funkcja potęga(x, n)
//jeżeli n = 0
//zwróć 1
//jeżeli n jest nieparzysta
//zwróć x ·(potęga(x, (n - 1) / 2))2
//zwróć(potęga(x, n / 2))2