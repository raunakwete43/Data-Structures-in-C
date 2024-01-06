#include <stdio.h>

typedef struct {
    int numerator;
    int denominator;
} Rational;

Rational createRational(int n, int d) {
    Rational r;
    r.numerator = n;
    r.denominator = d;
    return r;
}

Rational multiplyRational(Rational a, Rational b) {
    Rational result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

Rational divideRational(Rational a, Rational b) {
    Rational result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return result;
}

Rational subtractRational(Rational a, Rational b) {
    Rational result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

Rational addRational(Rational a, Rational b) {
    Rational result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

void printRational(Rational r) {
    printf("%d/%d\n", r.numerator, r.denominator);
}

int main() {
    Rational r1 = createRational(1, 2);
    Rational r2 = createRational(3, 4);
    Rational sum = addRational(r1, r2);
    printf("Addition: ");
    printRational(r1);
    printf(" + ");
    printRational(r2);
    printf(" = ");
    printRational(sum);
    printf("\n");

    // Test case 2: Subtraction
    Rational difference = subtractRational(r1, r2);
    printf("Subtraction: ");
    printRational(r1);
    printf(" - ");
    printRational(r2);
    printf(" = ");
    printRational(difference);
    printf("\n");

    // Test case 3: Multiplication
    Rational product = multiplyRational(r1, r2);
    printf("Multiplication: ");
    printRational(r1);
    printf(" * ");
    printRational(r2);
    printf(" = ");
    printRational(product);
    printf("\n");

    // Test case 4: Division
    Rational quotient = divideRational(r1, r2);
    printf("Division: ");
    printRational(r1);
    printf(" / ");
    printRational(r2);
    printf(" = ");
    printRational(quotient);
    printf("\n");


    return 0;
}
