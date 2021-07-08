#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class HangmanGame {
    public:
        void load(const string &);
        void setSecretWord();
        bool guess(char);
        void recycle(const string &);
        int getRemainingGuesses();
    private:
        vector<std::string> wordList;
        std::string word, correctLetters;
        int remainingGuesses;
};

void HangmanGame::load(const string &filename) {
    // open file with words list
    ifstream ifs(filename);
    if(!ifs.is_open()) {
        cerr << "error: unable to open secret words list\n";
        exit(EXIT_FAILURE);
    }

    // read from list and store words in vector
    clog << "loading secret words library from file " << filename << "... \n";
    for(int i = 0;;) {
        // read from file
        string x;
        ifs >> x;

        if(!ifs.fail()) { // add word only if read operation was successful...
            wordList.push_back(x);
            cout << "Loaded word #" << i << ".\n";
            ++i;
        } else { // otherwise:
            ifs.clear(); // clear error flags
            ifs.ignore(); // ignore next character
        }

        if(ifs.eof()) // exit when end of file has been reached
            break;
    }

    ifs.close(); // here you can see how to manually close a file
}

void HangmanGame::setSecretWord() {
    // starts a new game
    word = wordList[0];
    correctLetters.clear();
    remainingGuesses = 9;
}

bool HangmanGame::guess(char ch) {
    // processes the letter guessed by the user and provides feedback
    // returns false if no more guesses remain or the user guessed the word

    // check if the word contains the letter...
    std::string::size_type found = word.find(ch);
    if (found == std::string::npos) {
        --remainingGuesses;
        std::cout   << "Sorry, wrong guess! You have " 
                    << remainingGuesses << " guesses remaining.\n";
        if (remainingGuesses == 0) {
            std::cout << "Too bad... You lost.\n";
            return false;
        }
    } else correctLetters.push_back(ch); // ... if so, add it to the correctLetters string

    // show the word for as far as it has been guessed
    bool isSomeLettersWrong = false;
    std::cout << "\n\tGuessed so far: ";
    for (int i = 0; i < word.size(); ++i) {
        found = correctLetters.find(word[i]);
        if (found == std::string::npos) {
            isSomeLettersWrong = true;
            std::cout << '.';
        } else std::cout << word[i];
    }
    
    if (!isSomeLettersWrong) {
        cout << "\n\nCongratulations! You guessed the word."; 
    } else {
        cout << "\n\nPlease try again. ";
    }

    return isSomeLettersWrong;
}

void HangmanGame::recycle(const string &filename) {
    if (getRemainingGuesses() > 0) {
        cout << " Please give us a new word to add to our list of secret words: ";
        string addANewWord;
        cin >> addANewWord;

        // Put the guessed word at the end of the list
        string guessedWord = wordList[0];
        wordList.push_back(guessedWord);

        // Add the new word in place of the guessed word
        wordList[0] = addANewWord;
    }
    
    vector<string> newTmpList = wordList;
    int i = 0;

    for (; i < wordList.size() / 2 - 1; ++i) {
        newTmpList[i] = wordList[i + 1];
    }

    newTmpList[i] = wordList[0];
    wordList = newTmpList;   

    ofstream ofs(filename); 
    if(!ofs.is_open()) {
        std::cerr << "error: unable to open word library file\n";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < wordList.size(); ++i) {
        ofs << wordList[i] << "\n";
    }
}

// int getRemainingGuesses() const {return remainingGuesses;} // For some reason this doesn't work,
    // though it was copied directly from Sander's tutorial
int HangmanGame::getRemainingGuesses() {
    return remainingGuesses;
}

int main() {
    // declare HangmanGame object and set secret word
    HangmanGame hangman;
    hangman.load("hangman_words.txt");
    hangman.setSecretWord();

    // start game
    char ch;
    do {
        std::cout << "Enter a letter to guess the secret word : ";
        std::cin >> ch;
    } while (hangman.guess(ch));

    hangman.recycle("hangman_words.txt");

    return 0;
}