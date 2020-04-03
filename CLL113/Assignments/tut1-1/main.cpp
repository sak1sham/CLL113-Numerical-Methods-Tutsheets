//Saksham Garg 2018CH10927 
//Question 1 
//Truncation Error
//Maclaurin series

#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;
long int fac(int n){
    long int f = 1;
    for(int i = 1; i<=n; i++){
        f = f*i;
    }
    return f;
}

int main()
{  int n = 8;
   double es = 0.5 * pow(10,2-n);
   const double PI = std::atan(1.0)*4;
   double x = 0.3 * PI;
   int i = 0;
   double res = 0.00000000;
   //INV: res = res + pow(x,i)/fac(i) ^ pow(x,i)/fac(i)>=es
   while(pow(x,i)/fac(i)>=es){
       res += pow(-1,i/2)*pow(x,i)/fac(i);
       i+=2;
   }
   cout<<"Number of terms required are : "<<i/2<<endl;
   std::cout << std::fixed;
   cout<<std::setprecision(8);
   cout<<"Final answer : "<<res;
   //assert: res = sum(i = 0 to n){pow(x,i)/fac(i)} ^ pow(x,n)/fac(n)>=es 
   return 0;
}
