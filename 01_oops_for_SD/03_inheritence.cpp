#include<iostream>
#include<string>

using namespace std;

class Employee{
    protected:
        string name;
        int id ;
    public:
        Employee(){

        }
        Employee(string name,int id){
            this->name=name;
            this->id =id;
        }
        //setters and getters
        int getid(){
            return id;
        }
        virtual int calculatesalary(){
            cout<<"Use you salary method";
            return 0;
        }


};
class FulltimeEmployee:public Employee{
    private:
        int salary =0;
        int MonthWorked =0;
    public:
        FulltimeEmployee(string name,int id){
            this->name=name;
            this->id = id;
        }
        void setSalary(int salary){
            this->salary = salary;
        }
        void setMonthworked(int month){
            MonthWorked = month;
        }
        int calculatesalary(){
            return salary = salary*MonthWorked;
        }

};

class ContractEmployee : public Employee{
    private:
        int salary =0.0;
        int payPerHour=0;
        int hourworked=0;
    public:
        ContractEmployee(string name,int id){
            this->name=name;
            this->id =id;
        }
        void setSalary(int salary){
            payPerHour = salary;
        }
        void sethour(int hour){
            hourworked = hour;
        }
        int calculatesalary(){
            return salary = payPerHour*hourworked;
        }
};

int main(){
    FulltimeEmployee* e2 = new FulltimeEmployee("divyanshu",2);
    e2->setSalary(90000000);
    e2->setMonthworked(144);
    cout<<e2->calculatesalary()<<endl;

    ContractEmployee* e3 = new ContractEmployee("Deepak",3);
    e3->sethour(100);
    e3->setSalary(400000);
    cout<<e3->calculatesalary();
    cout<<endl<<e3->getid();

}