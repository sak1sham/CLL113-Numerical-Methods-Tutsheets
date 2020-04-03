#include <stdio.h>
#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

float f(float x, float y){
    return (1/((x-0.3)*(x-0.3)+0.01))+(1/((x-0.9)*(x-0.9)+0.04))-6;
}

float actual(float x){
    return (atan((x-0.3)/0.1)/0.1) + (atan((x-0.9)/0.2)/0.2) - 6*x;
}

float rk4(float h, float start, float end){
    float k1, k2, k3, k4, y0, y1, x = start;
    y0 = 0;
    while(x<=end){
        k1 = f(x,y0);
        k2 = f(x+h/2, y0+h*k1/2);
        k3 = f(x+h/2, y0+h*k2/2);
        k4 = f(x+h, y0+k3*h);
        y1 = y0 + (k1+2*k2+2*k3+k4)*h/6;
        y0 = y1;
        x = x+h;
    }
    return y1;
}

float Val_of_y(float h, float start, float end, float y_start){
    float k1, k2, k3, k4, y0, y1, x = start;
    y0 = y_start;
    while(x<=end){
        k1 = f(x,y0);
        k2 = f(x+h/2, y0+h*k1/2);
        k3 = f(x+h/2, y0+h*k2/2);
        k4 = f(x+h, y0+k3*h);
        y1 = y0 + (k1+2*k2+2*k3+k4)*h/6;
        y0 = y1;
        x = x+h;
    }
    return y1;
}



float rk4_adaptive(float h, float start, float end){
    
    float y0, y1, hNew;
    float eTol = 0.00001;
    
    do{    
        y0 = rk4(h,start, end);
        y1 = rk4(h/2,start, end);
        //cout<<y0<<endl<<y1<<endl;
        float delta = abs(y1-y0);
        float n1 = 0.2;
        hNew = h*pow(eTol/delta,n1);
        h = hNew;
    }while(hNew>eTol);
    
    return hNew; 
}

int main()
{
    
    float start=0, end=1, h=0.1, y_start_plus_h, y_start;
    
    //cout<<"RK-4 : "<<rk4(h,start,end)<<endl;
    float ans = rk4(rk4_adaptive(h,start,end), start, end);
    float hNew = rk4_adaptive(h,start,end);
    cout<<"h_New = "<<hNew<<endl;
    cout<<"Adaptive RK-4: "<<ans<<endl;
    cout<<"True value:"<<actual(1)-actual(0);
    
    ofstream myfile;
    myfile.open("graph.csv",ios::out);
    
    y_start = 0;
    
    myfile<<start<<","<<y_start<<endl;
    
    while(start<=end){
        y_start_plus_h = Val_of_y(hNew,start,start+h,y_start);
        //cout<<start<<":"<<y_start_plus_h<<endl;
        //cout<<"True value:"<<actual(1)-actual(0);
        myfile<<start+h<<","<<y_start_plus_h<<endl;
        start = start + h;
        y_start = y_start_plus_h;
    }    
    
    myfile.close();
    return 0;
    
}



