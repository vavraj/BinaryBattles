#include <iostream>
#include <vector>
using namespace std;

bool bs(vector<vector<int>> ar, int target)
{
    int row = ar.size();
    int col = ar[0].size();
    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int element = ar[mid / col][mid % col];
        if (element == target)
        {
            return true;
        }
        else if (target < element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return 0;
}

// array sorted in rowwise  

int main()
{
    vector<vector<int>> ar1;
    for (int i = 0; i < 2; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            int n;
            cout << "enter number: ";
            cin>>n;
            temp.push_back(n);
        }
        ar1.push_back(temp);
    }
    int target;
    cout << "Enter no to be searched: ";
    cin >> target;
    cout << endl;
    cout <<"Element found status: "<<bs(ar1, target) << endl;
    return 0;
}