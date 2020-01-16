#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int>> grid;
stack<int> stack1;
vector<int> markArray;

int vertices;
int edges;
int start;
int ending;

int main()
{
    cin >> vertices;
    for(int i=0; i<vertices; i++)
    {
        markArray.push_back(0);
        //above is mark array only.
        grid.push_back(vector<int> ());
        for(int j=0; j<vertices; j++)
        {
            grid[i].push_back(-1);
        }
    }

    cin>>edges;

    for(int i=0; i<edges; i++)
    {
        cin >> start;
        cin >> ending;
        grid[start][ending] = 1;
    }

    //grid[2][3] = 5;

    cout << "----------------------------" << "\n";
    for (int i = 0; i < vertices; i++) 
    { 
        for (int j = 0; j < vertices; j++)
        { 
            cout << grid[i][j] << "  "; 
        } 
        cout<< "\n"; 
    } 
    cout << "----------------------------" << "\n";

    stack<int> tempstack;

    for(int i=0; i<1; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            int temp = grid[i][j];
            tempstack.push(temp);
        }
    }


    //Take the generated stack and reverse it.
    while(!tempstack.empty())
    {
        int temp = tempstack.top();
        tempstack.pop();
        stack1.push(temp);
    }

    cout << "MARK ARRAY, INITIAL." << "\n";
    for(int i=0; i<markArray.size(); i++)
    {
        cout << markArray[i] << " -> ";
    }
 
    /*cout << "REVERSE COMPLETED, SHOULD PRINT IN ORDER." << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
    cout << "TOP: " << "\n";
    while(!stack1.empty())
    {
        cout << stack1.top() << " --> ";
        stack1.pop();
    }*/

}
