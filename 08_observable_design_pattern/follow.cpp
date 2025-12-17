#include<bits/stdc++.h>
using namespace std;

class Isubscriber{
    public :
        virtual void update()=0;
        virtual ~Isubscriber(){};
};
class Ichannel{
    public:
        virtual void Subscribe(Isubscriber* sub) =0;
        virtual void UnSubscribe(Isubscriber* sub)=0;
        virtual void notifySubscriber()=0;
        virtual ~Ichannel(){

        };
};

class channel : public Ichannel{
    private:
        string name;
        string LatestVideo;
        vector<Isubscriber*>subscriber;
    public:
        channel(string name){
            this->name=name;
        }
        void Subscribe(Isubscriber* sub){
            if(find(begin(subscriber),end(subscriber),sub)==subscriber.end()){
                subscriber.push_back(sub);
            }
        }
        void UnSubscribe(Isubscriber* sub){
            auto it = find(begin(subscriber),end(subscriber),sub);
            if(it!=subscriber.end()){
                subscriber.erase(it);
            }
        }
        void notifySubscriber(){
            for(auto p:subscriber){
                p->update();
            }
        }
        string getName(){
            return name;
        }
        string getLatestvideo(){
            return LatestVideo;
        }
        void uploadVideo(string LatestVideo){
            this->LatestVideo=LatestVideo;
            cout<<"Your video  "<<LatestVideo<<" is Uploaded successfully "<<endl;
            notifySubscriber();
        }
};
class Subscriber:public Isubscriber{
    private:
        string name;
        channel* ch;
    public:
        Subscriber(string name,channel* ch){
            this->name=name;
            this->ch=ch;
        }
        void update(){
            cout<<"the channel "<<ch->getName()<<"  has released the latest video "<<ch->getLatestvideo()<<endl;
        }
};
signed main() {
    freopen("output.txt","w",stdout);
    channel* CodeExplorerDKY = new channel("CodeExplorerDKY");
    channel* ch = new channel("MR BEAST");
    Isubscriber* sub1 = new Subscriber("Aman Singh",CodeExplorerDKY);
    Isubscriber* sub2 = new Subscriber("Divyanshu kumar",CodeExplorerDKY);
    Isubscriber* sub3 = new Subscriber("ABS",ch);
    Isubscriber* sub4 = new Subscriber("DPS",ch);
    ch->Subscribe(sub3);
    ch->Subscribe(sub4);
    CodeExplorerDKY->Subscribe(sub1);
    CodeExplorerDKY->Subscribe(sub2);
    CodeExplorerDKY->uploadVideo("Binary search tutorial");
    ch->uploadVideo("HELLO WORLD");
}