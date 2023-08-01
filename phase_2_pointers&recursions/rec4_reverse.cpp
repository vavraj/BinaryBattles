#include <iostream>
using namespace std;

string reverse(string &s, int start, int end)
{
    if (end <= start)
    {
        return s;
    }
    swap(s[start], s[end]);
    return reverse(s, start + 1, end - 1);
}

string reverse_1(string &s, int start)
{
    if (start >= s.length() / 2)
    {
        return s;
    }
    swap(s[start], s[s.length() - start - 1]);
    start++;
    return reverse_1(s, start);
}

bool check_palindrome(string s, int start)
{
    if (start >= s.length() / 2)
    {
        return 1;
    }
    if (s[start] == s[s.length() - start - 1])
    {
        return check_palindrome(s, start+1);
    }
    return 0;
}
int exponent(int a,int b)
{
    // base cases
    if(b==0)
    return 1;

    if(b==1)
    return a;

    // recursive call
    int ans=exponent(a,b/2);

    if(b%2==0)
    {//if b is even
        return ans*ans;
    }
    else
    //if b is odd
        return a*ans*ans;
    
}
int main()
{
    // string s;
    // cin >> s;
    // int start = 0;
    // int end = s.length() - 1;
    // cout<<reverse(s,start,end)<<endl;
    // cout<<reverse_1(s,start)<<endl;
    // cout << check_palindrome(s,start) << endl;
    cout<<exponent(2,3)<<endl;
    return 0;
}