#include <iostream>
using namespace std;

class IEmployee
{
    //Abstraction example with interface
    //Pure virtual function abstract function obligated to run this function
    virtual void askForPromotion() = 0;
};

//Class Employee interface
//Contract Interface Employee
class Employee : IEmployee
{
    //Private variables
private:
    //Encapsulation example as these are only accesed through get and set methods

    string employeeCompany;
    int employeeAge;
    int employeeYearsAtCompany;

protected:
    string employeeName;

public:
    //Get and Sets
    void setEmployeeName(string name)
    {
        employeeName = name;
    }
    void setEmployeeCompany(string company)
    {
        employeeCompany = company;
    }
    void setEmployeeAge(int age)
    {
        if (age >= 18)
        {
            employeeAge = age;
        }
    }
    void setEmployeeYearsAtCompany(int years)
    {
        employeeYearsAtCompany = years;
    }

    int getEmployeeAge()
    {
        return employeeAge;
    }
    string getEmployeeCompany()
    {
        return employeeCompany;
    }
    int getEmployeeYearsAtCompany()
    {
        return employeeYearsAtCompany;
    }
    //Employee Greeting
    void greeting()
    {
        cout << "\nHello: " << employeeName << endl;
        cout << "\nCompany: " << employeeCompany << endl;
        cout << "\nAge: " << employeeAge << endl;
        cout << "\nYears at Company: " << employeeYearsAtCompany << endl;
    }
    void askForPromotion()
    {
        if (employeeYearsAtCompany >= 30)
        {
            cout << employeeName << " promoted!"
                 << " with " << employeeYearsAtCompany << " Years" << endl;
        }
        else
        {
            cout << employeeName << " not promoted!" << endl;
        }
    }
    //Polymorhpism Example
    virtual void work()
    {
        cout << employeeName << " is doing work!" << endl;
    }
    //Employee Constructor
    Employee(string name, string company, int age, int years)
    {
        employeeName = name;
        employeeCompany = company;
        employeeAge = age;
        employeeYearsAtCompany = years;
    }
};

//Assigning contract Employee class to Developer
//Inhertince example
class Developer : public Employee
{
public:
    string favoriteLanguage;
    Developer(string name, string company, int age, int years, string language) : Employee(name, company, age, years)
    {
        favoriteLanguage = language;
    }
    // //Polymorphism
    // void work()
    // {
    //     cout << employeeName << " is doing coding! in " << favoriteLanguage << endl;
    // }
};

class Teacher : public Employee
{
public:
    string classSubject;
    Teacher(string name, string company, int age, int years, string subject) : Employee(name, company, age, years)
    {
        classSubject = subject;
    }
    void prepareLesson()
    {
        cout << employeeName << "Is preparing" << classSubject << "lesson" << endl;
    }
    //Polymorphism
    void work()
    {
        cout << employeeName << " is doing work! in " << classSubject << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Alex Macy", "Google", 35, 12);
    Employee employee2 = Employee("Cynthia Jones", "Dev.to", 15, 32);
    //Invoke greeting method

    employee1.greeting();
    //Second Employee
    //employee2.greeting();
    //employee1.setEmployeeAge(2);
    //cout << employee1.getEmployeeAge();

    employee1.askForPromotion();
    employee2.askForPromotion();

    //Inheritance example
    Developer developer1 = Developer("Bob Lenza", "Amazon", 42, 22, "Python");
    developer1.askForPromotion();

    //Inheritance example
    Teacher teacher1 = Teacher("Jade Smith", "Clevland High School", 35, 6, "Math");
    teacher1.askForPromotion();

    //Polymorphism
    // developer1.work();
    // teacher1.work();

    //Polymorphism
    //Employee pointer holds reference to developer and teacher
    Employee *e1 = &developer1;
    Employee *e2 = &teacher1;
    e1->work();
    e2->work();
}