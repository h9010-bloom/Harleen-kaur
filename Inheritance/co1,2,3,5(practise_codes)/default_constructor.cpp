#include <iostream>
using namespace std;
class student
{
    int roll;
    public:
    student() //default constructor
    {
        roll=10;
        cout<<"default constructor called: "<<roll<<endl;
    }
};
int main()
{
    student s;
    return 0;
}