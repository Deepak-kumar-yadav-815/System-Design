#include<bits/stdc++.h>
using namespace std;

class singleton{
    private:
      static singleton* instance;
        singleton(){
            cout<<"singleton constructor called";   
        }
    public:
        static singleton* getIntence(){
            if(instance==nullptr){
                instance= new singleton();
            }
            else{
                return instance;
            }
            return instance;
        }
};
singleton* singleton::instance = nullptr;

signed main() {
    singleton* ab = singleton::getIntence();
    singleton* cd = singleton::getIntence();
    
    
    cout<<endl<<(ab==cd);
}
