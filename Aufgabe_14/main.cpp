#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    // local variables!
    Fraction f1;
    Fraction f2;
    Fraction result;

    readFraction(f1);
    readFraction(f2);

    cout << endl << "Erster Bruch: ";
    printFraction(f1);

    cout << "Zweiter Bruch: ";
    printFraction(f2);

    // Addition
    result = add(f1, f2);
    cout << endl << "Addition: ";
    printFraction(result);

    // Substraktion
    result = subtract(f1, f2);
    cout << "Subtraktion: ";
    printFraction(result);

    // Multiplikation
    result = multiply(f1, f2);
    cout << "Multiplikation: ";
    printFraction(result);

    // Division
    result = divide(f1, f2);
    cout << "Division: ";
    printFraction(result);

    return 0;
}
