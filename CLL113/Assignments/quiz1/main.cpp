#include <iostream>
#include<math.h>
#include<fstream>
#include<bits/stdc++.h> 
using namespace std;


int main()
{   ifstream myfile;
    myfile.open ("example.txt", ios::in);
    int a[10][10];
    int n,m;
    int temp1;
    int temp2;
    
    myfile >>temp2;
    n = temp2;
    myfile >>temp2;
    m = temp2;
    int i=0;
    int j=0;
    while(myfile){
        myfile >>temp1;
        a[i][0] = 1;
        a[i][j+1]=temp1;
        
        if(j+1<n+1){
            j++;
        }
        else{
            j=0;
            if(i+1<m){
               i++;
            }
            else{
                break;
            }
        }
    }
    myfile.close();

    int xT[100][100], xTx[100][100], xTy[100][100];
    float  xTxi[100][100];
//INITIALIZED Y MATRIX
    float y[50];
    for(int i=0; i<m; i++){
        y[i] = a[i][n+1];
    }
//NOW, X AND Y MATRIX ARE INITIALIZED.
    for (int i=0; i<m; i++){           //print
        for(int j=0; j<n+1; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<y[i];
        cout<<endl;
    }
//INITIALIZING THE UNKNOWN THETA MATRIX
    float theta[100];
    for(int i=0; i<=n; i++){
        theta[i] = 0;
    }
    
    for(int i=0; i<=n; i++){
        cout<<theta[i];
    }
    float c[100][100];
    c[0][0] = m;
    float sum = 0;
    for(int i=0; i<m; i++){
        sum+=a[i][1];
    }
    c[0][1] = sum;
    sum = 0;
    for(int i=0; i<m; i++){
        sum+=a[i][2];
    }
    c[0][2] = sum;
    c[1][0] = c[0][1];
    c[2][0] = c[0][2];
    sum = 0;
    for(int i=0; i<m; i++){
        sum+=a[i][1]*a[i][1];
    }
    c[1][1] = sum;
    sum = 0;
    for(int i=0; i<m; i++){
        sum+=a[i][2]*a[i][2];
    }
    c[2][2] = sum;
    sum = 0;
    for(int i=0; i<m; i++){
        sum+=a[i][1]*a[i][2];
    }
    c[1][2] = sum;
    c[2][1] = c[1][2];
    
    for (int i=0; i<m; i++){
        c[i][3] = y[i];
    }
    
    n = 3;
    cout<<"Original Augmented Matrix:"<<endl;
    for (int i=0; i<=n-1; i++){
        for(int j = 0; j<=n; j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl<<"Final Matrix:"<<endl;
    for(int i=0; i<=n-1; i++){
        float dividend = c[i][i];
        for (int j=i; j<=n; j++){           //Normalizing ith pivot
            c[i][j] = c[i][j]/dividend;
        }
        
        for(int k=i+1; k<=n-1; k++){          //subtract other rows
            float var_k=c[k][i];
            for(int p = 0; p<=n; p++){
                c[k][p] = c[k][p] - (c[i][p]*var_k);
            }
        }
    }
    
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n; j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    
    for(int i=n-1; i>=0; i--){
        float sum_after = 0.0;
        for(int j=i+1; j<=n-1; j++){
            sum_after+=theta[j]*c[i][j];
        }
        theta[i] = a[i][n]-sum_after;
    }

    for(int i=0; i<3; i++){
        cout<<theta[i]<<"\t";
    }
    return 0;
    
}
