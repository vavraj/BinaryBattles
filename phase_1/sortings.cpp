#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

vector<int> vaibhav_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int k = j;
            while (arr[k] < arr[k - 1])
            {
                swap(arr[k], arr[k - 1]);
                if (k > 1)
                {
                    k--;
                }
            }
        }
    }
    return arr;
}

vector<int> selection_sort(vector<int> &arr)
{

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
        for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return arr;
}

vector<int> bubble_Sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++) // total rounds
    {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == true)
        {
            // already sorted
            break;
        }
    }
    return arr;
}

vector<int> insertion_Sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)                           
            { // shift
                arr[j + 1] = arr[j];
            }
            else
            { // ruk jao
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
    return arr;
}

int main()
{
    vector<int> vt = {1, 7, 9, 2, 3, 0};
    // vector<int> ans1 = vaibhav_sort(vt);
    // for (int i = 0; i < ans1.size(); i++)
    // {
    //     cout << ans1[i] << " ";
    // }
    vector<int> ans2 = selection_sort(vt);
    // for (int i = 0; i < ans2.size(); i++)
    // {
    //     cout << ans2[i] << " ";
    // }
    // vector<int> ans3 = bubble_Sort(vt);
    // for (int i = 0; i < ans3.size(); i++)
    // {
    //     cout << ans3[i] << " ";
    // }
    // vector<int> ans4 = insertion_Sort(vt);
    // for (int i = 0; i < ans4.size(); i++)
    // {
    //     cout << ans4[i] << " ";
    // }
    return 0;
}