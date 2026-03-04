#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    int n;
    cin >> n;
    int loc=1;
    for(int i=1;i<=n;i++){
    int sum = 0;
        for(int j=0;j<i;j++){
            sum=sum+loc;
            loc++;
        }
        v.push_back(sum);
    }
    cout<< v.back() << endl;
}
