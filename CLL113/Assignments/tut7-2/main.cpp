#include <iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
using namespace std;

float theta(float x){
    return (25*((-5*x*x*x*x) + (54*x*x) - 81)*0.0001)/(24*9);
}

float simpson1_3(float a, float b, int n){
    float x[10000];
    for(int i=0; i<=n; i++){
        x[i] = a + i*((b-a)/n);
    }
    float sum = 0.0;
    for(int i=0; i<=n; i++){
        if(i==0 || i==n){
            sum+=(theta(x[i]));
            //cout<<i<<'\t'<<theta(x[i])<<endl;
        }
        else if(i%2==0){
            sum+=2*(theta(x[i]));
            //cout<<i<<'\t'<<theta(x[i])<<endl;
        }
        else{
            sum+=4*(theta(x[i]));
            //cout<<i<<'\t'<<theta(x[i])<<endl;
        }
    }
    return ((b-a)/(3*n))*sum;
}

float centralDiff(float a, float h){
    return (theta(a+h)-theta(a-h))/(2*h);
}

float centralDiff2(float a, float h){
    return (theta(a+h)-(2*theta(a))+theta(a-h))/(h*h);
}

int main(){  
    cout<<"Net Deflection using numerical integration (Simpson 1/3rd rule) is :\t"<<simpson1_3(0.0, 3.0, 24)<<endl;

    cout<<"M(x) at various values of x using central Num. Diff. for (x:0.125->2.875):\n";

    for(int i=1; i<24; i++){
        cout<<"at "<<i*0.125<<":\t"<<60000000*centralDiff(i*0.125, 0.125)<<endl;
    }

    cout<<"V(x) at various values of x using central Num. Diff. for (x:0.125->2.875):\n";

    for(int i=1; i<24; i++){
        cout<<"at "<<i*0.125<<":\t"<<60000000*centralDiff2(i*0.125, 0.125)<<endl;
    }


}



