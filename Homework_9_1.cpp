/*
 * HackerRank link:
 * Title:
 * Abstract:
 * Author:
 * ID:
 * Date:
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display(vector<int> v)
{
    make_heap(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << "\n";
}

int main() 
{
    int numNodes;
    int numCommands;

    vector<int> inputs;
    vector<int> originals;

    cin >> numNodes;

    int input;

    for(int i=0; i<numNodes; i++)
    {
        cin >> input;   
        inputs.push_back(input);
        originals.push_back(input); 
    }

    make_heap(inputs.begin(), inputs.end());

    bool match = true;

    for(int i=0; i<originals.size(); i++)
    {
        if(inputs[i] != originals[i])
        {
            match = false;
            break;
        }
    }
    if(match  == true)
    {
        cout << "This is a heap." << "\n";
    }
    else if (match == false)
    {
        cout << "This is NOT a heap." << "\n";
    }

    cin >> numCommands;

    string command;
    int newNum;

    for(int i=0; i<numCommands; i++)
    {
        cin >> command;
        if(command == "deleteMax")
        {
            //inputs.erase(inputs.begin());
            //make_heap(inputs.begin(), inputs.end());
            int nFront = inputs.back();
            inputs.front() = nFront;
            inputs.pop_back();
        }
        if(command == "insert")
        {
            cin >> newNum;
            inputs.push_back(newNum);
            make_heap(inputs.begin(), inputs.end());
        }
        if(command == "delete")
        {
            cin >> newNum;
            for(int i=0; i<inputs.size(); i++)
            {
                if(newNum == inputs[i])
                {
                    inputs.erase(inputs.begin()+i);
                    make_heap(inputs.begin(), inputs.end());
                    /*int replacement = inputs.back();
                    inputs[i] = replacement;
                    inputs.pop_back();*/
                }
            }
            //make_heap(inputs.begin(), inputs.end());
        }
        if(command == "display")
        {
            //cout << "HEAP: \n";
            /*for(int i=0; i<inputs.size(); i++)
            {
                cout << inputs[i] << " ";
            }
            cout << "\n";*/
            //cout << " \n ----- \n";
            display(inputs);
        }
        if(command == "displayMax")
        {
            make_heap(inputs.begin(), inputs.end());
            int temp = inputs.front();
            cout << temp << "\n";
        }
    }

}
