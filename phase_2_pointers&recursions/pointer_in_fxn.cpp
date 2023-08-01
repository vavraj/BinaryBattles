#include<iostream>
using namespace std;

void update(int *p)
{
    p=p+1;
    cout<<"inside: "<<p<<endl;//it gets updated
}


void update_value(int *p)
{
    (*p)++;
}


void print(int *p)
{
    cout<<*p<<endl;
}

int get_sum1(int ar[], int n)
{
    cout<<"size of array: "<<sizeof(ar)<<endl;//ye actual pointer ka size de rha hai jo ki first element ko point kr rha hai naaa ki poora array ka size !!
    // so basically hamlog array ka pointer ko hi pass krte hai
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=i[ar]; // *(i+ar)
    }
    return sum;
}

int get_sum2(int *ar, int n)//ye array pass nii ho rha hai balki ek pointer create ho rha hai!
{
    cout<<"size of array: "<<sizeof(ar)<<endl;//ye actual pointer ka size de rha hai jo ki first element ko point kr rha hai!!
    return 0;
}

// dono ka matlab same hai

int main()
{
/*    int temp=5;
    int *p=&temp;
    // print(p);
    cout<<"Before: "<<p<<endl;
    update(p);
    cout<<"After: "<<p<<endl;//it doesn't gets updated
    cout<<"Before: "<<*p<<endl;
    update_value(p);
    cout<<"After: "<<*p<<endl;
    */
   int arr[5]={1,2,3,4,5};
   get_sum1(arr,5);
   get_sum2(arr,5);
    return 0;
}