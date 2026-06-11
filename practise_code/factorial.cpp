#include <iostream>
using namespace std;
class factorial
{
    private:

    int num;

    public:

    void setnumber(int n)
    {
        num = n;
    }
    int getfactorial()
    {
        int fact = 1;
        for(int i=1; i<=num; i++)
        {
            fact=fact*num;
        }
        return fact;
    }
    
};
int main()
{
    factorial f;
    f.setnumber(5);
    cout<<"factorial of 5 :" << f.getfactorial() <<endl;
    return 0;
}