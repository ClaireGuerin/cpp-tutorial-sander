#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// Elementary operations on a std::pair and a user-defined structure.
/* 
(a) Declare a std::pair that contains an integer and a character variable, and create an instance of it. 
Allow the user to set the values of the member variables first and second via keyboard input.
Finally pass the std::pair object to a function that prints the values of the member variables to the screen.

(b) Replace the std::pair by a home-made structure. */

// Elementary operations on a class object. 
/* Replace the struct of the previous exercise by a class in which the member variables are private. 
Add appropriate public member functions to take care of input and output operations on the member variables, 
exactly as in Exercise 10.1. */

// The PGCPPPHD phone directory. 
/* Use listing 10.2 as an inspiration for writing a C ++ program that serves as a search engine 
for the phone directory of the Pan-Galactic C++ Programming Help Desk (PGCPPPHD). 
Your program should import data from a file phonedirectory.txt with the following contents:

ET          6133
Arnold      8093
Jamie       8094
Yoda        8097
Nefertiti   8780

The data from the file should be loaded into a std::vector of struct objects, each containing a name and an extension. 
After loading the database, the program should allow the user to enter a name, and it should then show the corresponding extension on the screen 
(or an appropriate message if the requested name is not listed in the PGCPPPHD).
*/

// Complex number arithmetic.
/* Complex numbers can be implemented in C++ as structures that contain two floating point values to represent the 
real and imaginary parts of a complex number z = a + b i (with z ∈ C, a = Re(z) ∈ R and b = Im(z) ∈ R). 
Declare a struct ComplexNumber and write functions that operate on it to:

• print the value of a complex number z = a + b i to the screen in the ordinary notation a + b i.
• compute the norm of a complex number ||z|| = sqrt(a^2 + b^2).
• compute the conjugate of a complex number z̄ = a − b i.
• calculate the product of two complex numbers (a + b i)(c + d i) = (ac − bd) + (ad + bc) i
• calculate the ratio of two complex numbers y/z = (yz̄) / ||z||^2 

Test your code by verifying that it correctly evaluates:

(5 + 5 i) / (3 − 4 i) = -1/5 +7/5 i

*/

// Simulating a farm. 
/* Use the class Cow from listing 10.3 as a basis for simulating a farm. 
To do this, develop a class Farm that contains a private herd of Cow s and a variable money of type double.
Implement the following behaviours by means of public member functions: 

(a) The farmer can invest money into the Farm to realise a positive initial value of money , sufficient to
buy at least one Cow .

(b) The farmer can sell a Cow from the herd at the weekly livestock market, in order to increase the
value of money ;

(c) The farmer can buy a Cow at the livestock market and add it to the herd , which reduces the value
of money ;

(d) The farmer can use money to buy feed for the animals, which is distributed every day among the
Cow s in the herd ;

(e) The farmer milks the Cow s everyday, and sells the milk to make money .

Use your rural wit (if any) to implement clever rules for buying and selling cows, depending on the current
market prices of livestock, animal feed and milk. For simplicity, you can initially assume these to be given
and simulate a single Farm over the course of a year (for example, keep track of the development of the
size of the herd). Optional Challenge: simulate multiple Farm s and allow the law of supply and demand
to set the market price for milk.

*/

void printToScreen(std::pair<int, char> &somePair) {
    cout << "Your input: " << somePair.first << ", " << somePair.second << "\n";
}

struct TheStructure {
    int theInt;
    char theChar;
    double theDouble;
};

void printToScreen(TheStructure &someStructure) {
    cout    << "Your input: " << someStructure.theInt << ", " 
            << someStructure.theChar << ", "
            << someStructure.theDouble << "\n";
}

class MySuperUselessClass {
    public:
        void define(int, char, double);
        void print();
    private:
        int theInt;
        char theChar;
        double theDouble;
};

void MySuperUselessClass::define(int i, char c, double d) {
    theInt = i;
    theChar = c;
    theDouble = d;
}

void MySuperUselessClass::print() {
    cout    << "Your object contains: \n" 
            << "- an integer: " << theInt << "\n" 
            << "- a character: " << theChar << "\n"
            << "- a floating-point number: " << theDouble << "\n";
}

// PHONE DIRECTORY

struct PhoneBookEntry {
    string name;
    double phone;
};

class PhoneDirectory {
    public:
        void openPhoneDirectory();
        void listEntries();
        void callSomeone(string);
    private:
        std::vector<PhoneBookEntry> phoneBook;
};

void PhoneDirectory::openPhoneDirectory() {
    // open file
    std::ifstream ifs("phonedirectory.txt");
    if(!ifs.is_open()) {
        cerr << "error: unable to open datafile phonedirectory.txt\n";
        exit(EXIT_FAILURE);
    }

    // read data from file
    for(;;) {
        string entryName;
        ifs >> entryName;

        if(ifs.fail()) break;

        double entryPhone;
        ifs >> entryPhone;

        PhoneBookEntry entry = {entryName, entryPhone};
        phoneBook.push_back(entry);
    }
}

