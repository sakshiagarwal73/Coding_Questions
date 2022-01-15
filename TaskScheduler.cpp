//https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> m;
        for(int i=0;i<tasks.size();i++) {
           if(m.find(tasks[i])==m.end()) {
               m.insert(make_pair(tasks[i],1));
           } else {
               int freq = m.find(tasks[i])->second;
               m.erase(tasks[i]);
               m.insert(make_pair(tasks[i],freq +1 ));
           }
        }
        
        priority_queue<pair<int, char> > pq;
        for(auto it=m.begin();it!=m.end();it++) {
            pq.push(make_pair(it->second, it->first));
        }
        
        queue<pair<int, pair<int,char> > > q;
        
        int interval = 0;
        
        while(!pq.empty() || !q.empty()) {
            interval++;
            if(!pq.empty()) {
                pair<int, char> top = pq.top();
                pq.pop();
            
                if(top.first-1>0) {
                    q.push(make_pair(interval + n,make_pair(top.first-1,top.second)));
                }
            }
            
            if(!q.empty() && q.front().first==interval) {
            
                pq.push(q.front().second);
                q.pop();
            }
        }
        
        return interval;
    }
};
