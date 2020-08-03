//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/


class Solution {
public:
    
    vector<int> fun(TreeNode *root,int level,int distance,int &ans)
    {
        if(!root)
        {
            vector<int> v;
            return v;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            vector<int> v;
            v.push_back(level);
            return v;
        }
        
        vector<int> l = fun(root->left,level+1,distance,ans);
        vector<int> r = fun(root->right,level+1,distance,ans);
        
        if(l.size()==0)
        {
            return r;
        }
        else if(r.size()==0)
        {
            return l;
        }
        
        for(int i=0;i<(int)l.size();i++)
        {
            for(int j = 0;j<(int)r.size();j++)
            {
                int dist = l[i] - level + r[j] - level;
                if(dist<=distance)
                {
                    ans++;
                }
            }
        }
        
         l.insert(l.end(),r.begin(),r.end());
         return l;
    }
    
    int countPairs(TreeNode* root, int distance) {
        
        int ans = 0;
        fun(root,0,distance,ans);
        return ans;
    }
};