#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
^ Subsets
Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Subsets {
public:
    void func(int ind, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums){
        if (ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        //not take
        func(ind+1,ds,ans,nums);
        //take
        ds.push_back(nums[ind]);
        func(ind+1,ds,ans,nums);
        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,ds,ans,nums);
        return ans;
    }
};

/*
^ Subsets II
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Subsets2 {
public:
    vector<vector<int>> result;
    
    void subs(vector<int> &nums, int curr, vector<int> &res){
        result.push_back(res);
        // for (auto i : res)cout<<i<<" ";
        cout<<endl;
        for(int i = curr; i < nums.size(); i++){
            if(i!=curr && nums[i]==nums[i-1]){
                continue;
            }
            res.push_back(nums[i]);
            subs(nums, i+1, res);
            res.pop_back();
            // cout<<i<<" ";
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0){
            return result;
        }
        vector<int> res;
        sort(nums.begin(), nums.end());
        subs(nums, 0, res);
        return result;
    }
};

/*
^ Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

class Permutations {
public:
    vector<vector<int>> result;
    void perm(vector<int> &nums, int l, int r){
        if(l==r){
            result.push_back(nums);
            return;
        }
        for(int i = l; i <= r; i++){
            swap(nums[l],nums[i]);
            perm(nums, l+1, r);
            swap(nums[l],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0, nums.size()-1);
        return result;
    } 
};




int main(){
    return 0;
}