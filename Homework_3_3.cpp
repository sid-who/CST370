#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() 
{
    int vertices;
    int edges;
    int vrtIndex;
    int horIndex;

    cin >>  vertices;
    cin >> edges;

    int adj[vertices][vertices];

    for(int i=0; i<edges; i++)
    {
        cin >> vrtIndex;
        cin >> horIndex;
        adj[vrtIndex][horIndex] = 1;
    }

    for(int i=0; i<vertices; i++)
    {
        cout << i;
        for(int j=0; j<vertices; j++)
        {   
            if(adj[i][j] == 1)
            {
                cout << "->" << j;
            }
        }
        cout << "\n";
    }
}
