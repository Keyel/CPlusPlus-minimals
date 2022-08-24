/*

exercise 14 - 4. Define a Person class containing member variables to store a person’s age,
name, and gender.Derive an Employee class from Person that adds a member variable to store
a personnel number.Derive an Executive class from Employee.each derived class should
define a member function who() that displays information about what it is.think carefully
about proper data hidingand access specifiers in this exercise.In this particular application,
privacy concerns prohibit the exposure of personal details, except for the information printed by
an object’s who() member.each class can decide explicitly what to expose there. (name and
    type will do—something like “Fred Smith is an employee.”) Furthermore, people also aren’t
    allowed to change name or gender, but they are allowed to ageand have birthdays.Write a
    main() function to generate a vector of five executivesand a vector of five ordinary employees
    and display information about them.In addition, display the information about the executives by
    calling the member function inherited from the Employee class.

*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::string_view;

const char* male = "male";
const char* female = "female";


class Person
{
public:
    Person(int age, string_view name, string_view gender);


    //int get_age() const;
    //const string& get_name() const;
    //const string& get_gender() const;

    void now_is_my_birthday();
protected:
    int m_age;
    string m_name;
    string m_gender;
};

class Employee : public Person
{
public:
    Employee(int age, string_view name, string_view gender, string_view personel_number);

    void who() const;
private:
    string m_personel_number;
};

class Executive : public Employee
{
public:
    using Employee::Employee;

    void who() const;
};

Person::Person(int age, string_view name, string_view gender) : m_age(age), m_name(name), m_gender(gender)
{}

//int Person::get_age() const
//{
//    return m_age;
//}
//
//string const & Person::get_name() const
//{
//    return m_name;
//}
//
//string const& Person::get_gender() const
//{
//    return m_gender;
//}

void Person::now_is_my_birthday() 
{
    ++m_age;
}

Employee::Employee(int age, string_view name, string_view gender, string_view personel_number)
    : Person(age, name, gender), m_personel_number(personel_number)
{}

void Employee::who() const
{
    cout << m_name << " is an Employee" << endl;
}

void Executive::who() const
{
    cout << m_name << " is an Executive, " << (m_gender == "male" ? "his" : "her") << " age is " << m_age << endl;
}


int main()
{
    //Person p(35, "John Smith", male);
    //Employee e(25, "Agatha Smith", female, "AB123");
    //Executive ex(47, "Robert Redford", female, "ZW321");

    ////p.who();
    //e.who();
    //ex.who();

    std::vector<Employee> es{
        {25, "Agatha Smith 1", female, "AB121" },
        {26, "Robert Smith 2", male, "AB122" },
        {27, "Agatha Smith 3", female, "AB123" },
        {28, "John Smith 4", male, "AB124" },
        {29, "Agatha Smith 5", female, "AB125" },
    };

    std::vector<Executive> exs{
        {25, "Agatha Redford 1", female, "ZW121" },
        {26, "Robert Redford 2", male, "ZW122" },
        {27, "Agatha Redford 3", female, "ZW123" },
        {28, "John Redford 4", male, "ZW124" },
        {29, "Agatha Redford 5", female, "ZW125" },
    };

    for (auto const & e : es) {
        e.who();
    }
    
    cout << endl;
    
    for (auto const& ex : exs) {
        ex.who();
    }

    cout << endl;

    for (Employee const& ex : exs) {
        ex.who();
    }


    exs[4].now_is_my_birthday();

    cout << endl;

    for (auto const& ex : exs) {
        ex.who();
    }

}
