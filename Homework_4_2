#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <regex>
#include <vector>

using namespace std;

int main() 
{
    vector<string> input;
    vector<string> left;
    string instring;
    getline(cin, instring);

    for(int i=0; i < instring.length(); i++)
    {
        if(instring.substr(i, 1) == "[" || instring.substr(i, 1) == "]")
        {
            string temp = instring.substr(i, 1);
            input.push_back(temp);
        }
        else if(instring.substr(i, 1) == "{" || instring.substr(i, 1) == "}")
        {
            string temp = instring.substr(i, 1);
            input.push_back(temp);
        }
        else if(instring.substr(i, 1) == "(" || instring.substr(i, 1) == ")")
        {
            string temp = instring.substr(i, 1);
            input.push_back(temp);
        }
    }

    if(input.size()%2 != 0)
    {
        cout << "FALSE";
        exit(0);
    }
    else
    {
        for(int i=0; i < input.size(); i++)
        {
            if(input[i] == "{" || input[i] == "[" || input[i] == "(")
            {
                string temp = input[i];
                left.push_back(temp);
            }
            else
            {
                if(input[i] == "}" && left.back() == "{")
                {
                    left.pop_back();
                }
                else if(input[i] == "]" && left.back() == "[")
                {
                    left.pop_back();
                }
                else if(input[i] == ")" && left.back() == "(")
                {
                    left.pop_back();
                }
                else
                {
                    cout << "FALSE";
                    exit(0);
                }
            }
        }
        cout << "TRUE";
    }
}
