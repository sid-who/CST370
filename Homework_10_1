/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw10/challenges/radix-sort-4-1/submissions/code/1317832789
 * Title: hw10_1.cpp
 * Abstract:
 * Author: Gurpreet Sidhu
 * ID: 2486
 * Date: 11/21/19
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int proCount = 2;

int iter(int max, int factor)
{
    if(max < 10)
    {
        return 1;
    }
    else if(max/factor < 10)
    {
        return proCount;
    }
    else
    {
        factor = factor*10;
        proCount++;
        return iter(max, factor);
    }
}

int main()
{  
    int maxinput = 0;
    
    //map<int, vector<int>> radix;
    map<int, queue<int>> radix;
    vector<int> inputs;
    int size;
    int readin;

    for(int i=0; i<10; i++)
    {
        //vector<int> temp;
        queue<int> temp;
        radix[i] = temp;
    }

    cin >> size;

    for(int i=0; i<size; i++)
    {
        cin >> readin;
        if(maxinput < readin)
        {
            maxinput = readin;
        }
        inputs.push_back(readin);
    }

    int repeats;
    repeats = iter(maxinput, 10);

    //cout << "REPEATS: " << repeats << "\n";

    int factor = 10;
    int upscale1 = 1;

    queue<int> upscales;
    for(int i=0; i<repeats; i++)
    {
        upscales.push(upscale1);
        upscale1 = upscale1*10;
    }

    /*queue<int> test = upscales;
    while(!test.empty())
    {
        cout << test.front() << " ";
        test.pop();
    }
    cout << "\n";*/



    for(int i=0; i<repeats; i++)
    {

        int upscale = upscales.front();
        upscales.pop();

        for(int k=0; k<inputs.size(); k++)
        {
            if(inputs[k] < 10)
            {
                //radix[k].push_back(inputs[k]);
                int temp_1 = inputs[k]/upscale;
                radix[temp_1].push(inputs[k]);
            }
            else
            {
                int process = inputs[k]/upscale;
                int index = process%factor;
                //radix[index].push_back(inputs[k]);
                radix[index].push(inputs[k]);
            }
        }

        inputs.clear();

        for(int j=0; j<10; j++)
        {
            while(!radix[j].empty())//for(int n=0; n<radix[j].size(); n++)
            {
                //int temp = radix[j][n];
                int temp = radix[j].front();
                inputs.push_back(temp);
                radix[j].pop();
            }
        }

        for(int z=0; z<inputs.size(); z++)
        {
            cout << inputs[z] << " ";
        }
        cout << "\n";
    }
}
