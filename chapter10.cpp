#include <iostream>
#include <fstream>
#include <vector>
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

int main() {
    cout << "Give me an integer number: ";
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
    myClass.print();

    // PHONE DIRECTORY

    cout << "Loading phone directory...\n";
    PhoneDirectory lookUpPhone;
    lookUpPhone.openPhoneDirectory();
    // lookUpPhone.listEntries();
    cout << "Who would you like to call? ";
    string whoToCall;
    cin >> whoToCall;
    lookUpPhone.callSomeone(whoToCall);
    

    return 0;
}