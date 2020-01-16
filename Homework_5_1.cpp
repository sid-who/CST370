#include <iostream>

using namespace std;

int product = 1;

int compute(int n)
{
    if(n == 0)
    {
        product *= 1;
        cout << product;
        return 0;
    }
    else
    {
        product *= 2;
        n = n - 1;
        return compute(n);
    }
}

int main() {
    int value;
    cin>>value;
    compute(value);
}
