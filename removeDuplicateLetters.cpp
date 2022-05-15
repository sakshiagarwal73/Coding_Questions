//https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char>us;
        string ans = "";
        vector<int>freq(26,0);
        for(char x: s){
            freq[x-'a']++;
        }
        
        for(int i = 0; i<s.size(); i++){
            if(us.count(s[i]) == 0){
                while((ans.empty() == false) and freq[ans.back()-'a']>0 and ans.back()>s[i]){
                    us.erase(ans.back());
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                us.insert(s[i]);
            }
            
            freq[s[i]-'a']--;
        }
        
        return ans;
    }
};
