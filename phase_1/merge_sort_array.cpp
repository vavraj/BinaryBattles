#include <iostream>
using namespace std;

void merge_array(int ar1[], int n1, int ar2[], int n2)
{
    int n3;
    n3 = n1 + n2;
    int ar3[100];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (ar1[i] < ar2[j])
        {
            ar3[k++] = ar1[i++];
            // i++;
            // k++;
        }
        else
        {
            {
                ar3[k++] = ar2[j++];
                // j++;
                // k++;
            }
        }
    }
    while (i < n1)
    {
        ar3[k++] = ar1[i++];
    }
    while (j < n2)
    {
        ar3[k++] = ar2[j++];
    }

    for (int k = 0; k < n3; k++)
    {
        cout << ar3[k] << " ";
    }
    cout << endl;
}

int main()
{
    int ar1[] = {1, 2, 3, 4, 5, 10, 45, 50, 100};
    int ar2[] = {2, 3, 4, 6, 7, 8, 9, 15};
    int n1 = sizeof(ar1) / sizeof(int);
    int n2 = sizeof(ar2) / sizeof(int);
    merge_array(ar1, n1, ar2, n2);
    return 0;
}