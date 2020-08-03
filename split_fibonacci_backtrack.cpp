
https://leetcode.com/problems/split-array-into-fibonacci-sequence/

class Solution {
public:
    bool fun(string str,int index,vector<int> &v)
    {
        if(index==str.length())
        {
            if(v.size()>=3)
            {
                return true;
            }
            return false;
        }
        
        long long int num = 0;
        for(int i=index;i<(int)str.length();i++)
        {
            if(num==0 && i!=index && str[i-1]=='0') //skip leading zeros
                break;
             num=(long long int)(num*10)+(str[i]-'0');
            if(num>INT_MAX)
            {
               return false;
            }
            int size = v.size();
            if(v.size()<2 )
            {
                v.push_back(num);
                if(fun(str,i+1,v))
                {
                    return true;
                }
                v.pop_back();
            }
            else if((long long int) v[size-1] + (long long int)v[size-2]==num)
            {
                v.push_back(num);
                if(fun(str,i+1,v))
                {
                    return true;
                }
                v.pop_back();
                return false;
            }
            else if((long long int) v[size-1] + (long long int)v[size-2]<num)
            {
                return false;
            }
           
        }
        
        return false;
    }
    vector<int> splitIntoFibonacci(string str) {
        
        vector<int> v;
        fun(str,0,v);
        return v;
    }
};