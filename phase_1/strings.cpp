#include<iostream>
using namespace std;
int get_len(char name[])
{
    int count=0;
    for(int i=0;name[i]!='\0';i++)
    count++;
    return count;
}
void reverse(char name[])
{
    char temp[20];
    int s=0;
    int e=get_len(name)-1;
    while(s<e)
    {
        swap(name[s++],name[e--]);
    }
}

int main()
{
    char name[20];
    cout<<"enter name: ";
    cin>>name;
    cout<<"Before swap: "<<name<<endl;
    reverse(name);
    cout<<"after swap: "<<name<<endl;
    return 0;
}