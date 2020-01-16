#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() 
{
    int key;
    int prices;
    vector<int> items;

    cin >> key;

    for(int i = 0; i < key; i++)
    {
        cin >> prices;
        items.push_back(prices);
    }

    sort(items.begin(), items.end());

    int programCounter = 0;
    int sum = 0;
    for(int i=0; i < items.size(); i++)
    {
        programCounter += 1;
        if(programCounter == 1)
        {
            sum += items[i];
        }
        else if(programCounter == 2)
        {
            sum += items[i];
            items.pop_back();
            programCounter = 0;
        }
    }

    cout << sum;
}
