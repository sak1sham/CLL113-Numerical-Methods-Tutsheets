#include <iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
#include<fstream>
using namespace std;

float f(float x, float y){
    return (-y*y);
}


float y_analytical(float t){
    return (1/(1+t));
}

void eEuler(float h){
    float t = 0;
    float y0 = y_analytical(t), y1;
    cout<<y0<<endl;
    t = t+h;
    while(t<=10){
        y1 = y0 + f(t,y0)*h;
        cout<<y1<<"\t"<<y_analytical(t)<<endl;
        y0 = y1;
        t = t+h;
    };

}

float newtonR(float a, float b, float c){
    float ans, x0, x1, err;
    x0 = 1;
    err = 1;
    while(err>0.00001){
        x1 = x0 - (a*x0*x0 + b*x0 + c)/(2*a*x0 + b);
        err = abs(x0-x1);
        x0 = x1;
    }
    return x1;
}

void cranky(float h){
    float a = 1, b = 2/h, c, t = 0, y1;
    float y0 = y_analytical(t);
    cout<<y0<<"\t"<<y_analytical(t)<<endl;
    t = t+h;
    while(t<=10){
        c = (y0*y0) - (2*y0/h);
        y1 = newtonR(a,b,c);
        cout<<y1<<"\t"<<y_analytical(t)<<endl;
        y0 = y1;
        t = t+h;
    }
}


void iEuler(float h){
    float a = h, b = 1, c, t = 0, y1;
    float y0 = y_analytical(t);
    cout<<y0<<"\t"<<y_analytical(t)<<endl;
    t = t+h;
    while(t<=10){
        c = -y0;
        y1 = newtonR(a,b,c);
        cout<<y1<<"\t"<<y_analytical(t)<<endl;
        y0 = y1;
        t = t+h;
    }
}




void eEulerFile(float h){
    float t = 0;
    float y0 = y_analytical(t), y1;
    cout<<y0<<endl;
    t = t+h;
    ofstream myfile;
    myfile.open("example.csv", ios::out);
    while(t<=10){
        y1 = y0 + f(t,y0)*h;
        myfile<<y1<<","<<y_analytical(t)<<"\n";
        y0 = y1;
        t = t+h;
    };
    myfile<<"\n";
    myfile.close();
}

void crankyFile(float h){
    float a = 1, b = 2/h, c, t = 0, y1;
    float y0 = y_analytical(t);
    cout<<y0<<"\t"<<y_analytical(t)<<endl;
    t = t+h;
    ofstream myfile;
    myfile.open("example.csv", ios::out | ios::app);
    while(t<=10){
        c = (y0*y0) - (2*y0/h);
        y1 = newtonR(a,b,c);
        myfile<<y1<<","<<y_analytical(t)<<"\n";
        y0 = y1;
        t = t+h;
    }
    myfile<<"\n";
    myfile.close();
}


void iEulerFile(float h){
    float a = h, b = 1, c, t = 0, y1;
    float y0 = y_analytical(t);
    cout<<y0<<"\t"<<y_analytical(t)<<endl;
    t = t+h;    
    ofstream myfile;
    myfile.open("example.csv", ios::out | ios::app);
    while(t<=10){
        c = -y0;
        y1 = newtonR(a,b,c);
        myfile<<y1<<","<<y_analytical(t)<<"\n";
        y0 = y1;
        t = t+h;
    }
    myfile<<"\n";
    myfile.close();
}









int main(){  
    float ha[5];
    ha[0] = 0.1;
    ha[1] = 0.2;
    ha[2] = 0.5;
    ha[3] = 1;
    ha[4] = 2;
    cout << setprecision(5);
    for(int i=0; i<5; i++){
        float h = ha[i];
        cout<<endl<<endl<<"For h="<<h<<":"<<endl;
        cout<<endl<<"Explicit Eular : "<<endl;
        eEuler(h);
        cout<<endl<<"Crank-Nicolson : "<<endl;
        cranky(h);
        cout<<endl<<"Implicit Eular : "<<endl;
        iEuler(h);
    }
    
    eEulerFile(0.5);
    iEulerFile(0.5);
    crankyFile(0.5);
    return 0;
}






