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

const int N = 100*1001;

void min_self(auto &a, auto b)
{
    a = min(a, b);
}

void solve()
{
    int n, w;
    cin >> n >> w;
    int v[n + 1][2];
    // wi, vi
    loopf(i, 1, n + 1)
            cin >>
        v[i][0] >> v[i][1];

    vector<vector<ll>> dp(n + 1, vector<ll>(N));

    loopf(j, 0, N + 1)
        dp[0][j] = INT_MAX;

    loopf(i, 0, n + 1)
        dp[i][0] = 0;

    // definition of dp[i][j] -> minimum weight required when we consider the first i items and get an
    // exact weight of j

    // dp[i][j] = INT_MAX implies that it is not possible to get an exact value of j

    int ans = -1;

    loopf(i, 1, n + 1)
    {
        loopf(j, 1, N + 1)
        {
            dp[i][j] = INT_MAX;

            // don't consider the i'th value
            min_self(dp[i][j], dp[i - 1][j]);

            // check if we can add v[i] value to j
            if (j >= v[i][1] && dp[i - 1][j - v[i][1]] != INT_MAX)
            {
                min_self(dp[i][j], v[i][0] + dp[i - 1][j - v[i][1]]);
            }

            if (dp[i][j] <= w)
                ans = max(ans, j);
        }
    }

    cout << ans;
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