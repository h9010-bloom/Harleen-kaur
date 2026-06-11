#include<iostream>
using namespace std;
int function( int x)
{
    if (x > 0)
    {
        cout << x ;
        function(x - 2);
        cout << x ;
    }
}
int main()
{
    int result = function(5);
    return 0;
}