#include<bits/stdc++.h>
using namespace std;

class Icharacter{
    public:
        virtual string GetAbilities() const=0;
        virtual ~Icharacter(){};
};
//concrete Charactor SuperMan
class SuperMan : public Icharacter{
    public:
        string GetAbilities() const override {
            return "SuperMan";
        }
};

class Icharacter_Decorator:public Icharacter{
    protected:
        Icharacter* a;
    public:
        Icharacter_Decorator(Icharacter* a){
            this->a=a;
        }
        virtual ~Icharacter_Decorator() { delete a; }
};

class flyUP: public Icharacter_Decorator{
    public:
        flyUP(Icharacter*a):Icharacter_Decorator(a){
            
        };
        string GetAbilities()const override{
            return a->GetAbilities()+" with FLYUP";
        }
};

class LaserEyes:public Icharacter_Decorator{
    public:
        LaserEyes(Icharacter* a):Icharacter_Decorator(a){

        };
        string GetAbilities()const override{
            return a->GetAbilities()+" with LaserEyes";
        }
};
class SpeedUP:public Icharacter_Decorator{
    public:
        SpeedUP(Icharacter* a):Icharacter_Decorator(a){

        };
        string GetAbilities() const override{
            return a->GetAbilities() +" with SpeedUP";
        }
};

signed main() {
    freopen("output.txt","w",stdout);

    Icharacter* SuperMen = new SuperMan();
    SuperMen = new flyUP(SuperMen);
    SuperMen = new SpeedUP(SuperMen);
    SuperMen = new LaserEyes(SuperMen);
    
    cout<<SuperMen->GetAbilities();
}
