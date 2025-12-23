#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
        virtual void drive()=0;
        virtual ~ Car(){}
};

class Engine{
    public:
        virtual void start()=0;
        virtual ~Engine(){}
};

class petrolEngine: public Engine{
    public:
        void start()override{
            cout<<"Starting your petrol Engine";
        }
};

class SUV:public Car{
    private:
        Engine* eg;
    public:
        SUV(Engine* eg){
            this->eg=eg;
        }
        void drive()override{
            eg->start();
            cout<<"Starting your Car you can drive";
        }
};

signed main() {
    freopen("output.txt","w",stdout);
    Car * SuV = new SUV(new petrolEngine());
    SuV->drive();
}
