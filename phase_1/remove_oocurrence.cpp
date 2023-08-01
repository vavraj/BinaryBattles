#include <iostream>
using namespace std;

string remove_occ(string s, string part)
{
    while(s.length()!=0 && s.find(part)<s.length())
    {
        s.erase(s.find(part),part.length());//find returns the first index of the occurence of part 
    }
    return s;
}

int main()
{
    string s,part;
    cout << "Enter string: ";
    getline(cin, s);
    cout << "Enter part: ";
    getline(cin, part);
    cout<<s.find(part)<<endl;
    cout << remove_occ(s,part) << endl;
    return 0;
}