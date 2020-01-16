/*
 * HackerRank link: https://repl.it/@sidwho/Homework-71-370
 * Title: hw7_1.cpp
 * Abstract: This program takes a divide and conquer approach to iterate through an
 *           array to find the the index at which the maximum integer value is stored
 *           within that array.
 * Author: Gurpreet Sidhu  
 * ID: 2486
 * Date: 10/24/2019
 */

#include <iostream>

using namespace std;

void printResults(int maximum)
{
    cout << "Max Index: " << maximum;
    exit(0);
}

int main()
{
    int size;
    int input;

    int max1 = 0;
    int maxval1 = 0;

    int max2 = 0;
    int maxval2 = 0;
    
    cin >> size;

    int *frame;
    frame = new int[size];

    for(int i=0; i<size; i++)
    {
        cin >> input;
        frame[i] = input;
    }

    if(size%2 == 1)
    {
        int setFront = size/2;
        int midStart = size - setFront;
        for(int i=0; i<setFront; i++)
        {
            if( i == (setFront - 1))
            {
                if(frame[i] > maxval1)
                {
                    maxval1 = frame[i];
                    max1 = i;
                }
            }
            else
            {
                if(frame[i] > maxval1)
                {
                    maxval1 = frame[i];
                    max1 = i;
                }
                if(frame[i+setFront] > maxval2)
                {
                    maxval2 = frame[i+setFront];
                    max2 = i+setFront;
                }
            }
        }
        if(maxval1 > maxval2)//if(frame[max1] > frame[max2])
        {
            printResults(max1);
        }
        else
        {
            printResults(max2);
        }
    }
    else
    {
        int setFront = size/2;
        int midStart = size - setFront;
        for(int i=0; i<setFront; i++)
        {
            if(frame[i] > maxval1)
            {
                maxval1 = frame[i];
                max1 = i;
            }
            if(frame[i+setFront] > maxval2)
            {
                maxval2 = frame[i+setFront];
                max2 = i+setFront;
            }
        }
        if(maxval1 > maxval2)//if(frame[max1] > frame[max2])
        {
            printResults(max1);
        }
        else
        {
            printResults(max2);
        }
    }
}
