#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int count(string s,string target){
    int occurrences=0;
    std::string::size_type pos = 0;
    int i=0;
   while ((pos = s.find(target, pos )) != std::string::npos) {
          ++ occurrences;
          pos += target.length();
   }
   return occurrences;
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string s1="pie";
    string s2="map";
    int c1=count(s,s1);
    int c2=count(s,s2);
    int c3=count(s,"mapie");
    cout<<c1+c2-c3<<endl;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}