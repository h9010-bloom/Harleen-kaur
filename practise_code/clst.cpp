#include<iostream>
using namespace std;
struct studentstruct
{
    int age;
    void display()
    {
        cout<<"age(struct): "<<age <<endl;
    }

};
class studentclass
{
    private:
    int age;
    public:
    void setdata(int a)
    {
        age = a;
    }
    void getdata()
    {
        cout<<"age(class): "<<age <<endl;
    }
};
int main()
{
    studentstruct s1;
    s1.age = 20;
    s1.display();

    studentclass s2;
    s2.setdata(26);
    s2.getdata();

    return 0;

}