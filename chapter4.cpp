#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// What kind of critter is this?.
/* Write a C ++ program that implements the following simplified determination table from a children’s field guide to small creatures:
1. Does the bug fly? — If yes, Answer: It’s an insect; if no, continue
2. Does the bug have 8 legs? — If yes, Answer: It’s a spider; if no, continue
3. Does the bug have 6 legs? — If yes, Answer: It’s an insect; if no, continue
4. Does the bug have no legs? — If yes, Answer: It’s a worm or a larva; if no, continue
5. Answer: It might be a millipede
As a shortcut, use variables doesFly and iNumberOfLegs with preassigned values, instead of allowing the user to set these values via keyboard input. */

// Exclusive OR. 
/* Exclusive OR (XOR) is a logical operation that acts on two logical input values
and that evaluates to true if one of the two inputs is true, but not both. 
Write a C ++ program that implements an XOR switch. Define two logical variables, bool isInputA, isInputB, 
and print "Hurrah!"" to the screen if and only if XOR( isInputA , isInputB ) is true. 
Write a first implementation of the XOR switch and try all four combinations of the values true and false for the two input variables 
to verify that your implementation is correct. The XOR switch can be implemented in several different ways. 
Modify your code to create three alternative implementations:
(a) with nested if - else statements and without using the operators && , || , ! , == or !=
(b) with a single if - else statement and without using == or !=
(c) with a single if - else statement and without using && , || or ! */

// The optimist/pessimist quiz.
/* Write a program that collects answers to three multiple choice questions from the user, 
and that classifies him/her as either an optimist or a pessimist based on the answers provided. 
Each multiple choice question should have three alternative answers; at least one of them should be rated as 
an optimist answer and another one as a pessimist answer, and these should not be listed in the same order across the three questions.*/

// The abc formula - continued. 
/* A second order polynomial equation a x^2 + b x + c = 0 with a != 0 has 
two real-valued solutions if b 2 > 4ac, 
one real-valued solution if b 2 = 4ac, and 
no real-valued solution if b 2 < 4ac. 
Also, the equation has a single solution if a = 0 and b != 0. 
Extend your solution of exercise 3.5 and ensure that your program deals correctly with all of the above cases. */

// The conditional operator.
/* Use the conditional operator to replace the if - else statement in the following program fragment: 
std::cout << "Please enter a number: ";
double dVal;
std::cin >> dVal;
double dClip = dVal;
if(dVal < 0.0) dClip = 0.0; */

// The switch-statement.
/* Replace the if - else ladder in the following program fragment by a switch - statement 

std::cout << "Who is most resistant to alcohol?" << std::endl
<< "(1) Master Yoda" << std::endl
<< "(2) E.T." << std::endl
<< "(3) Nefertiti" << std::endl
<< "(4) Arnold Schwarzenegger" << std::endl
<< "(5) Jamie Oliver" << std::endl
<< "Your answer: ";
int iAnswer;
std::cin >> iAnswer;

if (iAnswer == 1 || iAnswer == 2) 
    std::cout << "wrong! (extraterrestrials don't drink alcohol)" << std::endl;
else if (iAnswer == 3)
    std::cout << "wrong! (Nefertiti only drinks the milk of she-donkeys)" << std::endl;
else if (iAnswer == 4)
    std::cout << "correct!" << std::endl;
else if (iAnswer == 5)
    std::cout << "wrong! (Jamie has a sip of wine now and then, but usually spits it out after tasting)" << << std::endl;
else
    std::cout << "invalid answer" << std::endl;*/

// The bitwise logical operators.
/* Table 3.1 indicates that there are three (binary) bitwise logical operators, & and | and ^ , 
and a (unary) bitwise complement operator ~ . 
These need to be carefully distinguished from the standard logical operators && , || and ! . 
The bitwise logical operators take integer operands and their result is an integer as well. Analyse the behaviour of the four operators by examining
the output produced by the following code. Try to make sense of the results by first writing the numbers
before and after the bitwise operation in binary notation. Next, formulate and test your hypothesis on 
the effect of the bitwise logical operators */

string identifyCritter(const bool flies, const int nLegs) {
    string critter;
    if (flies || nLegs == 6) {
        critter = "It's an insect.";
    } else if (nLegs == 8) {
        critter = "It's a spider.";
    } else if (nLegs == 0) {
        critter = "It's a worm or a larva.";
    } else {
        critter = "It might be a millipede";
    }

    return critter;
}

string hurray(const bool isInputA, const bool isInputB) {
    string myFuckingString = "";
    if ((isInputA && !isInputB) || (!isInputA && isInputB)) { // either A or B true, but not both
        myFuckingString = "Hurray!";
    }

    return myFuckingString;
}

