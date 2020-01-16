/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/floyd-all-pairs-shortest-paths/submissions/code/1318359966
 * Title: hw12_2.cpp
 * Abstract: This program performs functions of Floyd's Algorithm, taking a given
 * matrix and processing it to display all pairs shortest paths.
 * Author: Gurpreet Sidhu
 * ID: 2486
 * Date: 12/12/19
 */

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main() 
{
    int gridSize;
    
    cin >> gridSize;

    int value;

    int table[gridSize][gridSize];

    for(int i=0; i<gridSize; i++)
    {
        for(int j=0; j<gridSize; j++)
        {
            cin >> value;
            if(value == -1)
            {
                table[i][j] = INT_MAX;
            }
            else
            {
                table[i][j] = value;
            }
        }
    }

    //crooshair moves the top level controller, necessary for the comparison
    for(int crosshair=0; crosshair<gridSize; crosshair++)
    {
        //rows
        for(int i=0; i<gridSize; i++)
        {
            //columns
            for(int j=0; j<gridSize; j++)
            {
                if(table[i][crosshair] != INT_MAX && table[crosshair][j] != INT_MAX)
                {
                    int temp = table[i][crosshair] + table[crosshair][j];
                    if(temp < table[i][j])
                    {
                        table[i][j] = temp;
                    }
                }
            }
        }
    }

    for(int i=0; i<gridSize; i++)
    {
        for(int j=0; j<gridSize; j++)
        {
            if(table[i][j] == INT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << table[i][j] << " ";
            }
            
        }
        cout << "\n";
    }
    
}
