#include <iostream>
#include <cmath>
#include <vector>
#include<algorithm>
using namespace std;

int main() 
{
    vector<int> test;

    int key;
    int num;
    //cin>>num;
    cin>>key;
    for(int i=0; i<key; i++)
    {
        cin>>num;
        test.push_back(num);
    }

    sort(test.begin(), test.end());

    int firstFinal = -1;
    int secondFinal = -1;
    int minFinal = -1;

    for(int k = 0; k<test.size(); k++)
    {
        if(test.size()-1 != k)
        {
            int first = test.at(k);
            int second = test.at(k+1);
            int minDist = second - first;

            if(minFinal == -1)
            {
                firstFinal = first;
                secondFinal = second;
                minFinal = minDist;
            }
            else if(minDist<minFinal)
            {
                firstFinal = first;
                secondFinal = second;
                minFinal = minDist;
            }
        }
        /*else
        {
            cout << "Min Distance: " << minFinal << "\n";
            cout << "Two numbers for min distance: " << firstFinal << " and " << secondFinal;
        }*/
    }

    cout << "Min Distance: " << minFinal << "\n";
    cout << "Two numbers for min distance: " << firstFinal << " and " << secondFinal;
}
