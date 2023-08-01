#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(2);
    s.insert(2); // T.C. of insert operation is O(log n) due to binary search
    s.insert(5);
    s.insert(1);
    s.insert(10);
    s.insert(30);
    s.insert(6);
    s.insert(3);
    for (auto i : s)
    {
        cout << i << endl;
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for (auto i : s)
    {
        cout << i << endl;
    }
    cout<<endl;
    cout<<"is -5 present in set "<<s.count(-5);
    cout<<"is 5 present in set "<<s.count(5);
    cout<<endl;
    set<int>::iterator itr=s.find(5);
    for (auto it=itr;it!=s.end();it++)
    {
        cout << *it << endl;
    }
    cout<<endl;
    return 0;
}