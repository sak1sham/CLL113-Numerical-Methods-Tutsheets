#include <iostream>
#include<math.h>
#include<fstream>
using namespace std;

void partialpivot(float a[][10],int i, int n){
    int j=i;
    int large = i;
    for(int k=i; k<=n-1; k++){
        if(a[large][i]<a[k][i]){
            large = k;
        }
    }
    for(int k=0; k<=n; k++){
        float temp = a[i][k];
        a[i][k] = a[large][k];
        a[large][k] = temp;
    }
    cout<<"After partialpivot(float[][10], int i, int n), we get:"<<endl;
    for(int k=0; k<=n-1; k++){
        for(int l=0; l<=n; l++){
            cout<<a[k][l]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

int main()
{   ifstream myfile;
    myfile.open ("example2.txt", ios::in);
    float a[10][10];
    int n;
    float temp1;
    int temp2;
    
/*
    a[0][0]=10;
    a[0][1]=2;
    a[0][2]=-1;
    a[0][3]=27;
    a[1][0]=-3;
    a[1][1]=-6;
    a[1][2]=2;
    a[1][3]=-61.5;
    a[2][0]=1;
    a[2][1]=1;
    a[2][2]=5;
    a[2][3]=-21.5;
    int n=3;
*/
    myfile >>temp2;
    n = temp2;
    int i=0;
    int j=0;
    while(myfile){
        myfile >>temp1;
        a[i][j]=temp1;
        
        if(j+1<n+1){
            j++;
        }
        else{
            j=0;
            if(i+1<n){
               i++;
            }
            else{
                break;
            }
        }
        
        //cout<<temp<<endl;
    }
/*    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            cout<<a[i][j]<<endl;
        }
    }*/
    myfile.close();
    
    cout<<"Initial Augmented matrix is:"<<endl;
    for(int k=0; k<=n-1; k++){
        for(int l=0; l<=n; l++){
            cout<<a[k][l]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;


   
    for(int i=0; i<=n-1; i++){
        partialpivot(a,i,n);
        float dividend = a[i][i];
        for (int j=i; j<=n; j++){           //Normalizing ith pivot
            a[i][j] = a[i][j]/dividend;
        }
        
        for(int k=i+1; k<=n-1; k++){          //subtract other rows
            float var_k=a[k][i];
            for(int p = 0; p<=n; p++){
                a[k][p] = a[k][p] - (a[i][p]*var_k);
            }
        }
    }
    
    cout<<"Finally, we get:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    
    float sol[10];
    for(int i=n-1; i>=0; i--){
        float sum_after = 0.0;
        for(int j=i+1; j<=n-1; j++){
            sum_after+=sol[j]*a[i][j];
        }
        sol[i] = a[i][n]-sum_after;
    }
    
    cout<<endl<<"Solution:"<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<sol[i]<<endl;
    }
    float solcheck;
    for(int i=0; i<=n-1; i++){
        solcheck = 0.0;
        for(int j=0; j<=n-1; j++){
            solcheck+=a[i][j]*sol[j];    
        }
        if(abs(solcheck-a[i][n]) >0.00001){
            cout<<solcheck<<"!="<<a[i][n]<<"\t"<<"Wrong solution";
            return 0;
        }
    }
    cout<<"Correct solution";

    
    return 0;
    
}

