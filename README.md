
My template

``` C++
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#include<set> 
#include<numeric>
#include<cmath>
#include<queue>
#include<deque>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <climits>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class debugger {
public:
    template<typename T>
    void dbg(const T &x) {
        cerr << x;
    }
    template<typename T, typename... Args>
    void dbg(const T &x, const Args&... args) {
        cerr << x << " ";
        dbg(args...);
    }
    void ln() {
        cerr << '\n';
    }
    template<typename T>
    void dbg(const vector<T> &v) {
        cerr << "[ ";
        for (const auto &x : v) cerr << x << " ";
        cerr << "]";
    }
    template<typename T>
    void dbgl(const vector<T> &v) {
        dbg(v);
        ln();
    }
    template<typename A, typename B>
    void dbg(const pair<A, B> &p) {
        cerr << "(" << p.first << ", " << p.second << ")";
    }
    template<typename T>
    void dbg(const set<T> &s) {
        cerr << "{ ";
        for (auto &x : s) cerr << x << " ";
        cerr << "}";
    }
    template<typename K, typename V>
    void dbg(const map<K, V> &m) {
        cerr << "{ ";
        for (auto &x : m)
            cerr << "(" << x.first << ":" << x.second << ") ";
        cerr << "}";
    }
};
class GeeksForGeeks {
    // This function merges two sorted subarrays arr[l..m] and arr[m+1..r] 
    // and also counts inversions in the whole subarray arr[l..r]
    int countAndMerge(vector<int>& arr, int l, int m, int r) {
    
        // Counts in two subarrays
        int n1 = m - l + 1, n2 = r - m;

        // Set up two vectors for left and right halves
        vector<int> left(n1), right(n2);
        for (int i = 0; i < n1; i++)
            left[i] = arr[i + l];
        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];

        // Initialize inversion count (or result) and merge two halves
        int res = 0;
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {

            // No increment in inversion count if left[] has a 
            // smaller or equal element
            if (left[i] <= right[j]) 
                arr[k++] = left[i++];
        
            // If right is smaller, then it is smaller than n1-i 
            // elements because left[] is sorted
            else {
                arr[k++] = right[j++];
                res += (n1 - i);
            }
        }

        // Merge remaining elements
        while (i < n1)
            arr[k++] = left[i++];
        while (j < n2)
            arr[k++] = right[j++];

        return res;
    }

    // Function to count inversions in the array
    int countInv(vector<int>& arr, int l, int r){
        int res = 0;
        if (l < r) {
            int m = (r + l) / 2;

            // Recursively count inversions in the left and 
            // right halves
            res += countInv(arr, l, m);
            res += countInv(arr, m + 1, r);

            // Count inversions such that greater element is in 
            // the left half and smaller in the right half
            res += countAndMerge(arr, l, m, r);
        }
        return res;
    }

    public: 
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return countInv(arr, 0, n-1);
    }
};
// Class to revis a graph
class Graph {
private:
    int V;
    bool directed;
    vector<vector<int>> adj;

    // ---------- directed cycle helper ----------
    bool dfsDirected(int u, vector<int>& vis) {
        vis[u] = 1;   // in recursion stack
        for (int v : adj[u]) {
            if (vis[v] == 1) return true;          // back-edge → cycle
            if (vis[v] == 0 && dfsDirected(v, vis)) return true;
        }
        vis[u] = 2;   // exited
        return false;
    }

    // ---------- undirected cycle helper ----------
    bool dfsUndirected(int u, int parent, vector<int>& vis) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfsUndirected(v, u, vis)) return true;
            }
            else if (v != parent) {
                return true;
            }
        }
        return false;
    }

public:
    Graph(int n, bool isDirected) {
        V = n;
        directed = isDirected;
        adj.assign(V + 1, {});   // 1-indexed
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }

    bool hasCycle() {
        vector<int> vis(V + 1, 0);
        if (directed) {
            for (int i = 1; i <= V; i++) {
                if (vis[i] == 0 && dfsDirected(i, vis))
                    return true;
            }
        } else {
            for (int i = 1; i <= V; i++) {
                if (!vis[i] && dfsUndirected(i, -1, vis))
                    return true;
            }
        }
        return false;
    }
};
const int MAXN = 300000 + 5;
vector<int> spf(MAXN);
class solution {
public:
const long long MOD = 1e9 + 7;
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
bool check_prime(int n) {
    bool is_prime = true;
    if (n == 0 || n == 1) {
        is_prime = false;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}
vector<int> pre_computed_primes;
void pre_compute_primes(int n) {
    for(int i = 1; i <= n; ++i) {
        if(check_prime(i))
        pre_computed_primes.push_back(i);
    }
}
vector<vector<int>> factors;
void pre_compute_factors(int n) {
    factors.assign(n + 1, {});
    for (int d = 1; d <= n; d++) {
        for (int multiple = d; multiple <= n; multiple += d) {
            factors[multiple].push_back(d);
        }
    }
}
vector<long long> single_number_factor(long long n) {
    vector<long long> res;
    if (n <= 1) return {1};
    if (n % 2 == 0) {
        res.push_back(2);
        while (n % 2 == 0)
            n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res.push_back(n);

    return res;
}
#define int long long
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (b / gcd(a, b)) * a;
}
struct Trie {
    Trie* next[2] = {nullptr, nullptr};
    int n0 = 0, n1 = 0;
    int cnt = 0;  
};
void compute_spf() {
    for (int i = 1; i < MAXN; i++)
        spf[i] = i;

    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
static int digit_value(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}
static vector<int> to_base(long long n, long long base) {
    vector<int> digits;
    if (n == 0) {
        digits.push_back(0);
        return digits;
    }
    while (n > 0) {
        digits.push_back(n % base);
        n /= base;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}
void solve(debugger ddb) {
    
}
#undef int
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ;
    cin >> t;
    solution sol;
    debugger db;
    while(t--) {
        sol.solve(db);
    }
}
// :)
/**
 * Visit jclouds.space for more information about me and my projects.
 */


 