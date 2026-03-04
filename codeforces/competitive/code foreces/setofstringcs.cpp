#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <bits/stdc++.h>
using namespace std;
#define rev(x) reverse(all(x))
#define s0rt(x) sort(all(x))
#define s0rtd(x) sort(all(x)), rev(x);
#define s0rtx(x, ...) sort(all(x), __VA_ARGS__);
#define s9m(x) accumulate(all(x), 0ll)
#define len(x) (long long)(x.size())
#define mine(v) *min_element(all(v))
#define maxe(v) *max_element(all(v))
#define unq(x) s0rt(x), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define FOR1(a) for (int _ = 0; _ < (a); ++_)
#define FOR2(i, a) for (int i = 0; i < (a); ++i)
#define FOR3(i, a, b) for (int i = a; i < (b); ++i)
#define FOR4(i, a, b, c) for (int i = a; i < (b); i += (c))
#define FOR5(i, a, condn, b, add) for (int i = a; condn < b; i += add)
#define FOR1_R(a) for (int _ = (a); _ >= (0); --_)
#define FOR2_R(i, a) for (int i = (a); i >= (0); --i)
#define FOR3_R(i, a, b) for (int i = (a); i >= (b); --i)
#define FOR4_R(i, a, b, c) for (int i = (a); i >= (b); i -= c)
#define FOR5_R(i, a, condn, b, add) for (int i = (a); condn >= (b); i -= add)
#define TRAV1(i, a) for (auto &i : a)
#define TRAV2(i, j, a) for (auto &[i, j] : a)
#define LB1(x, y) lower_bound(all(x), y)
#define UB1(x, y) upper_bound(all(x), y)
#define LB2(x) lower_bound(x)
#define UB2(x) upper_bound(x)
#define CNT1(x, y) count(all(x), y)
#define cnt2(x) count(x)
#define overload5(a, b, c, d, e, f, ...) f
#define overload2(a, b, c, d, ...) d
#define overload1(a, b, c, ...) c
#define f0r(...) overload5(__VA_ARGS__, FOR5, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define f0rd(...) overload5(__VA_ARGS__, FOR5_R, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define trav(...) overload2(__VA_ARGS__, TRAV2, TRAV1)(__VA_ARGS__)
#define lb(...) overload1(__VA_ARGS__, LB1, LB2)(__VA_ARGS__)
#define ub(...) overload1(__VA_ARGS__, UB1, UB2)(__VA_ARGS__)
#define c0unt(...) overload1(__VA_ARGS__, CNT1, CNT2)(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define ep emplace
#define ins insert
#define ers erase
#define beg begin()
#define ed end()
#define back back()
#define mkp make_pair
#define f first
#define s second
#define yes "YES"
#define no "NO"
#define fun(type, name, ...) auto name = [&](__VA_ARGS__) -> type
#define recfun(type, name, ...) auto name = [&](auto &&name, __VA_ARGS__) -> type

/*******  All Required define Pre-Processors and typedef Constants *******/
#include <cstdio>
#define pfd(format, ...) printf(format, __VA_ARGS__)
#define pfld(format, ...) printf(format, __VA_ARGS__)
#define pflld(format, ...) printf(format, __VA_ARGS__)
#define pfc(c) printf("%c", c)
#define pfs(s) printf("%s", s)
#define pff(f) printf("%f", f)
#define pflf(f) printf("%lf", f)
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
//mOre use full functions.. ig.. 
template<typename T>
void remDup(std::vector<T> &v) {
    std::sort(v.begin(), v.end()); // Sort the vector
    v.erase(std::unique(v.begin(), v.end()), v.end()); // Remove duplicates
}
int BinarytoDecimal(long long int n){
long long int num = n;
long long int dec_value = 0;
long long int base = 1;
long long int temp = num;
while (temp) {
    long long int last_digit = temp % 10;
    temp = temp / 10;
    dec_value += last_digit * base;
    base = base * 2;
}
return dec_value;
}
// Input macros
#define INT(...) int __VA_ARGS__; read(__VA_ARGS__);
#define LONG(...) long long __VA_ARGS__; read(__VA_ARGS__);
#define STRING(...) string __VA_ARGS__; read(__VA_ARGS__);
#define VEC(type, name, size) vector<type> name(size); read(name);
#define VEC2D(type, name, n, m) vector<vector<type>> name(n, vector<type>(m)); read(name);
// Utility functions
template<typename T>
void read(T& x) { cin >> x; }
template<typename T>
void read(vector<T>& v) { for (auto& i : v) cin >> i; }
template<typename T>
void print(const T& x) { cout << x; }
template<typename T>
void print(const vector<T>& v) { for (const auto& i : v) cout << i << endl; }
int mex(vector<int> &arr, int N)
{
  sort(arr.begin(), arr.end());

  int mex = 0;
  for (int idx = 0; idx < N; idx++)
  {
    if (arr[idx] == mex)
    {
      mex += 1;
    }
  }

  return mex;
}
int isSubstring(string s1,string s2){
// using find method to check if s1 is
// a substring of s2
if (s2.find(s1) != string::npos)
    return s2.find(s1);
return -1;
}
bool isSubsequence(string s1, string s2) {
//s1 is a subsequence of s2 ?
int index = -1;
for (char c : s1) {
index = s2.find(c, index + 1);
if (index == string::npos) {
return false;
}
}
return true;
}

