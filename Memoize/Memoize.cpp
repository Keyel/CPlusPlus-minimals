// Memoize.cpp : Defines the entry point for the application.
//

#include "Memoize.h"
#include <chrono>
#include <thread>
#include <functional>
#include <map>


using namespace std;

namespace {
	
	int add(int param1, int param2)
	{
		this_thread::sleep_for(std::chrono::seconds(1));
		return param1 + param2;
	}

	string stringifyInt(int param1) {
		this_thread::sleep_for(std::chrono::seconds(1));
		return std::to_string(param1) + "!";
	}
}

namespace tools 
{
	//typedef int (*ints_to_int)(int, int);
	//ints_to_int memoize_old(int (*f)(int par1, int par2))
	//{
	//	return [&](int p1, int p2) -> int 
	//	{
	//		return f(p1, p2);
	//	}
	//}


	template <typename TKey, typename TValue>
	auto memoize(std::function<TValue(TKey)> func)
	{
		std::shared_ptr< std::map<TKey, TValue> > store = make_shared< std::map<TKey, TValue> >();
		return[func, store](TKey param) -> TValue
		{
			auto found_it = store->find(param);
			if ( found_it != store->end() ) 
			{
				return found_it->second;
			}

			TValue value = func(param);
			//(* store)[param] = value;
			store->insert(make_pair(param, value));
			
			//cout << "store changed to:" << endl;
			//for (auto it = store->cbegin(); it != store->cend(); ++it)
			//{
			//	cout << it->first << " => " << it->second << endl;
			//}

			cout << "store changed to:" << endl;
			for (auto const & item  : *store) {
				cout << item.first << " => " << item.second << endl;
			}

			cout << "store changed to:" << endl;
			for (auto const& [key, value] : *store) {
				cout << key << " => " << value << endl;
			}

			return value;
		};
	}


	//struct memoizer 
	//{
	//	typedef std::function<int(int, int)> func_type;
	//	typedef std::tuple<int, int> key_type;
	//private:
	//	func_type _func;
	//	std::map< key_type, int> memo;

	//public:
	//	//elteszem a memoizalando fuggvenyt
	//	memoizer(func_type func) : 
	//		_func(func) 
	//	{
	//		
	//	}

	//	//lehet fuggvenyszeruen hivni
	//	int operator()(int p1, int p2) {
	//		key_type key(p1, p2);

	//		auto it = memo.find(key);
	//		bool found = it != memo.end();
	//		if (found) {
	//			return it->second;
	//		}

	//		return memo[key] = _func(p1, p2);
	//	}
	//}; 

	
	template<typename param_type, typename value_type>
	struct tmemoizer
	{
		typedef std::function<value_type(param_type)> func_type;
		typedef param_type key_type;
	private:
		func_type _func;
		std::map< key_type, value_type> memo;

	public:
		//elteszem a memoizalando fuggvenyt
		tmemoizer(func_type func) :
			_func(func)
		{

		}

		//lehet fuggvenyszeruen hivni
		value_type operator()(param_type param) {
			//param => key, kesobb lehetne mas a key esetleg
			key_type key = param;
			auto it = memo.find(key);
			bool found = it != memo.end();
			if (found) {
				return it->second;
			}

			return memo[key] = _func(param);
		}
	};

}


int main()
{
	cout << "Hello CMake." << endl;
	
	//cout << std::format("1 + 2 = {}", add(1, 2)) << endl;
	//cout << "2 + 3 = " << add(2, 3) << endl;
	//cout << "4 + 5 = " << add(4, 5) << endl;
	//cout << "6 + 7 = " << add(6, 7) << endl;

	
	//{
	//	auto m_add = tools::memoizer(add);

	//	cout << "Starting" << endl;

	//	cout << "memo 2 + 3 = " << m_add(2, 3) << endl;
	//	cout << "memo 4 + 5 = " << m_add(4, 5) << endl;
	//	cout << "memo 6 + 7 = " << m_add(6, 7) << endl;

	//	cout << "memo 2 + 3 = " << m_add(2, 3) << endl;
	//	cout << "memo 4 + 5 = " << m_add(4, 5) << endl;
	//	cout << "memo 6 + 7 = " << m_add(6, 7) << endl;

	//	cout << "This is the end";
	//}

	//{
	//	auto m_convert = tools::tmemoizer<int, string>(stringifyInt);
	//	cout << "Starting" << endl;
	//	cout << 1 << " stringified is " << m_convert(1) << endl;
	//	cout << 2 << " stringified is " << m_convert(2) << endl;
	//	cout << 3 << " stringified is " << m_convert(3) << endl;
	//	cout << 1 << " stringified is " << m_convert(1) << endl;
	//	cout << 2 << " stringified is " << m_convert(2) << endl;
	//	cout << 3 << " stringified is " << m_convert(3) << endl;
	//	cout << "This is the end" << endl;
	//}

	{
		auto m_convert = tools::memoize<int, string>(stringifyInt);
		cout << "Starting" << endl;
		cout << 1 << " stringified is " << m_convert(1) << endl;
		cout << 2 << " stringified is " << m_convert(2) << endl;
		cout << 3 << " stringified is " << m_convert(3) << endl;
		cout << 1 << " stringified is " << m_convert(1) << endl;
		cout << 2 << " stringified is " << m_convert(2) << endl;
		cout << 3 << " stringified is " << m_convert(3) << endl;
		cout << "This is the end" << endl;
	}


	this_thread::sleep_for(std::chrono::seconds(5));

	return 0;
}
