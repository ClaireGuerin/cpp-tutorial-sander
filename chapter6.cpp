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
        cout << vec[i] << " ";
    }
}

int main() {
    simplify(6, 5);
    simplify(57, 323);
    simplify(52455, 34970);

    // SWAP
    double x = 1.0, y = 2.0;
    
    // show values
    cout << "in main() : x = " << x << ", y = " << y << endl;

    // call swap() to swap values
    swap(x, y);

    // show values again
    cout << "in main() : x = " << x << ", y = " << y << endl;

    // MINIMAL WORKING EXAMPLE OF REFERENCE
    cout << "Referencing &j = i \n";
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
    cout << "The largest element in vector 1 = {1,23,45,98,789} is: " << largest(vec1) << "\n"
        << "The largest element in vector 2 = {1,300,45,98,89} is: " << largest(vec2) << "\n";

    // REMOVE DUPLICATES FROM VECTOR

    vector<int> vec3 = {1,2,2,3,4,5,5,6};
    cout << "\n Vector 3 = " ;
    printOutVector(vec3);
    cout << "\n Removing duplicates: ";
    removeDuplicates(vec3);
    printOutVector(vec3);

    vector<int> vec4 = {1,300,1,45,98,89,89};
    cout << "\n Vector 4 = " ;
    printOutVector(vec4);
    cout << "\n Removing duplicates: ";
    removeDuplicates(vec4);
    printOutVector(vec4);
    cout << "\n";
    
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