#include <iostream>
using namespace std;

bool check_equality(int ar1[26], int ar2[26])
{
    int i = 0;
    while (i < 26)
    {
        if (ar1[i] != ar2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

bool check_perm(string s1, string s2)
{
    if(s1.length()>s2.length())
    {
        return 0;
    }
    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    int i = 0;
    int window = s1.length();
    while (i < window && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (check_equality(count1, count2))
    {
        return true;
    }
    while (i < s2.length())
    {
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]++;

        char oldchar = s2[i - window];
        index = oldchar - 'a';
        count2[index]--;
        i++;
        if (check_equality(count1, count2))
        {
            return true;
        }
    }

    return false;
}


int main()
{
    string s, part;
    cout << "Enter string: ";
    getline(cin, s);
    cout << "Enter part: ";
    getline(cin, part);
    int x = check_perm(part, s);
    cout <<"Returns the value: "<< x << endl;
    return 0;
}