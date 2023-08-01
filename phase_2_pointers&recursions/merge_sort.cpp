#include <iostream>
using namespace std;

int count = 0;
void merge(int *ar, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // creating new arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // copying values
    int mainarrayindex = s;

    for (int i = 0; i < len1; i++)
        first[i] = ar[mainarrayindex++];

    for (int i = 0; i < len2; i++)
        second[i] = ar[mainarrayindex++];

    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;

    // merging arrays
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            ar[mainarrayindex++] = first[index1++];
            // count++;
        }
        else
        {
            ar[mainarrayindex++] = second[index2++];
            count++;
        }
    }
    while (index1 < len1)
    {
        ar[mainarrayindex++] = first[index1++];
        // count++;
    }
    while (index2 < len2)
    {
        ar[mainarrayindex++] = second[index2++];
        count++;
    }
    // free space
    delete[] first;
    delete[] second;
}

void merge_sort(int *ar, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // sorting left part
    merge_sort(ar, s, mid);

    // sorting left part
    merge_sort(ar, mid + 1, e);

    // merging sorted array
    merge(ar, s, e);
}
int main()
{
    int ar[] = {1, 20, 6, 4, 5};
    int n = sizeof(ar) / sizeof(ar[0]);
    merge_sort(ar, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
    cout << "Total no of inversions required: " << count << endl;
    return 0;
}