#include<iostream>
using namespace std;

int main()
{
    while(1)
    {
        int num=1;
        switch(num)
        {
            case 1:
            cout<<"Exiting infinite loop using switch case!"<<endl;
            // break; //not gonna work since it exists only switch case
            exit(1);//it actually jumps to the end of the code after n times (here 1) of execution
        }
    }
    return 0;
}