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
int solutionIndex = 0;

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
    if(sum%2 != 0)
    {
        cout << "Equal Set: 0" << "\n";
        exit(0);
    }
    int target = sum/2;

    for(int i = 0; i < setMax; i++)
    {
        genBit();
        compMatrix();
        int j = 0;
        for(j=0; j < bitsize; j++)
        {
            if(bitCalc[j] == 1)
            {
                bitSum += input[j];
                set1.push_back(input[j]);
            }
            else
            {
                set2.push_back(input[j]);
            }
        }
        if(bitSum == target)
        {
            solutionIndex = j;
            break;
        }
        else{
            bitSum = 0;
            bitcount +=1;
            set1.erase(set1.begin(), set1.end());
            set2.erase(set2.begin(), set2.end());
        }
    }

    if(solutionIndex != 0)
    {
        sort(set1.begin(), set1.end());
        sort(set2.begin(), set2.end());

        if(set1[0] > set2[0])
        {
            cout << "Equal Set:";
            for(int i=0; i < set2.size(); i++)
            {
                cout << " " << set2[i];
            }
        }
        else if (set1[0] > set2[0])
        {
            cout << "Equal Set:";
            for(int i=0; i < set1.size(); i++)
            {
                cout << " " << set1[i];
            }
        }
    }
    else
    {
        cout << "Equal Set: 0";
    }
}
