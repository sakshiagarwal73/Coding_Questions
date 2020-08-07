
//https://leetcode.com/problems/zigzag-conversion/


//Akshit's code(allocating space for n characters without specifying rows and columns)
if (n == 1) {
		return s;
	}

	int x = 0;
	vector<string> a(n);

	int f = 0;
	for (int i = 0; i < s.size(); i++) {
		a[x].push_back(s[i]);
		if (x == 0) {
			f = 1;
		}
		else if (x == n - 1) {
			f = 0;
		}

		if (f == 1) {
			x++;
		}
		else {
			x--;
		}
	}
	string r = "";
	for (int i=0;i<a.size();i++){
		r += a[i];
	}
	return r;



	//My approach
	//find out number of columns and then fill the matrix in zigzag fashion
	class Solution {
public:
    string convert(string str, int r) {
        
        int n = str.length();
        if(n==0 || n==1 || n==2)
        {
            return str;
        }
        if(r==1)
        {
            return str;
        }
        int x = n/(2*r-2);
        int c = 0;
        if(n%(2*r-2)==0)
        {
            c = (r-1)*x;
        }
        else
        {
            c = (r-1)*x;
            int num_left = n%(2*r-2);
            num_left-=r;
            c++;
            while(num_left>0)
            {
                num_left--;
                c++;
            }
        }
        
        
        
        vector<vector<char> > v(r);
        for(int i=0;i<r;i++)
        {
            v[i] = vector<char>(c);
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                v[i][j] = '0';
            }
        }
        int iter = 0;
        int j = 0;
        while(j<c)
        {
            if(iter>=n)
            {
                break;
            }
            for(int i=0;i<r;i++)
            {
                v[i][j] = str[iter];
                iter++;
                if(iter>=n)
                {
                    break;
                }
            }
            int row = r-2;
            j++;
            while(row>=1 && j<c)
            {
                v[row][j] = str[iter];
                iter++;
                if(iter>=n)
                {
                    break;
                }
                row--;
                j++;
            }
        }
        
        string res;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(v[i][j]!='0')
                {
                    
                    res.push_back(v[i][j]);
                }
                
            }
            
        
        }
        
        return res;
    }
};