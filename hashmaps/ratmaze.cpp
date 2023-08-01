#include <iostream>
#include<vector>
using namespace std;
bool isSafe(int newx,int newy,vector < vector < int >> & arr,vector<vector<bool>>&visited,int n)
{
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && visited[newx][newy]==0 && arr[newx][newy]!=0)
    {
        // visited[newx][newy]=1;
        return true;
    }
    else
    {
        return false;
    }
}
void solve(int x,int y,vector < vector < int >> & arr,
     int n,vector<vector<bool>>&visited,vector<string>&ans,string path)
    {
        if(x==n-1 &&y==n-1 )
        {
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        // 4 possible path
        
        //down
        if(isSafe(x+1,y,arr,visited,n))
        {
            solve(x+1,y,arr,n,visited,ans,path+'D');
        } 
        // left
        if(isSafe(x,y-1,arr,visited,n))
        {
            solve(x,y-1,arr,n,visited,ans,path+'L');
        } 
        // right
        if(isSafe(x,y+1,arr,visited,n))
        {
            solve(x,y+1,arr,n,visited,ans,path+'R');
        } 
        // up
        if(isSafe(x-1,y,arr,visited,n))
        {
            solve(x-1,y,arr,n,visited,ans,path+'U');
        } 
        visited[x][y]=0;
    }

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    string path="";
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    solve(0,0,arr,n,visited,ans,path);
    return ans;
}