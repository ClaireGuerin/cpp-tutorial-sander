#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class NeighborJoin {
    public:
        void loadMatrix();
        bool findNode();
        void printTree();
    private:
        int nSpecies;
        vector<string> species;
        vector<vector<double> > matrix;
};

void NeighborJoin::loadMatrix() {
    // open input file

    ifstream ifs("distance_matrix.txt");
    if (!ifs.is_open()) {
        cerr << "error: unable to open data file\n";
        exit(EXIT_FAILURE);
    }

    // read number of species
    clog << "loading distance matrix... \n";
    ifs >> nSpecies;

    if(ifs.fail()) { // if read operation not successful...
        ifs.clear(); // clear error flags
        ifs.ignore(); // ignore, next character
    }

    cout << nSpecies << " species: \n";
    
    // read all species names

    for (int i = 0; i < nSpecies;) {
        string sp;
        ifs >> sp;

        if(!ifs.fail()) {
            ++i;
            species.push_back(sp);
            cout << sp << " ";
        } else { // if read operation not successful...
            ifs.clear(); // clear error flags
            ifs.ignore(); // ignore, next character
        } 
    }

    cout << "\n";
            
    // read distance matrix

    for (int i = 0; i < nSpecies;) {
        
        bool eof = false;

        vector<double> row;

        for (int j = 0; j < nSpecies;) {
            // read from file
            double x;
            ifs >> x;

            if(!ifs.fail()) { // add data point if read operation was successful...
                ++j;
                row.push_back(x);
                cout << x << " ";
            } else { // otherwise:
                ifs.clear(); // clear error flags
                ifs.ignore(); // ignore next character
            }
        }
        
        ++i; 
        matrix.push_back(row); 
        cout << "\n";     
    }

    ifs.close(); // here you can see how to manually close a file


}

bool NeighborJoin::findNode() {
    
    // Collect total distances for each species

    vector<double> sumPerSpecies;

    for (int i = 0; i < nSpecies; ++i) {
        double rowSum =  0;

        for (int j = 0; j < nSpecies; ++j) {
            rowSum += matrix[i][j];
        }

        sumPerSpecies.push_back(rowSum);
    }


    // Calculate Q values:
    // Q(i, j) = (n − 2) D(i, j) − sum_k^n (D(i, k)) - sum_k^n (D(j, k))
    // and find minimum

    pair<int, int> minQ (1, 0);

    cout << "Q matrix: \n";
    for (int i = 0; i < nSpecies - 1; ++i) {

        for (int j = i + 1; j < nSpecies; ++j) {

            matrix[j][i] = (nSpecies - 2) * matrix[i][j] - sumPerSpecies[i] - sumPerSpecies[j];
            cout << matrix[j][i] << " ";

            if (matrix[j][i] < matrix[minQ.first][minQ.second]) {
                minQ.first = j;
                minQ.second = i;
            }
        }
        cout << "\n";
    }

    cout << "minimum Q at f = " << minQ.first << ", g = " << minQ.second << "\n";

    // create new node (u, to be formally named in Newick convention: (a:Dau,b:Dbu) ) and calculate distance to this node for each species

    vector<double> distanceToNode (nSpecies); // distance between u and each k species
    double distanceIJ;
    // find distance between f and g
    distanceIJ = (minQ.first > minQ.second) ? matrix[minQ.second][minQ.first] : matrix[minQ.first][minQ.second]; 

    // calculate distance between u and joined species f and g 
    distanceToNode[minQ.first] = 0.5 * ( distanceIJ + (sumPerSpecies[minQ.first] - sumPerSpecies[minQ.second]) / (nSpecies - 2.0) );
    distanceToNode[minQ.second] = distanceIJ - distanceToNode[minQ.first];

    vector<int> keepSpecies;
    
    for(int k = 0; k < nSpecies; ++k) {

        if (k != minQ.first && k != minQ.second) {

            // keep the positions of remaining species, without f or g
            keepSpecies.push_back(k);

            double dik = (k > minQ.first) ? matrix[minQ.first][k] : matrix[k][minQ.first];
            double djk = (k > minQ.second) ? matrix[minQ.second][k] : matrix[k][minQ.second];
            distanceToNode[k] = 0.5 * (dik + djk - distanceIJ);
        }
    }

    
    // Print distances to node
    cout << "distance between species and node: ";
    for (int k = 0; k < nSpecies; ++k) {
        cout << distanceToNode[k] << " ";
    }
    cout << "\n keep species: ";

    for (int k = 0; k < keepSpecies.size(); ++k) {
        cout << keepSpecies[k] << " ";
    }
    cout << "\n";

    // Initialize new matrix with zeroes
    vector<vector<double> > updateMatrix;

    for (int i = 0; i < keepSpecies.size() + 1; ++i) { // add one to account for the additional node, u.
        vector<double> row;

        for (int j = 0; j < keepSpecies.size() + 1; ++j) { // add one to account for the additional node, u.
            row.push_back(0.0);
        }

        updateMatrix.push_back(row);
    }


    vector<string> newSpecies;

    for (int i = 0; i < keepSpecies.size(); ++i) {
        int formerI = keepSpecies[i];
        newSpecies.push_back(species[formerI]);

        for (int j = i + 1; j < keepSpecies.size() + 1; ++j) {

            if (j == keepSpecies.size()) { // if species j is actually node u:
                // distance data is distance between species i and node u
                updateMatrix[i][j] = updateMatrix[j][i] = distanceToNode[formerI];
                // cout << "distance species " << formerI << " - node = " << distanceToNode[formerI] << "\n";
            } else {
                int formerJ = keepSpecies[j];
                updateMatrix[i][j] = updateMatrix[j][i] = matrix[formerI][formerJ];
            }
        }
    }

    // Update species names

    ostringstream oss;
    oss << "("  << species[minQ.first] + ":" << distanceToNode[minQ.first] << "," 
                << species[minQ.second] << ":" << distanceToNode[minQ.second] << ")";
    string nodeName = oss.str();

    newSpecies.push_back(nodeName);
    species = newSpecies;

    // Update species number and matrix

    --nSpecies;
    bool isComplete = nSpecies == 3;
    matrix = updateMatrix;

    // print the new matrix to make sure

    cout << "new matrix \n";
    for (int k = 0; k < nSpecies; ++k) {
        cout << species[k] << " ";
    }
    cout << "\n";

    for (int i = 0; i < nSpecies; ++i) {
        for (int j = 0; j < nSpecies; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return isComplete;
}

void NeighborJoin::printTree() {
    double dist0 = 0.5 * (matrix[1][0] + matrix[2][0] - matrix[2][1]); 
    double dist1 = 0.5 * (matrix[1][0] + matrix[2][1] - matrix[2][0]);
    double dist2 = 0.5 * (matrix[2][0] + matrix[2][1] - matrix[1][0]);

    // Full tree in Newick representation: (label[0]:d 0 ,label[1]:d 1 ,label[2]:d 2 );
    ostringstream oss;
    oss << "("  << species[0] << ":" << dist0 << ","
                << species[1] << ":" << dist1 << ","
                << species[2] << ":" << dist2 << ");\n";

    string tree = oss.str();
    cout << tree;
}

int main() {

    NeighborJoin tree;
    tree.loadMatrix();

    int it = 0;
    do
    {
        cout << "iteration " << it << "\n";
        ++it;
    } while (!tree.findNode());

    cout << "Tree complete: ";
    tree.printTree();
    
    return 0;
}