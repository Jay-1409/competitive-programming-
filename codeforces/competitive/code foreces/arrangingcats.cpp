    #include<iostream>
    #include<vector>
    using namespace std;
    int countCats(string s,int n){
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
        } 
        return count;
    }
    void solve(){
        int n; cin >> n;
        string arro,arrf;
        cin>>arro; cin>> arrf;
        int counto=countCats(arro,n);
        int countn=countCats(arrf,n);
        int count=0;
        if(counto>=countn){
            int diff=abs(counto-countn);
            count=diff;
            for(int i=0;i<n;i++){
                if(arrf[i]=='1'){
                    if(arro[i]=='0'){
                        count++; //making 0 --> 1
                    }
                }
            }
        } else if(counto<=countn){
            int diff=abs(counto-countn);
            count=diff;
            for(int i=0;i<n;i++){
                if(arrf[i]=='0'){
                    if(arro[i]=='1'){
                        count++;//making 1-->0
                    }
                }
            }
        }
        cout << count << endl;
    }
int main(){
    int t; 
    cin >> t;
    cin.ignore(); 
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}
