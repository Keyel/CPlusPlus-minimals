// sizeof.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class A {
};

class B {
    int a = 1; //4  long int is 4, long 4, long long 8, double 8
};

class C {
    int a = 1; //4

    void f() { } // 0
};

class D {
    int a = 1; //4

    virtual void f() { } // 8 virtual table, de 4 + 8 =>  16 mert 8 byte-ra igazitja
};

class E {
    int a = 1;  //4

    E* ptr = nullptr;  // 8
};   //16, nem 12, alignment miatt

class E2 {
    E* ptr = nullptr;  // 8
    int a = 1;  //4
};   //16, nem 12, alignment miatt, ugy latszik nem szamit a sorrend

class E3 {
    int a = 1;  //4
    int b = 1;  //4
    E* ptr = nullptr;  // 8
};   //4 + 4 + 8 = 16, feltoltotte a lyukat

class E4 {
    int a = 1;  //4
    E* ptr = nullptr;  // 8
    int b = 1;  //4
};   //4 + lyuk_4 + 8 + 4 + lyuk(?) => 24, betett egy plusz lyukat, azaz ha van 8 byte-os benne, akkor a 4 byte-osnak is foglal 8 bytot

class E5 {
    int a = 1;  //4
    E* ptr = nullptr;  // 8
    int b = 1;  //4
    int c = 1;  //4
};   //4 + lyuk_4 + 8 + 4 + 4 => 24, feltoltotte a plusz lyukat

class E6 {
    int a = 1;  //4
    E* ptr = nullptr;  // 8
    int b = 1;  //4
    int c = 1;  //4
    int d = 1;  //4
};   //4 + lyuk_4 + 8 + 4 + 4 + 4 + lyuk => 24, megint egy 8-ast folglalt a 4-esnek


class F : B {
    
};

class G : B {
    virtual void f() { }
};

class H : D {
    void f() override { }
};

class I : B {
    int i = 0;
};

int main()
{
    A a;
    B b;
    C c;
    D d;
    E e;
    E2 e2;
    E3 e3;
    E4 e4;
    E5 e5;
    E6 e6;
    F f;
    G g;
    H h;
    I i;

    std::cout << "Size of a: " << sizeof a << std::endl;
    std::cout << "Size of b: " << sizeof b << std::endl;
    std::cout << "Size of c: " << sizeof c << std::endl;
    std::cout << "Size of d: " << sizeof d <<  "    virtual => 8 byte pointer (64 bit) to virtual table, but aligned to 8 size grid" << std::endl;
    std::cout << "Size of e: " << sizeof e << std::endl;
    std::cout << "Size of e2: " << sizeof e2 << std::endl;
    std::cout << "Size of e3: " << sizeof e3 << std::endl;
    std::cout << "Size of e4: " << sizeof e4 << std::endl;
    std::cout << "Size of e5: " << sizeof e5 << std::endl;
    std::cout << "Size of e6: " << sizeof e6 << std::endl;
    std::cout << "Size of f: " << sizeof f << std::endl;
    std::cout << "Size of g: " << sizeof g << std::endl;
    std::cout << "Size of h: " << sizeof h << std::endl;
    std::cout << "Size of i: " << sizeof i << "   inheritance cost 0" << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
