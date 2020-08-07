//https://leetcode.com/problems/k-closest-points-to-origin/

//complexity nlogk

class cmp
{
    public:
    bool operator()( pair<int,int> p1, pair<int,int> p2)
    {
        int x1 = p1.first;
        int y1 = p1.second;
        int x2 = p2.first;
        int y2 = p2.second;
        
        long long int a = pow(x1,2) + pow(y1,2);
        long long int b = pow(x2,2) + pow(y2,2);
        
        return a<b;
    }
    
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        
        int n = arr.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,cmp > pq;
        
        for(int i=0;i<k;i++)
        {
            pq.push(make_pair(arr[i][0],arr[i][1]));
        }
        
        for(int i=k;i<n;i++)
        {
            int x1 = pq.top().first;
            int y1 = pq.top().second;
            int x2 = arr[i][0];
            int y2 = arr[i][1];
            long long int a = pow(x1,2) + pow(y1,2);
            long long int b = pow(x2,2) + pow(y2,2);
            if(a>b)
            {
                pq.pop();
                pq.push(make_pair(arr[i][0],arr[i][1]));
            }
        }
        
        vector<vector<int> > ans;
        while(!pq.empty())
        {
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            vector<int> v;
            v.push_back(x);
            v.push_back(y);
            ans.push_back(v);
        }
        
        return ans;
    }
};