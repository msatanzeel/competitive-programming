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

class Fenwick
{
public:
    vector<int> v;
    int n;

    Fenwick() {}

    Fenwick(int n)
    {
        this->n = n;
        v.resize(n + 1, 0);
    }

    void add(int ind, int val) {
        while(ind <= n) {
            v[ind] += val;
            ind += (ind & (-ind));
        }
    }

    int query(int ind) {
        int ans = 0;
        while (ind > 0) {
            ans += v[ind];
            ind -= (ind & -ind);
        }
        return ans;
    }

    int query(int l, int r) {
        return query(r) - query(l-1);
    }

    int get_smallest(int ind) {

        // debug(ind);
        if (ind < 1 || ind > n)
            return -1;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r)/2;
            int n_mid = query(mid);
            int n_mid_minus_1 = query(mid - 1);

            if (n_mid == n_mid_minus_1) {
                if (ind < n_mid)
                    r = mid - 1;
                else 
                    l = mid + 1;
                continue;
            }
            
            int l_range = n_mid_minus_1 + 1;
            int r_range = n_mid;
            // debug(l_range, r_range);

            if (l_range <= ind && ind <= r_range)
                return mid;
            
            if (ind < l_range)
                r = mid - 1;
            else 
                l = mid + 1;

        }
        return -1;
    }

};

void solve()
{
    int n,q;
    cin >> n >> q;
    Fenwick fenwick(n);
    loopf(i,0,n) {
        int ele;
        cin >> ele;
        fenwick.add(ele, 1);
    }

    while(q--) {
        int ele;
        cin >> ele;
        if (ele > 0)
            fenwick.add(ele, 1);
        else 
        {
            ele = abs(ele);
            int kth = fenwick.get_smallest(ele);
            // debug(kth);
            fenwick.add(kth, -1);
        }
        // loopf(i, 1, n+1)
        // {
        //     cerr << fenwick.query(i, i) << " ";
        // }
        // cerr << endl;
    }

    loopf(i, 1, n+1) {
        if (fenwick.query(i, i))
        {
            cout << i << endl;
            return;
        }
    }

    cout << 0 << endl;
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