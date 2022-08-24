/*
exercise 14-1. Define a base class called Animal that contains two private member variables:
a string to store the m_name of the animal (e.g., “Fido” or “Yogi”) and an integer member called
m_weight that will contain the weight of the animal in pounds. also include a public member
function, who(), that outputs a message giving the name and weight of the Animal object.
Derive two classes named Lion and Aardvark, with Animal as a public base class. Write a
main() function to create Lion and Aardvark objects (“Leo” at 400 pounds and “algernon” at
50 pounds, say) and demonstrate that the who() member is inherited in both derived classes
by calling it for the derived class objects.

exercise 14-2. Change the access specifier for the who() function in the Animal class to
protected, but leave the rest of the class as before. now modify the derived classes so that
the original version of main() still works without alteration

exercise 14-3. In the solution to the previous exercise, change the access specifier for the
who() member of the base class back to public and implement the who() function as a
member of each derived class so that the output message also identifies the name of the
class. Change main() to call the base class and derived class versions of who() for each of the
derived class objects.

*/
#include <iostream>

#include <iostream>
#include <string_view>

class Animal
{
public:
    Animal(std::string_view name, int weight) : m_name(name), m_weight(weight) {}

    void who();

private:
    std::string m_name = "";
    int m_weight = 0;
};

class Lion : public Animal
{
    //constructor using access specifier remains public
    using Animal::Animal;

public:
    void who();
};

class Aardvark : public Animal
{
    using Animal::Animal;

public:
    void who();
};

using std::cout;
using std::endl;

void Animal::who()
{
    cout << "My name is " << m_name << " my weight is " << m_weight << endl;
}

void Lion::who()
{
    cout << "My class is Lion. ";
    Animal::who();
}

void Aardvark::who()
{
    cout << "My class is Aardvark. ";
    Animal::who();
}


int main()
{
    Lion l("Leo", 400);
    Aardvark a("Algernon", 50);;

    l.who();
    a.who();

    l.Animal::who();
    a.Animal::who();

}
