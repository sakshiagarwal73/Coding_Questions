//https://leetcode.com/problems/beautiful-array/

//https://leetcode.com/problems/beautiful-array/discuss/1370870/Java%3A-break-up-every-arithmetic-sequence-(with-visual-intuition) (proper explanantion)

class Solution {
public:
    vector<int> beautifulArray(int n) {
        
        vector<int> res;
        for(int i=1;i<=n;i++) {
            res.push_back(i);
        }
        
        return arrBeautiful(res);
        
    }
    
    vector<int> arrBeautiful(vector<int> arr) {
        int n = arr.size();
        if(n<=2) {
            return arr;
        }
        vector<int> left;
        vector<int> right;
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }
        
        vector<int> arrLeft = arrBeautiful(left);
        vector<int> arrRight = arrBeautiful(right);
        arrLeft.insert(arrLeft.end(),arrRight.begin(),arrRight.end());
        return arrLeft;
    }
};
