#include <iostream>
using namespace std;

int partition(int *ar, int s, int e)
{
    int pivot = ar[s];
    int count = 0;
    for (int i = s+1; i <= e; i++)
        if (ar[i] <= pivot)
            count++;

    int pivot_index=s+count;
 
    swap(ar[s], ar[pivot_index]); 
 
    int i = 0;
    int j = e ;
 
    while (i < pivot_index && j>pivot_index)
    {
        // yaha par while loop laga hai to dhayn de
        while(ar[i]<pivot)
        {
            i++;
        }
        // yaha par while loop laga hai to dhayn de
        while(ar[j]>pivot){
            j--;
        }
        if (i<pivot_index && j > pivot_index)
        {
            swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    return pivot_index;
}
void quickSort(int *ar, int s, int e)
{
    // base case
    if (s >= e)
        return;
    // finding partition and also performing shifting
    int p = partition(ar, s, e);

    // sorting left part
    quickSort(ar, s, p - 1);

    // sorting right part
    quickSort(ar, p + 1, e);
}
int main()
{
    int ar[] = {3, 1, 4, 5, 2};
    quickSort(ar, 0, 4);

    for (int i = 0; i < 5; i++)
        cout << ar[i] << " ";

    cout << endl;
    return 0;
}