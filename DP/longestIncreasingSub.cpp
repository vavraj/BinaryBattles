#include<iostream>
using namespace std;


// recursion
class Solution
{
    public:
    
    int solve(int n,int a[],int currIndex,int prevIndex){
        if(currIndex==n)
            return 0;
        
           
        int take=0;
        
        if(prevIndex==-1  || a[prevIndex]<a[currIndex])  
            take=1+solve(n,a,currIndex+1,currIndex);
        
        int notTake=0+solve(n,a,currIndex+1,prevIndex);
        
        int ans=max(take,notTake);
        return ans;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return solve(n,a,0,-1);
    }
};


// recursion+memoization


class Solution
{
    public:
    
    int solve(int n,int a[],int currIndex,int prevIndex,vector<vector<int> >&dp){
        if(currIndex==n)
            return 0;
        if(dp[currIndex][prevIndex+1]!=-1)
            return dp[currIndex][prevIndex+1];
        
        int take=0;
        
        if(prevIndex==-1  || a[prevIndex]<a[currIndex])  
            take=1+solve(n,a,currIndex+1,currIndex,dp);
        
        int notTake=0+solve(n,a,currIndex+1,prevIndex,dp);
        
        dp[currIndex][prevIndex+1]=max(take,notTake);
        return dp[currIndex][prevIndex+1];
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
      vector<vector<int> >dp(n,vector<int>(n+1,-1));
       return solve(n,a,0,-1,dp);
    }
};


// tabulation 
class Solution
{
    public:
    int solveTab(int n,int a[]){
        vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        
        for(int currIndex=n-1;currIndex>=0;currIndex--){
            for(int prevIndex=currIndex-1;prevIndex>=-1;prevIndex--){
                int take=0;
        
                if(prevIndex==-1  || a[prevIndex]<a[currIndex])  
                    take=1+dp[currIndex+1][currIndex+1];
        
                int notTake=0+dp[currIndex+1][prevIndex+1];
        
                dp[currIndex][prevIndex+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }

    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return solveTab(n,a);
    }
};


// space optimization
class Solution
{
    public:
    int solveTab(int n,int a[]){
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int currIndex=n-1;currIndex>=0;currIndex--){
            for(int prevIndex=currIndex-1;prevIndex>=-1;prevIndex--){
                int take=0;
        
                if(prevIndex==-1  || a[prevIndex]<a[currIndex])  
                    take=1+nextRow[currIndex+1];
        
                int notTake=0+nextRow[prevIndex+1];
        
                currRow[prevIndex+1]=max(take,notTake);
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }

    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return solveTab(n,a);
    }
};


// optimal sol
class Solution
{
    public:
    
    int optimalSol(int n,int a[]){
        if(n==0)
            return 0;
        vector<int>ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return optimalSol(n,a);
    }
};