#include <iostream>
#include <string>
using namespace std;

// Integer versus floating-point arithmetic.
/* What is the value of the integer variables i and j after the following statements?
(a) i = 2 / 5 * 3; j = 3 * 2 / 5; -> i = 0, j = 1
(b) i = 2.0 / 5 * 3; j = 2 / 5 * 3.0; -> i = 1.2, j = 0
The evaluation of the expressions in (b) involves implicit type conversion.
(c) Rewrite the expressions such that all type conversions are explicit.*/

// The Quetelet index. 
/* The Quetelet, or Body Mass Index (BMI), is used in medicine as a normalised measure of tissue mass in an individual, 
allowing that person to be classified as underweight, normal weight or obese. 
The Quetelet index Q is defined as the body mass (M, measured in kilograms) 
divided by the square of the body height (h, measured in meters), i.e., Q = M/h^2. 
Write a program that asks the user to enter weight and height via the keyboard. 
After reading in those values, the program should calculate the Quetelet index and report the result back to the user. 
You should start worrying about your weight, or about bugs in your program, if the result does not fall in the range 18.0-30.0. */

// An age and birthday calculator. 
/* Write a program that reads from keyboard input your date of birth and today’s date 
and that calculates your age and the number of days until your next birthday (display these results on screen). 
For simplicity, assume that a year has 365 days, and that a month has 30 days. Hint: make use of the modulo operator (%). */

double mokka() {
    // declaration of variables
    double dWeightCaffeine;
    const double dWeightC = 12.011, dWeightH = 1.008, dWeightN = 14.007, dWeightO = 15.999;
    // calculation of molecular weight of 1,3,7-trimethylpurine-2,6-dione (C8H10N4O2)
    dWeightCaffeine = 8 * dWeightC + 10 * dWeightH + 4 * dWeightN + 2 * dWeightO;
    return dWeightCaffeine;
}

double bmi(double dBodyMass, double dBodyHeight) {
    double dBMI;
    dBMI = dBodyMass / (dBodyHeight * dBodyHeight);
    return dBMI;
}

int * ager(int birthYear, int birthMonth, int birthDay, int nowYear, int nowMonth, int nowDay) {
    static int age [3];
    int monthsToBirth, monthsToNow, monthsDiff;
    monthsToBirth = birthYear * 12 + birthMonth - 1; // Number of months since JC (year 0) until birth
    monthsToNow = nowYear * 12 + nowMonth -1; // Number of months since JC (year 0) until now
    monthsDiff = monthsToNow - monthsToBirth; // Difference of months between now and birth
    age [0] = monthsDiff / 12; // years since birth to now
    age [1] = monthsDiff % 12; // remaining months to now
    age [2] = nowDay - birthDay; // remaining days to now

    return age;
}

int main() {
    // Weighing caffeine
    cout << "1,3,7-Trimethylpurine-2,6-dione (caffeine) weighs " << mokka() << " g/mol." << endl;

    // Numbers memory space
    int iSmall = 1, iLarge = 999999;
    cout << "sizeof iSmall = " << sizeof iSmall << endl;
    cout << "sizeof iLarge = " << sizeof iLarge << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;

    // Explicit type conversions
    double dCalculation;
    dCalculation = static_cast<double>(2) / static_cast<double>(5) * static_cast<double>(3);

    // Body Mass Index
    double dBM, dBH, userBMI;
    cout << "Enter your body mass in kg: ";
    cin >> dBM;
    cout << "Enter your body height in m: ";
    cin >> dBH;

    // Age and next birthday calculator
    int * calcAge;
    int bY, bM, bD, cY, cM, cD;
    cout << "Enter your year of birth: ";
    cin >> bY;
    cout << "Enter your month of birth: ";
    cin >> bM;
    cout << "Enter your day of birth: ";
    cin >> bD;
    cout << "Enter current year: ";
    cin >> cY;
    cout << "Enter current month: ";
    cin >> cM;
    cout << "Enter current day: ";
    cin >> cD;

    calcAge = ager(bY, bM, bD, cY, cM, cD);
    cout << "Congratulations! You are " << calcAge[0] << " years, " << calcAge[1] << " months and " << calcAge[2] << " days old.\n";
    cout << "Your next birthday is in " << 12 - calcAge[1] << " months and " << 30 - calcAge[2] << " days. Looking forward?\n";

    string message;
    userBMI = bmi(dBM, dBH);
    if (userBMI > 30.0) {
        message = ". You're fat!\n";
    } else if (userBMI < 18.0) {
        message = ". Gotta eat those carbs!\n";
    } else {
        message = ". You look fabulous!\n";
    }
    cout << "Also, your body mass index (BMI or Quetelet index) is: " << bmi(dBM, dBH) << message;

    // terminate program
    return 0;
}

