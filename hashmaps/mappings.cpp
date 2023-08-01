#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<string,int>m;
    pair<string,int>pair1= make_pair("vaibhav",1);
    m.insert(pair1);
    m["raj"]=2;
    cout<<"hello buddy"<<endl;
    // m.at("backchod")=3;

    cout<<m["vaibhav"]<<endl;
    // cout<<m.at("raj")<<endl;
    cout<<m["chutiya"]<<endl;
    // cout<<m.at("chutiya")<<endl;

    // to check the presence
    cout<<m.count("vaibhav")<<endl;

    // to erase
    m.erase("chutiya");

    cout<<m.size()<<endl;

    unordered_map<string,int>:: iterator it=m.begin();

    while(it!=m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}