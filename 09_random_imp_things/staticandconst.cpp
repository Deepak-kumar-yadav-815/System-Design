/*
========================================================
C++ `const` vs. `static` Quick Reference
================================

`const` Keyword:
- Immutability: A `const` variable cannot be changed after initialization.
- Use `const` to make variables, function parameters, or member functions read-only.
- Example:
  ```cpp
  const int x = 42;  // x cannot be modified.
static Keyword:

Storage Duration: A static variable or member is shared across all instances of a class or persists across function calls.

Use static for class-level variables or for variables that need to maintain state between function calls.

Example:

cpp
Copy code
static int count = 0;  // Shared across all instances or persists in function.
Combined Usage:

static const means a variable is shared and immutable.

Example:

cpp
Copy code
static const int MAX = 100;  // Shared and constant for all instances.
In Summary:

const = “This value cannot change.”

static = “This value or function is shared or persists.”

// End of Quick Reference
*/

#include <iostream>

// A class to demonstrate both const and static usage
class Example {
public:
    // Static member variable shared across all instances
    static int objectCount;

    // Const member function that doesn't modify the object
    int getValue() const {
        return value;
    }

    // Constructor increments the static object count
    Example(int v) : value(v) {
        ++objectCount;
    }

private:
    // Const member variable, set at initialization and never changed
    const int value;
};

// Initialize the static member outside the class definition
int Example::objectCount = 0;

int main() {
    // Create a few Example objects
    Example ex1(10);
    Example ex2(20);

    // Accessing the const member function
    std::cout << "ex1 value: " << ex1.getValue() << std::endl;
    std::cout << "ex2 value: " << ex2.getValue() << std::endl;

    // Accessing the static member variable
    std::cout << "Number of Example objects created: " << Example::objectCount << std::endl;

    return 0;
}

