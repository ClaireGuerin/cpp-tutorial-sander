#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// LOOPS: EXAMPLE 1
/* 
int iNumberOfOffspring; 
// ...some lines of code that determine the value of iNumberOfOffspring...
for(; iNumberOfOffspring; --iNumberOfOffspring) // the initialisation instruction is empty
    produceAnOffspring(); // the number of times the body is executed is determined by the initial value of iNumberOfOffspring
// the variable iNumberOfOffspring still exists here and has value 0 when the loop terminates. */

// LOOPS: EXAMPLE 2
/* 
for(int i = 0, k = 1; i < 5; ++i, k *= 2)
    std::cout << "2^" << i << " = " << k << std::endl; // this will print the first five powers of 2. */

// LOOPS: EXAMPLE 3
/* 
std::cout << "Please enter a number between 0 and 10: ";
int iInt;
std::cin >> iInt; // loop variable is initialised here

for(; iInt < 0 || iInt > 10 ;) { // initialisation and update instructions are empty
    std::cout << "Invalid input, please try again: ";
    std::cin >> iInt; // loop variable is updated here
} */

// LOOPS: EXAMPLE 4
/*
std::cout << "Please enter a number between 0 and 10: ";
int iInt;
for(;;) { // initialization, continuation criterion and update instruction are empty
    std::cin >> iInt; // iInt gets a value here
    if(!(iInt < 0 || iInt > 10)) break; // escape from the loop if input is valid
    std::cout << "Invalid input, please try again: "; // otherwise, try again...
} */

// The Ricker model of population growth.
/* The Ricker model is one of several classic discrete-time population growth models used in ecology to describe 
the change of the number of individuals in a population over time. In the Ricker model, the density of individuals N_t 
in generation t is fully determined by the density of individuals in the previous generation, N_{t−1}, according to the equation:
N_t = N_{t−1} e^r(1 − N_{t−1})
Here, r is a parameter that quantifies the intrinsic growth rate of the population, 
which corresponds to the maximal number of offspring produced per individual, exp(r). 
The term exp(r(1 − N_{t−1} )) is usually interpreted as the average number of offspring produced per individual. 
In the Ricker model, this quantity is assumed to decrease as an exponential function of the population size, 
to capture the negative effects of increased competition on offspring production at higher population densities. 

Write a C++ program to iterate the Ricker model, and study its behaviour for a few different values of the parameter r 
(e.g., try r = −0.05, r = 0.5, r = 2.0, r = 2.5 and r = 3.0). 
In all cases, set the initial population density to N_0 = 0.001, simulate for 100 timesteps, and 
store the sequence of population densities N_0, N_1, ... N_100 in a std::vector.
*/

// Estimating rates of mutation. 
/* A genome-wide comparison between an ancestral and a derived species revealed the following numbers of single base-pair mutations (see lecture notes).
Write a C++ program to estimate the relative rates of different kinds of mutations in the derived species. Proceed as follows. 
First, define a matrix object that contains the mutation counts from the table above.
Next, pool the counts from the upper-diagonal and lower-diagonal half of the table to estimate six relative mutation rates: 
AT → TA, AT → CG, AT → GC, TA → CG, TA → GC and CG → GC (this step reflects the assumption that mutations are equally likely to occur in both DNA strands). 
Finally, estimate the relative rates of transitions (mutations involving the substitution of a purine base for another purine, 
i.e. A # G, or the substitution of a pyrimidine base for another pyrimidine, i.e. C # T) and transversions (all other substitutions). */

// Nasty nested for-statements.
/* Compile the following code on your computer, execute the program and examine the output.
(a) Describe the function of the program.
Now, carefully go through the code and try to answer the following questions:
(b) What happens if you declare the loop variable iFactor in the inner for -loop instead of in the outer
one? Compare the scope of the loop variables in the modified and the original code to explain what
goes wrong.
(c) Interpret the expression !(iPrimeCandidate % iFactor) on line 7. Under what conditions is the
break statement on line 8 executed?
(d) If the inner for -loop is not terminated by the break -statement on line 8, it will eventually be
terminated by the loop condition on line 6. Why is it sufficient to only consider values of iFactor
for which iFactor <= (iPrimeCandidate / iFactor) ?
(e) Now consider the expression iFactor > (iPrimeCandidate / iFactor) on line 9. Does this condition
evaluate to true if the inner for -loop has been terminated by the break -statement on line 8? How
about when the loop was terminated by the loop condition on line 6?
*/

// Descriptive statistics. 
/* Write a program that reads a set of positive values from the keyboard input, as in listing 5.4. 
After collecting the values in a vector, the program should compute their mean and standard deviation (if enough data are available), 
and report these values back to the user. */

// Spaghetti code. 
/* Untangle the following spaghetti code, predict the output and replace the unnecessary goto statements by an equivalent loop statement. */

// All loop statements lead to Rome. 
/* Copy the code from exercise 5.4 (complete the questions if you have not done so already). 
Next, replace the inner for-loop by a while-loop. After verifying that the program still works as intended, 
replace the outer for-loop by a do-while-loop.*/

vector<double> ricker(const double r) {
    const int nGen = 100;
    double n = 0.001;
    vector<double> popSizes(nGen);

    for (int i = 0; i < nGen; ++i) {
        popSizes[i] = n;
        double nNext = n * exp(r * (1 - n));
        n = nNext;
    }
    
    return popSizes;
}

// SPAGHETTI CODE
// VERSION 1:

int spaghetti1() {
    int i = 0;
    test:
        if(i < 5)
            goto increment;
        return 0;
    increment:
        cout << i << endl;
        ++i;
        goto test;
}

// VERSION 2:

void spaghetti2() {
    int i = 0;
    while (i < 5) {
        cout << i << endl;
        ++i;
    }
}


