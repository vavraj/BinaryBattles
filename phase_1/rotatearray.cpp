#include <iostream>
using namespace std;
void rotate(int ar[], int size, int n)
{
    int temp[size];
    for (int i = 0; i < size; i++)
    {
        temp[(n + i) % size] = ar[i];
    }
    
    for (int i = 0; i < size; i++)
    {
       ar[i]=temp[i];
    }
    // ar=temp; will work in vector! 
}
bool check(int ar[], int size)
{
    int count=0;
    for(int i=1;i<size;i++)
    {
        if(ar[i-1]>ar[i])
        count++;
    }
    if(ar[size-1]>ar[0])
    count++;

    return count<=1;  //count=0 if all elements are equal or array is sorted but not rotated
}
int main()
{
    int ar[] = {2, 45, 65, 78, 94};
    int size = sizeof(ar) / sizeof(int);
    cout << "no of place u want to rotate: ";
    int n;
    cin >> n;
    rotate(ar, size, n);
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    if(check(ar,size))
    cout<<"sorted and maybe or maybe not rotated "<<endl;
    else
    cout<<"Unsorted ";
    return 0;
}