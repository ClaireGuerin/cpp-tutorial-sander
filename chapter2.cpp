#include <iostream>

double mokka() {
    // declaration of variables
    double dWeightCaffeine;
    const double dWeightC = 12.011, dWeightH = 1.008, dWeightN = 14.007, dWeightO = 15.999;
    // calculation of molecular weight of 1,3,7-trimethylpurine-2,6-dione (C8H10N4O2)
    dWeightCaffeine = 8 * dWeightC + 10 * dWeightH + 4 * dWeightN + 2 * dWeightO;
    return dWeightCaffeine;
}

int main() {
    // generate output
    std::cout << "1,3,7-Trimethylpurine-2,6-dione (caffeine) weighs " << mokka() << " g/mol." << std::endl;
    // terminate program
    return 0;
}