void solve(){
    int k; cin >> k;
    string x; cin >> x;
    int n = len(x);
    map<char,bool> mp;
    string cur="";
    vector<string> f;
    if(k == 1){
        cout << x << endl;
        return;
    }
    f0r(i,n-1){
        cur+=x[i];
        if(x[i] != x[i+1] && mp[x[i]] == false && k>0){
            mp[x[i]] = true;
            while(mp[x[i]] == false){
                i++;
                cur += x[i];
            }
            k--;
            f.pb(cur);
            cur= "";
        }else if(k == n - 1){
            if(mp[x[i]] == false){
                f.pb(cur);
                mp[x[i]] = true;
                cur = "";
                k--;
            }else{
                f[len(f) - 1] += x[i];
            }
        }
    }
    f[len(f) - 1] += x[len(x) - 1];
    if(k <= 0){
        cout << yes << endl;
        print(f);
    }else{
        cout << no << endl;
    }
}


void solve3(){
    int k; cin >>  k;
    string x; cin >> x;
    int n = len(x);  
    if(k == 1){
        cout << yes << endl;
        cout << x << endl; return;
    } else{
        map<char,bool> mp;
        string cur(1,x[0]);
        mp[x[0]] = true;
        vector<string> ans;
        ans.pb(cur);
        f0r(i,1,n){
                while(mp[x[i+1]] == false && i<n){i++;cur+=x[i+1];}
            if(mp[x[i]] == false){
                mp[x[i]] = true; 
                ans.pb(cur);
                cur = "";
                cur+=x[i];
            }
        }
        if(len(ans)>=k){
            cout<<yes<<endl;
            int cnt=0;
            string temp="";
            f0r(i,len(ans)){
                if(i<k){
                    cout << ans[i] << endl;
                }else{
                    temp+=ans[i];
                }
            }
            cout<<temp<<endl;
        }else{
            cout<<no<<endl;
        }
    }
}
void solvew(){
    int k; cin >>  k;
    string x; cin >> x;
    int n = len(x);  
    if(k == 1){
        cout << yes << endl;
        cout << x << endl; return;
    }else{
        map<char,bool> mp;
        vector<string> ans;
        string cur = "";
        cur += x[0];
        bool enter=true;
        f0r(i,1,n){
            if(x[i] != x[i-1] && mp[x[i-1]] == false && enter == true){
                ans.pb(cur);
                cur = "";
                mp[x[i-1]] = true;
                k--;
            }
            cur += x[i];
            if(k == 1 && enter == true){
                enter = false;
            }
        }
        cout << ans[len(ans)-1] << endl;
        cout << cur <<endl;
        if(mp[cur[0]] == false){
            k--;
            ans.pb(cur);
        }else{
            int p=0;
            bool ok = false;
            while(p<len(cur)){
                if(mp[cur[p]] == false){
                    ok = true;
                    break;
                }
                p++;
                }
                cout << p << endl;
                p--;
                if(ok == false){
                    cout << no << endl;
                    return;
                }
                // rev(cur);
                string temp = ans[len(ans) - 1];
                // rev(temp);
                int t=0;
                while(t<=p){
                    cout << temp <<" "<<cur<<endl;
                    temp+=cur[t];
                    // cout << cur[t] << " ";
                    rev(cur);
                    cur.pop_back();
                    rev(cur);
                    t++;
                }
                cout << endl;
                // rev(cur);
                // rev(temp);
                ans[len(ans)-1] = temp;
                ans.pb(cur);
                k--;
        }
        if(k == 0){
            // ans[len(ans)-2] += ans[len(ans)-1];
            // ans.pop_back();
            cout << yes << endl;
            print(ans);
        }else{
            cout << no << endl;
        }
    }
}
void solve2() {
    int k; cin >>  k;
    string x; cin >> x;
    int n = len(x);
    int cnt=0;
    if( k == 1){
        cout << yes << endl;
        cout << x << endl;
        return;
    }
    map<char,bool> mp;
    vector<string> ans;
    string cur =""; cur += x[0];
    bool enter = true;
    f0r(i,1,n){
        if(x[i] != x[i-1] && enter == true && mp[x[i-1]] == false){
            ans.pb(cur);
            cnt++;
            cur = "";
            mp[x[i-1]] = true;
        }
        cur += x[i];
        if(cnt == k){
            enter = false;
        }
    }
    if(mp[cur[0]] == false){
        ans.pb(cur);
    }else{
        // cout <<"--"<<cur<< endl;
        int p=0;
        bool ok = false;
        rev(cur);
        while(p<len(cur)){
            p++;
            if(mp[cur[p]] == false){
                ok = true;
                break;
            }
        }
        rev(ans[len(ans)-1]);
        // rev(cur);
        int t=0;
        while(t<=p && t < len(cur)){
            ans[len(ans)-1].pb(cur[t]);
            cur.pop_back();
            t++;
        }
        rev(ans[len(ans)-1]);
        rev(cur);
        if(ok){
            ans.pb(cur);
        }else{
            cout << no << endl;
            return;
        }
        // rev(ans[len(ans)-1]);
    }
    if(cnt == k){
        cout << yes << endl;
        print(ans);
    } else{
        cout << no << endl;
    }
}

int main() {
//freopen("input.txt", "r", stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
    int t;
    t = 1;
    while (t--) {
        solve();
    }

    return 0;
}