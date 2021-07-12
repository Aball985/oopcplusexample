#include <iostream>
using namespace std;

class IEmployee
{
    //Abstraction example with interface
    //Pure virtual function abstract function obligated to run this function
    virtual void askForPromotion() = 0;
};

// Class Employee interface
// Contract Interface Employee
class Employee : IEmployee
{
    // Private variables
private:
    // Encapsulation example as these are only accesed through get and set methods
    string employeeName;
    string employeeCompany;
    int employeeAge;
    int employeeYearsAtCompany;

public:
    // Get and Sets
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
    string getEmployeeName()
    {
        return employeeName;
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
    // Employee Greeting
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

    // Employee Constructor
    Employee(string name, string company, int age, int years)
    {
        employeeName = name;
        employeeCompany = company;
        employeeAge = age;
        employeeYearsAtCompany = years;
    }
};

int main()
{
    Employee employee1 = Employee("Alex", "Google", 35, 12);
    Employee employee2 = Employee("Cynthia", "Dev.to", 15, 32);
    // Invoke greeting method
    employee1.greeting();
    // Second Employee
    // employee2.greeting();
    // employee1.setEmployeeAge(2);
    // cout << employee1.getEmployeeAge();

    employee1.askForPromotion();
    employee2.askForPromotion();
}