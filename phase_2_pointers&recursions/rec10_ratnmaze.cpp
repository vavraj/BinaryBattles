#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>m,vector<vector<int>> visited,int newx,int newy,int a,int b)
{
    if((newx>=0 && newx<a) && (newy>=0 && newy<b) && m[newx][newy]==1 && visited[newx][newy]==0)
    {
        return true;
    }
    return false;
}

void solve(vector<vector<int>>m,int a,int b,vector<vector<int>>visited,string path,vector<string>&ans,int x,int y)
{
    // you have reached x,y here

    // base condition
    // reached destination
    if(x>=a-1 && y>=b-1)
    {
        ans.push_back(path);
        return;
    }
    
    visited[x][y]=1;

    // 4 choices --> D U L R
    // for down movement
    int newx=x+1;
    int newy=y;
    if(isSafe(m,visited,newx,newy,a,b)){
        path.push_back('D');
        solve(m,a,b,visited,path,ans,newx,newy);
        path.pop_back();
    }

    // for up movement
    newx=x-1;
    newy=y;
    if(isSafe(m,visited,newx,newy,a,b)){
        path.push_back('U');
        solve(m,a,b,visited,path,ans,newx,newy);
        path.pop_back();
    }

    // for left movement
    newx=x;
    newy=y-1;
    if(isSafe(m,visited,newx,newy,a,b)){
        path.push_back('L');
        solve(m,a,b,visited,path,ans,newx,newy);
        path.pop_back();
    }

    // for right movement
    newx=x;
    newy=y+1;
    if(isSafe(m,visited,newx,newy,a,b)){
        path.push_back('R');
        solve(m,a,b,visited,path,ans,newx,newy);
        path.pop_back();
    }

    visited[x][y]=0;
} 

int main()
{
    vector<vector<int>> m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    if(m[0][0]==0)
    {
        cout<<" no Safe path! "<<endl;
        exit(1);
    }
    int a=m.size();
    int b=m[0].size();
    vector<vector<int>> visited=m;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            visited[i][j]=0;
        }
    }
    int srcx=0;
    int srcy=0;
    string path="";
    vector<string> ans;
    solve(m,a,b,visited,path,ans,srcx,srcy);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}