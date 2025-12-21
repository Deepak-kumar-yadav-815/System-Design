#include<bits/stdc++.h>
using namespace std;

class PowerSupply{
    public:
        void Power(){
        cout<<"\nprovinding power to your computer\n";
        }
};
class CoolingSystem{
    public:
        void cool(){
            cout<<"\n starting the cooling system \n";
        }
};
class CPU{
    public:
        void initialize(){
            cout<<"\n Initializing the CPU ";
        }
};
class Memory{
    public:
        void selfTest(){
            cout<<"\n setting up your Memory system";
        }
};
class HardDrive{
    public:
        void Install(){
            cout<<"\n Installing the HardDrive";
        }
};
class OS{
    public:
        void load(){
            cout<<"\nyour os is loaded in memory\n";
        }
};
class BIOS{
    private:
        OS os;
    public:
        void Boot(CPU c, Memory m,OS os){
            cout<<"\n started your cpu and memory is tested successfullu\n your computer is booted\n";
            this->os=os;
            c.initialize();
            m.selfTest();
            os.load();
        }
};
class computerFacade{
    private:
        PowerSupply ps;
        CoolingSystem fan;
        CPU nvidia;
        Memory sanDisk;
        HardDrive Bluray;
        BIOS windowsManager;
        OS Ubuntu;
    public:
        void StartComputer(){
            cout<<"Starting your Computer\n";
            ps.Power();
            fan.cool();
            windowsManager.Boot(nvidia,sanDisk,Ubuntu);

            cout<<"Welcome to Ubuntu operating system";
        }
};

signed main() {
    freopen("output.txt","w",stdout);
    computerFacade* Hp_version1256 = new computerFacade();
    Hp_version1256->StartComputer();
}
