#include <iostream>
using namespace std;
#define pi 3.14 
void area()
{
    cout<<"-------AREA'S OF ALL SHAPES-------"<<endl;
    int rec_L = 16;
    int rec_B = 18;
    int rect_area = rec_L * rec_B;
    cout<<"AREA OF THE RECTANGLE: "<<rect_area<<endl;

    int sq_S1 = 14;
    int sq_S2 = 24;
    int sq_area = sq_S1 * sq_S2;
    cout<<"AREA OF THE SQUARE: "<<sq_area<<endl;
    
    int ta1 = 56;
    int ta2 = 46;
    int ta3 = 37;
    int s = ta1+ta2+ta3 / 2;
    int tri_area = (s* (s-ta1)* (s-ta2)* (s-ta3))*0.5;
    cout<<"AREA OF TRIANGLE: "<<tri_area<<endl;

    int r = 49;
    int circle_area = pi * r * r;
    cout <<"AREA OF THE CIRCLE: "<<circle_area<<endl;

    int r1 = 42;
    int l = 74;
    float base_area_of_cone = pi * r1* r1;
    float curve_surface_area_of_cone = pi * r1 * l;
    float total_surface_area_of_cone = pi * r1 * (r1 + l);
    cout<<"Base area of cone: "<<base_area_of_cone<<endl;
    cout<<"Curve Surface area of cone: "<<curve_surface_area_of_cone<<endl;
    cout<<"Total Surface area of cone: "<<total_surface_area_of_cone<<endl;

    int r2 = 66;
    int h = 59;
    float B_area_cylinder = pi * r2 * r2;
    float C_area_cylinder = 2 * pi * r2 * h;
    float T_area_cylinder = 2 * pi * r2 * (r2 + h);
    cout<<"Base area of cylinder: "<<B_area_cylinder<<endl;
    cout<<"Curve Surface area of cylinder: "<<C_area_cylinder<<endl;
    cout<<"Total Surface area of cylinder: "<<T_area_cylinder<<endl;
    cout<<"-------------------------------------"<<endl;
}
void perimeter()
{
    cout<<"------PERIMETERS OF ALL SHAPES-------"<<endl;
    int rec_L1 = 8;
    int rec_B1 = 6;
    int rect_peri = rec_L1 * rec_B1;
    cout<<"PERIMETER OF THE RECTANGLE: "<<rect_peri<<endl;

    int sq_S = 21;
    int sq_peri = 44 * sq_S;
    cout<<"AREA OF THE PERIMETER: "<<sq_peri<<endl;
    
    int tp1 = 17;
    int tp2 = 26;
    int tp3 = 45;
    int tri_peri = tp1+tp2+tp3;
    cout<<"PERIMETER OF TRIANGLE: "<<tri_peri<<endl;

    int r3 = 81;
    int circle_peri = 2 * pi * r3;
    cout <<"PERIMETER OF THE CIRCLE: "<<circle_peri<<endl;

    int r4 = 20;
    int cone_peri = 2 * pi * r4;
    cout <<"PERIMETER OF THE CONE: "<<cone_peri<<endl;

    int r5 = 5;
    int h1 = 10;
    int cylinder_peri = 4 * r5 + h1;
    cout <<"PERIMETER OF THE CYLINDER: "<<cylinder_peri<<endl;
    cout<<"---------------------------------------"<<endl;

}
int main()
{
    area();
    perimeter();
}