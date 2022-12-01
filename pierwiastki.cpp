#include <iostream>
#include <string>
using namespace std;

int* pierwsze(int x)
{
    int n = 0;

    for (int i = 2; i <= x; i++)
    {
        if (i == 2) { n++; };
        if (i % 2 == 0) { continue; }
        for (int j = 2; j <= i; j++)
        {
            if (i == j) { n++; }
            if (i % j == 0) { break; }
        }
    }

    int* tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = 0;
    }

    int index = 0;

    for (int i = 2; i <= x; i++)
    {
        if (i == 2) { tab[index] = i; index++; };
        if (i % 2 == 0) { continue; }
        for (int j = 2; j <= i; j++)
        {
            if (i == j) { tab[index] = i;  index++; }
            if (i % j == 0) { break; }
        }
    }

    return tab;
}

int* wylacz_tab(int x) {
    int* pTab = pierwsze(x);
    int n = 0;
    int tmp = x;

    for (int j = 0; ; j++)
    {
        if (x == 1) { break; }
        for (int i = 0; ; i++) {
            if (x % pTab[i] == 0) {
                x = x / pTab[i];
                n++;
                break;
            }
        }
    }

    int* tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = 0;
    }
    x = tmp;

    for (int j = 0; ; j++)
    {
        if (x == 1) { break; }
        for (int i = 0; ; i++) {
            if (x % pTab[i] == 0) {
                x = x / pTab[i];
                tab[j] = pTab[i];
                break;
            }
        }
    }

    //for (int i = 0; i < n; i++)
    //{
    //    cout << tab[i] << "\t";
    //}

    return tab;
}

void wylacz(int x)
{
    int* tab = wylacz_tab(x);
    int left = 1, right = 1;
    int n = sizeof(tab) / sizeof(int)+2;
    //for (int i = 0; i < n; i++)
    //{
    //    cout << tab[i] << "\t";
    //}
    //cout << endl;
    for (int i = 0; i < n; i++) {
        if (tab[i] == 0) { continue; }
        for (int j = 0; j < n; j++) {
            if (i == j || tab[j] == 0) { continue; }
            if (tab[i] == tab[j]) {
                left *= tab[i] ;
                tab[i] = 0;
                tab[j] = 0;
            }
        }
    }
    //for (int i = 0; i < n; i++)
    //{
    //    cout << tab[i] << "\t";
    //}
    //cout << endl;
    for (int i = 0; i < n; i++) {
        if (tab[i] == 0) { continue; }
        for (int j = 0; j < n; j++) {
            if (i == j || tab[j] == 0) { continue; }
            if (tab[i] != tab[j]) {
                right *= tab[i] * tab[j];
                tab[i] = 0;
                tab[j] = 0;
            }
        }
    }
    //for (int i = 0; i < n; i++)
    //{
    //    cout << tab[i] << "\t";
    //}
    //cout << endl;

    cout << left << "|" << right << endl;
}

int main()
{
    int x;
    cout << "podaj pierwiastek: ";
    cin >> x;
    cout << endl;
    wylacz(x);

    //wylacz_tab(24);

     //pierwsze(17);
     // 
     //int x;
     //cout << "Pierwiastek: ";
     //cin >> x;

     //for (int i=0 ; ; i++)
     //{
     //    if (pow(i, 2) == x) {
     //        cout << i << endl;
     //        break;
     //    }
     //    if (pow(i, 2) > x) {
     //        cout << "/" << x << endl;
     //        break;
     //    }
     //}
}
