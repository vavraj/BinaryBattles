#include<iostream>
#include<stack>
using namespace std;

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

// POSTFIX TO PREFIX
string postToPre(string post_exp)
{
    stack<string> s;
 
    // length of expression
    int length = post_exp.size();
 
    // reading from left to right
    for (int i = 0; i < length; i++) {
 
        // check if symbol is operator
        if (isOperator(post_exp[i])) {
 
            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
 
            // concat the operands and operator
            string temp = post_exp[i] + op2 + op1;
 
            // Push string temp back to stack
            s.push(temp);
        }
 
        // if symbol is an operand
        else {
 
            // push the operand to the stack
            s.push(string(1, post_exp[i]));
        }
    }
 
    string ans = "";
    // while (!s.empty()) {
    //     ans += s.top();
    //     s.pop();
    // }
    return s.top();
}



// POSTFIX TO INFIX
string postToInfix(string post_exp)
{
    stack<string> s;
 
    // length of expression
    int length = post_exp.size();
 
    // reading from left to right
    for (int i = 0; i < length; i++) {
 
        // check if symbol is operator
        if (isOperator(post_exp[i])) {
 
            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
 
            // concat the operands and operator
            string temp =op2+ post_exp[i] + op1;
 
            // Push string temp back to stack
            s.push(temp);
        }
 
        // if symbol is an operand
        else {
 
            // push the operand to the stack
            s.push(string(1, post_exp[i]));
        }
    }
 
    string ans = "";
    // while (!s.empty()) {
    //     ans += s.top();
    //     s.pop();
    // }
    return s.top();
}
 
// Driver Code
int main()
{
    string post_exp = "ABC/-AK/L-*";
 
    // Function call
    cout << "Prefix : " << postToInfix(post_exp);
    return 0;
}