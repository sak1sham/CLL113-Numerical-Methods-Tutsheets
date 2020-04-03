#include <iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
using namespace std;

int n=8;

float nthDiff(int j, int i, float y[], float x[]){
    if(i==j){
        return y[i];
    }
    return (nthDiff(j, i+1, y, x) - nthDiff(j-1, i, y, x))/(x[j]-x[i]);
}

float divideInParts(float x1, float x2, float x[]){
    for(int i=0; i<n; i++){
        x[i] = i*((x2-x1)/n);
    }
}

int main()
{  
    float x[10], y[10];
    float PI = 3.141592653;
    divideInParts(0, 2*PI, x);
    for(int i=0; i<n; i++){
        y[i] = pow(sin(x[i]),2);
    }
    cout<<"Enter the input to find the value of sin^2(t):\t";
    float input;
    cin>>input;
    cout<<"sin^2(t) = "<<pow(sin(input),2);
    float answer = 0.0;
    for(int i=0; i<n; i++){
        float ci = nthDiff(i,0,y,x);
        float prod = 1;
        for(int j=0; j<i; j++){
            prod *= (input-x[j]);
        }
        answer += ci*prod;
    }
    cout<<"\nThe value is = "<<answer<<endl;
    return 0;
}






