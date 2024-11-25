#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

typedef struct {
    int numerator;
    int denominator;
} Fraction;

void printFraction(Fraction& f); // Ausgabe des Bruchs
void readFraction(Fraction& f); // Eingabe des Bruchs
int gcd(int p, int q); // Berechnung größter gemeinsamer Teiler
void cancel(Fraction& f); // Kürzen des Bruchs
void format(Fraction& f); // Formatieren des Bruchs (kein Minus im Nenner)
Fraction add(Fraction& f1, Fraction& f2); // Addition zweier Brüche
Fraction subtract(Fraction& f1, Fraction& f2); // Subtraktion zweier Brüche
Fraction multiply(Fraction& f1, Fraction& f2); // Multiplikation zweier Brüche
Fraction divide(Fraction& f1, Fraction& f2); // Divison zweier Brüche

#endif // FRACTION_H
