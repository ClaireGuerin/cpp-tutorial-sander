#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

// Practising file I/O - part 1. 
/* Prepare a file measurements.txt containing a list of 20 arbitrary floating point values 
(e.g. paste some values from a spreadsheet into a simple text editor and save the result as a .txt file). 
Next, write a C ++ program that opens the file, reads in the values and displays them on the screen. */

void readFile(const std::string fileName) {
    // open file with measurement data
    std::ifstream ifs(fileName);
    if(!ifs.is_open()) {
        std::cerr << "error: unable to open data file\n";
        exit(EXIT_FAILURE);
    }

    // read input data
    for(int iN = 0;; ++iN) {
        // read from file
        double x;
        ifs >> x;
        cout << "Value " << iN << " = " << x << "\n";

        // add data point
        // ++iN;

        if(ifs.eof()) // exit when end of file has been reached
            break;
    }

    ifs.close(); // here you can see how to manually close a file
}

int main() {

    readFile("measurements.txt");
    return 0;
}