#include<iostream>
using namespace std;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 cout<<"hi"<<endl;
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    int ver=binaryToDecimal(s1.substr(0, 4));
    int protocol=binaryToDecimal(s1.substr(4, 8));
    string name="";
    if(protocol==6)
    name="TCP";
    else name="UDP";
    int ttl=binaryToDecimal(s1.substr(12, 8));
    int packLen=binaryToDecimal(s1.substr(20, 12));
    int sa1=binaryToDecimal(s2.substr(0, 8));
    int sa2=binaryToDecimal(s2.substr(8, 8));
    int sa3=binaryToDecimal(s2.substr(16, 8));
    int sa4=binaryToDecimal(s2.substr(24, 8));
    int da1=binaryToDecimal(s3.substr(0, 8));
    int da2=binaryToDecimal(s3.substr(8, 8));
    int da3=binaryToDecimal(s3.substr(16, 8));
    int da4=binaryToDecimal(s3.substr(24, 8));
    cout<<ver<<","<<name<<","<<ttl<<","<<packLen<<endl;
    cout<<sa1<<"."<<sa2<<"."<<sa3<<"."<<sa4<<endl;
    cout<<da1<<"."<<da2<<"."<<da3<<"."<<da4<<endl;
    return 0;
}