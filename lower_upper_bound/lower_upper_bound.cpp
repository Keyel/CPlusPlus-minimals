// upper_upper_bound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <thread>
#include <vector>
#include <string>

using std::endl;
using std::cout;


namespace
{
/*
    lower_bound(4)   upper_bound(4)
            |        |
    { 1, 2, 3,       5, 6, 7}
  

    lower_bound(4)   upper_bound(4)
                |       |
    { 1, 2, 3,  4,4,4,  5, 6, 7}


*/

    template <typename RandomAccessIt, typename T>
    RandomAccessIt lower_bound_linear(RandomAccessIt first, RandomAccessIt last, T const& value)
    {
        RandomAccessIt ret = last;
        for (auto it = first; it < last; std::advance(it, 1))
        {
            if (!(*it < value))
            {
                ret = it;
                break;
            }
        }

        return ret;
    }

    template <typename RandomAccessIt, typename T>
    RandomAccessIt upper_bound_linear(RandomAccessIt first, RandomAccessIt last, T const& value)
    {
        RandomAccessIt ret = last;
        for (auto it = first; it < last; std::advance(it, 1))
        {
            if (*it > value)
            {
                ret = it;
                break;
            }
        }

        return ret;
    }
}

template <typename RandomAccessIt, typename T>
RandomAccessIt lower_bound_logaritmic(RandomAccessIt first, RandomAccessIt last, T const& value)
{
    auto count = last - first; //random access iterators
    while (count > 0)
    {
        RandomAccessIt mid = first;
        std::advance(mid, count / 2);
        
        if ( (*mid) < value)
        {
            first = ++mid;
        }
        else
        {
            last = mid;
        }
        count = last - first;
    }

    return first;
}

template <typename ForwardIt, typename T>
ForwardIt lower_bound_logaritmic_forward_iterator(ForwardIt first, ForwardIt last, T const& value)
{
    auto count = std::distance(first, last); // forwar iterator
    decltype(count) delta;
    while (count > 0)
    {
        ForwardIt mid = first;
        
        delta = count / 2;
        std::advance(mid, delta);

        if ((*mid) < value)
        {
            first = ++mid;
            count -= (delta + 1);
        }
        else
        {
            last = mid;
            count = delta;
        }
    }

    return first;
}


template <typename RandomAccessIt, typename T>
RandomAccessIt upper_bound_logaritmic(RandomAccessIt first, RandomAccessIt last, T const& value)
{
    auto count = last - first;
    while (count > 0)
    {
        RandomAccessIt mid = first;
        std::advance(mid, count / 2);

        if ((*mid) <= value)
        {
            first = ++mid;
        }
        else
        {
            last = mid;
        }
        count = last - first;
    }

    return first;
}

std::string f()
{
    return "g hi";
}

auto g() -> std::string
{
    return "f hi";
}

auto h = []()->std::string
{
    size_t i = 0;
    return "h hi";
};

int main()
{
    cout << f() << endl;

    int v[] = { 1, 2, 4, 4, 5, 6 };
    //std::array<int, 6> v2 = { 1, 2, 3, 3, 4, 5 };

    std::vector<std::string> ss = { "A", "B", "C", "C", "D", "E" };
    auto lb_ss = lower_bound_linear(ss.begin(), ss.end(), "C");
    cout << "C is lowerbound from index " << std::distance(ss.begin(), lb_ss) << endl ;

    //cout << v2.size();
    
    auto first = v;
    auto last = v + 6;

    for (int i = 0; i < 8; ++i)
    {
        auto lb = std::lower_bound(first, last, i);

        cout << "lower bound for index " << i;

        if (lb == last)
        {
            cout << " not found";
        }
        else
        {
            cout << " is " << std::distance(first, lb);
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 8; ++i)
    {
        auto lb = lower_bound_logaritmic_forward_iterator(first, last, i);

        cout << "lower bound for index " << i;
        
        if (lb == last) 
        {
            cout << " not found";
        }
        else 
        {
            cout << " is " << std::distance(first, lb);
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 8; ++i)
    {
        auto lb = std::upper_bound(first, last, i);

        cout << "upper bound for value " << i;

        if (lb == last)
        {
            cout << " not found";
        }
        else
        {
            cout << " is " << std::distance(first, lb);
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 8; ++i)
    {
        auto lb = upper_bound_logaritmic(first, last, i);

        cout << "upper bound for value " << i;

        if (lb == last)
        {
            cout << " not found";
        }
        else
        {
            cout << " is " << std::distance(first, lb);
        }

        cout << endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

};



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
