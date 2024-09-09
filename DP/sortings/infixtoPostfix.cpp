#include<iostream>
#include<stack>

// infix to postfix
using namespace std;
int prec(char x){
    if(x=='^')
        return 3;
    else if(x=='/'|| x=='*')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    else 
        return -1;
}

char assco(char x){
    if(x=='^')
        return 'R';
    return 'L';
}

string infixToPostfix(string str){
    stack<char>st;
    string result="";

    for(int i=0;i<str.length();i++){
        char s=str[i];

        if(s>='A' && s<='Z' ||s>='a' && s<='z' || 
        s>='0' && s<='9'){
            result=result+s;    
        }

        else if(s=='('){
            st.push(s);
        }
        else if(s==')'){
            while(st.top()!='('){
                result=result+st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && prec(s)<prec(st.top()) ||
            !st.empty() && prec(s)==prec(st.top()) && assco(s)=='L'){
                result=result+st.top();
                st.pop();
            }
            st.push(s);
        }
    }

    while(!st.empty()){
        result=result+st.top();

        st.pop();
    }
    return result;

    

}


bool isOperator(char c){
    switch (c)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

// prefix to infix
string preToInfix(string str){
    int len=str.length();
    stack<string>st;

    for(int i=len-1;i>=0;i--){
        if(isOperator(str[i])){
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();

            string temp=s1+str[i]+s2;
            st.push(temp);
        }
        else{
            st.push(string(1,str[i]));
        }
    }
    return st.top();
}
string preToPostfix(string str){
    int len=str.length();
    stack<string>st;

    for(int i=len-1;i>=0;i--){
        if(isOperator(str[i])){
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();

            string temp=s1+s2+str[i];
            st.push(temp);
        }
        else{
            st.push(string(1,str[i]));
        }
    }
    return st.top();
}


int main(){
    string str="a+b*(c^d-e)^(f+g*h)-i";
    string ans=infixToPostfix(str);
    string ans2=preToInfix("*-A/BC-/AKL");
    string ans3=preToPostfix("*-A/BC-/AKL");
    cout<<ans<<" "<<ans2<<" "<<ans3<<endl;
}