#include <iostream>
using namespace std;
class student
{
    public:

    student()
    {
        cout << " Default constructor is called:"<< endl;
    }
};
int main()
{
    student s;
    return 0;
}