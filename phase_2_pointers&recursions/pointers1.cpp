#include<iostream>
using namespace std;

int main()
{/*
    int arr[10];
    arr[0]=23;
    arr[1]=42;
    cout<<"Address of first memory block is "<<arr<<endl;
    cout<<"Address of first memory block is "<<&arr[0]<<endl;
    cout<<"Address of first memory block is "<<&arr<<endl;
    cout<<"Value at first memory block is "<<*arr<<endl;
    cout<<*arr+1<<endl;//23+1
    cout<<*(arr)+1<<endl;//23+1
    cout<<"Value at second memory block "<<*(arr+1)<<endl;//*(0+1 index) or dereference the 
    // value at second memory block
    cout<<0[arr]<<" "<<1[arr]<<endl;
    //  arr[i]=*(arr+i)
    // i[arr]=*(i+arr)
    //  dono sahi hai 
 */   /*
    int temp[10];
    temp[0]=23;
    cout<<sizeof(temp)<<endl;
    cout<<sizeof(*temp)<<endl;
    cout<<sizeof(&temp)<<endl;

    int *ptr = &temp[0];
    cout<<sizeof(ptr)<<endl;//8 print hona chahiye but memory address hexadecimal me nii hai isiliye nii ho rha hai shaayad!!
    cout<<&temp<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;
 
   int a[20]={1,2,3,4,5};
   cout<<a<<endl;
   cout<<&a<<endl;
   cout<<&a[0]<<endl;
   int *ptr=&a[0];
   cout<<ptr<<endl;
   cout<<*ptr<<endl;
   cout<<&ptr<<endl;
      */
     int ar[10]={1,2,3,4,5};
    //  ar=ar+1;   throw an error because it is stored in symbol table
     int *ptr=&ar[0];
     cout<<ptr<<endl;
     cout<<*ptr<<endl;
     ptr=ptr+1;
     cout<<ptr<<endl;
     cout<<*ptr<<endl;
    return 0;
}