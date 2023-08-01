#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;
    m[3] = "Laxmi";
    m[2] = "Saraswati";
    m.insert({4, "Tanu"});
    m[1] = "Parvati";
    m.insert({5, "Muskan"});
    m.insert({6, "Sanika"});
    m.insert({7, "Varsha"});
    for (auto i : m)
    {
        cout << i.first << " " << i.second << " " << endl;
    }
    cout << endl;
    m.erase(5);
    for (auto i : m)
    {
        cout << i.first << " " << i.second << " " << endl;
    }
    cout << endl;
    map<int, string>::iterator itr = m.find(6);
    for (auto i = m.begin(); i != itr; i++)
    {
        cout << (*i).first << " " << (*i).second << " " << endl;
    }

    return 0;
}