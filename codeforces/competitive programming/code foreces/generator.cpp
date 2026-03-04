#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void generateTestCases() {
    ofstream outputFile("input.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening file 'input.txt'!" << endl;
        return;
    }

    int n = 100000000; // Length of casserole
    int k = 100000; // Number of pieces

    // Initialize pieces vector with k-1 pieces set to 9
    vector<int> pieces(k - 1, 9);

    // Calculate the last piece to ensure the sum equals n
    int sum_of_nines = (k - 1) * 9;
    int last_piece = n - sum_of_nines;
    pieces.push_back(last_piece);

    // Writing to file
    outputFile << n << " " << k << endl;
    for (int j = 0; j < k; ++j) {
        outputFile << pieces[j];
        if (j != k - 1)
            outputFile << " ";
    }
    outputFile << endl;

    outputFile.close();
    cout << "Test case generated and stored in input.txt." << endl;
}

int main() {
    generateTestCases();
    return 0;
}
