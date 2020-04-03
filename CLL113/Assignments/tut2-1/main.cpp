#include <iostream>
#include<math.h>
#include<fstream>
using namespace std;

int main()
{   ifstream myfile;
    myfile.open ("example.txt", ios::in);
    float a[10][10];
    int n;
    float temp1;
    int temp2;
    
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
   
    cout<<"Original Augmented Matrix:"<<endl;
    for (int i=0; i<=n-1; i++){
        for(int j = 0; j<=n; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl<<"Final Matrix:"<<endl;
    for(int i=0; i<=n-1; i++){
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
    
    cout<<endl<<endl<<"Solution:"<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<sol[i]<<endl;
    }
    
    cout<<endl<<"Results after checking the solution:"<<endl;
    
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

