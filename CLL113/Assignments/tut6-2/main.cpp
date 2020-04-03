#include <iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
using namespace std;

void quadroots(float p, float r, float s){
    float disc = r*r - 4*p*s;
    if(disc>=0){
        cout<<endl<<((-r)+pow(disc,0.5))/(2*p);
        cout<<endl<<((-r)-pow(disc,0.5))/(2*p);
    }
    else{
        cout<<endl<<(-r)/(2*p)<<" + "<<pow(-disc,0.5)/(2*p)<<"i";
        cout<<endl<<(-r)/(2*p)<<" - "<<pow(-disc,0.5)/(2*p)<<"i";
    }
}

void bairstower(float a[], int n, float r, float s){
    float b[10], c[10], dr, ds;
    while(n>=3){
        float maxErr = 100.0;
        while(maxErr >= 0.00000001){
            b[n] = a[n];
            b[n-1] = a[n-1] + r*b[n];
            c[n] = b[n];
            c[n-1] = c[n-1] + r*b[n];
            for(int i=n-2; i>=0; i--){
                b[i] = a[i] + r*b[i+1] + s*b[i+2];
                c[i] = b[i] + r*c[i+1] + s*c[i+2];
            }
            if(c[2]*c[2] - c[1]*c[3] != 0){
                dr = (-(b[1]*c[2])+(b[0]*c[3]))/(c[2]*c[2] - c[1]*c[3]);
                ds = (-(b[0]*c[2])+(b[1]*c[1]))/(c[2]*c[2] - c[1]*c[3]);
                cout<<endl<<dr<<"\t"<<ds;
                r = r + dr;
                s = s + ds;
            }
            else{
                r = r+1; 
                s = s+1; 
            }
            
            if(abs(dr)>abs(ds)){
                maxErr = abs(dr/r);
            }
            
            else{
                maxErr = abs(ds/s);
            }
        }
        
        n = n - 2;
        quadroots(1,-r,-s);
        for(int i=0; i<=n; i++){
            a[i] = b[i+2];
        }
        
    }
    
    if(n==2){
        quadroots(a[2],a[1],a[0]);
    }
    
    else if(n==1){
        cout<<endl<<-1*a[0]/a[1];
    }
}


int main()
{  
    int n = 3;
    float a1[10];
    a1[0] = -4.0;
    a1[1] = -4.0;
    a1[2] = 1.0;
    a1[3] = 1.0;
    float a2[10];
    a2[0] = -2;
    a2[1] = 4;
    a2[2] = -0.5;
    a2[3] = 1;
    float r = -1, s = -1;
    cout<<"\nThe answer for part (i) is: ";
    bairstower(a1,n,r,s);
    cout<<"\nThe answer for part (ii) is: ";
    bairstower(a2,n,r,s);
    return 0;
}





