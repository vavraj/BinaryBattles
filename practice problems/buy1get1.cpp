#include <iostream>
#include<vector>
using namespace std;

int total_cost()
{
    string s;
    cin>>s;
    int n=s.length();
    int count=0;
    int ar[26]={0};
    int AR[26]={0};
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            int index=s[i]-'a';
            ar[index]++;
        }
        else 
        {
            int index=s[i]-'A';
            AR[index]++;
        }
    }
    for(int i=0;i<26;i++)
    {
        int q=ar[i]/2;
        int r=ar[i]%2;
        int Q=AR[i]/2;
        int R=AR[i]%2;
        count=count+q+r+Q+R;
    }
    return count;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    cout<<total_cost()<<endl;
	}
	return 0;
}
