//Saksham Garg 2018CH10927 
//Question 2 
//Round-off error
//pi^4/90

#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;


int main()
{  int n = 8;
   double es = 0.5 * pow(10,2-n);
   const double PI = std::atan(1.0)*4;
   double ans = (PI*PI*PI*PI)/90.0;
   double res1 = 0.00000000;
   double res2 = 0.00000000;
   for(int i = 1; i<=10000; i++){
       res1  += (float)pow(i,-4);
   }
   for(int i = 10000; i>=1; i--){
       res2  += (float)pow(i,-4);
   }
   
   double err1 = (abs(ans-res1)/ans)*100;
   double err2 = (abs(ans-res2)/ans)*100;
   std::cout << std::fixed;
   cout<<std::setprecision(20);
   cout<<"(pi^4)/90 = "<<ans<<endl;
   cout<<"i = 1 to 10,000 gives f(n) = "<<res1<<endl;
   cout<<"i = 10,000 to 1 gives f(n) = "<<res2<<endl;
   cout<<"True percent Relative Error in i = 1 to 10,000 is "<<err1<<" %"<<endl;
   cout<<"True percent Relative Error in i = 10,000 to 1 is "<<err2<<" %"<<endl;
   
   return 0;
}

