#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 

using namespace std;

bool sortBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), sortBySecond);

    int ans = 0;
    int space = n;

    for(int i = m - 1; i >= 0 && space > 0; i--) {
        if(v[i].first <= space) {
            ans += v[i].second * v[i].first;
            space -= v[i].first;
        } else {
            ans += v[i].second * space; 
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
