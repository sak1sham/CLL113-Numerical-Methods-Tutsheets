#include <iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
using namespace std;

int n=8;
int order = 7;

float poly(float x[], float y[], float input){
    float ans = 0.0;
    float phi[100][100];
//make phi[][]
    for(int i=0; i<n; i++){
        for(int j=0; j<order+1; j++){
            phi[i][j] = pow(x[i], j);
        }
    }
//find Y[]*(phi[][]-1) = a[]
    float I[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<order+1; j++){
            if(i==j){
                I[i][j] = 1;
            }
            else{
                I[i][j] = 0;
            }
        }
    }

    for(int i=0; i<n; i++){
        //normalization
        float pivot = phi[i][i];
        for (int j=0; j<order+1; j++){
            phi[i][j] = phi[i][j]/pivot;
            I[i][j] = I[i][j]/pivot;
        }
        //subtracting lower rows
        for (int j=i+1; j<n; j++){
            float mult = phi[j][i];
            for(int k=0; k<order+1; k++){
                phi[j][k] = phi[j][k] - (mult*phi[i][k]);
                I[j][k] = I[j][k] - (mult*I[i][k]);
            }
        }
        //subtracting upper rows
        for (int j=0; j<i; j++){
            float mult = phi[j][i];
            for(int k=0; k<order+1; k++){
                phi[j][k] = phi[j][k] - (mult*phi[i][k]);
                I[j][k] = I[j][k] - (mult*I[i][k]);
            }
        }
    }    
    
    //multiplying inverse and y[]
    float a[100];
    for (int i = 0; i<n; i++){ 
        a[i] = 0; 
        for (int k = 0; k<n; k++) 
            a[i] += I[i][k] * y[k]; 
    }
    
//find (a[]*x[]) at x = input
    for(int i=0; i<n; i++){
        ans+=a[i]*pow(input,i);
    }
    
//Return final answer    
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
//Initializing X[] and Y[] data-points
    divideInParts(0, 2*PI, x);
    for(int i=0; i<n; i++){
        y[i] = pow(sin(x[i]),2);
    }
//Input value of 't'    
    cout<<"Enter the input to find the value of sin^2(t):\t";
    float input;
    cin>>input;
    cout<<"sin^2(t) = "<<pow(sin(input),2);
//Calculating the final answer
    cout<<"\nThe value by order "<<order<<" interpolating polynomial is = "<<poly(x,y,input)<<endl;
    return 0;
}

