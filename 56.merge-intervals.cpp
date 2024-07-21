/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& v) {
            vector<vector<int>> ans;
            int n = v.size();
            sort(begin(v), end(v));
            ans.push_back(v.front());

            for (int i=1; i<n; i++)
            {
                int l = ans.back()[0];
                int r = ans.back()[1];

                if (l <= v[i][0] && v[i][0] <= r)
                {
                    r = max(r, v[i][1]);
                    ans.back()[1] = r;
                }
                else 
                {
                    ans.push_back(v[i]);
                }
            }

            return ans;

        }
    };
// @lc code=end

