#include <iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
using namespace std;

int n=8;

//P[i] = P(x[], i, j) = PI(j=0 to n, j!=i)((x-x[j])/(x[i]-x[j]))
float P(float x[], int i, float input){
    float ans = 1.0;
    for(int k=0; k<n; k++){
        if(k!=i){
            ans *= (input-x[k])/(x[i]-x[k]);
        }
    }
    return ans;
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
        answer += y[i]*P(x, i, input);
    }
    cout<<"\nThe value by Lagrangian Polynomial is = "<<answer<<endl;
    
    
    return 0;
}




