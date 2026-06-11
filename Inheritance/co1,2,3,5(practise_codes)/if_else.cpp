#include<iostream>
using namespace std;
int main()
{
    string name ="XYZ ZZZ XXX";
    int roll_no = 12025;
    int sem = 3;
    string branch = "COE";
    string institution = "AMRITSAR GROUP OF COLLEGES";
    int eng_marks = 90;
    int maths_marks = 80;
    int bio_marks = 85;
    int phy_marks = 70;
    int chem_marks = 89;

    float total_marks =eng_marks+maths_marks+bio_marks+phy_marks+chem_marks;
    float percentage = (total_marks / 500) * 100;
    string grade;

    if (percentage >= 95)
    {
        grade = "A+";
    }
    else if (85 >= percentage <= 94 )
    {
        grade = "A";
    }
    else if (80 >= percentage <= 84 )
    {
        grade = "B+";
    }
    else if (75 >= percentage <= 79 )
    {
        grade = "B";
    }
    else if (60 >= percentage <= 74 )
    {
        grade = "C";
    }
    else if (percentage <= 59)
    {
        grade = "D";
    }
    else 
    {
        grade = "Fail";
    }
    cout<<"------------STUDENT RESULT----------------|"<<endl;
    cout<<"|   Name: "<<name<<"                      |"<<endl;           
    cout<<"|   Roll No: "<<roll_no<<"                |"<<endl;
    cout<<"|   Semester: "<<sem<<"                   |"<<endl;
    cout<<"|   Branch: "<<branch<<"                  |"<<endl;
    cout<<"|   Institution: "<<institution<<"        |"<<endl;
    cout<<"|-----------------------------------------|"<<endl;
    cout<<"|-------MARKS OF ALL FIVE SUBJECTS--------|"<<endl;
    cout<<"|   ENGLISH MARKS: "<<eng_marks<<"        |"<<endl;
    cout<<"|   MATHS MARKS: "<<maths_marks<<"        |"<<endl;
    cout<<"|   BIOLOGY MARKS: "<<bio_marks<<"        |"<<endl;
    cout<<"|   PHYSICS MARKS: "<<phy_marks<<"        |"<<endl;
    cout<<"|   CHEMISTRY MARKS: "<<chem_marks<<"     |"<<endl;
    cout<<"|-----------------------------------------|"<<endl;
    cout<<"|   Total Marks: "<<total_marks<<"        |"<<endl;
    cout<<"|   Percentage: "<<percentage<<"%"<<"     |"<<endl;
    cout<<"|   Grade: " <<grade <<"                    |"<<endl;
    cout<<"|-----------------------------------------|"<<endl;
    return 0;
    
}