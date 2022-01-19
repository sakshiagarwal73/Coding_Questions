//https://leetcode.com/problems/cheapest-flights-within-k-stops/

class cmp
{
    public:
    bool operator()( pair<int,pair<int,int> > a, pair<int,pair<int,int> > b)
    {
        return (a.second.second>b.second.second);
    }
};

class graph
{
    private:
    int vertices;
    list<pair<int,int> > adj[105];
    public:
    graph(int vertices)
    {
        this->vertices = vertices;
    }
    void addedge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
    }
    int dijkstra(int src,int dest,int k)
    {
        
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, cmp> pq;
        pq.push(make_pair(src,make_pair(-1,0)));
        int visited[105];
        for(int i=0;i<vertices;i++)
        {
            visited[i] = false;
        }
        
        while(!pq.empty())
        {
            pair<int,pair<int,int> > p = pq.top();
            pq.pop();
            if(p.first == dest)
            {
                return p.second.second;
            }
            int stops = p.second.first;
            for(auto iter = adj[p.first].begin();iter!=adj[p.first].end();iter++)
            {
                    int v = (*iter).first;
                    int w = (*iter).second;
                    
                    
                    if(visited[v] == false &&  1+stops<=k)
                    {
                       
                        
                        
                            
                            int x = p.second.first + 1;
                            int y = p.second.second + w;
                        
                            
                            pq.push(make_pair(v,make_pair(x,y)));
                        
                        
                        
                    }
                
                    
            }
                    
            visited[p.first] = true;      
            
        }
            
            return -1;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        graph g(n);
        int len = flights.size();
        for(int i=0;i<len;i++)
        {
            vector<int> v = flights[i];
            g.addedge(v[0],v[1],v[2]);
        }
        
        return g.dijkstra(src,dst,k);
        
    }
};
