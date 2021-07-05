#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// Practising file I/O - part 1. 
/* Prepare a file measurements.txt containing a list of 20 arbitrary floating point values 
(e.g. paste some values from a spreadsheet into a simple text editor and save the result as a .txt file). 
Next, write a C ++ program that opens the file, reads in the values and displays them on the screen. */

// Practising file I/O - part 2. 
/* Extend your solution of the previous exercise in two steps. 
First replace a few numbers in your .txt input file by the character code NA to represent missing values, 
and adjust the .cpp code to correctly deal with these elements in the input file. 
Next, adjust the program to allow the user to specify the name of the input file as a command-line argument. 
Make sure the program is terminated correctly if no file name is provided. */

// Practising file I/O - part 3. 
/* Building on your solution to the previous exercises, write a program that reads in a list of floating point values x_i from a file 
and that replaces them by values y_i that are scaled between 0 and 1 as follows: 

y_i = (x_i − min(x)) / (max(x) − min(x))

Here, min(x) is equal to the smallest of the x_i and max(x) is equal to the largest.
*/

void readFile(const std::string &fileName) {
    // open file with measurement data
    std::ifstream ifs(fileName);
    if(!ifs.is_open()) {
        std::cerr << "error: unable to open data file\n";
        exit(EXIT_FAILURE);
    }

    // read input data
    std::clog << "reading parameters from file " << fileName << "... \n";
    for(int iN = 0;;) {
        // read from file
        double x;
        ifs >> x;

        if(!ifs.fail()) { // add data point if read operation was successful...
            ++iN;
            cout << "Value " << iN << " = " << x << "\n";
        } else { // otherwise:
            ifs.clear(); // clear error flags
            ifs.ignore(); // ignore next character
        }

        if(ifs.eof()) // exit when end of file has been reached
            break;
    }

    ifs.close(); // here you can see how to manually close a file
}

double max(const vector<double> &vec) {
    double elem = vec[0];

    for (int i = 1; i < vec.size(); ++i) {
        if (elem < vec[i]) {
            double tmpElem = vec[i];
            elem = tmpElem;
        }

    }

    return elem;
}

double min(const vector<double> &vec) {
    double elem = vec[0];

    for (int i = 1; i < vec.size(); ++i) {
        if (elem > vec[i]) {
            double tmpElem = vec[i];
            elem = tmpElem;
        }

    }

    return elem;
}

void fromXToY(const std::string &fileName) {
    // open file with x_i data
    std::ifstream ifs(fileName);
    if(!ifs.is_open()) {
        std::cerr << "error: unable to open data file\n";
        exit(EXIT_FAILURE);
    }

    vector<double> xValues;

    // read input data (x_i)
    for(int iN = 0;;) {
        // read from file
        double x;
        ifs >> x;

        if(!ifs.fail()) { // add data point if read operation was successful...
            ++iN;
            xValues.push_back(x);
        } else { // otherwise:
            ifs.clear(); // clear error flags
            ifs.ignore(); // ignore next character
        }

        if(ifs.eof()) // exit when end of file has been reached
            break;
    }

    // vector<double> yValues;
    for (int i = 0; i < xValues.size(); ++i) {
        double y = (xValues[i] - min(xValues)) / (max(xValues) - min(xValues));
        cout << i << ") For value x = " << xValues[i] << ", y = " << y << "\n";
    }

    ifs.close(); // here you can see how to manually close a file
}

int main(int argc, char* argv[]) {

    std::clog << "starting program " << argv[0] << "... \n";

    // extract parameter file name from program arguments or use default
    std::string parameterFileName ("default_parameters.txt");
    if(argc > 1)
        parameterFileName = argv[1];

    // readFile(parameterFileName);
    fromXToY(parameterFileName);

// read parameters from parameterfile

    // readFile("measurements.txt");

    return 0;
}