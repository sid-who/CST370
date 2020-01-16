/*
 * HackerRank link:
 * Title:
 * Abstract:
 * Author:
 * ID:
 * Date:
 */


#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() 
{
    map<int, int> order;
    map<int, bool> alternate;
    queue<int> solutions;
    queue<int> solChecker;
    
    queue<int> inputOrder;

    int vertices;
    int edges;
    int discard;
    int important;

    cin >> vertices;
    
    for(int i=0; i<vertices; i++)
    {
        order[i] = 0;
        alternate[i] = false;
    }

    cin >> edges;

    for(int i=0; i<edges; i++)
    {
        cin >> discard; //this value doesn't matter.
        cin >> important;

        order[important]++;
        inputOrder.push(discard);
        inputOrder.push(important);
    }

    /*while(!inputOrder.empty())
    {
        cout << inputOrder.front() << "___" ;
        inputOrder.pop();
    }*/

    for(int i=0; i<=edges; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            if(order[j] == i)
            {
                int temp = j;
                int temp2 = order[j];
                solutions.push(temp);
                solChecker.push(temp2);
            }
        }
    }

    /*while(!solChecker.empty())
    {
        cout << solChecker.front() << " --> ";
        solChecker.pop();
    }*/

    //print results below here =================
    if(edges == 0)
    {
        for(int i=0; i<vertices; i++)
        {
            int temp = order[i];
            cout << "In-degree["<< i <<"]:" << temp <<"\n"; 
        }
        cout << "Order:";
        for(int i=0; i<vertices; i++)
        {
            if( i == (vertices - 1))
            {
                cout << i;
            }
            else
            {
                cout << i << "->";
            }
        }
        exit(0);
    }
    if(edges == vertices)
    {
        for(int i=0; i<vertices; i++)
        {
            int temp = order[i];
            cout << "In-degree["<< i <<"]:" << temp <<"\n"; 
        }
        cout << "No Order:";
        exit(0);
    }

    if(solChecker.front() !=0)
    {
        for(int i=0; i<vertices; i++)
        {
            int temp = order[i];
            cout << "In-degree["<< i <<"]:" << temp <<"\n"; 
        }
        cout << "No Order:";
        exit(0);
    }

    if(edges > vertices) //&& edges !=0 && vertices !=0)
    {
        if((edges - vertices) > 1)
        {
            for(int i=0; i<vertices; i++)
            {
                int temp = order[i];
                cout << "In-degree["<< i <<"]:" << temp <<"\n"; 
            }
            cout << "No Order:";
            exit(0);
        }
        else
        {
            int vertCount = 1;//= 0;
            //cout << "\n";
            for(int i=0; i<vertices; i++)
            {
                int temp = order[i];
                cout << "In-degree["<< i <<"]:" << temp <<"\n"; 
            }
            cout<< "Order:";
            while(!inputOrder.empty())
            {
                if(vertCount == vertices)//(edges))//(inputOrder.size() == 1)
                {
                    int temp = inputOrder.front();
                    if(alternate[temp] == false)
                    {
                        alternate[temp] = true;
                        inputOrder.pop();
                        cout << temp;
                    }
                    else
                    {
                        inputOrder.pop();
                    }
                    //solutions.pop();
                    //cout << temp;
                }
                else
                {
                    int temp = inputOrder.front();
                    if(alternate[temp] == false)
                    {
                        alternate[temp] = true;
                        inputOrder.pop();
                        cout << temp << "->";
                        vertCount++;
                    }
                    else
                    {
                        inputOrder.pop();
                        //vertCount++;
                    }
                }
            }
            exit(0);
        }
    }

    if(edges < vertices)
    {
        if((vertices - edges) > 1)
        {
            for(int i=0; i<vertices; i++)
            {
                int temp = order[i];
                cout << "In-degree["<< i <<"]:" << temp <<"\n"; 
            }
            cout << "No Order:";
            exit(0);
        }
        else
        {
            for(int i=0; i<vertices; i++)
            {
                int temp = order[i];
                cout << "In-degree["<< i <<"]:" << temp <<"\n"; 
            }
            
            cout << "Order:";
            while(!solutions.empty())
            {
                if(solutions.size() == 1)
                {
                    int temp = solutions.front();
                    solutions.pop();
                    cout << temp;
                }
                else
                {
                    int temp = solutions.front();
                    solutions.pop();
                    cout << temp << "->";
                }
            }
        }
    }
}
