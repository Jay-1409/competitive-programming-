#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPermutation(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != i + 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for (int times = 0; times < t; times++) {
        int size;
        cin >> size;

        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        int swaps = 0;
        for (int i = 0; i < size; i++) {
            while (arr[i] != i + 1) {
                swap(arr[i], arr[arr[i] - 1]);
                swaps++;
            }
        }

        if (swaps % 2 == 0 || isPermutation(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
