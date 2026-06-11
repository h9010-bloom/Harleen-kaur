#include <iostream>
using namespace std;
class ram
{
    int age;
    public:
    ram(int a)//parameterized constructor
    {
        age=a;
    }
    ram(const ram &obj)
    {
        age=obj.age;
        cout<<"copy constructor called:"<<age<<endl;
    }
};
int main()
{
    ram r(51);
    ram r1(r);//copy constructor r1(r) which 'r1' copies the value of 'r'
    return 0;
}