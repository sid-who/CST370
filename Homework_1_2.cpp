#include <iostream>
#include <iterator>
#include <cmath>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> left;
    vector<int> right;

    int key;
    int leftnum;
    int rightnum;
    cin>>key;
    for(int i=0; i<key; i++)
    {
        cin>>leftnum;
        cin>>rightnum;
        left.push_back(leftnum);
        right.push_back(rightnum);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if(left[key-1]<=right[0])
    {
        cout<<left[key-1]<<" "<<right[0];
    }
    else
    {
        cout<<-1;
    }
}
