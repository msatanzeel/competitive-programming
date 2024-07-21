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


vector<vector<int>> weights, adj;
vector<int> vis, comp;
int conn;

void dfs(int node) {
    vis[node] = 1;
    comp[node] = conn;

    for (int child : adj[node]) 
        if (vis[child] == 0)
            dfs(child);

}

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        weights.clear();
        adj.clear();
        vis.clear();
        comp.clear();

        weights.resize(n);
        adj.resize(n);
        vis.resize(n);
        comp.resize(n);

        for(auto edge : edges) {
            int a,b,w;
            a = edge[0];
            b = edge[1];
            w = edge[2];

            adj[a].push_back(b);
            adj[b].push_back(a);
            weights[a].push_back(w);
            weights[b].push_back(w);
        }

        conn = 0;

        for(int i=0; i<n; i++) {
            if (vis[i] == 0) {
                dfs(i);
                conn++;
            }
        }

        vector<int> ands(conn, -1);

        for (int i=0; i<n; i++) {
            int conn_num = comp[i];
            
            for (int weight : weights[conn_num]) 
            {
                if (ands[conn_num] == -1)
                    ands[conn_num] = weight;
                else 
                    ands[conn_num] &= weight;
            }
        }

        vector<int> ans;

        for(auto q : query) {
            int a = q[0], b = q[1];
            if (comp[a] != comp[b]) {
                ans.push_back(-1);
            }
            else 
                ans.push_back(ands[comp[a]]);
        }

        return ans;

    }
};


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