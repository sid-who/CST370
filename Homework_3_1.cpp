#include <iostream>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string input;
    bool match = true;
    
    getline(cin, input);
        
    regex nonum ("[^A-Za-z0-9]");
        
    input = regex_replace(input, nonum, "");

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if(input.length()%2 == 0)//even
    {
        int backPos = 1;
        for(int i=0; i < input.length()/2; i++)
        {
            if(input.substr(i, 1).compare(input.substr(input.length()-backPos, 1)) == 0)
            {
                backPos += 1;
            }
            else
            {
                match = false;
                break;
            }
        }
    }
    else if(input.length()%2 !=0)//odd
    {
        int backPos = 1;
        double range = (input.length()/2) - 0.5;

        for(int i=0; i < range; i++)
        {
            if(input.substr(i, 1).compare(input.substr(input.length()-backPos, 1)) == 0)
            {
                backPos += 1;
            }
            else
            {
                match = false;
                break;
            }
        }
    }

    if(match == false)
    {
        cout << "FALSE";
    }
    else
    {
        cout << "TRUE";
    }
}
