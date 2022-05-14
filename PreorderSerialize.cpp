// Verify preorder serialization of a binary tree.
// Leetcode: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
    public:
        bool isValidSerialization(string preorder) {
            int count = 1;
            stringstream ss(preorder);
            string token;
            while (getline(ss, token, ',')) {
                if (--count < 0) return false;
                if (token != "#") count += 2;
            }
            return count == 0;      
        }
    };
