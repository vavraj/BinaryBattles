#include <iostream>
using namespace std;

void selec_sort(int *ar, int n)
{
    // base condition
    if (n == 0 || n == 1)
        return;

    // relative recursion
        int temp_index = 0;
        for (int j =0; j < n; j++)
        {
            if(ar[j]<ar[temp_index])
            {
                temp_index=j;
            }
        }
        swap(ar[0],ar[temp_index]);
        for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
        cout<<endl;
    
    selec_sort(ar+1,n-1);

}

/*
void selec_sort(int *ar, int n)
{
    // base condition
    if (n == 0 || n == 1)
        return;

    // relative recursion
        int temp_index = n-1;
        for (int j =0; j < n; j++)
        {
            if(ar[j]>ar[temp_index])
            {
                temp_index=j;
            }
        }
        swap(ar[n-1],ar[temp_index]);
        for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
        cout<<endl;
    
    selec_sort(ar,n-1);

}
*/
int main()
{
    int ar[] = {45,5,82,14,3};
    selec_sort(ar, 5);
    for(int i=0;i<5;i++)
    cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}