void PhoneDirectory::listEntries() {
    for (int i = 0; i < phoneBook.size(); ++i) {
        cout << "You can call " << phoneBook[i].name << " at this phone number: " << phoneBook[i].phone << " \n";
    }
}

void PhoneDirectory::callSomeone(string who) {
    int i = 0;

    for (; i < phoneBook.size();) {
        if (phoneBook[i].name == who) {
            cout << "Calling " << phoneBook[i].name << " ... " << phoneBook[i].phone << ". Ring, ring! \n";
            break;
        }

        ++i;
    } 

    if (i == phoneBook.size())
        cerr << who << " not found. Are you sure this is the right name?\n"; 
}

// COMPLEX NUMBERS

struct ComplexNumber {
    double realPart, imaginaryPart;
};

void printAComplexNumber(const ComplexNumber &num) {
    if (num.imaginaryPart < 0)
        cout << num.realPart << " - " << abs(num.imaginaryPart) << " i. \n";
    else
        cout << num.realPart << " + " << num.imaginaryPart << " i. \n";
}

class Complex {
    public:
        void create(const double &, const double &);
        void print();
        double norm();
        void conjugate();
        void printConjugate();
        ComplexNumber product(const ComplexNumber &);
        ComplexNumber ratio(const ComplexNumber &);
    private:
        ComplexNumber number;
        ComplexNumber conj;
};

void Complex::create(const double &re, const double &im) {
    number.realPart = re;
    number.imaginaryPart = im;
}

void Complex::print() {
    // print the value of a complex number z = a + b i to the screen in the ordinary notation a + b i.
    printAComplexNumber(number);
}

double Complex::norm() {
    // compute the norm of a complex number ||z|| = sqrt(a^2 + b^2).
    return sqrt(number.realPart * number.realPart + number.imaginaryPart * number.imaginaryPart);
}

void Complex::conjugate() {
    // compute the conjugate of a complex number z̄ = a − b i.
    conj.realPart = number.realPart;
    conj.imaginaryPart = 0.0 - number.imaginaryPart;
}

void Complex::printConjugate() {
    printAComplexNumber(conj);
}

ComplexNumber Complex::product(const ComplexNumber &othernum) {
    // calculate the product of two complex numbers (a + b i)(c + d i) = (ac − bd) + (ad + bc) i
    ComplexNumber prod;
    prod.realPart = number.realPart * othernum.realPart - number.imaginaryPart * othernum.imaginaryPart;
    prod.imaginaryPart = number.realPart * othernum.imaginaryPart + number.imaginaryPart * othernum.realPart;

    return prod;
}

ComplexNumber Complex::ratio(const ComplexNumber &othernum) {
    // calculate the ratio of two complex numbers y/z = (yz̄) / ||z||^2
    Complex newComplex;
    newComplex.create(othernum.realPart, othernum.imaginaryPart);
    conjugate();
    ComplexNumber conjProduct = newComplex.product(conj);
    const double numNorm = norm();
    ComplexNumber ratio {conjProduct.realPart / (numNorm * numNorm), conjProduct.imaginaryPart / (numNorm * numNorm)};
    
    return ratio;

}

// FARM AND COWS

class Cow {
    public:
        void feed(double);
        double produceMilk();
    private:
        double fatReserve = 0.0;
};

void Cow::feed(double food) {
    fatReserve += food;
}

double Cow::produceMilk() {
    // 5 % of the fat reserve is used for producing milk
    const double milk = 0.05 * fatReserve;
    fatReserve -= milk;
return milk;
}

class Farm {
    public:        
        void invest(const double);
        void sellCow(const int);
        void buyCow(const int);
        void buyFeed(const double);
        void sellMilk();
        bool checkCapital(const string);
        bool checkHerd();
    private:
        double perCapitaCostOfCow = 5.0;
        vector<Cow> herd;
        double money = 0.0;
};

void Farm::invest(const double investment) {
    // The farmer can invest money into the Farm to realise a positive initial value of money, 
    // sufficient to buy at least one Cow.
    if (investment < perCapitaCostOfCow)
        cout << "The farmer needs to invest more money to be able to buy a cow. Minimum " << perCapitaCostOfCow << ". \n";
    else {
        money += investment; 
        cout << "You now have " << money << " moneyzzz. \n";
    }

}

void Farm::sellCow(const int nCows) {
    // The farmer can sell a Cow from the herd at the weekly livestock market, 
    // in order to increase the value of money
    if (nCows <= herd.size()) {
        money += perCapitaCostOfCow * nCows;
        int nCowsRemaining = herd.size() - nCows;
        for (int i = herd.size() - 1; i >= nCowsRemaining; --i) {
            herd.pop_back();
        }
        cout    << "Sold " << nCows 
                << " cow(s). The herd has now " << herd.size() 
                << " cows and the farm has " << money << " moneyzz. \n";
    } else {
        cout << "Not enough cows in the herd to sell.";
    }
}

