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
Use this number n to generate a prime number P (n) using the formula P (n) = n 2 + n + 41
and write the resulting number to the screen. 
Hint: use the multiplication operator * to compute the square of the number n (i.e., n 2 = n * n ). */

int main() {
    int i, j;
    std::cout << "Give me a first number: \n";
    std::cin >> i;
    std::cout << "Give me a second number: \n";
    std::cin >> j;

    std::cout << "Addition: " << i + j << "\n";
    std::cout << "Subtraction: " << i - j << "\n";
    std::cout << "Mutiplication: " << i * j << "\n";
    std::cout << "Division: " << i / j << "\n";
    std::cout << "Modulo: " << i % j << "\n";

    return 0;
}