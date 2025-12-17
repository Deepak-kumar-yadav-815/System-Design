#ifndef MenuItem_h
#define MenuItem_h

#include<bits/stdc++.h>
using namespace std;

class MenuItem{
    private:
        string code;
        string name;
        int price;
    public:
        MenuItem(string code,string name,int price){
            this->code=code;
            this->name=name;
            this->price=price;
        }
        //getters and setters
        int getPrice() const{ 
            return price;
        }
        void setprice(int price){
            this->price=price;
        }
        string getName()const {
            return name;
        }
        void setName(string name){
            this->name=name;
        }
        string getCode()const{
            return code;
        }
        void setCode(string code){
            this->code=code;
        }
};

#endif