#include <iostream>
#include <bits/stdc++.h>
using namespace std;
float func(float x)
{
    float y=(x*x*x)+(5*x*x)-3;
    return y;
}
float G(float x, float h)
{
    float y,temp;
    //temp=func(x);
    y=(func(x+h)-func(x-h))/(2*h);
    return y;
}
int main()
{
    float h=0.0001, x=1.5, fn, gx, tr=0.723956489491132, et=1;
    int i=1;
    ofstream obj("data.csv");
    while(et>0.001)
    {
        fn=func(x);
        gx=G(x,h);
        x=x-(fn/gx);
        et=100*(abs(tr-x)/tr);
        obj<<i<<","<<et<<endl;
        i++;
    }
    cout<<"Root: "<<x;
    return 0;
}   
