#include <iostream>
using namespace std;

char getmaxchar(string s)
{
    // initialize 0 value to all 26 (0-25) index position
    int ar[26] = {0};

    // stores th count of all characters in the array
    for (int i = 0; i < s.length(); i++)
    {
        int number = s[i] - 'a'; // number lies between 0 to 25
        ar[number]++;
    }
    int maxi = -1;
    int ans = 0;

    // finds the index position whose count is maximum!
    for (int i = 0; i < 26; i++)
    {
        if (maxi < ar[i])
        {
            ans = i; //store the index position with max count
            maxi = ar[i];
        }
    }

    //returns the caharacter with max count
    return ans + 'a';
}

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    cout << "Maximum occured cahracter is: " << getmaxchar(s)<<endl;
    return 0;
}