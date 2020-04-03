#include <iostream>
#include<math.h>
#include<fstream>
#include<iomanip>
using namespace std;


int abc(char file[])
{   std::cout<<std::fixed;
    cout<<std::setprecision(4);
    ifstream myfile;
    myfile.open (file, ios::in);
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
        
    
    }

    myfile.close();
    
    cout<<"Initial matrix A is:"<<endl;
    for(int k=0; k<=n-1; k++){
        for(int l=0; l<=n; l++){
            cout<<a[k][l]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    float l[10][10], u[10][10];
//INITIALIZING U MATRIX
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            u[i][j] = a[i][j];
        }
    }
//INITIALIZING l MATRIX
    for(int i=n-1; i>=0; i--){
        for (int j=0; j<=n; j++){           
            if(i<j){
                l[i][j] = 0;
            }
            else if(i==j){
                l[i][j] = 1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        l[i][n] = a[i][n];
    }


    for(int i=0; i<=n-1; i++){
        //partialpivot(u,i,n);
        float dividend = u[i][i];
        /*for (int j=0; j<=n; j++){           //Normalizing ith pivot
            u[i][j] = u[i][j]/dividend;
        }*/
      
        for(int k=i+1; k<=n-1; k++){          //subtract other rows
            l[k][i] = u[k][i]/dividend; 
            float var_k=u[k][i];
            for(int p = 0; p<=n; p++){
                u[k][p] = u[k][p] - (u[i][p]*var_k/dividend);
            }
        }
    }

    
    
    cout<<"Finally, we get U matrix as:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n-1; j++){
            cout<<u[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    
    cout<<"Finally, we get L matrix as:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n; j++){
            cout<<l[i][j]<<"\t";
        }
        cout<<endl;
    }

    
    float lu[20][20];
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++){ 
            lu[i][j] = 0; 
            for (int k = 0; k < n; k++) 
                lu[i][j] += l[i][k] * u[k][j]; 
        } 
    } 
    
    cout<<endl<<"Final L*U matrix is: "<<endl;
    for (int i=0; i<=n-1; i++){ 
        for(int j=0; j<=n-1; j++){
            cout<<lu[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Which is same as Matrix A";

    float sol1[10];
    for(int i=0; i<n; i++){
        float sum_before = 0.0;
        for(int j=0; j<=i-1; j++){
            sum_before+=sol1[j]*l[i][j];
        }
        sol1[i] = (l[i][n]-sum_before)/l[i][i];
    }
    
    cout<<endl<<endl<<"Solution from matrix L:"<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<sol1[i]<<endl;
    }
    
    for(int i=0; i<n; i++){
        u[i][n] = sol1[i];
    }
    
    cout<<endl<<"Then, we our U matrix becomes:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n; j++){
            cout<<u[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    
    
    float sol2[10];
    for(int i=n-1; i>=0; i--){
        float sum_after = 0.0;
        for(int j=i+1; j<=n-1; j++){
            sum_after+=sol2[j]*u[i][j];
        }
        sol2[i] = (u[i][n]-sum_after)/u[i][i];
            
    }

    
    cout<<endl<<"The FINAL Solution set for the equations is:"<<endl;
    for(int k=0; k<=n-1; k++){
        cout<<sol2[k]<<endl;
    }
    return 0;
    
}


int main(){
    abc("example.txt");
    cout<<endl<<endl<<"***********************************   PART (C):   ****************************************"<<endl<<endl;
    abc("example1.txt");
    return 0;
}