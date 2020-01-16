/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-row/submissions/code/1318174324
 * Title: hw11_1.cpp
 * Abstract: This program solves a coin row problem, wherein you want to return
 *           the max set value while skipping the next coin when one coin is picked.
 * Author: Gurpreet Sidhu
 * ID: 2486
 * Date: 12/5/19
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int bitcount = 0;
vector<int> bitCalc;

vector<int> input;

vector<int> set1;
vector<int> set2;

vector<int> solutionSet;
queue<int> locs;


int bitsize;
int num;
int sum = 0;
int bitSum = 0;
int maxSum = 0;
int solutionIndex = 0;
int prevBit = 0; //this tracks the previously added bit to the sum.

void genBit()
{  
    bitCalc.erase(bitCalc.begin(), bitCalc.end());
    int n = bitcount;
    while(n>0)
    {
        int temp = n%2;
        bitCalc.insert(bitCalc.begin(),temp);
        n = n/2;
    }
}

void compMatrix()
{
    while(bitCalc.size() - bitsize !=0)
    {
        bitCalc.insert(bitCalc.begin(),0);
    }
}

int main()
{
    int attempts = 0;
    cin>>bitsize;
    int setMax = pow(2, bitsize);
    for(int i=0; i<bitsize; i++)
    {
        cin>>num;
        sum += num;
        input.push_back(num);
    }

    for(int i = 0; i < setMax; i++)
    {
        genBit();
        compMatrix();
        /*cout << "binary value is: ";
        for(int k=0; k<bitCalc.size(); k++)
        {
            cout << bitCalc[k] << ", ";
        }
        cout << "\n";*/

        prevBit = 0;
        int j = 0;
        for(j=0; j < bitsize; j++)
        {
            //cout << "bit calc @ j = " << j << " is " << bitCalc[j] << "\n";
            if(bitCalc[j] == 1)
            {
                if(prevBit != 1)
                {
                    //cout << "Added " << input[j] << " to SUM";
                    bitSum += input[j];
                    //cout << "\n" << "Current SUM is" << bitSum << "\n";
                    prevBit = bitCalc[j];

                    //adding to the loc queue
                    locs.push(j+1);
                }
                else
                {
                    prevBit = 0;
                }
            }
        }
        if(bitSum > maxSum)
        {
            solutionSet.erase(solutionSet.begin(), solutionSet.end());
            maxSum = bitSum;
            bitSum = 0;
            bitcount = bitcount + 1;
            while(!locs.empty())
            {
                int temp = locs.front();
                locs.pop();
                solutionSet.push_back(temp);
            }
        }
        else if(i == (setMax - 1))
        {
            break;
        }
        else
        {
            bitSum = 0;
            bitcount = bitcount + 1;
            while(!locs.empty())
            {
                locs.pop();
            }
            //cout << "you were here @" << i << "\n";
        }
    }

    cout << "Best set:";

    for(int i=0; i<solutionSet.size(); i++)
    {
        cout << solutionSet[i] << " ";
    }

    cout << "\n" << "Max value:" << maxSum;
}
