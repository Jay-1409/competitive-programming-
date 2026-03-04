#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;
#define rev(x) reverse(all(x))
#define s0rt(x) sort(all(x))
#define s0rtd(x) sort(all(x)), rev(x);
#define s0rtx(x, ...) sort(all(x), __VA_ARGS__);
#define sum(x) accumulate(all(x), 0ll)
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
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
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


void solve() {
    int n; cin>>n;
    vector<int> v(n);
    f0r(i,n)cin>>v[i];
    if(n==1){
        cout<<0<<endl; return;
    }
    int minnn=mine(v);
    int maxxx=maxe(v);
    vector<int> b(all(v));
    vector<int> c(all(v));
    vector<int> v2(all(v));
    vector<int> fresh(all(v));
    s0rt(c);
    s0rt(b);
    int mx;
    int ans1;
        int mxi=mx;
    f0r(i,n){
    int x=b.back;  
    // cout<<x<<endl;
        if(i==0&&v[i]==x){
            b.pop_back();
        }else if(v[i]==x){
            mxi=i;
            mx=x;
            int a=mx-v[0];
            int b=mx-v[n-1];
            swap(v[i],v[n-1]);
            ans1=max(a,b);
            break;
        }
    }
        int mni=mx;
    int ans2;
    f0r(i,n){
    int x=c.front();
    // cout<<x<<endl;
        if(i==n-1&&v2[i]==x){
            c.erase(c.begin());
        }else if(v2[i]==x){
            mni=i;
            mx=x;
            int a=v2[n-1]-mx;
            int b=v2[0]-mx;
            ans2=max(a,b);
            swap(v2[i],v2[0]);  
            break;
        }
    }
    int ans=max(ans1,ans2);
    f0r(i,n-1){
        if(abs(fresh[i]-fresh[i+1])<=maxxx)
        ans=max(ans,abs(fresh[i]-fresh[i+1]));
        // cout<<ans<<endl;
    }
    // cout<<mxi<<" "<<mni<<endl;
    // if(abs(mxi-mni)==1){
    //     int temp=abs(fresh[mxi]-fresh[mni]);
    //     // cout<<fresh[mxi]-fresh[mni]<<endl;
    //     ans=max(ans,temp);
    // }
    cout<<ans<<endl;
}
void solve2(){
    long long a, b, c, d, n, m, k, i, j, cnt, temp;
    cin>>n;
    vector<long long> v(n);
    long long ma = 0;
    long long mi = INF;
    for(i=0;i<n;i++){
        cin>>v[i];
        mi = min(mi, v[i]);
        ma = max(ma, v[i]);
    }
    long long ans = 0;
    for(i = 0 ; i < n - 1; i++){
        ans = max(ans, v[i] - v[i + 1]);
    }
    ans = max({ans, v[n - 1] - v[0], v[n - 1] - mi, ma - v[0]});
    cout<<ans<<endl;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve2();
    }

    return 0;
}