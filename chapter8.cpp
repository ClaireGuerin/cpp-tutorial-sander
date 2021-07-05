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

// RNA translation.
/* Extend your solution to the previous exercise with a function that can read an RNA sequence, 
and that lists the separate codons that it contains, starting from the start codon (AUG), until a stop codon (UAG, UGA or UAA) is encountered. */

void alphabet() {
    for (char letter = 65; letter < 91; ++letter) {
        cout << letter << "\n";
    }
}

void tolower(char &letter) {
    letter += 32; 
}

void toupper(char &letter) {
    letter -= 32;
}

std::string transcribeAntiSense(const std::string &dna) {
    // A -> U, T -> A, C -> G, G -> C

    std::string rna;

    for (int i = dna.size() - 1; i >= 0 ; --i) {
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
                break;
            default:
                cout << "Warning: skipping invalid dna character: " << dna[i] << " (position " << i << ") \n";
        }
    }

    return rna;
}

std::string translate(const std::string &rna) {

    std::string prot;
    int startPos;

    // find start codon (AUG):

    for (int i = 0; i < rna.size() - 3; ++i) {
        if (rna.substr(i, 3) == "AUG") {
            startPos = i;
            break;
        } 
    }

    // List codons until stop codon (UAG, UGA or UAA)

    for (int i = startPos; i <= rna.size() - 3; i += 3) {
        std::string codon = rna.substr(i, 3);
        std::string codonStart2 = rna.substr(i,2);
        char aa;

        if (codon == "UUU" || codon == "UUC") 
            aa = 'F';
        else if (codon == "UUA" || codon == "UUG" || codonStart2 == "CU")
            aa = 'L';
        else if (codonStart2 == "AU" && codon.back() != 'G')
            aa = 'I';
        else if (codon == "AUG")
            aa = 'M';
        else if (codonStart2 == "GU")
            aa = 'V';
        else if (codonStart2 == "UC" || codon == "AGU" || codon == "AGC")
            aa = 'S';
        else if (codonStart2 == "CC")
            aa = 'P';
        else if (codonStart2 == "AC")
            aa = 'T';
        else if (codonStart2 == "GC")
            aa = 'A';
        else if (codon == "UAU" || codon == "UAC")
            aa = 'Y';
        else if (codon == "CAU" || codon == "CAC")
            aa = 'H';
        else if (codon == "CAA" || codon == "CAG")
            aa = 'Q';
        else if (codon == "AAU" || codon == "AAC")
            aa = 'N';
        else if (codon == "AAA" || codon == "AAG")
            aa = 'K';
        else if (codon == "GAU" || codon == "GAC")
            aa == 'D';
        else if (codon == "GAA" || codon == "GAG")
            aa = 'E';
        else if (codon == "UGU" || codon == "UGC")
            aa = 'C';
        else if (codon == "UGG")
            aa = 'W';
        else if (codonStart2 == "CG" || codon == "AGA" || codon == "AGG")
            aa = 'R';
        else if (codonStart2 == "GG")
            aa = 'G';
        else if (codon == "UAG" || codon == "UGA" || codon == "UAA" ) {
            aa = '.';
            break;
        } else
            aa = '?';        

        prot.push_back(aa);
    }

    return prot;
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
    // const std::string myDNAStrand = "ATAGCGCGGGTGAGAGGGTAATCAGCCGTGTCCACCAACACAACGCTATCGGGCGATTCTATAAGATTCC";
    cout << myDNAStrand << " (" << myDNAStrand.size() << " bp) transcribes as: \n" << transcribeAntiSense(myDNAStrand) 
        << " and translates as: \n" << translate(transcribeAntiSense(myDNAStrand)) << "\n";

    return 0;
}