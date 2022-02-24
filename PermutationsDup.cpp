//https://leetcode.com/problems/permutations-ii/
//solution given in cracking the coding interview

class Solution {
public:
    
    void fun(unordered_map<int,int> &m,vector<int> &curr, int remaining, vector<vector<int> > &res) {
        if(remaining == 0) {
            res.push_back(curr);
            return;
        }
        
        for(auto it=m.begin();it!=m.end();it++) {
            if(it->second>0) {
                int num = it->first;
                int count = it->second;
                m[num]--;
                curr.push_back(num);
                fun(m, curr, remaining -1, res);
                curr.pop_back();
                m[num]++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num : nums) {
            if(m.find(num)!=m.end()) {
                int freq = m.find(num)->second;
                m.erase(num);
                m.insert(make_pair(num, freq+1));
            } else {
                m.insert(make_pair(num, 1));
            }
        }
        
        vector<vector<int> > res;
        vector<int> curr;
        fun(m, curr, nums.size(), res);
        return res;
    }
};
