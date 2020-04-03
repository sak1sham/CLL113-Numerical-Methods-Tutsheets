#include <iostream>
#include<math.h>
#include<fstream>
#include<iomanip>

using namespace std;

void partialpivot(float a[][10],float I[][10], int i, int n){
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
    /*cout<<"After partialpivot(float[][10], int i, int n), we get:"<<endl;
    for(int k=0; k<=n-1; k++){
        for(int l=0; l<=n; l++){
            cout<<a[k][l]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;*/
}

int main()
{   std::cout << std::fixed;
    cout<<std::setprecision(4);
    ifstream myfile;
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
        
    
    }

    myfile.close();
    
    cout<<"Initial Augmented matrix is:"<<endl;
    for(int k=0; k<=n-1; k++){
        for(int l=0; l<=n; l++){
            cout<<a[k][l]<<"\t";
        }
        cout<<endl;
    }

    float B[10][10];
    cout<<endl<<"Now, we have assigned the values of A to B. Now, A = B."<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            B[i][j] = a[i][j];
       }
    }
   
    float I[10][10];
    cout<<endl<<"Now, we have initialised the identity matrix as I[][]."<<endl;
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

//******************Main LOOP****************

    for(int i=0; i<n; i++){
        partialpivot(a,I,i,n);
        float dividend = a[i][i];
        for (int j=0; j<=n; j++){           //Normalizing ith pivot
            a[i][j] = a[i][j]/dividend;
            I[i][j] = I[i][j]/dividend;
        }
        
        for(int k=i+1; k<n; k++){          //subtract other rows
            float var_k=a[k][i];
            for(int p = 0; p<=n; p++){
                a[k][p] = a[k][p] - (a[i][p]*var_k);
                if(p!=n){
                    I[k][p] = I[k][p] - (I[i][p]*var_k);
                }    
            }
        }
        
        for(int k=0; k<i; k++){          //subtract other rows
            float var_k=a[k][i];
            for(int p = 0; p<=n; p++){
                a[k][p] = a[k][p] - (a[i][p]*var_k);
                if(p!=n){
                    I[k][p] = I[k][p] - (I[i][p]*var_k);
                }
            }
        }
    }
    
///////////////////////////////////    
    cout<<"Finally, we get A[][] as:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
   
//////////////////////////////////////////////    
    float sol[10];
    
    for(int i=0; i<=n-1; i++){
        sol[i] = a[i][n];
    }
    
    cout<<endl<<"Solution of AX = C is :"<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<sol[i]<<endl;
    }

    cout<<endl<<"Finally, we get B[][] as:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n-1; j++){
            cout<<B[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    cout<<endl<<"Finally, we get I[][] as:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n-1; j++){
            cout<<I[i][j]<<"\t";
        }
        cout<<endl;
    }
  
    float mult[20][20];
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++){ 
            mult[i][j] = 0; 
            for (int k = 0; k < n; k++) 
                mult[i][j] += B[i][k] * I[k][j]; 
        } 
    } 
    
    cout<<endl<<"Finally, we get I[][] X B[][] as:"<<endl;
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n-1; j++){
            cout<<mult[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}


