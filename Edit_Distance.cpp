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
int n, m;

vector<vector<int>> dp; 

int calculate_edit_distance(int ind1, int ind2, string &s, string &t)
{
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (ind2 == m)
        return dp[ind1][ind2] = n - ind1;
    if (ind1 == n)
        return dp[ind1][ind2] = m - ind2;
    int curr_ans = INFINITY;
    // matches
    if (s[ind1] == t[ind2])
        curr_ans = min(curr_ans, calculate_edit_distance(ind1 + 1, ind2 + 1, s, t));
    // replace
    curr_ans = min(curr_ans, 1 + calculate_edit_distance(ind1 + 1, ind2 + 1, s, t));
    // add the character
    curr_ans = min(curr_ans, 1 + calculate_edit_distance(ind1, ind2 + 1, s, t));
    // delete the character
    curr_ans = min(curr_ans, 1 + calculate_edit_distance(ind1 + 1, ind2, s, t));

    return dp[ind1][ind2] = curr_ans;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    dp.resize(n+1, vector<int>(m+1, -1));
    cout << calculate_edit_distance(0, 0, s, t);
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