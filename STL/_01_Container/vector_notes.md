# C++ STL: Vector Notes

## 1. What is a Vector?

A `vector` is a dynamic array in C++. It stores elements contiguously and can grow or shrink as needed.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    v.push_back(40);

    for (int x : v) {
        cout << x << " ";
    }
}
```

Output:

```text
10 20 30 40
```

Include:

```cpp
#include <vector>
```

## 2. Declaration and Initialization

```cpp
vector<int> a;                    // Empty vector
vector<int> b(5);                 // Five elements, all initialized to 0
vector<int> c(5, 10);             // Five elements, all 10
vector<int> d = {1, 2, 3, 4};     // Initializer list
vector<int> e(d);                 // Copy of d
vector<int> f = {5};              // One element: 5
```

Important distinction:

- `vector<int> v(5);` creates five elements.
- `vector<int> v = {5};` creates one element whose value is `5`.

## 3. Element Access

| Method | Arguments | Return (non-const vector) | Purpose | Complexity |
|---|---|---|---|---|
| `v[i]` | Index | `int&` | Access element; no bounds checking | `O(1)` |
| `v.at(i)` | Index | `int&` | Bounds-checked access; throws `out_of_range` if invalid | `O(1)` |
| `v.front()` | None | `int&` | First element | `O(1)` |
| `v.back()` | None | `int&` | Last element | `O(1)` |
| `v.data()` | None | `int*` | Pointer to contiguous element storage | `O(1)` |

Example:

```cpp
vector<int> v = {10, 20, 30};

cout << v[1];       // 20
cout << v.at(2);    // 30
cout << v.front();  // 10
cout << v.back();   // 30

int* p = v.data();
cout << p[1];       // 20
```

**Safety:** Do not call `front()`, `back()`, or `pop_back()` on an empty vector. `v[i]` requires a valid index. `v.at(i)` checks the index.

## 4. Size and Capacity

| Method | Arguments | Return type | Meaning |
|---|---|---|---|
| `size()` | None | `size_t` | Number of elements |
| `empty()` | None | `bool` | Whether vector has no elements |
| `capacity()` | None | `size_t` | Number of elements that can fit without reallocation |
| `max_size()` | None | `size_t` | Implementation-dependent theoretical maximum |
| `reserve(n)` | Requested capacity | `void` | Requests capacity of at least `n`; does not change size |
| `resize(n)` | New size | `void` | Changes the number of elements |
| `resize(n, value)` | New size, fill value | `void` | New elements are initialized to `value` |
| `shrink_to_fit()` | None | `void` | Non-binding request to reduce excess capacity |

Example:

```cpp
vector<int> v;

v.reserve(100);
cout << v.size();      // 0
cout << v.capacity();  // At least 100

