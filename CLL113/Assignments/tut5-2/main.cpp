#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;

void partialpivot(double a[][10],double I[][10], int i, int n){
    int j=i;
    int large = i;
    for(int k=i; k<n; k++){
        if(a[large][i]<a[k][i]){
            large = k;
        }
    }
    for(int k=0; k<=n; k++){
        float temp = a[i][k];
        float temp1 = I[i][k];
        a[i][k] = a[large][k];
        I[i][k] = I[large][k];
        a[large][k] = temp;
        I[large][k] = temp1;
    }
}

int main(){
    double J[10][10], f[10], Jif[10];
    double Ca=1.0, Cb=1.0, Cc=1.0, Cd=1.0;
    double Ca_=1.0, Cb_=1.0, Cc_=1.0, Cd_=1.0;
    int iter = 0;
    int n = 4;
    while(iter<20){
        Ca = Ca_;
        Cb = Cb_;
        Cc = Cc_;
        Cd = Cd_;
        f[0] = -Ca + 1 + (-Ca -0.2*pow(Ca,1.5) + 0.05*pow(Cc,2))*2;
        f[1] = -Cb + (2*Ca - 0.4*pow(Cb,2))*2;
        f[2] = -Cc + (0.2*pow(Ca,1.5) - 0.05*pow(Cc,2) + 0.4*pow(Cb,2))*2;
        f[3] = -Cd + (0.4*pow(Cb,2))*2;
    
        J[0][0] = -3 - (0.6*pow(Ca,0.5)) ;
        J[0][1] = 0;
        J[0][2] = 0.2*Cc;
        J[0][3] = 0;
    
        J[1][0] = 4;
        J[1][1] = -1-(1.6*Cb);
        J[1][2] = 0;
        J[1][3] = 0;
    
        J[2][0] = 0.6*pow(Ca,0.5);
        J[2][1] = 1.6*Cb;
        J[2][2] = -(0.2*Cc)-1;
        J[2][3] = 0;
    
        J[3][0] = 0;
        J[3][1] = 1.6 * Cb;
        J[3][2] = 0;
        J[3][3] = -1;

        double I[10][10];

        //Now, we have initialised the identity matrix as I[][]
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(i==j){
                    I[i][j] = 1;
                }
                else{
                    I[i][j] = 0;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            partialpivot(J,I,i,n);
            float dividend = J[i][i];
            for (int j=0; j<=n; j++){           //Normalizing ith pivot
                J[i][j] = J[i][j]/dividend;
                I[i][j] = I[i][j]/dividend;
            }
            
            for(int k=i+1; k<n; k++){          //subtract other rows
                float var_k=J[k][i];
                for(int p = 0; p<=n; p++){
                    J[k][p] = J[k][p] - (J[i][p]*var_k);
                    if(p!=n){
                        I[k][p] = I[k][p] - (I[i][p]*var_k);
                    }    
                }
            }
            
            for(int k=0; k<i; k++){          //subtract other rows
                float var_k=J[k][i];
                for(int p = 0; p<=n; p++){
                    J[k][p] = J[k][p] - (J[i][p]*var_k);
                    if(p!=n){
                        I[k][p] = I[k][p] - (I[i][p]*var_k);
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            Jif[i] = 0;
            for(int j=0; j<n; j++){
                Jif[i] += I[i][j]*f[j];
            }
        }
        
        for(int i=0; i<n; i++){
            Ca_ = Ca - Jif[0];
            Cb_ = Cb - Jif[1];
            Cc_ = Cc - Jif[2];
            Cd_ = Cd - Jif[3];
        }
        
        cout<<"iter "<<iter+1<<":\t";
        cout<<"Ca = "<<Ca_<<"\t";
        cout<<"Cb = "<<Cb_<<"\t";
        cout<<"Cc = "<<Cc_<<"\t";
        cout<<"Cd = "<<Cd_<<"\t";
        cout<<"\n";
        iter++;
    }    
    
    return 0;
}

