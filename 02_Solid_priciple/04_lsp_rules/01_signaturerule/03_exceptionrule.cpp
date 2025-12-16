/*
=====================================================================
LSP – Exception Rule (Signature Rule) | C++ REVISION NOTE
=====================================================================

Core Rule:
---------
A derived (child) class must NOT throw broader or unexpected exceptions
than what the base (parent) class behavior implies.

Reason:
-------
Client code written for the base class relies on its exception contract.
If a child throws new or broader exceptions, substitutability breaks.

---------------------------------------------------------------------
VALID PERMUTATIONS (LSP SAFE):
---------------------------------------------------------------------

1) Base throws exception E
   Child throws SAME exception E
   ✔ Allowed

2) Base throws exception E
   Child throws DERIVED (narrower) exception of E
   ✔ Allowed

3) Base throws exception E
   Child throws NOTHING
   ✔ Allowed (safer behavior)

4) Base throws nothing
   Child throws nothing
   ✔ Allowed

---------------------------------------------------------------------
INVALID PERMUTATIONS (LSP VIOLATION):
---------------------------------------------------------------------

5) Base throws exception E
   Child throws BASE of E (broader exception)
   ✘ NOT allowed

6) Base throws exception E
   Child throws UNRELATED exception
   ✘ NOT allowed

7) Base throws nothing
   Child throws ANY exception
   ✘ NOT allowed (unexpected behavior)

---------------------------------------------------------------------
STANDARD C++ EXCEPTION HIERARCHY (IMPORTANT):
---------------------------------------------------------------------

std::exception
    |
    +-- std::logic_error
    |       +-- std::invalid_argument
    |       +-- std::out_of_range
    |
    +-- std::runtime_error
    |       +-- std::overflow_error
    |       +-- std::underflow_error
    |
    +-- std::bad_alloc
    +-- std::bad_cast
    +-- std::bad_typeid

Ultimate base class:
--------------------
std::exception   <-- parent of almost all standard exceptions

---------------------------------------------------------------------
CATCHING RULE (VERY IMPORTANT):
---------------------------------------------------------------------

- Catch blocks are checked TOP → DOWN
- FIRST matching catch executes
- ONLY ONE catch runs
- Always catch CHILD before PARENT

Correct order:
--------------
catch (DerivedException&)
catch (BaseException&)
catch (std::exception&)

---------------------------------------------------------------------
USER-DEFINED EXCEPTION TEMPLATE (BEST PRACTICE):
---------------------------------------------------------------------

#include <exception>

class AppException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Application exception";
    }
};

class DatabaseException : public AppException {};
class ConnectionFailed : public DatabaseException {};

---------------------------------------------------------------------
LSP-SAFE BASE / DERIVED EXAMPLE:
---------------------------------------------------------------------

class Service {
public:
    virtual void process() {
        throw AppException();
    }
};

class ChildService : public Service {
public:
    void process() override {
        throw ConnectionFailed();   // narrower → LSP safe
    }
};

---------------------------------------------------------------------
LSP MEMORY TRICK:
---------------------------------------------------------------------

Arguments  → Wider
Return     → Narrower
Exceptions → Narrower

Child must NOT surprise the client.
=====================================================================
*/

#include <iostream>
using namespace std;
class Parent {
public:
    virtual void getValue() noexcept(false) { // Parent throws logic_error exception
        throw logic_error("Parent error");
    }
};

class Child : public Parent {
public:
    void getValue() noexcept(false)  override { // Child throws out_of_range exception
        throw out_of_range("Child error");
        // throw runtime_error("Child Error"); // This is Wrong
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }
    void takeValue() {
        try {
            p->getValue();
        }
        catch(const logic_error& e) {
            cout << "Logic error exception occured : " << e.what() << endl;
        }
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(parent);
    //Client* client = new Client(child);

    client->takeValue();

    return 0;
}
    