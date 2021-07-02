#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// GUIDELINES: PASSING BY REFERENCE IN FUNCTION ARGUMENTS
/* 
- If a function just needs read-access to its input variable, pass the argument by const-reference.
- If a function is intended to change the variable used to call the function, pass the argument by reference.
- Pass the argument by value only if the function needs write-access to its input parameter and 
when it is not meant to change the variable used to call the function. */

// Finding the largest element in a vector. 
/* Write a function that takes a vector of floating-point variables as input and that returns its largest element. */

// Removing duplicates from a vector.
/* Write a function that can be called to remove all duplicate elements from a vector of integers. */

// Inline function to optimize code
/* use inline only for frequently called, small functions such as the function sqr() in the following example:

inline double sqr(const double &x) { // returns the square of the number x
    return x * x;
}

The compiler may ignore the request to expand a function inline. This is particularly likely to happen 
- if the function contains a loop, a switch or a goto statement; 
- if the function calls itself, or 
 -if it contains static variables. */

// Static function variables.
/* Consider the following program that reports the running average of a sequence of weight measurements entered by the user. 
Rewrite the code, and apply static variables to separate the task of requesting input from the user from the task of keeping track of the running average.
Delegate both to their own function. */

// Computing the factorial of a number.
/* Write an iterative and a recursive version of a function that computes the factorial n! of an integer number n ≥ 0. 
Recall that 0! = 1, by definition, and that n! = n * (n − 1)! = n * (n − 1) * ... * 2 * 1, for all n > 0. 
When testing the functions, use only small values of n to avoid integer overflow. */

// An efficient power function for integer powers. 
/* Write a function *** double pow(const int&, const int&) ***
that overloads the standard *** double pow(const double&, const double&) *** function from the library cmath. 
Your function should return the value of x^n for arbitrary integer values x and integer powers n.

Attempt to code a recursive implementation, based on the following recursive definition of x^n :
= 1/(x^{−n}) if n < 0;
= 1 if n = 0;
= x * x^{n-1} if n > 0 and n is odd;
= (x^{n/2})^2 otherwise.

If you are having trouble to code the recursion, fall back to an iterative implementation. Compute
pow(2, -4) and pow(2.0, -4.0) , and identify which pow() function is executed in each case.
*/

void simplify(int, int); // global declaration: simplify() is recognised from this point onwards

void swap(double &x, double &y) {
    // show values
    // cout << "in swap() : x = " << x << ", y = " << y << endl;

    // swap values
    const double tmp = x;
    x = y;
    y = tmp;

    // show values again
    // cout << "in swap() : x = " << x << ", y = " << y << endl;
}

void updatePopulationDensity(double &N, const double &r) {
    N *= exp(r * (1.0 - N));
}

double largest(const vector<double> &vec) {
    double elem = vec[0];

    for (int i = 1; i < vec.size(); ++i) {
        if (elem < vec [i]) {
            double tmpElem = vec[i];
            elem = tmpElem;
        }

    }

    return elem;
}

void removeDuplicates(vector<int> &vec) {

    vector<int> tmpVec = {vec.back()};

    for (int i = 0; i < vec.size() - 1; ++i) {
        bool unique = true;

        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[i] == vec[j]) {
                unique = false;
                break;
            } 
        }

        if (unique) {
            tmpVec.push_back(vec[i]);
        }
        
    }

    vec = tmpVec;
}

void printOutVector(const vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}

double requestInput() {
    
    // read measurement value
    std::cout << "Next value : ";
    double dWeight;
    cin >> dWeight;

    return dWeight;

}

bool averageInput() {

    // request input
    double newVal = requestInput();

    static int n = 1;
    static double dSum = 0.0;
    static bool running = true;

    if (newVal >= 0.0) {
        dSum += newVal;
        //  report running average
        std::cout << "The running average of the values entered thus far is : "
                << dSum / n << std::endl;
        
        ++n;
    } else {
        std::cout << "End of program.\n";
        running = false;
    }

    return running;
}

int iterativeFactorial(int n) {
    //0! = 1
    // n! = n * (n − 1)! = n * (n − 1) * ... * 2 * 1

    int fac = 1;

    while (n > 0) {
        fac *= n;
        --n;
    }

    return fac;

}

int recursiveFactorial(const int n) {
    //0! = 1
    // n! = n * (n − 1)! = n * (n − 1) * ... * 2 * 1

    return (n == 0) ? 1 : n * recursiveFactorial(n - 1);
}

