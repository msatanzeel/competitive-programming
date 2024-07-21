#include <bits/stdc++.h>
using namespace std;

void optmised_func()
{
    string s = "a";
    int n = s.length();
    int freq[256];
    memset(freq, 0, sizeof(freq));

    int ans = 0;

    int l = 0;
    for (int i = 0; i<n; i++)
    {
        int val = int(s[i]);
        freq[val]++;
        while (freq[val] > 1)
        {
            freq[int(s[l])]--;
            l++;
        }

        ans = max(ans, i - l + 1);
    }

    cout << ans << endl;
}

void solve()
{

    string s;
    s = "abcdfbef";

    // l r

    int n = s.length();

    const int N = 256;

    int prefix_sums[n][256];
    memset(prefix_sums, 0, sizeof(prefix_sums));

    for (int i = 0; i < n; i++)
    {
        int val = int(s[i]);
        prefix_sums[i][val] = 1;
    }

    /*

    a 1 0 0 
    a 1 0 0
    b 0 1 0
    c 0 0 1
    
    */

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < N; j++)
            prefix_sums[i][j] += prefix_sums[i - 1][j];
    }

    /*
    a 1 0 0 
    a 2 0 0 
    b 2 1 0
    c 2 1 1
    */

    auto check = [&](int l, int r) -> bool
    {
        int temp[256];
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < N; j++)
            temp[j] = prefix_sums[r][j];
        if (l != 0)
        {
            for (int j = 0; j < N; j++)
                temp[j] -= prefix_sums[l - 1][j];
        }
        
        for (int i=0; i<256; i++)
            if (temp[i] > 1)
                return false;
        
        return true;
    };

    int ans = 1;

    for (int i=0; i<n;  i++)
    {
        int l = i, r = n - 1;
        while (l <= r)
        {
            int mid = (l+r)/2;
            bool possible = check(i, mid);
            if (possible)
            {
                ans = max(ans, mid - i + 1);
                l = mid + 1;
            }
            else 
            {
                r = mid - 1;
            }
        }
    }

    cout << ans << endl; 

}

int main()
{
    optmised_func();
}