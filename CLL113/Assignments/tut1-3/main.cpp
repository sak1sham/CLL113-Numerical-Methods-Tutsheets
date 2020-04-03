//Saksham Garg 2018CH10927 
//Question 3 
//Total Error in Iterative Methods
//The “divide and average” method


#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int a = 5;
    float x1 = 0.005;
	float x2;
	int i = 0;
    double eTol = 0.000001;
    double ans = pow(a,0.5);
	std::cout << std::fixed;
    cout<<std::setprecision(8);
    
    while(abs(ans-x1)>=eTol){
        x2 = 0.5*(x1 + ( ((float)a) / x1));
        cout<<"Step: "<<++i<<endl;
		cout<<"True % rel err "<<(abs(x2-ans)/ans)*100<<" %"<<endl;
		cout<<"Approx. % rel err ("<<i<<") steps: "<<(abs(x2-x1)/x1)*100<<" %"<<endl<<endl;
		x1 = x2;
    }
    
	cout<<"sqrt("<<a<<") = "<<x1<<endl;
    return 0;
}
