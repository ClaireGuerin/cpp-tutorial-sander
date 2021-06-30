#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Gompertz law for tumour growth.
/* For many types of cancer, the size of a tumour is well described by Gompertz law for tumour growth:
x(t) = xmax exp( ln(x0 / xmax) exp(-αt) )
Here, x(t) is the size of the tumour at time t, 
x0 is its initial size and 
xmax is the maximum size it can reach given the availability of nutrients. 
Write a program that calculates the size of a tumour at a given time point, assuming that 
x0 = 0.01, 
xmax = 1.0 and 
α = 0.2. 
How long does it approximately take for the tumour to grow to 95% of its maximum size?*/

// The mystery of the bitshift operators (?).
/* According to Table 3.1, the operators << and >> can have two different meanings. 
When they occur with a stream object such as std::cout or std::cin,
they are interpreted as, respectively, output and input operator. 
When they occur with two integer operands, however, they are interpreted as so-called bitshift operators. 
Analyse the behaviour of the bitshift operators by examining the output produced by the following code 
for some different values of the integers iShift and iInt. */

// The abc formula. 
/* The solutions x∗ of the second order polynomial equation a x 2 + b x + c = 0 
can be found by applying the abc formula: 
x* = (−b ± b 2 − 4ac) / 2a
Write a program that reads three coefficients a, b and c from keyboard input, and that computes the
locations of the two roots of the polynomial a x ** 2 + b x + c = 0. For the moment, assume that the program
is only used when two solutions exist (i.e., when b^2 > 4ac).*/

double gompertz(const int t) {
    const double x0 = 0.01, xmax = 1.0, alpha = 0.2;
    const double tumorSize = xmax * exp( log(x0 / xmax) * exp(-alpha * t) );

    return tumorSize;
}

vector<double> roots(const double a, const double b, const double c) {
    const double xminus = (- b - sqrt(b * b - 4 * a * c)) / (2 * a);
    const double xplus = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
    const vector<double> r = {xminus, xplus};

    return r;
}

int main() {
    int i = 7, j; 
    i %= 3;
    cout << "i = 7; i %= 3 GIVES i = " << i << "\n";
    i = 7; 
    j = i *= 2;
    cout << "i = 7, j = i *= 2 GIVES i = " << i << ", j = " << j << "\n";
    j *= (i = 2, j = 4);
    cout << "j *= (i = 2, j = 4) GIVES i = " << i << ", j = " << j << "\n";

    cout << "After t = 5, the tumor has size " << gompertz(5) << ". After t = 10, the tumor has size " << gompertz(10) << "\n";
    cout << "The tumor reaches 95% of its maximum size after t = " << - log(log(0.95) / log(0.01 / 1.0)) / 0.2 << "\n";

    const int iInt = 12, iShift = 1;
    const int iResultLeft = iInt << iShift;
    cout << "Bitshift iInt << " << iShift << " = " << iResultLeft << std::endl;
    const int iResultRight = iInt >> iShift;
    cout << "Bitshift iInt >> " << iShift << " = " << iResultRight << std::endl;

    const vector<double> findRoot = roots(4, 3, -5);
    cout << "The roots of polynomial 4x^2 + 3x - 5 are " << findRoot[0] << " and " << findRoot[1] << "\n";

    return 0;
}