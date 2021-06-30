#include <iostream>

// Basic calculations in C ++.
/* The operators + , - , * and / are available in C ++ to perform 
addition, subtraction, multiplication and division operations on numbers. 
Write a program that reads in two integer numbers, i and j, from the keyboard 
and that writes the result of i + j , i - j , i * j and i / j to the screen. 
Do the operators behave as you would expect? In particular, can you explain the behaviour of
the division operator? What happens if you divide a number by 0? */

// Integer division. 
/* C ++ has another arithmetic operator ( % ) that is used in the context of integer division. 
Modify the program you wrote in the previous exercise to calculate i%j for two integers i and j. 
Interpret and explain the result. */

// Prime number machine (?).
/* In this exercise, you will create an incredibly useful prime number machine that will allow you generate 40 different prime numbers. 
Write your program in such a way that it first asks the user to enter a natural number less than forty. 
Use this number n to generate a prime number P(n) using the formula P(n) = n^2 + n + 41 and write the resulting number to the screen. 
Hint: use the multiplication operator * to compute the square of the number n (i.e., n^2 = n * n ). */

int primer(int num) {
    // For numbers less than 40:
    int p = num * num + num + 41;
    return p;
}

int main() {
    int i, j;
    std::cout << "Give me a first number: \n";
    std::cin >> i;
    std::cout << "Give me a second number: \n";
    std::cin >> j;

    std::cout << "Addition: " << i + j << "\n";
    std::cout << "Subtraction: " << i - j << "\n";
    std::cout << "Mutiplication: " << i * j << "\n";
    // DIVIDING INTEGERS
    /* When integers are divided, the result of the / operator is the algebraic quotient with any fractional part discarded. 
    If the quotient a/b is representable, the expression (a/b)*b + a%b shall equal a. 
    This is often called "truncation toward zero".
    The usual arithmetic conversions are performed on the operands.
    The result of the / operator is the quotient from the division of the first operand by the second; 
    the result of the % operator is the remainder. 
    In both operations, if the value of the second operand is zero, the behavior is undefined.
    An annoying problem with integer division is that different compilers have different opinions on the value of i / j and i % j,
    when either one or both of the integers i or j are negative, 
    so it is better to avoid integer division with negative numbers.*/
    std::cout << "Division: " << i / j << "\n";
    std::cout << "Modulo: " << i % j << "\n";

    // PRIME NUMBER MACHINE
    int n;
    std::cout << "Give me a number < 40: \n";
    std::cin >> n;
    std::cout << "Here's a prime number: " << primer(n) << "\n";

    return 0;
}