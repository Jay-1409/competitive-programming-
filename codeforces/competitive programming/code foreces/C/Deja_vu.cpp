#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;//Number of tests
    cin >> t;
    for(int times=0;times<t;times++) {
        int n, q;//Lenghts of the array
        cin >> n >> q;
        int a[n];
        int x[q];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < q; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < q; i++) {
            int expo=(int)pow(2, x[i]);
            int add = (int)pow(2, x[i] - 1);
            for (int j = 0; j < n; j++) {
                if (a[j] % expo == 0) {
                    a[j] = a[j]+add;
                }
            }
        }
        
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
    
    return 0;
}