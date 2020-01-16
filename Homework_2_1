#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

int main() 
{
    vector<int> list;
    int value;
    int bitsize = 1;

    cin>>value;

    bool setbits = false;

    while(setbits == false)
    {
        if(value >= pow(2, bitsize))
        {
            bitsize +=1;
        }
        else
        {
            setbits = true;
        }
    }

    for(int i = 0; i <= value; i++)
    {
        //bitset requires constant value for length
        switch(bitsize)
        {
            case 1:
            {
                bitset<1> a(i);
                cout << a << "\n";
                break;
            }
            case 2:
            {
                bitset<2> a(i);
                cout << a << "\n";
                break;
            }
            case 3:
            {
                bitset<3> a(i);
                cout << a << "\n";
                break;
            }
            case 4:
            {
                bitset<4> a(i);
                cout << a << "\n";
                break;
            }
            case 5:
            {
                bitset<5> a(i);
                cout << a << "\n";
                break;
            }
            case 6:
            {
                bitset<6> a(i);
                cout << a << "\n";
                break;
            }
            case 7:
            {
                bitset<7> a(i);
                cout << a << "\n";
                break;
            }
            
        }
    }
}
