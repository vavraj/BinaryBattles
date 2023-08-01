#include <iostream>
#include <algorithm>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(6);
    v.push_back(4);
    v.push_back(50);
    v.push_back(10);
    cout << "Finding 2 " << binary_search(v.begin(), v.end(), 2) << endl;
    cout << "Finding 50 " << binary_search(v.begin(), v.end(), 50) << endl;
    cout << "lower bound of 4: " << lower_bound(v.begin(), v.end(), 4) - v.begin() << endl;
    cout << "upper bound of 4: " << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;

    int a = 3, b = 5;
    cout << "Min-->" << min(a, b) << endl;
    cout << "Max-->" << max(a, b) << endl;
    cout << "Before swap   a:" << a << "  b:" << b << endl;
    swap(a, b);
    cout << "After swap   a:" << a << "  b:" << b << endl;

    string s = "abcd";
    cout << "string before reverse: " << s << endl;
    reverse(s.begin(), s.end());
    cout << "string after reverse: " << s << endl;
    cout << "before roatate" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    rotate(v.begin(), v.begin() + 2, v.end());
    cout << "After roatate" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(v.begin(),v.end());   
    cout<<"After sorting: "<<endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout<<endl;
    return 0;
}