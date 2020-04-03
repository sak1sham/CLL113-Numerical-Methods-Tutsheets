#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{   float err1[100],err2[100];
    cout.precision(4);
    cout.setf(ios::fixed);
    int n,i,j,k,flag=0,count=0;
    double a[100][100];            //declare a 2d array for storing the elements of the augmented matrix
    double x[100];                //declare an array to store the values of variables
    double y;
    ifstream myfile;
    myfile.open ("example.txt", ios::in);
    float temp1;
    int temp2;
    float answer[100];
    answer[0] = 3;
    answer[1] = -5;
    answer[2] = 9;
    myfile >>temp2;
    n = temp2;
    i=0;
    j=0;
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
    
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }    
    


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



    float ini[100];
    cout<<"\nEnter the initial values of the variables:\n";
    //initializing the matrix ini[] as the initial matrix and x[]=ini[] for GS
    for (i=0;i<n;i++)
    {   cin>>ini[i];
        x[i] = ini[i];
    }
    
    cout<<"\nEnter the number of iterations:\n";
    int iter;
    cin>>iter;

    for(i = 0; i<iter; i++){
        for(int j=0; j<(sizeof(x)/sizeof(x[0])); j++){
            float sum = 0;
            for(int k=0; k<=n-1; k++){
                if(k!=j){
                    sum = sum + (a[j][k]*x[k]);
                }    
            }
            x[j] = (a[j][n] - sum)/a[j][j];
        }
        cout<<"iteration "<<i+1;
        for (int ctr=0;ctr<n;ctr++){
            cout<<"\t\t"<<x[ctr];        //Print the contents of x[]
        }    
        cout<<endl;
        float SumErr = 0;
        for(int ctr=0; ctr<n; ctr++){
            SumErr = SumErr + pow(x[ctr]-answer[ctr],2);   
        }
        err1[i] = sqrt(SumErr);
    }
    
    
    cout<<"\nThus, the solution is as follows for the Gauss-Seidel matrix:\n";
    for (i=0;i<n;i++){
        cout<<"x"<<i<<" = "<<x[i]<<endl;        //Print the contents of x[]
    }
    
    cout<<endl;    


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////Program for the Jacobi matrix ///////////////////////////////    


    double arr[100],arr_prev[100];
    //initializing arr[] = arr_prev[]
    for(int i = 0; i<n; i++){
        arr[i] = ini[i];
        arr_prev[i] = ini[i];
    }
    
    for(i = 0; i<iter; i++){
        for(int j=0; j < sizeof(arr)/sizeof(arr[0]); j++){
            float sum = 0;
            for(int k=0; k<=n-1; k++){
                if(k!=j){
                    sum = sum + (a[j][k]*arr_prev[k]);
                }    
            }
            
            arr[j] = (a[j][n] - sum)/a[j][j];
        }
        for(int i = 0; i<n; i++){
            arr_prev[i] = arr[i];
        }

    
        cout<<"iteration "<<i+1;
        for (int ctr=0;ctr<n;ctr++){
            cout<<"\t\t"<<arr[ctr];        //Print the contents of x[]
        }    
        cout<<endl;
        float SumErr = 0;
        for(int ctr=0; ctr<n; ctr++){
            SumErr = SumErr + pow(arr[ctr]-answer[ctr],2);   
        }
        err2[i] = sqrt(SumErr);
    }
    
    
    cout<<"\nThe solution is as follows for the Jacobi-matrix:\n";
    for (i=0;i<n;i++){
        cout<<"x"<<i<<" = "<<arr[i]<<endl;        //Print the contents of arr[]
    }
    cout<<endl;
        
        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    ////////////////////////// Program for SOR /////////////////////////////////////////


    double sor[100];
    for(int i = 0; i<n; i++){
        sor[i] = ini[i];
    }
    
    for(i = 0; i<iter; i++){
        for(int j=0; j<(sizeof(sor)/sizeof(sor[0])); j++){
            float sum = 0;
            for(int k=0; k<=n-1; k++){
                if(k!=j){
                    sum = sum + (a[j][k]*sor[k]);
                }    
            }
            float w = 1.5;
            sor[j] = (1-w)*sor[j] + w*(a[j][n]-sum)/a[j][j];
        }
    
        cout<<"iteration "<<i+1;
        for (int ctr=0;ctr<n;ctr++){
            cout<<"\t\t"<<sor[ctr];        //Print the contents of sor[]
        }    
        cout<<endl;
    }
    
    cout<<"\nThe solution is as follows for the SOR GS method:\n";
    for (i=0;i<n;i++){
        cout<<"x"<<i<<" = "<<sor[i]<<endl;        //Print the contents of sor[]
    }
    cout<<endl;
    cout<<"\nWe can clearly see that SOR converges much faster as compared to the usual GS method";
    cout<<"\nCovergence rates : Jacobi < Gauss-Seidel < SOR\n";
    
    
    ofstream outdata;
    outdata.open("outfile.csv",ios::app);
    for (i=0;i<iter;i++){
        outdata<<i+1<<","<<err1[i]<<endl;
    }
    outdata<<endl;
    for (i=0;i<iter;i++){
        outdata<<i+1<<","<<err2[i]<<endl;
    }
    outdata.close();
    return 0;
    
}