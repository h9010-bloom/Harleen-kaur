#include<iostream>
using namespace std;
class vehicle_company
{
    string name;
    string adress;

    public:
    void setvehicle_company()
    {
        cout<<"-----Here the details about vehicle company------\n";
        cout<<"enter company name: ";
        cin>>name;
        cout<<"enter company adress: ";
        cin>>adress;
    }
    void getvehicle_company()
    {
        cout<<"-----Here the details about vehicle company------\n";
        cout<<"COMPANY NAME: "<<name<<endl;
        cout<<"COMPANY ADRESS: "<<adress<<endl;
    }
};
class car:public vehicle_company
{
    int number_of_cars;

    public:
    void setcar()
    {
        cout<<"\n-----Here the details about cars in the company------\n";
        cout<<"enter number of cars in the vehicle company: ";
        cin>>number_of_cars;
    }
    void getcar()
    {
        cout<<"\n-----Here the details about cars in the company------\n";
        cout<<"NUMBER OF CARS IN COMPANY: "<<number_of_cars<<endl;
    }
};
class bike:public vehicle_company
{
    int number_of_bikes;

    public:
    void setbike()
    {
        cout<<"\n-----Here the details about bikes in the company------\n";
        cout<<"enter the number of bikes in the vehicle company: ";
        cin>>number_of_bikes;
    }
    void getbike()
    {
        cout<<"\n-----Here the details about bikes in the company------\n";
        cout<<"NUMBER OF BIKES IN COMPPANY: "<<number_of_bikes<<endl;
    }
};
class customer1_car:public car
{
    string car_name;
    string car_model;
    int car_number;

    public:
    void setcustomer1_car()
    {
        cout<<"\n-----Here the details about buy a CAR from customer_1------\n";
        cout<<"enter car name: ";
        cin>>car_name;
        cout<<"enter carmodel: ";
        cin>>car_model;
        cout<<"enter car number: ";
        cin>>car_number;
    }
    void getcustomer1_car()
    {
        cout<<"\n-----Here the details about buy a CAR from customer_1------\n";
        cout<<"CUSTOMER 1 CAR'S NAME: "<<car_name<<endl;
        cout<<"CUSTOMER 1 CAR'S MODEL: "<<car_model<<endl;
        cout<<"CUSTOMER 1 CAR'S NUMBER: "<<car_number<<endl;
    }
};
class customer2_bike:public bike
{
    string bike_name;
    string bike_model;
    int bike_number;

    public:
    void setcustomer2_bike()
    {
        cout<<"\n-----Here the details about buy a bike from customer_2------\n";
        cout<<"enter bike name: ";
        getline(cin,bike_name);
        cout<<"enter bike model: ";
        getline(cin,bike_model);
        cout<<"enter bike number: ";
        getline(cin,bike_number);
    }
    void getcustomer2_bike()
    {
        cout<<"\n-----Here the details about buy a bike from customer_2------\n";
        cout<<"CUSTOMER 2 BIKE'S NAME: "<<bike_name<<endl;
        cout<<"CUSTOMER 2 BIKE'S MODEL: "<<bike_model<<endl;
        cout<<"CUSTOMER 2 BIKE'S NUMBER: "<<bike_number<<endl;
    }
};
int main()
{
    vehicle_company vc;
    car ca;
    bike bi;
    customer1_car c;
    customer2_bike b;

    vc.setvehicle_company();
    ca.setcar();
    bi.setbike();
    c.setcustomer1_car();
    b.setcustomer2_bike();

    vc.getvehicle_company();
    ca.getcar();
    bi.getbike();
    c.getcustomer1_car();
    b.getcustomer2_bike();

    return 0;
}