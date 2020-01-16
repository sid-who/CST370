/*
 * HackerRank link:
 * Title:
 * Abstract:
 * Author:
 * ID:
 * Date:
 */



#include <iostream>
#include <vector>
#include <algorithm>

#include <queue>
using namespace std;

vector<vector<int>> grid;
queue<int> activeQ;
vector<bool> markArray;
vector<int> solutions;

int commandCounter = 0;
//the counter tracks the row position
int marker = 1;
//marks for the mark array
int cLoc = 0;
//marks initial command location

int vectorLocation = 0;

int vertices;
int edges;
int start;
int ending;

void printResults(vector<int> s)
{
    //cout << "\n";
    vector<int> edgeResults;
    s.pop_back();
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == s.front())
        {
            int temp = s[0];
            //cout << "Added via route 1 " << temp << "\n";
            edgeResults.push_back(temp);
        }
        else if(s[i] == -999)
        {
            int temp = s[i+1];
            //cout << "Added via route 2 " << temp << "\n";
            edgeResults.push_back(temp);
        }
    }
    //cout << "CHECKING BACK COMMAND --> " << edgeResults.back() << "\n";

    /*if(edgeResults.back() == 0)
    {
        edgeResults.back() = -999;
    }*/

    //cout << "\n" << "RESULTS VECTOR, AFTER MODIFICATION: ";
    /*for(int i=0; i<edgeResults.size(); i++)
    {
        cout << edgeResults[i] << ", ";
    }*/

    //cout << "\n";

    vector<string> fResults;

    if(edgeResults.size() == 1)
    {
        cout << "No new edge:";
        exit(0);
    }

    //edgeResults.pop_back();

    for(int i=0; i<edgeResults.size()-1; i++)
    {
        /*if(edgeResults[i] == edgeResults.back())
        {
            break;
            //cout << "Edge: " << edgeResults[i] << "-" << edgeResults[i+1] << "\n";
        }*/
        if(edgeResults[i] == edgeResults[i+1])
        {
            cout << "No new edge:";
            exit(0);
        }
        else
        {
            cout << "Edge: " << edgeResults[i] << "-" << edgeResults[i+1] << "\n";
        }
        //cout << "Edge: " << edgeResults[i] << "-" << edgeResults[i+1] << "\n";
    }

    exit(0);
}

void runTrace(int edges, vector<vector<int>>)
{
    vector<int> temp1;

    if(edges == 0)
    {
        for(int i=0; i<vertices; i++)
        {
            temp1.push_back(i);
            temp1.push_back(-999);
        }
        for(int j=0; j<temp1.size(); j++)
        {
            solutions.push_back(temp1[j]);
        }
        printResults(solutions);
    }

    do
    {
        //cout << "CLOC IS " << cLoc << "\n\n";
        for(int i=0; i<vertices; i++)
        {
            int temp = grid[cLoc][i];
            if(temp == 1 && markArray[i] == false)
            {
                //cout << "Added to queue: " << i << "\n";
                activeQ.push(i);
            }
        }
        
        /*cout << "===queue before set==="<< "\n";
        while(!activeQ.empty())
        {
            cout << activeQ.front() << "\n";
            activeQ.pop();
        }*/


        if(!activeQ.empty())
        {
            int locTemp = activeQ.front();
            //cout << "LOC TEMP IS : " << locTemp << "\n";
            if(cLoc == 0 && markArray[cLoc] == false)
            {
                markArray[cLoc] = true;
                //solutions[vectorLocation].push_back(cLoc);
                temp1.push_back(cLoc);
                //cout << " LOCATION 1 : HERE FOR " << cLoc << " Connecting to " << locTemp << "\n \n";
                cLoc = locTemp;
                activeQ.pop();
                commandCounter +=1;
            }
            else if(markArray[cLoc] == true) //&& activeQ.size() > 1)
            {
                activeQ.pop();
                commandCounter +=1;
                
                //cout << " LOCATION 2 : HERE FOR " << cLoc << " Connecting to " << locTemp << "\n \n";

                cLoc = activeQ.front();
            }
            else if(markArray[cLoc] == false)
            {
                markArray[cLoc] = true;
                //cout << "Marked " << cLoc << " as " << markArray[cLoc] << "\n";
                //solutions[vectorLocation].push_back(cLoc);
                temp1.push_back(cLoc);
                //cout << " LOCATION 3 : HERE FOR " << cLoc << " Connecting to " << locTemp << "\n \n";;
                cLoc = locTemp; 
                activeQ.pop();
                commandCounter +=1;
            }
            
        }
        else//if(activeQ.empty())//else
        {
            //cout << "=============== \n";
            //cout << "temp1 size is : " << temp1.size() << "\n";
            //cout << "=============== \n";
            temp1.push_back(cLoc);
            temp1.push_back(-999);
            markArray[cLoc] = true;
            int temp2 = temp1.front();
            for(int i=0; i<temp1.size(); i++)
            {
                solutions.push_back(temp1[i]);
            }
            //solutions.push_back(temp1[0]);
            temp1.erase(temp1.begin(), temp1.end());

            //cout << "YOU ARE HERE. \n";
            
            int p = 0;
            while(markArray[p] == true && p < markArray.size())
            {
                p++;
            }
            cLoc = p;
            //cout << "P moved to " << p <<"\n";
            if(p == markArray.size())
            {
                //THIS BLOCK IS REMOVABLE (TOP)
                /*for(int i=0; i<markArray.size(); i++)
                {
                    cout << "Value @ " << i << " is = " << markArray[i] << "\n\n";
                }

                cout << "VECTOR SIZE IS: " << solutions.size() << "\n";

                for(int i=0; i<solutions.size(); i++)
                {
                    cout << solutions[i] << ", ";
                }*/
                //THIS BLOCK IS REMOVABLE (BOTTOM)

                printResults(solutions);
            }
            commandCounter +=1;

            /*for(int i=0; i<markArray.size(); i++)
            {
                if(markArray[i] == false)
                {
                    cLoc = i;
                    //vectorLocation +=1;
                    commandCounter += 1;
                    break;
                }
            }*/
        }
    }while(commandCounter < edges);//(commandCounter <= edges);

    /*for(int i=0; i<markArray.size(); i++)
    {
        cout << "Value @ " << i << " is = " << markArray[i] << "\n\n";
    }

    cout << "VECTOR SIZE IS: " << solutions.size() << "\n";

    for(int i=0; i<solutions.size(); i++)
    {
        cout << solutions[i] << ", ";
    }*/

    printResults(solutions);

}


int main()
{
    cin >> vertices;
    for(int i=0; i<vertices; i++)
    {
        markArray.push_back(false);
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

    /*cout << "The array: " << "\n";
    for(int i=0; i< grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            cout << "[" << i << "] " << "[" << j << "] = " << grid[i][j] << "\n";
        }
    }*/


    runTrace(edges, grid);

}
