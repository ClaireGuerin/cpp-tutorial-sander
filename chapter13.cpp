#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>

class Individual {
    public:
        Individual(double);
        bool giveUp() const;
        int operator*(Individual&);
        friend int fight2(Individual&, Individual&);
    private:
        int k, n;
        const double rhp;
};

Individual::Individual(double RHP) : rhp (RHP) {
    k = 2; 
    n = 4; 
}

bool Individual::giveUp() const {
    if(n == 0)
        return false; // IN THE BEGINNING, no one gives up
    else {
        double p = static_cast<double> (k) / n;
        return p + 2.0 * sqrt(p * (1.0 - p) / n) < 0.5; // give up if proba to win too low, don't otherwise
    }
}

int Individual::operator*(Individual &opponent) {
    if(giveUp()) 
        return opponent.giveUp() ? 0 : -1;  // if you give up and so does your opponent, you get 0 points
                                            // else if you give up but not your opponent, you get -1 points
    else {
        if(opponent.giveUp()) return +1; // if you don't give up but your opponent does, you get +1 points
        else { // if none of you give up
            if (n > 25) n, k = 0; // if you exceeded the number of rounds you can remember
            if (opponent.n > 25) opponent.n, opponent.k = 0;
                
            ++n; // you go to next round
            ++opponent.n; // your opponent goes to next round
            if(std::rand() < RAND_MAX * rhp / (rhp + opponent.rhp)) ++k; // if you win stochastically based on relative force, increment own wins
            else ++opponent.k; // if you lose, increment opponent's wins
            return 0; // no one wins the whole battle yet, everyone gets zero points
        }
    }
}


int fight2(Individual &ind1, Individual &ind2) {
    if (ind1.giveUp())
        return ind2.giveUp() ? 0 : -1;

    else {
        if (ind2.giveUp()) return +1;
        else {
            ++ind1.n;
            ++ind2.n;
            if (std::rand() < RAND_MAX * ind1.rhp / (ind1.rhp + ind2.rhp)) ++ind1.k;
            else ++ind2.k;
            return 0;
        }
    }
}

int main() {
    std::srand(5); // seed random number generator
    Individual A(0.80), B(0.85), C(0.90), D(0.95), E(1.00);
    std::vector<Individual> group {A, B, C, D, E};
    std::vector<std::string> fightingBoardHeaders   {"A>B", "A>C", "A>D", "A>E", "B>C", 
                                                     "B>D", "B>E", "C>D", "C>E", "D>E"};
    std::vector<int> fightingBoardCounts {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int iter = 0; iter < 1000; ++iter) {
        int pointToBoard = 0;

        for (int opponent1 = 0; opponent1 < group.size() -1; ++opponent1) {
            for (int opponent2 = opponent1 + 1; opponent2 < 5; ++opponent2) {
                int outcome = group[opponent1] * group[opponent2];
                fightingBoardCounts[pointToBoard] += outcome;
                ++pointToBoard;
            }
        }
    }

    for (int pair = 0; pair < fightingBoardCounts.size(); ++pair) {
        std::cout << fightingBoardHeaders[pair] << ": " << fightingBoardCounts[pair] << "\n";
    }
    
    return 0;
}