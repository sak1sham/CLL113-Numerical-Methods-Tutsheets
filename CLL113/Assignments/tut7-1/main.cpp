#include <iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
#include<fstream>
using namespace std;

float f(float x){
    return (pow(x,0.1))*(1.2-x)*(1-pow(2.71828,20*(x-1)));
}

float trapezoidal(float a, float b, int n){
    float x[10000];
    for(int i=0; i<=n; i++){
        x[i] = a + i*((b-a)/n);
    }
    float sum = 0.0;
    for(int i=0; i<n; i++){
        sum+=f(x[i]) + f(x[i+1]);
    }
    return ((b-a)/(2*n))*sum;
}

float simpson1_3(float a, float b, int n){
    float x[10000];
    for(int i=0; i<=n; i++){
        x[i] = a + i*((b-a)/n);
    }
    float sum = 0.0;
    for(int i=0; i<=n; i++){
        if(i==0 || i==n){
            sum+=f(x[i]);
        }
        else if(i%2==0){
            sum+=2*f(x[i]);
        }
        else{
            sum+=4*f(x[i]);
        }
    }
    return ((b-a)/(3*n))*sum;
}

float simpson3_8Partial(float a, float b, int n){
    float x[1000];
    float h = (b-a)/3;
    x[0] = a;
    x[1] = a+h;
    x[2] = a+ 2*h;
    x[3] = b;
    return ((b-a)/(8))*(f(x[0]) + 3*f(x[1]) + 3*f(x[2]) + f(x[3]));
}

float simpson3_8(float a, float b, int n){
    float x[10000];
    for(int i=0; i<=n; i++){
        x[i] = a + i*((b-a)/n);
    }
    float sum = 0.0;
    for(int i=0; i<n; i++){
        sum+=simpson3_8Partial(x[i],x[i+1],n);
    }
    return sum;
}

int main(){  
    float a = 0, b = 1;
    //cout<<"Enter the value of n:\t";
    int n = 5;
    //cin>>n;

    ofstream myfile;
    myfile.open ("example.csv", ios::out);
    
    while(n<500){
        float err1, err2, err3, val1, val2, val3;

        cout<<endl<<n<<endl;

        cout<<"\nTrapezoidal rule: ";
        val1 = trapezoidal(a,b,n);
        cout<<val1;
        err1 = abs(val1 - 0.602298)/0.00602298;

        cout<<"\nSimpson 1/3 rule: ";
        val2 = simpson1_3(a,b,n);
        cout<<val2;
        err2 = abs(val2 - 0.602298)/0.00602298;

        cout<<"\nSimpson 3/8 rule: ";
        val3 = simpson3_8(a,b,n);
        cout<<val3<<endl;
        err3 = abs(val3 - 0.602298)/0.00602298;
        
        myfile<<n<<","<<err1<<","<<err2<<","<<err3<<"\n";        
        n+=5;

        
    }
    
    myfile.close();
    
    return 0;
}

