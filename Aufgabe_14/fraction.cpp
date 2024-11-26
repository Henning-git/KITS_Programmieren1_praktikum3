#include <iostream>
#include "fraction.h"

using namespace std;

// Ausgabe des Bruchs
void printFraction(Fraction& f) {
    cout << f.numerator << "/" << f.denominator << endl;
}

// Eingabe des Bruchs
void readFraction(Fraction& f) {
    cout << "Zaehler: ";
    cin >> f.numerator;

    int denominator = 0;
    do {
        cout << "Nenner: ";
        cin >> denominator;
    } while(denominator == 0);

    f.denominator = denominator;

    format(f);
}

// Berechnung größter gemeinsamer Teiler
int gcd(int p, int q) {
    while (q != 0)
    {
        int r = p % q;
        p = q;
        q = r;
    }
    return p;
}

// Kürzen des Bruchs
void cancel(Fraction& f) {
    int gcdNumDenom = gcd(f.numerator, f.denominator);
    f.numerator /= gcdNumDenom;
    f.denominator /= gcdNumDenom;
}

// Bruch formatieren (Aufruf am Ende der vier Grundrechenarten und von readFraction)
void format(Fraction& f) {
    cancel(f);
    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    else if (f.denominator == 0) {
        cout << "Nenner darf nicht Null sein!" << endl;
    }
}

// Addition
Fraction add(Fraction& f1, Fraction& f2) {
    Fraction erg;
    erg.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    erg.denominator = f1.denominator * f2.denominator;

    format(erg);
    return erg;
}

// Subtrahiere
Fraction subtract(Fraction& f1, Fraction& f2) {
    Fraction erg;
    erg.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    erg.denominator = f1.denominator * f2.denominator;

    format(erg);
    return erg;
}

// Multipliziere
Fraction multiply(Fraction& f1, Fraction& f2) {
    Fraction erg;
    erg.numerator = f1.numerator * f2.numerator;
    erg.denominator = f1.denominator * f2.denominator;

    format(erg);
    return erg;
}

// Dividiere
Fraction divide(Fraction& f1, Fraction& f2) {
    Fraction erg;
    erg.numerator = f1.numerator * f2.denominator;
    erg.denominator = f1.denominator * f2.numerator;

    format(erg);
    return erg;
}
