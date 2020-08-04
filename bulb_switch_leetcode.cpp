//https://leetcode.com/problems/bulb-switcher-iv/


class Solution {
public:
    int minFlips(string target) {
        
        int n = target.length();
        bool b = false;
        for(int i=0;i<n;i++)
        {
            if(target[i]=='1')
            {
                b = true;
                break;
            }
        }
        if(!b)
        {
            return 0;
        }
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(0);
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==0 && target[i]=='1')
            {
                v[i] = 1;
            }
            else if(i!=0)
            {
                if(target[i-1]!=target[i])
                {
                    v[i] = v[i-1] + 1;
                }
                else
                {
                    v[i] = v[i-1];
                }
            }
        }
        
       
        int ans = v[n-1];
        return ans;
    }
};