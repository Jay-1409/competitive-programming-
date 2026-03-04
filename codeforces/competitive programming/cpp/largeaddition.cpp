#include <bits/stdc++.h>
using namespace std;
void solve()
{

    long long int n;
    cin >> n;
    string s = to_string(n);
    int sx = s.size();
    bool flg = false;
    int sum = 0, bdt = 5 + 6 + 7 + 8 + 9;
    for (int i = 0; i < sx - 1; i++)
    {
        sum += (s[i] - '0');
        if (s[i] == '0')
        {
            flg = true;
        }
    }
    if (s[sx - 1] == '9')
    {
        cout << "NO" << endl;
    }
    else if (sum == bdt)
    {
        cout << "NO" << endl;
    }
    else if (s[0] != '1')
    {
        cout << "NO" << endl;
    }
    else if (sx % 10 == 0)
    {
        cout << "NO" << endl;
    }
    else if (flg)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}