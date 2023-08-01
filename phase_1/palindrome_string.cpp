#include<iostream>
using namespace std;
int get_len(char name[])
{
    int count=0;
    for(int i=0;name[i]!='\0';i++)
    count++;
    return count;
}
/*
bool palindrome(char name[])
{
    string temp=name;//but this increases space complexity 
    int s=0;
    int e=get_len(name)-1;
    while(s<e)
    {
        // swap(name[s++],name[e--]);
        char tmp=name[s];
        name[s++]=name[e];
        name[e--]=tmp;
    }
    if(temp==name)
    {
        return true;
    }
    return false;
}*/


char tolowercase(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else
    ch=ch-'A'+'a';
    return ch;
}


bool palindrome(char name[])
{
    int s=0;
    int e=get_len(name)-1;
    while(s<=e)
    {

        if(tolowercase(name[s++])==tolowercase(name[e--]))
        {
            
        }
        else
        break;
    }
    if(s>e)
    {
        return true;
    }
    return false;
}

int main()
{
    char name[20];
    cout<<"enter name: ";
    cin>>name;
    if(palindrome(name))
    {
        cout<<"String is palindrome! "<<endl;
    }   
    else
    cout<<"Not palindrome! "<<endl;
    return 0;
}