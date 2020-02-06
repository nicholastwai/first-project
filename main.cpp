/*
 Nicholas Wai
 Professor Xu
 CISC 2200
 18 November 2019
 This program uses a stack to check if a string expression has balanced parentheses.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* checks if a string is balanced and returns a boolean value accordingly
 @param str: string that is being checked for balance
 @pre: string is initialized
 @post: if string is balanced, function returns true, else function returns false
 @return: true or false depending on whether or not the function is balanced
 */
bool checkExpression(string str);

/* checks if a closing parenthesis has a matching open parenthesis in the stack
   and returns a boolean value accordingly
 @param ch: closing parenthesis that is being checked for a match in the stack
 @param s: stack that parentheses in the string have been pushed to
 @pre: ch is a closing parenthesis (e.g. ), }., or ]) and stack has been used to store open parentheses
 (e.g. (, {, or [)
 @post: if there is a matching parenthesis, function returns true, else function returns false
 @return: true or false depending on whether or not there is a matching parenthesis
 */
bool match(char ch, stack <char> s);

/* displays to the user whether or not the string has balanced parentheses
 @param balanced: boolean variable, assigned whatever checkExpression returns
 @pre: checkExpression has been run, and balanced has been assigned its return value
 @post: a statement is outputted to user about whether or not the string was balanced
 @return: nothing
 */
void printResult(bool balanced);

int main()
{
    string str1 = "()()]";
    string str2 = "{[()(})";
    string str3 = "[()]{}";
    string str4 = "{[()()]{}}";
    string input;
    char choice;
    bool balanced;
    
    cout << "Welcome to lab 5." << endl;
    
    do
    {
        cout << "Please select a test case to run (1, 2, 3, 4), ";
        cout << "input your own string (5), or press q to quit." << endl;
        cin >> choice;
        
        switch (choice)
        {
            case '1':
            {
                cout << "Test Case 1:" << endl << str1 << endl;
                balanced = checkExpression(str1);
                printResult(balanced);
                cout << endl;
                break;
            }
            case '2':
            {
                cout << "Test Case 2:" << endl << str2 << endl;
                balanced = checkExpression(str2);
                printResult(balanced);
                cout << endl;
                break;
            }
            case '3':
            {
                cout << "Test Case 3:" << endl << str3 << endl;
                balanced = checkExpression(str3);
                printResult(balanced);
                cout << endl;
                break;
            }
            case '4':
            {
                cout << "Test Case 4:" << endl << str4 << endl;
                balanced = checkExpression(str4);
                printResult(balanced);
                cout << endl;
                break;
            }
            case '5':
            {
                cout << "Please input a string without spaces." << endl;
                cin >> input;
                balanced = checkExpression(input);
                printResult(balanced);
                cin.clear();
                cin.ignore(1000, '\n');
                cout << endl;
                break;
            }
            case 'q':
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Please enter a valid input." << endl;
                break;
        }
    }   while (choice != 'q');
    
    return 0;
}

bool checkExpression(string str)
{
    stack <char> s;
    bool balanced = true;
    
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            s.push(str[i]);
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (s.empty())
                balanced = false;
            else if(match(str[i], s))
                s.pop();
            else
                balanced = false;
        }
        else
            continue;
    }
    
    if (!s.empty())
        balanced = false;

    return balanced;
}

bool match(char ch, stack <char> s)
{
    if(ch == ')')
    {
        if (s.top() == '(')
            return true;
        else
            return false;
    }
    else if(ch == '}')
    {
        if (s.top() == '{')
            return true;
        else
            return false;
    }
    else if (ch == ']')
    {
        if (s.top() == '[')
            return true;
        else
            return false;
    }
    else
        return false;
}

void printResult(bool balanced)
{
    if (balanced)
        cout << "This expression is balanced." << endl;
    else
        cout << "This expression is unbalanced." << endl;
}
