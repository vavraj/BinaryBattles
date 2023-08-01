#include<iostream>
#include<vector>
using namespace std;

void solve(string digits, string output,int index,string mapping[],vector<string>& ans)
{
    // base condition
    if(index>=digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number=digits[index]-'0';
    string value=mapping[number];
    
    // digits="234"
    // index=0(then 1,2,3....)
    // number=2(string)-0(string)=2(int)
    // value=mapping_of(2) --> "abc"

    for(int i=0;i<value.length();i++)
    {
        output.push_back(value[i]);
        solve(digits,output,index+1,mapping,ans);
        output.pop_back();//back-tracking so that when it will return its output is again empty as its final output is stored in ans 
    }
}

int main()
{
    vector<string> ans;
    string output=" ";
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string digits="23";
    solve(digits,output,index,mapping,ans);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}