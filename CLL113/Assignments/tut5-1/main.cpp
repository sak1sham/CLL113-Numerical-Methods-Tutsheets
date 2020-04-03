#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
    double ca = 1.0, cb = 1.0, cc = 1.0, cd = 1.0;
    int iter = 0;
    
    while(iter<=20){
        ca = (1 + 0.1*pow(cc,2))/(3+0.4*pow(ca, 0.5));
        cb = (4*ca)/(1+0.8*cb);
        cc = ((0.4*pow(ca,1.5))+(0.8*pow(cb,2)))/(1+0.1*cc);
        cd = (0.8*pow(cb,2));
        cout<<"iter:"<<iter+1<<"\t";
        cout<<ca<<"\t";
        cout<<cb<<"\t";
        cout<<cc<<"\t";
        cout<<cd<<"\t";
        cout<<"\n\n";
        iter++;
    };

    return 0;
}

