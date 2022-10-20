#include <iostream>
using namespace std;
class stack
{
    int capacity;
    int *array;
    int top;

public:
    stack(int totalsize)
    {
        capacity = totalsize;
        top = -1;
        array = new int[capacity];
    }

private:
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if (top == capacity - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(char str)
    {
        if (isfull())
        {
            cout << "stack is full" << endl;
            return;
        }
        top++;
        array[top] = str;
    }
    char pop()
    {
        char val;
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return '\0';
        }
        val = array[top];
        top--;
        return val;
    }
    bool ismatch(char a, char b)
    {
        if (a == '[' && b == ']')
        {
            return true;
        }
        else if (a == '(' && b == ')')
        {
            return true;
        }
        else if (a == '{' && b == '}')
        {
            return true;
        }
        return false;
    }

public:
    bool check_parenthesis(string s)
    {
        char c;
        int x=0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (isempty())
                {
                    return false;
                }
                c = pop();
                if (!ismatch(c, s[i]))
                {
                    return false;
                }
                else{
                    x++;
                }
            }
        }
        if (isempty())
        {
            return true;
        }
        else
        {
            return false;
        }
    
    }
};
int main()
{
    string s = ")))())()";
    stack str(s.length() + 1);
    if (str.check_parenthesis(s))
    {
        cout << "blanced expression" << endl;
    }
    else
    {
        cout << "not blanced expression" << endl;
    }
    return 0;
}