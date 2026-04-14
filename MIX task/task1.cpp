#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char c)
{
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') 
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else {
        return -1;
    }
}

string reversestring(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) 
    {
        st.push(s[i]);
    }
    string reversed = "";
    while (!st.empty())
    {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

bool isbalanced(string expr) 
{
    stack<char> st;
    for (int i = 0; i < expr.length(); i++) 
    {
        if (expr[i] == '(') 
        {
            st.push(expr[i]);
        }
        else if (expr[i] == ')') 
        {
            if (st.empty()) 
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

string infixtopostfix(string s) 
{
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) 
        {
            result += c;
        }
        else if (c == '(') 
        {
            st.push('(');
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') 
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    string word = "hello";
    cout << "input: " << word << endl;
    cout << "output: " << reversestring(word) << endl << endl;

    string expr1 = "((a+b)*c)";
    string expr2 = "((a+b)";
    cout << "input: " << expr1 << " -> " << (isbalanced(expr1) ? "balanced" : "not balanced") << endl;
    cout << "input: " << expr2 << " -> " << (isbalanced(expr2) ? "balanced" : "not balanced") << endl << endl;

    string infix = "(a+b)*c";
    cout << "input: " << infix << endl;
    cout << "output: " << infixtopostfix(infix) << endl;

    return 0;
}