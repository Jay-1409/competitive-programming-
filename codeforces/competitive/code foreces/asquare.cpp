#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
int t;
cin>>t;
while (t--)
{
    vector<int> x(4);
    int temp;
    cin>>x[0];
        cin>>temp;
        cin>>x[1];
    cin>>temp;
        cin>>x[2];
        cin>>temp;
    cin>>x[3];
        cin>>temp;
    
    
    sort(x.begin(),x.end());
    
    cout<<(x[0]-x[2])*(x[0]-x[2])<<endl;

}

return 0;
}