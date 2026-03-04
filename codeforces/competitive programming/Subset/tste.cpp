#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to generate and output beautiful test cases
void generate_beautiful_test_cases() {
    const int max_side_length = 140;  // 140x140 matrix is the largest square matrix fitting within 2 * 10^5
    const int max_length = max_side_length * max_side_length;
    const int t = 50;  // Number of test cases

    cout << t << endl;  // Output the number of test cases

    for (int _ = 0; _ < t; ++_) {
        // Construct a beautiful binary matrix of size max_side_length x max_side_length
        vector<string> matrix(max_side_length);
        for (int i = 0; i < max_side_length; ++i) {
            if (i == 0 || i == max_side_length - 1) {
                // First and last rows are all 1s
                matrix[i] = string(max_side_length, '1');
            } else {
                // Inner rows: first and last elements are 1s, others are 0s
                matrix[i] = '1' + string(max_side_length - 2, '0') + '1';
            }
        }
        
        // Convert matrix to a single string
        string s;
        for (const auto& row : matrix) {
            s += row;
        }
        
        // Output the test case
        cout << max_length << endl;
        cout << s << endl;
    }
}

int main() {
    generate_beautiful_test_cases();
    return 0;
}
