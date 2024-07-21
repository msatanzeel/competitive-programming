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

const ll MAX_LEN = 10001;

map<int, int> mp;

void init()
{
    mp[6]++;
    mp[8]++;
    mp[9]++;
    mp[12]++;
    mp[15]++;
    mp[17]++;
    mp[19]++;
    mp[22]++;
    mp[23]++;
    mp[25]++;
    mp[26]++;
    mp[27]++;
    mp[28]++;
    mp[29]++;
    mp[30]++;
    mp[31]++;
    mp[32]++;
    mp[33]++;
    mp[34]++;
    mp[36]++;
    mp[37]++;
    mp[38]++;
    mp[39]++;
    mp[40]++;
    mp[41]++;
    mp[42]++;
    mp[43]++;
    mp[44]++;
    mp[45]++;
    mp[46]++;
    mp[47]++;
    mp[48]++;
    mp[49]++;
    mp[50]++;
    mp[51]++;
    mp[52]++;
    mp[53]++;
    mp[54]++;
    mp[55]++;
    mp[56]++;
    mp[57]++;
    mp[58]++;
    mp[59]++;
    mp[60]++;
    mp[61]++;
    mp[62]++;
    mp[63]++;
    mp[64]++;
    mp[65]++;
    mp[66]++;
    mp[67]++;
    mp[69]++;
    mp[70]++;
    mp[71]++;
    mp[72]++;
    mp[73]++;
    mp[74]++;
    mp[75]++;
    mp[76]++;
    mp[77]++;
    mp[78]++;
    mp[79]++;
    mp[80]++;
    mp[81]++;
    mp[82]++;
    mp[83]++;
    mp[84]++;
    mp[85]++;
    mp[86]++;
    mp[87]++;
    mp[88]++;
    mp[91]++;
    mp[92]++;
    mp[93]++;
    mp[95]++;
    mp[96]++;
    mp[97]++;
    mp[98]++;
    mp[99]++;
    mp[100]++;
}

void solve()
{

    ll n;
    cin >> n;
    if (mp[n] == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll s_len = to_string(n).length();
    vector<pair<ll, ll>> v;
    string refer = to_string(n);
    while (refer.length() < MAX_LEN)
        refer += refer;
    loopf(a, 1, MAX_LEN)
    {
        ll curr_len = s_len * (a);
        loopb(i, 11, 0)
        {
            if (i > curr_len)
                continue;
            ll d = curr_len - i;
            if (d == 0)
                continue;
            string temp;
            temp = refer.substr(0, i);

            if (temp == "")
                continue;
            ll val = stoll(temp);
            if (val == 0)
                continue;
            if (val == n * (a)-d)
            {
                // debug(i);
                // debug(temp,a,d);
                v.push_back({a, d});
            }
        }
    }

    // debug(n, v.size());
    // debug(v);

    // sort(all(v));
    cout << v.size() << endl;
    for (auto ele : v)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}

int main()
{
    fast;
    int t = 100;
    init();
    cin >> t;
    loopf(i, 0, t)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
}