/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/closed-hashing/submissions/code/1318195838
 * Title: hw11_3.cpp
 * Abstract: This program performs closed hashing, it responds to a variety of commands
 *           to modify the table. 
 * Author: Gurpreet Sidhu
 * ID: 2486
 * Date: 12/5/19
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> table;
vector<int> noElements;


/*
 * isPrime method is sourced from geeksforgeeks, it simply
 * returns a boolean result confirming whether or not a number is prime
 * This is used for the load factor doubling. 
 * Link to code: https://www.geeksforgeeks.org/c-program-to-check-prime-number/
 */
 bool isPrime(int n)
 {
     if(n<=1)
     {
         return false;
     }

     for(int i=2; i<n; i++)
     {
         if(n%i == 0)
         {
             return false;
         }
     }
     return true;
 }

 double loadFactor(int tablesize, int elements)
 {
     double lf;
     lf = elements / tablesize;
     return lf;
 }

 int resizeTable(int tableSize)
 {
     //tableSize = tableSize*2;
     if(isPrime(tableSize))
     {
         return tableSize;
     }
     else
     {
         tableSize = tableSize + 1;
         return resizeTable(tableSize);
     }
 }

 void insertionCalculator(int val, int tableSize, int index)
 {
     if(index == 0)
     {
         index = val % tableSize;
     }

     if(table[index] < 0)
     {
         table[index] = val;
     }
     else
     {
         /*if(index+1 > tableSize)
         {
             insertionCalculator(val, resizeTable(tableSize), 0);
         }*/
         insertionCalculator(val, tableSize, index+1);
     }
 }

 void insert(int val, int tableSize)
 {
     int elements = noElements.size();
     if(loadFactor(tableSize, elements) > 0.5)
     {
         tableSize = tableSize *2;
         tableSize = resizeTable(tableSize);
         table.erase(table.begin(), table.end());
         for(int i=0; i<tableSize; i++)
         {
             table.push_back(-999);
         }
         for(int i=0; i<noElements.size()-1; i++)
         {
             if(noElements[i] > -1)
             {
                 insertionCalculator(noElements[i], tableSize, 0);
             }
             /*else
             {
                 insertionCalculator(noElements[i]*-1, tableSize, 0);
             }*/
         }
     }

     insertionCalculator(val, tableSize, 0);
 }

 bool search(int val)
 {
     for(int i=0; i < table.size(); i++)
     {
         if(table[i] == val)
         {
             return true;
         }
     }
     return false;
 }

 void deleteThis(int val)
 {
     for(int i=0; i < table.size(); i++)
     {
         if(table[i] == val)
         {
             table[i] = table[i] * -1;
         }
     }

     for(int i=0; i < noElements.size(); i++)
     {
         if(noElements[i] == val)
         {
             noElements[i] = noElements[i] * -1;
         }
     }
 }

void displayStatus(int val)
{
    if(val < table.size())
    {
        if(table[val] > -1 && table[val] != -999)
        {
            cout << table[val] << " Active \n";
        }
        else if(table[val] < -1 && table[val] != -999)
        {
            cout << table[val]*-1 << " Deleted \n";
        }
        else
        {
            cout << "Empty \n";
        }
    }
}

int main() 
{
    int tableSize;
    int numCommands;

    cin >> tableSize;
    cin >> numCommands;

    for(int i=0; i<tableSize; i++)
    {
        table.push_back(-999);
    }

    string command;
    int commandVal;

    //load factor = number elements / size tableSize
    //if load_factor > 0.5

    int numElements = 0;

    for(int i=0; i<numCommands; i++)
    {
        cin >> command;
        if(command == "insert")
        {
            cin >> commandVal;
            noElements.push_back(commandVal);
            int tableSizer = table.size();
            insert(commandVal, tableSizer);
        }
        if(command == "tableSize")
        {
            cout << table.size() << "\n";
        }
        if(command == "search")
        {
            cin >> commandVal;
            if(search(commandVal) == true)
            {
                cout << commandVal << " Found \n";
            }
            else
            {
                cout << commandVal << " Not found \n";
            }
        }
        if(command == "delete")
        {
            cin >> commandVal;
            deleteThis(commandVal);
        }
        if(command == "displayStatus")
        {
            cin >> commandVal;
            displayStatus(commandVal);
        }
    }

}
