#include <bits/stdc++.h>
using namespace std;

/*There are n students in a class. Every student can have 0 or more friends. 
  If A is a friend of B and B is a friend of C then A and C are also friends. So we define a friend circle as a group of
  students who are friends as given by above definition. Given an nXn-matrix friends which consists of characters Y or N. 
  If friends[i][j]=Y, then ith and jth students are friends, friends[i][j]=N, then i and j are not friends. Find the total 
  number of such friend circles in the class.*/

void dfs(int x,int y, int matrix[4][4], int n, bool visited[4][4]) {
    if(x<0 || y<0 || x>=n || y>=n || visited[x][y] || matrix[x][y]==0) {
        return;
    }
     
    visited[x][y] = 1;
    dfs(x+1,y,matrix,n,visited); 
    dfs(x,y+1,matrix,n,visited); 
    dfs(x-1,y,matrix,n,visited); 
    dfs(x,y-1,matrix,n,visited); 
}

int getCircles(int matrix[4][4],int n) {

    bool visited[4][4] ;
    memset(visited,false,sizeof(visited));
    
    int numOfCircles = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
           if(matrix[i][j]==1 && visited[i][j]==false) {
               numOfCircles++;
               dfs(i,j,matrix,n,visited);
           }
        }
    }

    return numOfCircles;
}



int main() {

  int n = 4;
  int friends[4][4] = {
    {1,1,0,0},
    {1,1,1,0},
    {0,1,1,0},
    {0,0,0,1}
  };
  
  cout << "Number of friends circles: " << getCircles(friends, n);
  return 0;
}