double pow(const int &x, const int &n) {

    double power;

    if (n < 0) {
        power = 1 / pow(x, - n);
    } else if (n == 0) {
        power = 1;
    } else if (n > 0 && (n % 2) != 0) {
        power = x * pow(x, n - 1);
    } else {
        double sqroot = pow(x, n / 2.0);
        power =  sqroot * sqroot;
    }

    return power;
}

int main() {
    simplify(6, 5);
    simplify(57, 323);
    simplify(52455, 34970);

    // SWAP
    double x = 1.0, y = 2.0;
    
    // show values
    std::cout << "in main() : x = " << x << ", y = " << y << endl;

    // call swap() to swap values
    swap(x, y);

    // show values again
    std::cout << "in main() : x = " << x << ", y = " << y << endl;

    // MINIMAL WORKING EXAMPLE OF REFERENCE
    std::cout << "Referencing &j = i \n";
    int i = 0;
    int &j = i;
    std::cout << "i = " << i << "; j = " << j << std::endl;
    ++j;
    std::cout << "i = " << i << "; j = " << j << std::endl;
    ++i;
    std::cout << "i = " << i << "; j = " << j << std::endl;

    // RICKER POPULATION GROWTH MODEL

    const int nGen = 10;
    double n = 0.01;
    vector<double> densities(nGen);
    for (int i = 0; i < nGen; ++i) {
        densities[i] = n;
        updatePopulationDensity(n, 2.0);
    }
    
    // LARGEST ELEMENT IN VECTOR

    vector<double> vec1 = {1,23,45,98,789};
    vector<double> vec2 = {1,300,45,98,89};
    std::cout << "The largest element in vector 1 = {1,23,45,98,789} is: " << largest(vec1) << "\n"
        << "The largest element in vector 2 = {1,300,45,98,89} is: " << largest(vec2) << "\n";

    // REMOVE DUPLICATES FROM VECTOR

    vector<int> vec3 = {1,2,2,3,4,5,5,6};
    std::cout << "\n Vector 3 = " ;
    printOutVector(vec3);
    std::cout << "\n Removing duplicates: ";
    removeDuplicates(vec3);
    printOutVector(vec3);

    vector<int> vec4 = {1,300,1,45,98,89,89};
    std::cout << "\n Vector 4 = " ;
    printOutVector(vec4);
    std::cout << "\n Removing duplicates: ";
    removeDuplicates(vec4);
    printOutVector(vec4);
    std::cout << "\n";

    // RUNNING AVERAGE INPUT

    std::cout << "Enter a series of weight measurements, or a negative value to stop." << std::endl;
    bool thisIsRunning = true;
    while (thisIsRunning) {
        thisIsRunning = averageInput();
    }
    
    // FACTORIAL
    std::cout << "Factorial 3 = " << iterativeFactorial(3) << " (iterative) " << recursiveFactorial(3) << " (recursive)" << "\n"
        << "Factorial 4 = " << iterativeFactorial(4) << " (iterative) " << recursiveFactorial(4) << " (recursive)" << "\n"
        << "Factorial 5 = " << iterativeFactorial(5) << " (iterative) " << recursiveFactorial(5) << " (recursive)" << "\n"
        << "Factorial 6 = " << iterativeFactorial(6) << " (iterative) " << recursiveFactorial(6) << " (recursive)" << "\n";

    // OVERLOAD POWER FUNCTION WITH INTEGERS

    std::cout << "5 to the power of -2: " << pow(5, -2) << "\n"
            << "5 to the power of 0: " << pow(5, 0) << "\n"
            << "5 to the power of 3: " << pow(5, 3) << "\n"
            << "5 to the power of 2: " << pow(5, 2) << "\n";

    // terminate program
    return 0;
}

void simplify(int iNum, int iDenom) { // writes the fraction iNum / iDenom in a simplified form
    int getGCD(int, int); // declares getGCD() within the scope of simplify()
    std::cout << iNum << "/" << iDenom << " = "; 
    
    // divide numerator and denominator by their greatest common divisor
    const int iGCD = getGCD(iNum, iDenom);
    iNum /= iGCD;
    iDenom /= iGCD;

    if(iNum / iDenom)
        std::cout << (iNum / iDenom) << " + ";
    std::cout << (iNum % iDenom) << "/" << iDenom << std::endl;
}

/* the function getGCD() is not recognised here 
void test() { 
    getGCD(1,2); //error : use of undeclared identifier 'getGCD'
    } */

int getGCD(int iNr1, int iNr2) {// global declaration: getGCD() is recognized from then on
    // Euclid’s algorithm for computing the
    // greatest common divisor of two numbers iNr1 and iNr2
    while(iNr2 != 0) {
    int tmp = iNr2;
    iNr2 = iNr1 % iNr2;
    iNr1 = tmp;
    }

    return iNr1;
}