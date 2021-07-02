#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// Looping through the alphabet. 
/* Look up an ASCII table on the internet and verify that the letters of the alphabet are listed on consecutive positions in the table. 
Exploit this fact to write a loop that prints all letters of the alphabet. */

// Converting between upper- and lowercase letters. 
/* The functions tolower() and toupper(), respectively, which are defined in the C-library header cctype, 
convert uppercase letters to lowercase and vice-versa. Code your own version of these functions. */

// DNA transcription. 
/* Write a function that takes as argument an (antisense) DNA sequence (written in the 5’ to 3’ direction in a std::string object), 
and that returns the RNA sequence transcribed from it (also written in the 5’ to 3’ direction in a std::string object). 
To test your program, apply the function to a short sequence, such as CGTCACAGATTAAGGTATACCATT and print the result to the screen. */

void alphabet() {
    char letter;
    for (int i = 65; i < 91; ++i) {
        letter = i;
        cout << letter << "\n";
    }
}

void tolower(char &letter) {
    letter += 32; 
}

void toupper(char &letter) {
    letter -= 32;
}

std::string transcribe(const std::string &dna) {
    // A -> U, T -> A, C -> G, G -> C

    std::string rna;

    for (int i = 0; i < dna.size(); ++i) {
        switch (dna[i]) {
            case 65:
                rna.push_back(85);
                break;
            case 84:
                rna.push_back(65);
                break;
            case 67:
                rna.push_back(71);
                break;
            case 71:
                rna.push_back(67);
            default:
                cout << "Invalid dna strand. Input data as ATCG\n";
        }
    }

    return rna;
}

int main() {

    /* alphabet(); // uncomment to print the alphabet */

/*     cout << "Enter an UPPER CASE letter: \n";
    char upperToLower;
    cin >> upperToLower;
    tolower(upperToLower);
    cout << upperToLower << "\n";

    cout << "Enter a LOWER CASE letter: \n";
    char lowerToUpper;
    cin >> lowerToUpper;
    toupper(lowerToUpper);
    cout << lowerToUpper << "\n"; */

    const std::string myDNAStrand = "CGTCACAGATTAAGGTATACCATT";
    cout << "CGTCACAGATTAAGGTATACCATT transcribes as: " << transcribe(myDNAStrand) << "\n";

    return 0;
}