v.resize(3);
cout << v.size();      // 3; new int elements are 0
```

Remember:

- `size()` = current number of elements.
- `capacity()` = current allocated capacity.
- `reserve()` changes capacity when needed, not size.
- `resize()` changes size.
- `shrink_to_fit()` is a request; the implementation may ignore it.

## 5. Adding Elements

### `push_back(value)`

Adds an element to the end. Returns `void`.

```cpp
vector<int> v = {10, 20};
v.push_back(30);  // {10, 20, 30}
```

Complexity: amortized `O(1)`; an individual insertion can be `O(n)` if reallocation is needed.

### `emplace_back(args...)`

Constructs an element at the end. In C++17 and later, returns a reference to the inserted element; in earlier standards, returns `void`.

```cpp
vector<int> v;
v.emplace_back(10);
v.emplace_back(20);  // {10, 20}
```

For simple types such as `int`, the practical difference from `push_back()` is usually negligible.

### `insert(position, value)`

Inserts before `position`; returns an iterator to the first inserted element.

```cpp
vector<int> v = {10, 20, 40};
auto it = v.insert(v.begin() + 2, 30);
// v: {10, 20, 30, 40}
// *it == 30
```

Common overloads:

```cpp
v.insert(pos, value);           // One value
v.insert(pos, count, value);    // count copies of value
v.insert(pos, first, last);     // Elements from iterator range [first, last)
v.insert(pos, {a, b, c});       // Initializer list
```

Example:

```cpp
vector<int> v = {10, 40};
v.insert(v.begin() + 1, 3, 20);
// {10, 20, 20, 20, 40}
```

### `emplace(position, args...)`

Constructs an element at the specified position and returns an iterator to it.

```cpp
vector<int> v = {10, 30};
auto it = v.emplace(v.begin() + 1, 20);
// v: {10, 20, 30}
```

Insertion at the beginning or middle is generally `O(n)` because elements may need to shift.

## 6. Removing Elements

### `pop_back()`

Removes the last element. Takes no arguments and returns `void`.

```cpp
vector<int> v = {10, 20, 30};
v.pop_back();  // {10, 20}
```

Complexity: `O(1)`. It does **not** return the removed value.

Correct way to read the last value before removing it:

```cpp
int last = v.back();
v.pop_back();
```

### `erase(position)`

Removes the element at the iterator position and returns an iterator to the next element, or `end()` if there is no next element.

```cpp
vector<int> v = {10, 20, 30, 40};
auto it = v.erase(v.begin() + 1);
// v: {10, 30, 40}
// *it == 30
```

### `erase(first, last)`

Removes the half-open iterator range `[first, last)`: `first` is included and `last` is excluded.

```cpp
vector<int> v = {10, 20, 30, 40, 50};
v.erase(v.begin() + 1, v.begin() + 4);
// {10, 50}
```

`erase()` returns an iterator. Removing from the beginning or middle is generally `O(n)` due to shifting.

### `clear()`

Removes all elements. Returns `void`; size becomes zero. Capacity usually remains unchanged.

```cpp
vector<int> v = {1, 2, 3};
v.clear();
cout << v.size();  // 0
```

### Remove all occurrences of a value: erase-remove idiom

`remove()` is an algorithm from `<algorithm>`. It rearranges the retained elements and returns a new logical end, but does not itself change the vector's size.

```cpp
#include <algorithm>
#include <vector>

vector<int> v = {1, 2, 3, 2, 4, 2};
v.erase(remove(v.begin(), v.end(), 2), v.end());
// {1, 3, 4}
```

C++20 also provides `std::erase(v, value)` for this purpose:

```cpp
#include <vector>

vector<int> v = {1, 2, 3, 2, 4, 2};
erase(v, 2);  // C++20; removes all values equal to 2
```

## 7. Iterators

An iterator behaves somewhat like a pointer and provides access to elements.

```cpp
vector<int> v = {10, 20, 30, 40};
```

| Method | Meaning |
|---|---|
| `begin()` | Iterator to first element |
| `end()` | Past-the-last position; not an element |
| `rbegin()` | Reverse iterator to the last element |
| `rend()` | Reverse past-the-first position |
| `cbegin()` | Const iterator to first element |
| `cend()` | Const past-the-last position |
| `crbegin()` | Const reverse iterator to last element |
| `crend()` | Const reverse past-the-first position |

Forward traversal:

```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
// 10 20 30 40
```

Reverse traversal:

```cpp
for (auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << " ";
}
// 40 30 20 10
```

`end()` and `rend()` are boundary positions. Do not dereference them.

### Const iterators

```cpp
auto it = v.cbegin();
cout << *it;  // 10
// *it = 100; // Error: cannot modify through a const iterator
```

### Vector iterator arithmetic

Vector iterators are random-access iterators.

```cpp
cout << *(v.begin() + 2);  // 30
cout << *(v.end() - 1);    // 40, only when non-empty
cout << (v.end() - v.begin()); // 4
```

`begin() + index` works for vectors, but not for `std::list` iterators.

## 8. `assign()` and `swap()`

### `assign()`

Replaces the vector's contents. Returns `void`.

```cpp
vector<int> v = {1, 2, 3};

