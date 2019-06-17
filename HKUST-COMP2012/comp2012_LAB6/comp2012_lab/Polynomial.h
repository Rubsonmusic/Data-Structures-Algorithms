#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Fraction.h"
using namespace std;

class Polynomial {
  public:
    // Constructors and destructor
    Polynomial();
    Polynomial(const Polynomial& p);
    ~Polynomial();

    // Mutator
    void addCoef(const Fraction& f, const int deg);

    // Arithmetic operators (+, -, *) Optional: (/, %)
    Polynomial operator+(const Polynomial& poly) const;
    Polynomial operator*(const Polynomial& poly) const;
    Polynomial operator-(const Polynomial& poly) const;


    // Assignment operators (=, +=, -=)
    /* TODO */
    const Polynomial& operator=(const Polynomial& poly);
    const Polynomial& operator+=(const Polynomial& poly);
    const Polynomial& operator-=(const Polynomial& poly);

    // Other functions (<<)
    /* TODO */
    friend ostream& operator<<(ostream& os, const Polynomial& poly);

  private:
    // Reduce function
    Polynomial& reduce();

    // Member variables
    Fraction* coef;
    int deg;
};

#endif
