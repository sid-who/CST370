#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main() 
{
    string time1;
    string time2;
    int h2sec = 0;
    int h1sec = 0;
    int tfinal;
    bool complete = false;

    int fullDay = 86400;

    int hfinal;
    int mfinal;
    int sfinal;

    cin>>time1;
    cin>>time2;

    string hour1 = time1.substr(0,2);
    string min1 = time1.substr(3,2);
    string sec1 = time1.substr(6,2);

    stringstream h_1(hour1);
    int h1;
    h_1 >> h1;

    stringstream m_1(min1);
    int m1;
    m_1 >> m1;

    stringstream s_1(sec1);
    int s1;
    s_1 >> s1;

    string hour2 = time2.substr(0,2);
    string min2 = time2.substr(3,2);
    string sec2 = time2.substr(6,2);

    stringstream h_2(hour2);
    int h2;
    h_2 >> h2;

    stringstream m_2(min2);
    int m2;
    m_2 >> m2;

    stringstream s_2(sec2);
    int s2;
    s_2 >> s2;

    if(h2 < h1)
    {
        int temp = h2*60*60;
        h2sec += temp;
        temp = m2*60;
        h2sec += temp;
        h2sec += s2;

        temp = h1*60*60;
        h1sec += temp;
        temp = m1*60;
        h1sec += temp;
        h1sec += s1;

        int add = fullDay - h1sec;
        tfinal = h2sec + add;

        sfinal = tfinal%60;
        tfinal = tfinal - sfinal;

        tfinal = tfinal/60;
        mfinal = tfinal%60;
        tfinal = tfinal - mfinal;

        hfinal = tfinal/60;
        complete = true;
    }
    else if(h2 >= h1)
    {
        int temp = h2*60*60;
        h2sec += temp;
        temp = m2*60;
        h2sec += temp;
        h2sec += s2;

        temp = h1*60*60;
        h1sec += temp;
        temp = m1*60;
        h1sec += temp;
        h1sec += s1;

        tfinal = h2sec - h1sec;

        sfinal = tfinal%60;
        tfinal = tfinal - sfinal;

        tfinal = tfinal/60;
        mfinal = tfinal%60;
        tfinal = tfinal - mfinal;

        hfinal = tfinal/60;
        complete = true;
    }

    if(complete == true)
    {
        if(hfinal <= 9)
        {
            cout << "0" << hfinal << ":";
        }
        else
        {
            cout << hfinal << ":";
        }

        if(mfinal <= 9)
        {
            cout << "0" << mfinal << ":";
        }
        else
        {
            cout << mfinal << ":";
        }

        if(sfinal <= 9)
        {
            cout << "0" << sfinal;
        }
        else
        {
            cout << sfinal;
        }
    }    
}
