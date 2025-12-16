/*
LSP – Method Argument Rule:
When overriding a method, the child class must NOT require
more specific (narrower) arguments than the parent.

Reason:
Client code written for the parent should work
without change when a child object is substituted.

Allowed:
- Same parameter type
- Wider (more general) parameter type

Not Allowed:
- Narrower parameter type
- Additional required parameters

Rule of thumb:
Child should ask for LESS, not MORE.
*/

#include <iostream>

using namespace std;

// Method Argument Rule : 
// Subtype method arguments can be identical or wider than the supertype
// C++ imposes this by keeping singature identical

class Parent {
public:
    virtual void print(string msg) {
        cout << "Parent: " << msg << endl;
    }
};

class Child : public Parent {
public:
    void print(string msg) override { 
        cout << "Child: " << msg << endl;
    }
};

//Client that pass string as msg as client expects.
class Client {
private:
    Parent* p;

public:
  Client(Parent* p) {
        this->p = p;
    }  
    void printMsg() {
        p->print("Hello");
    }
};

int main() {

    Parent* parent = new Parent();
    Parent* child = new Child();

    //Client* client = new Client(parent);
    Client* client = new Client(child);

    client->printMsg();


    return 0;
}
