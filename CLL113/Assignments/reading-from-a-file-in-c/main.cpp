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
        
    
    }

    myfile.close();
    
    for (int i=0; i<=n-1; i++){           //print
        for(int j=0; j<=n; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    return 0;
    
}
