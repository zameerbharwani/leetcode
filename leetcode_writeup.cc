//Brute Force Solution 

class Solution {
    
    int travel(const int m, const int n,const int i, const int j){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j==n-1) return 1;
        return travel(m,n,i+1,j) + travel(m,n,i,j+1);
    }
    
public:
    int uniquePaths(int m, int n) {
        return travel(m,n,0,0);
    }
};

/*
Analysis: When we go out of bounds, we can't possibly get to the bottom right corner by going down or right, so
by returning 0 we're saying we have found no path by taking these steps to try to get to the bottom right corner.
Likewise, when do we reach the bottom right corner, we return 1, which is akin to saying we've found a path. 
These two are our bases cases. Our recursive cases are when we are in bounds and not at the bottom right corner, 
so we try to take a step right and we try to take step down. 

Time Complexity: O((n+m)!/n!m!). In order to reach [m-1][n-1], we need to take m steps down (D) and n steps right (R),
in any order. In other words, how many permutations are there of a string composed of 'm' 'D's and 'n' 'R's.
Space complexity: O(m+n). This is due to our recursion stack. 
*/

//Memoization Solution:

class Solution {
    
    int travel(const int m, const int n,const int i, const int j,vector<vector<int>>&memo){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j==n-1) return 1;
        if(memo[i][j]!=-1) return memo[i][j];
        memo[i][j] = travel(m,n,i+1,j,memo) + travel(m,n,i,j+1,memo);
        return memo[i][j];
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n,-1));
        return travel(m,n,0,0,memo);
    }
};

/*
Analysis: If we try drawing the recursion tree, we'll see that there are many repeated calls. For example,
consider m = 3, n = 2. We will call the function with input (3,2,1,1) more than once.

Time Complexity: O(n*m) since we visit every co-ordinate of our mxn grid at most once
Space Complexity: O(n*m). This is for the memo matrix we use to cache our results
*/

//Dynamic Programming Solution:

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,1));        
        for (int i = n-2; i>=0;i--){
            for(int j = m-2; j>=0;j--){
                dp[i][j]= dp[i][j+1] + dp[i+1][j];
            }
        }     
        return dp[0][0];
    }
};

/*
Analysis: When initializing our DP matrix, we want to fill the bottom most row and the right most colum with 1's. 
This is because once we travel to the bottom row, we only have 1 way to go to grid[m-1][n-1]; this happens by going right every time.
The same goes with once we arrive at the last column. There is only 1 way to get to to [m-1][n-1]; 
this happens by going down every time. Now, every preceeding position, the number of ways to get to the 
bottom right corner is simply the sum of the ways to get there by going right + the number of the ways to get there by 
going down; this is our optimal substructure.


Time Complexity: O(n*m) since we visit every co-ordinate of our mxn grid at most once
Space Complexity: O(n*m). This is for the dp matrix we need to build.
*/
