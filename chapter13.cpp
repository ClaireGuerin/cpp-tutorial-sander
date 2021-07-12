#include <cstdlib>
#include <cmath>
#include <iostream>

class Individual {
    public:
        Individual(double);
        bool giveUp();
        int fight1 (Individual&);
    private:
        int k, n;
        const double rhp;
};

Individual::Individual(double RHP) : rhp (RHP) {
    k = 2; 
    n = 4; 
}

bool Individual::giveUp() {
    if(n == 0)
        return false; // IN THE BEGINNING, no one gives up
    else {
        double p = static_cast<double> (k) / n;
        return p + 2.0 * sqrt(p * (1.0 - p) / n) < 0.5; // give up if proba to win too low, don't otherwise
    }
}

int Individual::fight1(Individual &opponent) {
    if(giveUp()) 
        return opponent.giveUp() ? 0 : -1;  // if you give up and so does your opponent, you get 0 points
                                            // else if you give up but not your opponent, you get -1 points
    else {
        if(opponent.giveUp()) return +1; // if you don't give up but your opponent does, you get +1 points
        else { // if none of you give up
            ++n; // you go to next round
            ++opponent.n; // your opponent goes to next round
            if(std::rand() < RAND_MAX * rhp / (rhp + opponent.rhp)) ++k; // if you win stochastically based on relative force, increment own wins
            else ++opponent.k; // if you lose, increment opponent's wins
            return 0; // no one wins the whole battle yet, everyone gets zero points
        }
    }
}

int main() {
    std::srand(5); // seed random number generator
    Individual A(1.0), B(0.95);

    int outcome;
    do {
        outcome = A.fight1(B);
        std::cout << outcome << '\n';
    } while(outcome == 0);
    
    return 0;
}