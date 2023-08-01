#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a(5,1);
    for(int i:a)
    {
        cout<<i;
    }
    vector<int> vt;
    cout<<"Capcity of vector "<<vt.capacity()<<endl;
    vt.push_back(1);
    cout<<"Capcity of vector "<<vt.capacity()<<endl;
    vt.push_back(2);
    cout<<"Capcity of vector "<<vt.capacity()<<endl;
    vt.push_back(3);
    cout<<"Capcity of vector "<<vt.capacity()<<endl;
    cout<<"element at 2nd index "<<vt.at(2)<<endl;
    cout<<"1st element "<<vt.front()<<endl;
    cout<<"last element "<<vt.back()<<endl;
    cout<<"befor pop "<<endl;
    for(int i:vt)
    cout<<i;
    vt.pop_back();
    cout<<"\nafter pop "<<endl;
    for(int i:vt)
    cout<<i;
    cout<<endl;
    cout<<"Size before clear: "<<vt.size()<<endl;
    vt.clear();
    cout<<"Size after clear: "<<vt.size()<<endl;
    // cout<<vt.begin(); //wrong statement since its an iterartor   
    cout<<endl;
    return 0;
}