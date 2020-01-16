/*
 * HackerRank link:
 * Title:
 * Abstract:
 * Author:
 * ID:
 * Date:
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int bitcount = 0;
vector<int> bitCalc;

vector<int> input;

vector<int> set1;
vector<int> set2;



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
                }
                else
                {
                    prevBit = 0;
                }
            }
        }
        if(bitSum > maxSum)
        {
            maxSum = bitSum;
            bitSum = 0;
            bitcount = bitcount + 1;
        }
        else if(i == (setMax - 1))
        {
            break;
        }
        else
        {
            bitSum = 0;
            bitcount = bitcount + 1;
            //cout << "you were here @" << i << "\n";
        }
    }

    cout << "Max Apples: " << maxSum;
}
