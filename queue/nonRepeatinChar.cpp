#include<iostream>
#include<map>
#include<queue>
using namespace std;

string FirstNonRepeating(string s)
{
    map<char,int>count;
    queue<char>q;
    string ans="";
    for(int i=0;i<s.length();i++)// aaabbbcddd   abcde
    {
        char ch=s[i];
        // increase count
        count[ch]++;
        // push element in queue
        q.push(ch);

        while(!q.empty())
        {
            if(count[q.front()]>1)
            {//repeating character
                q.pop();
            }
            else{
                // non-repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<FirstNonRepeating(s)<<endl;
    return 0;
}