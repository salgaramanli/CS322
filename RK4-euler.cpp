#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>

#define e 2.7182818284590452353602874713527

using namespace std;

double f(double x, double y)
{
    //return  2*(x)-y+2;
    return 1-pow(y,2);//(pow(e,(-x))-y) ; // Exmaple y' = x + y

}

void rungeKutta(double x0, double y0, double h, double x)
{
    double y = y0;
    double xn = x0;
    cout << "x = " << x0 << ", y = " <<setprecision(10)<< y0 <<endl;
    while (xn <= x-h)
    {
        double k1 = h * f(xn, y);cout<<"k1 : "<<k1<<endl;
        double k2 = h * f(xn + h/2, y + k1/2);cout<<"k2 : "<<k2<<endl;
        double k3 = h * f(xn + h/2, y + k2/2);cout<<"k3 : "<<k3<<endl;
        double k4 = h * f(xn + h, y + k3);cout<<"k4 : "<<k4<<endl;

        double yn = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        cout <<endl<< "x = " << xn+h << "\t , y = " <<setprecision(10)<< yn <<endl<<endl;
        y = yn;
        xn += h;
    }
}

void eulerMethod(double x0, double y0, double h, double x)
{
    double y = y0;
    double xn = x0;
    cout << "x = " << x0 << ", y = " <<setprecision(10)<< y0 <<endl;
    while (xn <= x-h)
    {
        double yn = y + h * f(xn, y);
        cout << "x = " << xn+h << "\t , y = " <<setprecision(10)<< yn <<endl;
        y = yn;
        xn += h;
    }
}

int main()
{
    double x0 = 0;
    cout<<"Enter number of X0 : ";
    cin>>x0;
    double y0 = 1;
    cout<<"Enter number of Y0 : ";
    cin>>y0;
    double h = 0.2;
    cout<<"Enter number of h : ";
    cin>>h;
    double x = 0.4;
    cout<<"Enter number of Last X : ";
    cin>>x;

    eulerMethod(x0, y0, h, x);
    rungeKutta(x0, y0, h ,x);

    return 0;
}
