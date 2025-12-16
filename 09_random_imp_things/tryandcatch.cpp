#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
    void run(){
        vector<int>a(10,0);
        try{
            a.at(1)+=15000;
            cout<<a.at(1);
        }
        catch(out_of_range&e ){
            cout<<"THis message if from catch block"<<endl;
            cout<<e.what()<<endl;
        }
    }
};

signed main() {
    Animal* fox = new Animal();
    fox->run();
}
