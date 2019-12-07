//X^3-3X^2+3X-1

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double function(double a, double b, double c, double d)
{
    double n0 = -1000;
    double nn = 1000;
        
    double x;

    while (n0 < nn)
    {
        x = (n0 + nn) / 2;
        if (abs(a * pow(x, 3) + b * pow(x, 2) + c * x + d) < 0.000001)
            return x;
        else if (0.000001 < a * pow(x, 3) + b * pow(x, 2) + c * x + d)
            nn = x;
        else if (0.000001 > a * pow(x, 3) + b * pow(x, 2) + c * x + d)
            n0 = x;
    }

    return -1000;
}

int main()
{
    cout << "Enter a, b, c, d, if f(x) = a*X^3 + b*X^2 + c*X + d" << endl << endl;
    
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    
    double p = function(a, b, c, d);
    
    if (p == -1000)
        cout << "x not included in [-1000; 1000]";
    else
        cout << p;    
    
    return 0;
}
