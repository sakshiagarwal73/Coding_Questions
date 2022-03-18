//https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(long num, long den) {
        
        unordered_map<long, long> m; //key - rem , value - position at which this remainder was found
        bool isNeg = false;
        
       
        if((num<0 && den>0) || (num>0 && den<0)) {
            isNeg = true;
        }
         if(num<0) {
            num = num * -1;
        }
        if(den<0) {
            den = den*-1;
        }
        cout<<isNeg<<endl;
        
        string res;
        long div = num/den;
        long rem = num % den;
        res+=to_string(div);
        res+=".";
        while(rem!=0 && m.find(rem)==m.end()) {
            m.insert(make_pair(rem, res.length()));
            rem = rem*10;
            res+=to_string(rem/den);
            rem = rem%den;
        }
        
        if(rem==0) {
            if(isNeg) {
                res = "-" + res;
            }
            if(res[res.length()-1]=='.') {
                return res.substr(0, res.length()-1);
            }
            return res;
        } else {
            string rep = res.substr(m[rem]);
            long index = res.find(rep);
            string before = res.substr(0, index);
            string final_res = before + "(" + rep + ")";
            if(isNeg) {
                final_res = "-" + final_res;
            }
            return final_res;
        }
    }
};
