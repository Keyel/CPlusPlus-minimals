// smart_pointers.cpp : Defines the entry point for the application.
//

#include "smart_pointers.h"

#include "unique_pointer.h"
#include "unique_pointer.cpp"

#include "shared_pointer.h"
#include "weak_pointer.h"

void use_unique_pointer();
void use_shared_pointer();

using namespace std;


struct A 
{
	int a;
	A(int _a = 0) : a(_a) 
	{
		cout << "A constructed " << a << endl;
	};

	~A() 
	{
		cout << "A destructed " << a << endl;
	}

};

template class unique_pointer<A>;

int main()
{

	//use_unique_pointer();
	use_shared_pointer();

	return 0;
}

void use_string()
{
	//char s[] = { "Hello" };
	//char s2[10] = { "Hello2" };

	//char const * s3 = { "Hi" };
	//char* s4 = new char[5];
	//s4[0] = 'H';
	//s4[1] = 'i';
	//s4[2] = '\0';
	////delete s;

	//cout << s << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;
}

void use_unique_pointer()
{
	//if(false)
	{
		A* _a1 = new A(1);
		unique_pointer<A> a1(_a1);
		unique_pointer<A> a2 = new A(2);
		if (false)
		{
			cout << a2->a << endl;
			a2->a = 22;
			cout << a2->a << endl;
			A& x = *a2;
			x.a = 222;
			cout << a2->a << endl;
		}

		unique_pointer a3(std::move(a2));
	}

	{
		unique_pointer<A> a5 = makeUnique<A>(new A(3));
	}
}

#define LOG \
cout << "sp_a refcount: " << sp_a.get_ref_count() << " weak: " << sp_a.get_weak_count() << endl; \
cout << "sp_b refcount: " << sp_b.get_ref_count() << " weak: " << sp_b.get_weak_count() << endl; \
cout << endl;


void use_shared_pointer()
{
	A* a = new A(1);
	A* b = new A(2);
	
	shared_pointer sp_a(a);
	shared_pointer sp_b(b);

	LOG
	
	shared_pointer sp_a2(sp_a);
	cout << "shared_pointer sp_a2(sp_a);" << endl;
	
	LOG
	weak_pointer wp_a(sp_a);
	cout << "weak_pointer wp_a(sp_a);" << endl;
	LOG

	{
		weak_pointer wp_a2(sp_a);
		cout << "weak_pointer wp_a2(sp_a);" << endl;
		LOG
	}

	LOG

	shared_pointer sh_a3{ wp_a.getSharedPointer() };
	cout << "shared_pointer sh_a3{ wp_a.getSharedPointer() };" << endl;
	LOG

	sp_b = sp_a;
	cout << "sp_b = sp_a;" << endl;

	LOG

	weak_pointer<A> wp(sp_a);

	{
		shared_pointer<A> sp_temp{ new A(3) };
		wp = sp_temp;
	}

	cout << "wp ref count:" << wp.get_ref_count() << " wp: " << wp.get_weak_count() << endl; 

	shared_pointer<A> sp_null(nullptr);
}
//destructed 1
