#include <iostream>
using namespace std;

string check(char ar[], int x)
{
    if(x<4)
    {
        return "Yes";
    }
    for(int j=0;j<x-4;j++)
    {
        int count=0;
        for(int i=j;i<4;i++)
        {
            if(ar[i]!='a'&&ar[i]!='e'&&ar[i]!='i'&&ar[i]!='o'&&ar[i]!='u')
            {
                count++;
                if(count==4)
                return "No";
            }
        }
        
    }
    return "Yes";
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    char s[100];
	    int x;
	    cin>>x;
	    for(int i=0;i<x;i++)
	    {
	        cin>>s[i];
	    }
	    cout<<check(s,x)<<endl;
	}
	return 0;
}
