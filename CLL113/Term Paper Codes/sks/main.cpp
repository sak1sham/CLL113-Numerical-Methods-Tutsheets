#include <iostream>
#include <bits/stdc++.h>
using namespace std;
float func(float x)
{
    float y=(x*x*x)+(5*x*x)-3;
    return y;
}
float deriv(float x)
{
    float y=(3*x*x)+(10*x);
    return y;
}
int main()
{
    float x=1.5,fn,der,dery,et=1,tr=0.723956489491132,y;
    int i=1;
    ofstream obj("data.csv");
    while(et>0.001)
    {
        fn=func(x);
        der=deriv(x);
        y=x-0.6666667*(fn/der);
        dery=deriv(y);
        x=x-(fn/der)*(-0.5+(1.125*(der/dery))+(0.375*(dery/der)));
        et=100*(abs(tr-x)/tr);
        obj<<i<<","<<et<<endl;
        i++;
    }
    cout<<"Root: "<<x;
    return 0;
}   