void Farm::buyCow(const int nCows) {
    // The farmer can buy a Cow at the livestock market and add it to the herd, 
    // which reduces the value of money
    if (money / perCapitaCostOfCow >= nCows) {
        money -= nCows * perCapitaCostOfCow;
        for (int i = 0; i < nCows; ++i) {
            Cow newCow;
            herd.push_back(newCow);
        }
        cout    << "The herd has now " << herd.size() 
                << " cows and the farm has " << money << " moneyzz. \n";
    } else {
        cout    << "The farm does not have enough money to buy " << nCows 
                << " cows. Invest at least " << nCows * perCapitaCostOfCow - money << ". \n";
    }       
}

void Farm::buyFeed(const double food) {
    // The farmer can use money to buy feed for the animals...
    if (food <= money) {
        money -= food;
        cout << "The farm acquired food and now has a capital of " << money << " moneyzz. Feeding cows...";
        // ... which is distributed every day among the Cow s in the herd
        double foodPerCow = food / herd.size(); 

        for (int i = 0; i < herd.size(); ++i) {
            herd[i].feed(foodPerCow);
            cout << i << ". ";
        }
    } else {
        cout    << "The farm does not have enough money to buy " << food
                << " feed. Invest at least " << food - money << ". \n";
    }
    cout << "\n"; 
}

void Farm::sellMilk() {
    double collectMilk = 0;
    cout << "Milking cows...";
    for (int i = 0; i < herd.size(); ++i) {
        // The farmer milks the Cow s everyday, 
        collectMilk += herd[i].produceMilk();
        cout << i << ". ";
    }

    // and sells the milk to make money.
    money += collectMilk;
    cout << "The farm sold " << collectMilk << " units of milk ! The capital is now of " << money << " moneyzz. \n";
}

bool Farm::checkCapital(const string whatFor) {
    bool canBuy = false;
    if (whatFor == "cow") {
        if (money / perCapitaCostOfCow > 2)
            canBuy = true;
    } else if (whatFor == "feed") {
        if (money > 2) 
            canBuy = true;
    }

    return canBuy;
}

bool Farm::checkHerd() {
    bool canSell = false;
    if (herd.size() > 8)
        canSell = true;
    
    return canSell;
}

int main() {
/*     cout << "Give me an integer number: ";
    int myInt;
    cin >> myInt;
    cout << "Give me a character: ";
    char myChar;
    cin >> myChar;

    std::pair <int, char> myPair(myInt, myChar);
    printToScreen(myPair);

    cout << "Give me a floating point number: ";
    double myDouble;
    cin >> myDouble;

    TheStructure myStructure = {myInt, myChar, myDouble};
    printToScreen(myStructure);

    MySuperUselessClass myClass;
    myClass.define(myInt, myChar, myDouble);
    myClass.print(); */

    // PHONE DIRECTORY

/*     cout << "Loading phone directory...\n";
    PhoneDirectory lookUpPhone;
    lookUpPhone.openPhoneDirectory();
    // lookUpPhone.listEntries();
    cout << "Who would you like to call? ";
    string whoToCall;
    cin >> whoToCall;
    lookUpPhone.callSomeone(whoToCall); */

    // COMPLEX NUMBERS

/*     Complex myComplex;
    myComplex.create(2.3, 6.9);
    cout << "Your complex number z is: ";
    myComplex.print();
    cout << "This complex number has a norm ||z|| = " << myComplex.norm() << "\n"; 
    myComplex.conjugate();
    cout << "Its conjugate is z* = ";
    myComplex.printConjugate();
    const ComplexNumber myOtherComplex {8.2, 5.1};
    cout << "The product of z with y = ";
    printAComplexNumber(myOtherComplex);
    cout << " is z * y = ";
    printAComplexNumber(myComplex.product(myOtherComplex));
    cout << "The ratio y / z = ";
    printAComplexNumber(myComplex.ratio(myOtherComplex));   */ 

    // FARM AND COWS

    Farm myFarm;
    // invest money into the farm:
    myFarm.invest(1.0); // should return a warning
    myFarm.invest(26.0);
    myFarm.buyCow(5);

    for (int year = 0; year < 100; ++year) {
        if (myFarm.checkCapital("cow")) {
            // Buy a cow if capital large enough 
            myFarm.buyCow(1);
        } else {
            myFarm.sellCow(1);
        }

        if (myFarm.checkCapital("feed")) {
            // Buy food and feed the cows with money
            myFarm.buyFeed(1.5);
        }

        // Milk the cows and sell the milk
        myFarm.sellMilk();
    }

    return 0;
}