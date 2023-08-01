#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> form_pair(vector<int> &arr)
{
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == 5)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    // sort(ans.begin(), ans.end());
    return ans;
}
vector<vector<int>> form_triplet(vector<int> &arr)
{
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == 12)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    // temp.push_back(max(arr[i], arr[j], arr[k]));
                    ans.push_back(temp);
                }
            }
        }
    }
    // sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> vt = {2, 3, 5, 6, 1, 4, 3, 7, -2, 10, -5};
    vector<vector<int>> a = form_triplet(vt);
    for (int i = 0; i < a.size(); i++)
    {
        vector<int> temp = a[i];
        for (int j = 0; j < 3; j++)
        {
            cout << temp[j] << " ";
        }
        cout << endl;
    }
    return 0;
}