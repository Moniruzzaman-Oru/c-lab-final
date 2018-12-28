#include<iostream>
using namespace std;

class Person
{
    string name,birthday;

public:
    Person(){};
    Person(string name,string birthday)  ///Constructor
    {
        this->name=name;
        this->birthday=birthday;
    }
    void viewPerson()                    /// Person view function
    {
        cout<<"Name : "<<this->name<<endl;
        cout<<"Birthday : "<<this->birthday<<endl;
    }
};

class Department
{
    string department_name;
public:
    Department(){};
    Department(string department_name)
    {
        this->department_name=department_name;
    }
    void view_Department()
    {
        cout<<"Department : "<<this->department_name<<endl;
    }

};

class Student : public Person
{
    int roll;
    Department department;
public:
    Student(){};
    Student(string name,string birthday,int roll,Department dpt) : Person(name,birthday)
    {
        this->roll=roll;
        department=dpt;
    }
    void viewStudent()
    {
        viewPerson();
        department.view_Department();
        cout<<"Roll : "<<this->roll<<endl;
    }
};

class Teacher : public Person
{
    int teacher_id;
    Department department;
public:
    Teacher(){};
    Teacher(string name,string birthday,int teacher_id,Department dpt) : Person(name,birthday)
    {
        this->teacher_id=teacher_id;
         department=dpt;
    }

};

class Society_member : public Student
{
    string designation;
public:
    Society_member(){};
    Society_member(string name,string birthday,int roll,Department department,string deisgnation): Student(name,birthday,roll,department)
    {
        this->designation=designation;
    }
    void view_memberInfo()
    {
        cout<<"Society Member Info: "<<endl;
        viewStudent();
        cout<<"Designation : "<<this->designation<<endl;
    }
};

int main()
{
    Department department("CSE");

    Teacher *teachers[3]=
    {
        new Teacher("Hasan Hafizur Rahman","20-02-1975",1,department),
        new Teacher("Kamal Hossain Chowdhury","03-05-1978",2,department),
        new Teacher("Faisal Bin Abdul Aziz","11-02-1982",3,department)
    };

    Student *students[3]=
    {
        new Student("Moniruzzaman ","25-05-1997",10608018,department),
        new Student("Mohibur Rahman","02-12-1998",10608030,department),
        new Student("Yasir Uddin Nabil","11-03-1996",10508010,department)

    };

    Society_member *members[3]=
    {
        new Society_member("Imrul Hossain Niloy","11-02-1993",11508011,department,"Member"),
        new Society_member("Jishu Das","17-11-1990",11308011,department,"GS")
    };
    int teacherScores[3][2]={(2,3),(3,3),(2,4)};
    int studentMarks[3][2]={(2,2),(3,2),(3,3)};
    int finalScore[2];
    for(int i=0;i<2;i++)
    {
        int sum=0;
        for(int j=0;j<3;j++)
        {
           sum+=teacherScores[j][i]+studentMarks[j][i];
        }
        finalScore[i]=sum;
    }
    cout<<"DISPLAY BOARD"<<endl;
    for(int i=0;i<2;i++)
    {
        members[i]->viewStudent();
    }
}
