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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0)), pref(n + 1, vector<int>(m + 1, 0));
    loopf(i, 1, n+1)
        loopf(j, 1, m+1)
            cin >> v[i][j];

    char s[n + 1][m + 1];
    ll sum1 = 0, sum2 = 0;

    loopf(i, 1, n+1)
        loopf(j, 1, m+1)
        {
            cin >> s[i][j];
            pref[i][j] = s[i][j] - '0';
            if (pref[i][j])
                sum1 += v[i][j];
            else 
                sum2 += v[i][j];
        }

    // debug(pref);

    loopf(i, 2, n+1)
        pref[i][1] += pref[i-1][1];
    
    loopf(j, 2, m+1)
        pref[1][j] += pref[1][j-1];
    
    loopf(i, 2, n+1)
    {
        loopf(j, 2, m+1)
        {
            pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);
        }
    }

    // debug(pref);

    set<int> differences;

    loopf(i, k, n+1)
    {
        loopf(j, k, m+1)
        {
            int diff = k * k - 2 *(pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k]);
            if (diff != 0)
                differences.insert(diff);
            // debug(diff);
        }
    }

    // debug(differences);
    // debug(abs(sum1- sum2));

    int gcd =  0;
    for (auto diff : differences)
        gcd = __gcd(gcd, diff);
    
    if (differences.size() == 0 && abs(sum1 - sum2) != 0)
    {
        no1;
        return;
    }
    
    // debug(gcd);
    
    if (gcd == 0 || abs(sum1 - sum2) % gcd == 0)
        cout << "YES";
    else 
        cout << "NO";
    
    cout << endl;

    
    
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    loopf(i, 0, t)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
}