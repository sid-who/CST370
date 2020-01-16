#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int key, num1, num2;
    int running = 1;

    do{
        cin>>key; cin>>num1; cin>>num2;

        if(key == 1)
        {
            int sum = num1+num2;
            cout<<sum<<endl;
        }
        if(key == 2)
        {
            int diff;
            diff = num1 - num2;
            cout<<abs(diff)<<endl;

        }

        if(key == 9)
        {
            running=0;
            return 0;
        }

    }while(running ==1);
}
