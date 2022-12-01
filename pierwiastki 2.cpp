#include <iostream>
using namespace std;

// funkcja potegowania liczb rzeczywistych do liczb calkowitych
double fpow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 != 0)
    {
        return x * (fpow(x, n - 1));
    }
    return fpow(x, n / 2) * fpow(x, n / 2);
}

// funkcja wykonujaca obliczenie (1/n) * ( (n-1)*xₖ + (A/xₖⁿ⁻¹)
double fnev(double &nth, double &n, int &r) {
    return (1.0 / r) * ((r - 1) * nth + (n / fpow(nth, r - 1)));
}

// glowna funkcja liczaca pierwiastki, ustala przyblizona wartosc z liczby 1 (a = 1)
// nastepnie powtarza funkcje dla pozyskania zadowalajacej precyzji pierwiastka (epsilon = 100)
double nthrt(double number, int root)
{
    double a = 1.0, nthrt = fnev(a, number, root);
    for (unsigned int i = 0; i < 100; i++)
    {
        nthrt = fnev(nthrt, number, root);
    }
    return nthrt;
}

int main()
{
    // testowe wartosci
    cout << nthrt(125, 3) << endl; // 5.0
    cout << nthrt(25, 2) << endl; // 5.0
    cout << nthrt(500, 2) << endl; // 22.36068
    cout << nthrt(531610, 2) << endl; // 729.1159
    cout << nthrt(531610, 3) << endl; // 81.00859

    return 0;
}

// wzor
// xₖ₊₁ = (1/n) * ( (n-1)*xₖ + (A/xₖⁿ⁻¹) )