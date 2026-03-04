#include<bits/stdc++.h>
#define pb          push_back
#define vec         vector
#define ub          upper_bound
#define lb          lower_bound
#define per         next_permutation
#define itn         int
#define sc          second
#define fr          first
#define FOR(i,l,r)  for(int i=l;i<=r;i++)
#define RFOR(i,r,l) for(int i=r;i>=l;i--)
#define IOS         ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x)      x.begin(), x.end()
#define rall(c)     (c).rend(), (c).rbegin
#define kill(x)     return cout << x << endl, 0
#define SZ(x)       int(x.size())
#define it          iterator
#define mp          make_pair
#define BPT(n)      pow(2,floor(log2((n))));
#define LPT(n)      pow(2,ceil(log2((n))*1.0));
#define endl        "\n"
#define dbg(x) {cerr<<#x<<" = "<<x<<'\n';}
#define dbgp(x) {cerr<<#x<<" : {"<<x.fr<<", "<<x.sc<<"}\n";}
#define dbgv(x) {cerr<<#x<<" : "; for(int i:x) cerr<<i<<' '; cerr<<'\n';}
#define dbga(x, l, r) {cerr<<#x<<' '<<l<<"..."<<r<<" : "; for(int i=l; i<r; i++) cerr<<x[i]<<' '; cerr<<'\n';}
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
typedef pair <pii, pii> ppp;
typedef pair <ll, ll>   pll;
/* Reverse Iterate on Set A sintax
    for( set<int>::reverse_iterator i = A.rbegin() ; i!=A.rend() ; i++){
        cout << *i <<' ';
    }
*/
ll pw(ll base,ll e){
    return e?pw(base*base,e/2)*(e%2?base:1):1;
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
//Converts s string to int
ll to_int(string s){
    ll ret = 0;
    FOR(i,0,s.size()){
        ret += pw(10,s.size()-i-1) * (ll)(s[i] - '0');
    }
    return ret;
}
const int maxn=2e5+10,mod=1e9+7;
const ll INF=1e9;
vec<int>adj[maxn];
int sz[maxn];
bool ok[maxn] , mark[maxn];
int par[maxn];
void update(int cur){
        vec<pii>temp;
        for(int u:adj[cur]){
            if(u!=par[cur]){
                temp.pb({sz[u],u});
            }
        }
        sort(temp.begin(),temp.end());
        int c=1;
        ok[cur]=1;
        for(auto u:temp){
            if(u.fr>c || !ok[u.sc]){
                ok[cur]=0;
            }
            c+=u.fr;
        }
}
void dfs(int cur,int p){
    mark[cur]=1;
    par[cur]=p;
    for(int u:adj[cur]){
        if(!mark[u]){
            dfs(u,cur);
            sz[cur]+=sz[u];
        }
    }
    update(cur);
}
bool vis[maxn];
int main(){
    int n;
    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        sz[i]=1;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sz[n-1]=1;
    dfs(0,-1);
    int root=0 ,newroot ,prev;
    vis[root]=1;
    if(ok[root]){
        kill("YES\n");
    }
    if(adj[root].size()==1){
        newroot= adj[root][0];
        prev= root;
        root= newroot;
        par[root]= -1;
        par[prev]= root;
        sz[prev]-= sz[root];
        sz[root]+= sz[prev];
        update(prev);
        update(root);
        
    }
    while(adj[root].size()>1){
        vis[root]=1;
        if(ok[root]){
            kill("YES\n");
        }
        vec<int>bad;
        for(int u:adj[root]){
            if(!ok[u]){
                bad.pb(u);
            }
        }
        if(bad.size()==0){
            vec<pii>temp;
            for(int u:adj[root]){
                if(u!=par[root]){
                    temp.pb({sz[u],u});
                }
            }
            sort(temp.begin(),temp.end());
            int c=1;
            ok[root]=1;
            for(int i=0;i<temp.size()-1;i++){
                auto u = temp[i];
                if(u.fr>c || !ok[u.sc]){
                    ok[root]=0;
                }
                c+=u.fr;
            }
            if(ok[root]){
                kill("YES\n");
            }
            else{
                kill("NO\n");
            }
        }
        if(bad.size()>1){
            kill("NO\n");
        }
        int u=bad[0];
        if(vis[u]){
            kill("NO\n");
        }
        newroot= u;
        prev= root;
        root= newroot;
        par[root]= -1;
        par[prev]= root;
        sz[prev]-= sz[root];
        sz[root]+= sz[prev];
        update(prev);
        update(root);
        
    }
    kill("NO\n");
    
}