string ratePessimism(const int answer1, const int answer2, const int answer3) {
    string mentality;
    int score = answer1 + answer2 + answer3;
    
    if (score < 0) {
        mentality = "pessmist";
    } else if (score > 0) {
        mentality = "optimist";
    } else {
        mentality = "indifferent";
    }

    return mentality;
}

void findRoots(const double a, const double b, const double c) {
    double xminus, xplus, x;
    if (a == 0 && b !=0) {
        x = -c / b;
        cout << "Your polynomial has one real solution, " << x << "\n";
    } else if (b * b > 4 * a * c) { // 2 real-valued solutions
        xminus = (- b - sqrt(b * b - 4 * a * c)) / (2 * a);
        xplus = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << "Your polynomial has two real-valued solutions, " << xminus << " and " << xplus << "\n";
    } else if (b * b == 4 * a * c) {
        x = - b / (2 *a);
        cout << "Your polynomial has one real solution, " << x << "\n";
    } else {
        cout << "Your polynomial has non real solution" << "\n";
    }
}

int main() {

    const bool doesMyCritterFly = true;
    const bool myCritterHasNLegs = 6;
    cout << "A critter has " 
        << myCritterHasNLegs 
        << " legs. Does it fly? " 
        << doesMyCritterFly 
        << " . "
        << identifyCritter(doesMyCritterFly, myCritterHasNLegs) 
        << "\n";

    cout << "A and B are both true. " << hurray(true, true) << "\n";
    cout << "A and B are both false. " << hurray(false, false) << "\n";
    cout << "A is true, B is false. " << hurray(true, false) << "\n";
    cout << "A is false, B is true. " << hurray(false, true) << "\n";

    char firstAnswer, secdAnswer, thirdAnswer;
    cout << "Do you think Humanity is: A - beautiful, B - boring, C - doomed? ";
    cin >> firstAnswer;
    const int a1 = firstAnswer == 'A' ? 1 : (firstAnswer == 'B' ? 0 : -1);
    cout << "What should one always keep in their wallet: A - a donor card, B - a condom, C - a picture of their cat? ";
    cin >> secdAnswer;
    const int a2 = secdAnswer == 'A' ? -1 : (secdAnswer == 'B' ? 1 : 0);
    cout << "What do you want for dinner: A - pasta, B - spinach , C - chocolate? ";
    cin >> thirdAnswer;
    const int a3 = thirdAnswer == 'A' ? 0 : (thirdAnswer == 'B' ? -1 : 1);

    cout << "You're " << ratePessimism(a1, a2, a3) << "\n";

    findRoots(-10, 0, 50);

    std::cout << "Please enter a number: ";
    double dVal;
    std::cin >> dVal;
    const double dClip = (dVal < 0.0) ? 0.0: dVal;
    cout << dClip << "\n";

    std::cout << "Who is most resistant to alcohol?" << std::endl
    << "(1) Master Yoda" << std::endl
    << "(2) E.T." << std::endl
    << "(3) Nefertiti" << std::endl
    << "(4) Arnold Schwarzenegger" << std::endl
    << "(5) Jamie Oliver" << std::endl
    << "Your answer: ";
    int iAnswer;
    std::cin >> iAnswer;

    switch (iAnswer) {
        case 1: case 2:
            std::cout << "wrong! (extraterrestrials don't drink alcohol)" << std::endl;
            break;
        case 3:
            std::cout << "wrong! (Nefertiti only drinks the milk of she-donkeys)" << std::endl;
            break;
        case 4:
            std::cout << "correct!" << std::endl;
            break;
        case 5:
            std::cout << "wrong! (Jamie has a sip of wine now and then, but usually spits it out after tasting)" << std::endl;
            break;
        default:
            std::cout << "invalid answer" << std::endl;
    }   

    const int i = 12, j = 10;
    std::cout << "i & j = " << (i & j) << endl; // i & j has value 8 (binary 0000 1000)
    std::cout << "i | j = " << (i | j) << endl; // i | j has value 14 (binary 0000 1110)
    std::cout << "i ^ j = " << (i ^ j) << endl; // i ^ j has value 6 (binary 0000 0110)
    std::cout << "~i = " << (~i) << endl; // ~i has value -13 (binary 1111 0011)

    /* the bitwise operators & , | and ^ apply, respectively, the logical operations AND, OR and XOR on a bit-by-bit basis on a pair of two integers. 
    For example, the bitwise AND operator ( & ) compares each bit of the first operand to the corresponding bit of the second operand.
    If both bits are 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0. 
    The unary bitwise complement operator ~ is the bitwise equivalent of the standard logical NOT (operator ! ): 
    for each bit in its operand the corresponding bit in the result is set to the complementary value. 
    The resulting bit pattern is interpreted on most platforms according to the so-called two’s complement representation of signed numbers, 
    which interprets the first bit of the pattern as a sign bit (0 for positive number, 1 for negative numbers). 
    According to this representation, ~i then evaluates to the number -(i + 1) using ordinary arithmetic.*/

    return 0;
}