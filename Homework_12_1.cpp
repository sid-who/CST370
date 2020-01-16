/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/knapsack-7-1/submissions/code/1318359938
 * Title: hw12_1.cpp
 * Abstract: This program is used to calculate the maximum value obtained by
 * a knapsack problem. It utilizes a dynamic approach to calculate the maximum
 * value.
 * Author: Gurpreet Sidhu
 * ID: 2486
 * Date: 12/12/2019
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() 
{
    int itemCount;
    int wCap;

    cin >> itemCount;
    cin >> wCap;

    int table[itemCount+1][wCap+1];

    for(int i=0; i<itemCount+1; i++)
    {
        for(int j=0; j<wCap+1; j++)
        {
            table[i][j] = 0;
        }
    }

    vector<int> weight;
    vector<int> value;

    weight.push_back(0);
    value.push_back(0);

    int wei;
    int val;

    for(int i=1; i<=itemCount; i++)
    {
        cin >> wei;
        cin >> val;
        weight.push_back(wei);
        value.push_back(val);
    }

    for(int i=1; i<=itemCount; i++)
    {
        int i_val = i;
        int aWeight = weight[i];
        int aVal = value[i];
        for(int j=1; j<=wCap; j++)
        {
            if(aWeight <= j)
            {
                int temp_j = j - aWeight;
                int temp_i = i - 1;
                int newVal = (table[temp_i][temp_j]) + aVal;
                int oldUpper = table[i-1][j];
                if(newVal > oldUpper)
                {
                    // cout << "Placed " << newVal << " @ " << i << ", " << j << "\n";
                    table[i][j] = newVal;
                }
                else
                {
                    table[i][j] = oldUpper;
                }

            }
            else if(aWeight > j)
            {
                table[i][j] = table[i-1][j];
            }
        }
    }

    //result
    cout << "Final step:";
    for(int r=0; r<wCap+1; r++)
    {
        cout << table[itemCount][r] << " ";
    }

    cout << "\n";

    cout << "Max value:" << table[itemCount][wCap] << "\n";

    stack<int> routeBack;
    int ROW = itemCount;
    int COL = wCap;
    
    do{
        if(table[ROW][COL] == table[ROW-1][COL])
        {
            ROW = ROW - 1;
        }
        else
        {
            routeBack.push(ROW);
            COL = COL - weight[ROW];
            ROW = ROW - 1;
        }
    }while(ROW !=0);

    cout << "Items:";
    while(!routeBack.empty())
    {
        cout << routeBack.top() << " ";
        routeBack.pop();
    }

}
