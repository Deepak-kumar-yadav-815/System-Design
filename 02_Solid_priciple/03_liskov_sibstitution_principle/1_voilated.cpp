#include<bits/stdc++.h>
using namespace std;

class Account{
    public:
        virtual void deposit(int amount)=0;
        virtual void withdraw(int amount)=0;
};

class SavingAccount:public Account{
    private :
        int balance =0;
    public:
        void deposit(int amount){
            balance+=amount;
            cout<<endl<<"your amount has been deposited to Saving account new balance is : -"<<balance<<" "<<endl;
        }
        void withdraw(int amount){
            if(amount>=balance){
                cout<<"Insufficient balance"<<endl;
            }
            balance-=amount;
            cout<<"here is your amonut withdrawn and here is your new net balance :- "<<balance<<endl;
        }
};

class CurrentAcount:public Account{
    private :
        int balance =0;
    public:
        void deposit(int amount){
            balance+=amount;
            cout<<endl<<"your amount has been deposited to currentAccount new balance is : -"<<balance<<" "<<endl;
        }
        void withdraw(int amount){
            if(amount>=balance){
                cout<<"Insufficient balance"<<endl;
            }
            balance-=amount;
            cout<<"here is your amonut withdrawn and here is your new net balance :- "<<balance<<endl;
        }
};

class fixedAccount:public Account{
    private :
        int balance =0;
    public:
        void deposit(int amount){
            balance+=amount;
            cout<<endl<<"your amount has been deposited to fixed account new balance is :-> "<<balance<<" "<<endl;
        }
        void withdraw(int amount){
            throw logic_error("cant withdraw the money");
        }
};

class bankClient{
    private:
        vector<Account*>accounts;
    public:
        bankClient(vector<Account*>& accounts){
            this->accounts=accounts;
        }
        void process_transection(){
            for(auto account : accounts){
                account->deposit(5000);
                try
                {
                    account->withdraw(1000);
                }
                catch(const logic_error& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
};

signed main() {
    freopen("output.txt","w",stdout);
    vector<Account*>a;
    a.push_back(new SavingAccount());
    a.push_back(new CurrentAcount());
    a.push_back(new fixedAccount());
    bankClient* Sbi = new bankClient(a);
    Sbi->process_transection();
}
