#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main() 
{
    vector<string> inputs;

    vector<char> discovery;

    vector<vector<char>> adjlist;

    queue<char> fullq;
    queue<char> solq;

    //unordered_map<char, bool> markMap;
    unordered_map<char, int> markMap;

    unordered_set<char> uniqueSet;

    string input;
    
    int numin;

    int maxStr = 0;

    cin >> numin;

    for(int i=0; i<numin; i++)
    {
        //getline(cin, input);
        cin >> input;
        if(input.size() > maxStr)
        {
            maxStr = input.size();
        }
        inputs.push_back(input);
    }

    for(int i=0; i<maxStr; i++)
    {
        vector<char> temp;
        adjlist.push_back(temp);
    }

    int stringLoc = 0;

    for(int i=0; i<inputs.size(); i++)
    {
        for(int j=0; j<inputs[i].length(); j++)
        {
            char temp = inputs[i].at(j);
            uniqueSet.insert(temp);
        }
    }

    for(const char& x : uniqueSet)
    {
        //cout << x << " ";
        markMap.insert( {x, 0} );
    }

    //grab first character of each string
    /*for(int i=0; i<inputs.size(); i++)
    {
        char temp = inputs[i].at(0);
        if(markMap.count(temp) == 0)
        {
            markMap.insert({temp, mark});
            mark = mark + 1;
        }
    }*/

    for(int i=0; i<inputs.size(); i++)
    {
        for(int j=0; j<inputs[i].length(); j++)
        {
            //cout << "INPUT --> \n";
            char temp = inputs[i].at(j);
            //cout << temp << " pushed to " << i << ", " << j << "\n";
            adjlist[j].push_back(temp);
            //uniqueSet.insert(temp);
        }
    }

    //cout << "adjlist size" << adjlist.size() << " " << endl;

    /*for(int i=0; i<adjlist.size(); i++)
    {
        for(int j=0; j<adjlist[i].size(); j++)
        {
            //cout << " " << adjlist[i][j] << " " << "@ i//"<< i << " j//" << j;
            cout << adjlist[i][j] << " ";
        }
        cout << "\n";
    }*/

    /*if(adjlist[0].size() > 1 && adjlist[1].size() > 0)
    {
        if(adjlist[0][0] == adjlist[1][0])
        {
            cout << "Invalid input";
            exit(0);
        }
    }*/

    for(int i=0; i<adjlist.size(); i++)
    {
        for(int j=0; j<adjlist[i].size(); j++)
        {
            fullq.push(adjlist[i][j]);
        }
    }

    int mark = 1;

    while(!fullq.empty())
    {
        char checked = fullq.front();
        fullq.pop();
        if(markMap[checked] == 0)
        {
            markMap[checked] = mark;
            mark = mark + 1;
        }
    }

    /*do{
        int position = 0;
        for(int i=0; i<inputs.size(); i++)
        {
            if(mark <= inputs[i].length())
            {
                temp = inputs[i].at(position);
                if(markMap.count(temp) == 0)
                {
                    markMap.insert({temp, mark});
                    mark = mark + 1;
                }
            }
        }
        position = position + 1;
    }while (mark <= uniqueSet.size());//(mark != (inputs.size()));*/

    //int totalChars = uniqueSet.size();
    

    //cout << temp << "\n";
    
    /*for(const char& x: uniqueSet)
    {
        cout << x << " -> " << markMap[x] << "\n";
    }*/

    //check the inputs against the mark array
    /*for(int i=0; i<inputs.size(); i++)
    {
        for(int j=1; j<inputs[i].length(); j++)
        {
            if(inputs[i].length() - 1 != j)
            {
                char temp1 = inputs[i].at(j);
                char temp2 = inputs[i].at(j+1);
                int t1_val = markMap[temp1];
                int t2_val = markMap[temp2];
                if(!(t1_val <= t2_val))
                {
                    cout << "i->" << i << " t1 was " << temp1 << "_" << t1_val << "... t2 was " << temp2 << "_"<< t2_val << "\n";
                    cout << "Invalid input";
                    exit(0);
                }
            }
        }
    }*/

    for(int i=0; i<uniqueSet.size(); i++)
    {
        for(const char& x: uniqueSet)
        {
            //cout << x << " -> " << markMap[x] << "\n";
            if(markMap[x] == (i+1))
            {
                solq.push(x);
            }
        }
    }

    while(!solq.empty())
    {
        char printing = solq.front();
        if(solq.size() > 1)
        {
            cout << printing << "->";
        }
        else
        {
            cout << printing;
        }
        solq.pop();
    }

    //cout << "Final Mark Count: " << mark;
}
