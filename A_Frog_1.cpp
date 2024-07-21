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

void merge(vector<int> &v, int l1, int r1, int l2, int r2)
{
    debug(v);
    debug(l1, r1, l2, r2);
    int n = r2 - l2 + 1 + r1 - l1 + 1;
    vector<int> res(n);
    int ind = 0, ind1 = l1, ind2 = l2;

    while (ind1 <= r1 && ind2 <= r2)
    {
        if (v[ind1] < v[ind2])
            res[ind++] = v[ind1++];
        else 
            res[ind++] = v[ind2++];
    }

    while (ind1 <= r1)
        res[ind++] = v[ind1++];

    while (ind2 <= r2)
        res[ind++] = v[ind2++];
    
    debug(res);

    ind = l1;

    for (auto ele : res)
        v[ind++] = ele;
}

void merge_sort(vector<int> &v, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    // 0 2
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);

    merge(v, l, mid, mid + 1, r);
}

void solve()
{
    vector<int> v = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(v, 0, sz(v) - 1);

    for (auto ele : v)
        cout << ele << " ";

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