int main() {

    // RICKER POPULATION GROWTH MODEL

    // r = −0.05, 0.5, 2.0, 2.5 and 3.0
    vector<double> densitiesR1 = ricker(-0.05);
    vector<double> densitiesR2 = ricker(0.5);
    vector<double> densitiesR3 = ricker(2.0);
    vector<double> densitiesR4 = ricker(2.5);
    vector<double> densitiesR5 = ricker(3.0);

    // BASE PAIR MUTATION RATES

    int nRow = 4;
    vector< vector<double> > mutations(nRow);
    mutations[0] = {0.0, 24.0, 26.0, 111.0};
    mutations[1] = {41.0, 0.0, 91.0, 33.0};
    mutations[2] = {35.0, 114.0, 0.0, 34.0};
    mutations[3] = {93.0, 33.0, 27.0, 0.0};

    cout << "Mutation matrix: \n";

    double counter = 0;

    for (int i = 0; i < nRow - 1; ++i) {
        for (int j = i + 1; j < nRow; ++j) {
            counter += mutations[i][j] += mutations[j][i];
            mutations[j][i] = 0.0;

            cout << mutations[i][j] << " ";
        }
        cout << "\n";
    }

    // normalise rates
    for (int i = 0; i < nRow - 1; ++i)
        for (int j = i + 1; j < nRow; ++j)
            mutations[i][j] /= counter;

    // compute transition rate
    const double transitionRate = mutations[0][3] + mutations[1][2];
    
    cout << "Total mutations: " << counter << "\n";

    // Mutation rates from AT → TA, AT → CG, AT → GC, TA → CG, TA → GC and CG → GC.

    cout << "Mutation rate from AT to TA: " << mutations[0][1] << "\n"
        << "Mutation rate from AT to CG: " << mutations[0][2] << "\n"
        << "Mutation rate from AT to GC: " << mutations[0][3] << "\n"
        << "Mutation rate from TA to CG: " << mutations[1][2] << "\n"
        << "Mutation rate from TA to GC: " << mutations[1][3] << "\n"
        << "Mutation rate from CG to GC: " << mutations[2][3] << "\n"
        << "Transition rate: " << transitionRate << "\n"
        << "Transversion rate: " << 1.0 - transitionRate << "\n";

    // NASTY NESTED FOR-STATEMENTS
    // NB: I reduced the original loop size from 1000 to 10

    for(int iPrimeCandidate = 2, iFactor; iPrimeCandidate < 10; ++iPrimeCandidate) {
        for(iFactor = 2; iFactor <= (iPrimeCandidate / iFactor); ++iFactor)
            if(!(iPrimeCandidate % iFactor))
                break;
        if(iFactor > (iPrimeCandidate / iFactor))
            std::cout << iPrimeCandidate << " is prime" << std::endl;
    }

    /* This function finds which numbers between 2 and 1000 are prime numbers. 
    If we declare iFactor in the inner for-loop instead of in the outer for-loop,
    the outer for-loop will not have access to iFactor and will thus not be able to test the outer condition.
    The break statement will be executed when there is an exact solution to the integer division prime / factor,
    i.e the remainder is null (=0). This means that the candidate number can be the product of another smaller number: it is composite, not prime. 
    Any number c that is not prime can be written in the form c = a × b, for at least one pair of integer factors a and b, where a ≤ b. 
    The condition a ≤ b implies that c = a × b ≥ a × a, such that a ≤ c/a.
    In other words, to determine if c is a prime number it is sufficient to check whether it can be divided by factors a that are no larger than c/a.
    If we break out of the inner loop, the outer condition can never be true. 
    If we get out of the inner loop because the condition iFactor <= (iPrimeCandidate / iFactor), then the outer condition is necessarily true.*/

    // DESCRIPTIVE STATISTICS

    // Read a set of positive values from the keyboard input, as in listing 5.4. 

    // read series of numbers from keyboard input
    std::vector<double> numbers; // Collect the values in a vector 
    std::cout << "Please enter positive numbers, or a negative number to stop." << std::endl;
    for (;;) {
        std::cout << "Your next input: ";
        double userInput;
        std::cin >> userInput;
        if (userInput < 0.0)
            break;
        else
            numbers.push_back(userInput); // adds the value at the end of vector
    }
    
    // Compute the mean and standard deviation (if enough data are available)

    double numberSum = 0;
    double numberSumOfSquares = 0;
    if (numbers.size() > 1){
        for (int i = 0; i < numbers.size(); ++i) {
            numberSum += numbers[i];
            numberSumOfSquares += numbers[i] * numbers[i];
        }
    } else {
        cout << "I do not have enough numbers to compute the mean and standard deviation.";
    }

    double mean = numberSum / numbers.size();
    double std = sqrt((numberSumOfSquares - (numberSum * numberSum) / numbers.size()) / (numbers.size() - 1));

    // Report statistics back to the user
    cout << "Your set of numbers have mean: " << mean << " and standard deviation: " << std << "\n";

    // SPAGHETTI CODE

    cout << "Spaghetti!" << "\n";
    spaghetti1();
    cout << "Spaghetti!" << "\n";
    spaghetti2();

    // ALL LOOPS LEAD TO ROME

    cout << "Let's Prime!" << "\n";

    int iPrimeCandidate = 2;
    do {
        int iFactor = 2;
        while (iFactor <= (iPrimeCandidate / iFactor)) {
            if(!(iPrimeCandidate % iFactor))
                break;
            ++iFactor;
        }

        if(iFactor > (iPrimeCandidate / iFactor))
            std::cout << iPrimeCandidate << " is prime" << std::endl;

        ++iPrimeCandidate;
    } while (iPrimeCandidate < 10);

    return 0;
}