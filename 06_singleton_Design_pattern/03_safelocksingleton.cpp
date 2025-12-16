#include<bits/stdc++.h>
#include<mutex>
using namespace std;

class singleton{
    private:
      static singleton* instance;
      static mutex mtx;
        singleton(){
            cout<<"singleton constructor called";   
        }
    public:
        static singleton* getIntence(){
            if(instance==nullptr){
                lock_guard<mutex> lock(mtx);
                instance= new singleton();
            }
            else{
                return instance;
            }
            return instance;
        }
};
singleton* singleton::instance = nullptr;
mutex singleton::mtx;
signed main() {
    singleton* ab = singleton::getIntence();
    singleton* cd = singleton::getIntence();
    
    
    cout<<endl<<(ab==cd);
}
