/*

exercise 14 - 1. Define a base class called Animal that contains two private member variables :
a string to store the m_name of the animal(e.g., “Fido” or “Yogi”) and an integer member called
m_weight that will contain the weight of the animal in pounds.also include a public member
function, who(), that outputs a message giving the nameand weight of the Animal object.
Derive two classes named Lionand Aardvark, with Animal as a public base class.Write a
main() function to create Lionand Aardvark objects(“Leo” at 400 pounds and “algernon” at
    50 pounds, say) and demonstrate that the who() member is inherited in both derived classes
    by calling it for the derived class objects.

*/

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
    using Animal::Animal;
};

class Aardvark : public Animal
{
    using Animal::Animal;
};

using std::cout;
using std::endl;

void Animal::who() 
{
    cout << "My name is " << m_name << " my weight is " << m_weight << endl;
}

int main()
{
    Lion l("Leo", 400);
    Aardvark a("Algernon", 50);;

    l.who();
    a.who();

}
