//https://learnyard.com/practice/dsa?sheet=frazs-interview-sheet

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40};

    // 1. begin() and end()
    cout << "First element: " << *v.begin() << '\n';

    // 2. size() and capacity()
    cout << "Size: " << v.size() << '\n';
    cout << "Capacity: " << v.capacity() << '\n';

    // 3. empty()
    cout << "Empty: " << boolalpha << v.empty() << '\n';

    // 4. front() and back()
    cout << "Front: " << v.front() << '\n';
    cout << "Back: " << v.back() << '\n';

    // 5. operator[] and at()
    cout << "Index 1: " << v[1] << '\n';
    cout << "At index 2: " << v.at(2) << '\n';

    // 6. push_back()
    v.push_back(50);

    // 7. emplace_back()
    v.emplace_back(60);

    // 8. pop_back()
    v.pop_back();

    // 9. insert(position, value)
    v.insert(v.begin() + 1, 15);

    // 10. insert(position, count, value)
    v.insert(v.begin() + 2, 2, 17);

    // 11. erase(position)
    v.erase(v.begin() + 1);

    // 12. erase(first, last)
    v.erase(v.begin() + 1, v.begin() + 3);

    // 13. resize()
    v.resize(5, 100);

    // 14. reserve()
    v.reserve(20);

    // 15. assign()
    vector<int> temp;
    temp.assign(3, 7);

    // 16. swap()
    vector<int> other = {1, 2};
    v.swap(other);

    // 17. clear()
    temp.clear();

    // 18. sort()
    sort(v.begin(), v.end());

    // 19. reverse()
    reverse(v.begin(), v.end());

    // 20. find()
    auto it = find(v.begin(), v.end(), 2);

    if (it != v.end())
        cout << "Found: " << *it << '\n';
    else
        cout << "Not found\n";

    // 21. count()
    cout << "Count of 1: "
         << count(v.begin(), v.end(), 1) << '\n';

    // 22. min_element() and max_element()
    cout << "Minimum: "
         << *min_element(v.begin(), v.end()) << '\n';

    cout << "Maximum: "
         << *max_element(v.begin(), v.end()) << '\n';

    // 23. accumulate()
    cout << "Sum: "
         << accumulate(v.begin(), v.end(), 0) << '\n';

    // 24. lower_bound() and upper_bound()
    sort(v.begin(), v.end());

    auto lb = lower_bound(v.begin(), v.end(), 2);
    auto ub = upper_bound(v.begin(), v.end(), 2);

    cout << "Lower bound index: "
         << lb - v.begin() << '\n';

    cout << "Upper bound index: "
         << ub - v.begin() << '\n';

    // 25. binary_search()
    cout << "Contains 2: "
         << binary_search(v.begin(), v.end(), 2) << '\n';

    // 26. data()
    if (!v.empty())
        cout << "First element using data(): "
             << *v.data() << '\n';

    // 27. Reverse iteration
    cout << "Reverse iteration: ";

    for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
        cout << *rit << " ";

    cout << '\n';

    // 28. cbegin() and cend()
    cout << "Elements: ";

    for (auto cit = v.cbegin(); cit != v.cend(); ++cit)
        cout << *cit << " ";

    cout << '\n';

    // 29. max_size()
    cout << "Max size: " << v.max_size() << '\n';

    // 30. shrink_to_fit()
    v.shrink_to_fit();

    return 0;
}

/*
OUTPUT (selected lines; capacity and max_size are
implementation-dependent):

First element: 10
Size: 4
Empty: false
Front: 10
Back: 40
Index 1: 20
At index 2: 30
Found: 2
Count of 1: 1
Minimum: 1
Maximum: 2
Sum: 3
Lower bound index: 1
Upper bound index: 2
Contains 2: 1
First element using data(): 1
Reverse iteration: 2 1
Elements: 1 2
*/



/*
========================================
          VECTOR MEMBER FUNCTIONS
========================================

.begin()
-> Returns an iterator pointing to the first element.

.end()
-> Returns an iterator pointing past the last element.

.size()
-> Returns the number of elements.
   Return type: size_type

.empty()
-> Returns true if the vector is empty; otherwise false.
   Return type: bool

.capacity()
-> Returns the number of elements that can be stored
   without reallocating memory.
   Return type: size_type

.max_size()
-> Returns the theoretical maximum number of elements.

.front()
-> Returns a reference to the first element.

.back()
-> Returns a reference to the last element.

[index] or operator[](index)
-> Accesses the element at the specified index.
   Does not perform bounds checking.

.at(index)
-> Accesses the element at the specified index.
   Throws std::out_of_range if index is invalid.

.push_back(value)
-> Appends an element to the end of the vector.
   Argument: value
   Return type: void

.emplace_back(args...)
-> Constructs an element directly at the end.
   Arguments: Constructor arguments
   Return type: reference to the inserted element (C++17+)

.pop_back()
-> Removes the last element.
   Return type: void

.insert(position, value)
-> Inserts value before the specified iterator position.
   Returns: Iterator to the first inserted element.

.insert(position, count, value)
-> Inserts count copies of value before position.
   Returns: Iterator to the first inserted element.

.insert(position, first, last)
-> Inserts elements from the iterator range [first, last).
   Returns: Iterator to the first inserted element.

.erase(position)
-> Removes the element at the specified iterator position.
   Returns: Iterator to the element after the erased element.

.erase(first, last)
-> Removes elements in the range [first, last).
   Returns: Iterator to the element after the erased range.

.clear()
-> Removes all elements.
   Size becomes 0; capacity is not necessarily reduced.

.resize(n)
-> Changes the number of elements to n.
   New elements are default-inserted if size increases.

.resize(n, value)
-> Changes size to n.
   New elements are initialized with value if size increases.

.reserve(n)
-> Requests capacity of at least n elements.
   Does not change size.

.shrink_to_fit()
-> Requests reduction of capacity to fit size.
   Non-binding request; implementation may ignore it.

.assign(count, value)
-> Replaces contents with count copies of value.

.assign(first, last)
-> Replaces contents with elements from [first, last).

.swap(vector& other)
-> Exchanges the contents of two vectors.
   Return type: void

.rbegin()
-> Returns a reverse iterator to the last element.

.rend()
-> Returns a reverse iterator before the first element.

.cbegin()
-> Returns a constant iterator to the first element.

.cend()
-> Returns a constant iterator past the last element.

.crbegin()
-> Returns a constant reverse iterator to the last element.

.crend()
-> Returns a constant reverse iterator before the first element.

.data()
-> Returns a pointer to the underlying element array.

========================================
*/

/*
========================================
       COMMON VECTOR ALGORITHMS
========================================

sort(first, last)
-> Sorts elements in ascending order.

sort(first, last, greater<int>())
-> Sorts elements in descending order.

reverse(first, last)
-> Reverses the specified range.

find(first, last, value)
-> Returns iterator to the first matching element,
   or last if not found.

count(first, last, value)
-> Returns the number of occurrences of value.

min_element(first, last)
-> Returns iterator to the smallest element.

max_element(first, last)
-> Returns iterator to the largest element.

binary_search(first, last, value)
-> Returns true if value exists in a sorted range.

lower_bound(first, last, value)
-> Returns iterator to the first element >= value.

upper_bound(first, last, value)
-> Returns iterator to the first element > value.

accumulate(first, last, initial_sum)
-> Calculates the sum when used with plus operation.
   Header: <numeric>

next_permutation(first, last)
-> Rearranges elements into the next lexicographical
   permutation, if one exists.

*/