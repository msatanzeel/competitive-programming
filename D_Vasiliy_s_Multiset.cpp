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

class Node
{

public:
    Node *arr[2];
    int count;

    Node()
    {
        arr[0] = NULL;
        arr[1] = NULL;
        count = 0;
    }
};

vector<int> getBinaryRepr(int n)
{
    vector<int> v;
    for (int i = 0; i < 30; i++)
    {
        v.push_back(n % 2);
        n /= 2;
    }
    return v;
}

class XorTree
{
public:
    Node *root;

    XorTree()
    {
        root = new Node();
    }

    void add(int n)
    {
        vector<int> bits = getBinaryRepr(n);
        reverse(begin(bits), end(bits));
        root->count++;
        Node *curr = root;
        for (int bit : bits)
        {
            if (curr->arr[bit] == NULL)
            {
                curr->arr[bit] = new Node();
            }
            curr = curr->arr[bit];
            curr->count++;
        }
    }

    void remove(int n)
    {
        vector<int> bits = getBinaryRepr(n);
        reverse(begin(bits), end(bits));
        root->count--;
        Node *curr = root;
        for (int bit : bits)
        {
            curr->arr[bit]->count--;
            if (curr->arr[bit]->count == 0)
            {
                curr->arr[bit] = NULL;
                break;
            }
            curr = curr->arr[bit];
        }
    }

    int find(int n) 
    {
        vector<int> bits = getBinaryRepr(n);
        reverse(begin(bits), end(bits));
        vector<int> ans_bits;

        Node *curr = this->root;

        for (auto bit : bits)
        {
            if (curr->arr[bit^1])
            {
                ans_bits.push_back(1);
                curr = curr->arr[1^bit];
            }
            else if (curr->arr[bit])
            {
                ans_bits.push_back(0);
                curr = curr->arr[bit];
            }
        }
        reverse(ans_bits.begin(), ans_bits.end());
        int ans = 0, pos = 0;
        for (auto ele : ans_bits)
        {
            ans += ele * (1 << pos);
            pos++;
        }

        return ans;
    }

};

void solve()
{
    int n;
    cin >> n;

    XorTree tree = *(new XorTree());
    int x;

    while (n--)
    {
        char c;
        cin >> c;

        switch (c)
        {
        case '+':
            cin >> x;
            tree.add(x);
            break;
        
        case '-':
            cin >> x;
            tree.remove(x);
            break;
        
        case '?':
            cin >> x;
            cout << tree.find(x) << endl;
            break;
        
        default:
            break;
        }
    }
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