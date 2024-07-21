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


class CountIntervals {
public:
    set<pair<int, int>> st;
    long long tot;

    CountIntervals() {
        st.clear();
        tot = 0;
    }
    
    void add(int left, int right) {
        pair<int, int> temp = {left, left - 1};
        auto itr = st.lower_bound(temp);

        if (itr == st.end())
        {
            tot += (right - left + 1);
            st.insert({left, right});
        }
        else 
        {
            if (itr != st.begin())
                itr--;
            vector<pair<int, int>> to_be_deleted;
            while (itr != st.end())
            {
                pair<int, int> curr = *itr;
                itr++;
                if (curr.first > right)
                    break;
                to_be_deleted.push_back(curr);
                tot -= (curr.second - curr.first + 1);
                right = max(right, curr.second);
                left = min(left, curr.first);
            }
            for (auto ele : to_be_deleted)
                st.erase(ele);
            tot += (right - left + 1);
            st.insert({left, right});
        }

    }
    
    int count() {
        return tot;
    }
};

auto compare(auto a, auto b)
{
    return a&b;
}

class RangeQueries
{
public:
    vector<vector<int>> sparse;
    int n;
    int logN;

    RangeQueries(vector<int> &arr)
    {
        n = arr.size();
        logN = ceil(log2(n));
        sparse.resize(n, vector<int>(logN + 1, INT_MAX));


        for (int i = 0; i < n; i++)
        {
            sparse[i][0] = arr[i];
        }

        for (int j = 1; j <= logN; j++)
        {
            for (int i = 0; i + (1 << (j - 1)) < n; i++)
            {
                sparse[i][j] = compare(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r)
    {
        int len = (r - l + 1);
        int power = 0;
        while (1 << (power + 1) <= len)
            power++;
        return compare(sparse[l][power], sparse[r - (1 << power) + 1][power]);
    }
};

class Solution
{
public:
    long long countSubarrays(vector<int> &v, int k)
    {
        int n = v.size();
        RangeQueries rangeQuerie(v);

        ll ans = 0;
        loopf(i, 0, n)
        {
            int l, r;
            int low = -1, high = -1;

            l = i, r = n - 1;

            while (l <= r)
            {
                int mid = (l + r) / 2;
                int curr = rangeQuerie.query(i, mid);
                if (mid == k)
                {
                    low = mid;
                    r = mid - 1;
                }
                else if (mid < k)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            l = i;
            r = n - 1;

            while (l <= r)
            {
                int mid = (l + r) / 2;
                int curr = rangeQuerie.query(i, mid);
                if (mid == k)
                {
                    high = mid;
                    l = mid + 1;
                }
                else if (mid < k)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            if (low == -1 || high == -1)
                continue;
            ans += (high - low + 1);
        }
        return ans;
    }
};

void solve()
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(all(v));
    cout << v.back() - v.front() << endl;
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