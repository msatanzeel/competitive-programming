#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loopf(i, a, b) for (int i = a; i < b; i++)
#define loopb(i, a, b) for (int i = a; i > b; i--)
#define loopit(it, st) for (auto it = st.begin(); it != st.end(); it++)
#define pb push_back
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ff first
#define ss second
#define vc vector
#define vii vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define sz(v) (int)(v.size())
#define len(v) (int)(v.length())
const ll M = 1e9 + 7;

#define yes1 cout << "YES" << endl
#define no1 cout << "NO" << endl
#define yes2 cout << "Yes" << endl
#define no2 cout << "No" << endl
#define minus1 cout << "-1" << endl
#define imax INT_MAX
#define imin INT_MIN
#define lmax LLONG_MAX
#define lmin LLONG_MIN

//*********************************************DEBUG*****************************************
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

//*************************************************************************************

int n;

vector<int> prefix;

vector<vector<ll>> dp;

int helper(int sum1, int index)
{
    if (dp[sum1][index] != -1)
    {
        return dp[sum1][index];
    }
    if (index > n)
    {
        int sum2 = prefix[index - 1] - sum1;
        return dp[sum1][index] = (sum1 == sum2 ? 1 : 0);
    }
    return dp[sum1][index] = (helper(sum1 + index, index + 1) + helper(sum1, index + 1)) % M;
}

ll power(ll a, ll n)
{
    ll res = 1, mod = M;
    while (n)
    {
        if (n % 2)
            res = (res * a) % mod;

        a = (a * a) % mod;
        n = n / 2;
    }

    return res;
}



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
    }
};



void solve()
{
    cin >> n;
    prefix.resize(n + 1);

    int max_sum = n * (n + 1) / 2;
    dp.resize(max_sum + 2, vector<ll>(n + 2, -1));

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + i;
    }

    if (prefix[n] & 1)
    {
        cout << 0 << endl;
        return;
    }

    ll inv_2 = power(2, M - 2);
    cout << (1LL * helper(0, 1) * inv_2) % M << endl;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    loopf(i, 0, t)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
}