v.assign(4, 100);       // {100, 100, 100, 100}
v.assign({10, 20, 30}); // {10, 20, 30}
```

Other common overload:

```cpp
v.assign(first, last);  // Copy elements from [first, last)
```

### `swap()`

Exchanges contents with another compatible vector.

```cpp
vector<int> a = {1, 2};
vector<int> b = {10, 20, 30};

a.swap(b);
// a: {10, 20, 30}
// b: {1, 2}
```

For ordinary vectors with compatible allocators, swapping is constant-time.

## 9. Iterator Invalidation

Vector modifications can invalidate iterators, pointers, and references.

- **Reallocation:** invalidates all iterators, references, and pointers to vector elements.
- **`insert()` without reallocation:** iterators before the insertion position remain valid; those at or after it are invalidated.
- **`erase()`:** iterators and references at or after the erased position are invalidated.
- **`push_back()` without reallocation:** existing element iterators/references remain valid, but the old `end()` iterator is invalidated.
- **`clear()`:** all element iterators and references are invalidated.

After a modifying operation, do not use an iterator that may have been invalidated. `erase()` returns a valid iterator to continue from.

Safe erase-while-iterating pattern:

```cpp
vector<int> v = {10, 20, 30, 40, 50};

for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 20 == 0) {
        it = v.erase(it);  // Use the iterator returned by erase
    } else {
        ++it;
    }
}
// v: {10, 30, 50}
```

## 10. Time Complexity Cheat Sheet

| Operation | Typical complexity |
|---|---|
| `operator[]`, `at()`, `front()`, `back()` | `O(1)` |
| `size()`, `empty()`, `capacity()` | `O(1)` |
| `push_back()` | Amortized `O(1)` |
| `pop_back()` | `O(1)` |
| `insert()` at beginning/middle | `O(n)` |
| `erase()` at beginning/middle | `O(n)` |
| `clear()` | `O(n)` |
| `reserve()` | `O(n)` if reallocation occurs; otherwise `O(1)` |
| `resize()` | Depends on how many elements are added/removed; may be `O(n)` |
| `swap()` | Usually `O(1)` for compatible allocators |
| Iterator arithmetic such as `begin() + i` | `O(1)` |

## 11. Common Interview Traps

1. `size()` counts elements; `capacity()` reports allocated capacity.
2. `reserve(n)` does not create elements; `resize(n)` does.
3. `end()` is not the last element. Use `*(v.end() - 1)` only when the vector is non-empty.
4. `pop_back()` returns `void`; it does not return the removed element.
5. `erase()` returns an iterator to the next element, or `end()`.
6. `erase(first, last)` removes `[first, last)`; `last` is excluded.
7. `remove()` alone does not shrink a vector; use the erase-remove idiom or C++20 `std::erase`.
8. Vector elements are stored contiguously and vector iterators support random access.
9. `front()`, `back()`, and `pop_back()` require a non-empty vector.
10. Inserting or erasing can invalidate iterators.

## 12. Practice Questions

Try answering without running the code.

### Question 1

```cpp
vector<int> v(4, 7);
cout << v.size() << " " << v[2];
```

What is the output?

### Question 2

```cpp
vector<int> v = {10, 20, 30, 40};
auto it = v.erase(v.begin() + 1);
cout << *it;
```

What is printed?

### Question 3

```cpp
vector<int> v = {10, 20};
v.reserve(50);
cout << v.size() << " " << (v.capacity() >= 50);
```

What does this print?

### Question 4

```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.erase(v.begin() + 1, v.begin() + 4);
```

What are the remaining elements?

### Question 5

Explain the difference between:

```cpp
v.erase(v.begin());
v.pop_back();
```

---

## Quick Revision

- **Add at end:** `push_back()`, `emplace_back()`
- **Remove at end:** `pop_back()`
- **Insert at position:** `insert()`, `emplace()`
- **Remove by iterator/range:** `erase()`
- **Access:** `[]`, `at()`, `front()`, `back()`
- **Size/storage:** `size()`, `capacity()`, `reserve()`, `resize()`
- **Traversal:** `begin()`, `end()`, `rbegin()`, `rend()`
- **Remove all matching values:** erase-remove idiom or C++20 `std::erase()`
