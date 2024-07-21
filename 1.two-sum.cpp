/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int req = target - val;

            if (mp.find(req) != mp.end()) {
                if (req == val && mp[req].size() > 1) {
                    return {mp[req][0], mp[req][1]};
                } else if (req != val && mp[req].size() > 0) {
                    return {i, mp[req][0]};
                }
            }

        }
        return {-1, -1};
    }
};
// @lc code=end

