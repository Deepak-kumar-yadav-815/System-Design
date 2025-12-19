#include<bits/stdc++.h>
using namespace std;

//command Interface
class Command{
    public:
        virtual void Execute()=0;
        virtual void Undo()=0;
        virtual ~Command(){};
};

// Reciever

class Light{
    public :
        void ON(){
            cout<<"Light is ON";
        }
        void OFF(){
            cout<<"Light if OFF";
        }
};

class Fan{
    public:
        void ON(){
            cout<<"Fan is ON";
        }
        void OFF(){
            cout<<"Fan is OFF";
        }
};

//Concrete Commands
class LighCommand : public Command{
      private:
        Light* L;
      public:
        LighCommand(Light* L){
            this->L=L;
        }
        void Execute()override{
            L->ON();
        }
        void Undo()override{
            L->OFF();
        }
};

class FanCommand: public Command{
    private:
        Fan* F;
    public:
        FanCommand(Fan* F){
            this->F=F;
        }
        void Execute()override{
            F->ON();
        }
        void Undo()override{
            F->OFF();
        }
};
//INvokers //remote
class RemoteControl{
    private:
        int NumOfButtons;
        vector<Command*>keys;
        vector<bool>status;
    public:
        RemoteControl(int Num){
            this->NumOfButtons=Num;
            this->keys.resize(NumOfButtons,nullptr);
            this->status.resize(NumOfButtons,false);
        }
        void SetCommand(int index,Command* object){
            if(index>=0&&index<NumOfButtons){
                if(keys[index]!=nullptr){
                    delete keys[index];
                }
                keys[index]=object;
            }
            else {
                cout<<"Select a valid Key Or Index";
            }
        }
        void Press(int index){
            if(index>=0&&index<NumOfButtons)
            if(status[index]){
                keys[index]->Undo();
                status[index]=0;
            }
            else{
                keys[index]->Execute();
                status[index]=1;
            }
            else{
                cout<<"Press A Valid Button";
            }
        }
        ~RemoteControl(){
            for(int i=0;i<NumOfButtons;i++){
                if(keys[i]){
                    delete keys[i];
                }
            }
        }
};


signed main() {
    freopen("output.txt","w",stdout);

    Light* LivingRoomLight = new Light();
    Fan* Cieling_fan = new Fan();

    Command* c1 = new LighCommand(LivingRoomLight);
    Command* c2 = new FanCommand(Cieling_fan);

    RemoteControl Remote(4);
    Remote.SetCommand(0,c1);
    Remote.SetCommand(3,c2);
    Remote.Press(0);
    cout<<endl;
    Remote.Press(3);
    cout<<endl;
    Remote.Press(0);
    cout<<endl;
    Remote.Press(3);
    cout<<endl;
}
