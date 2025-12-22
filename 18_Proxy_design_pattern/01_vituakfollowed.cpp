#include<bits/stdc++.h>
using namespace std;

class IImage{
    public:
        virtual void Display()=0;
        virtual ~IImage(){}
};

class DisplayRealImage : public IImage{
    private:
        string path;
    public:
        DisplayRealImage(const string& path){
            //heavy operation
            this->path=path;
            cout<<"\nloading your image from the disk\n";
        }
        void Display(){
            cout<<"displaying the image at "<<path<<endl;
        }
};

class proxyDisplay:public IImage{
    private:
        DisplayRealImage* real;
        string path;
    public:
        proxyDisplay(const string& path){
            this->path=path;
            real=nullptr;
        };
        void Display(){
            //lazy loading
            if(real==nullptr){
                real=new DisplayRealImage(path);
            }
            real->Display();
        }
};
signed main() {
    freopen("output.txt","w",stdout);
    IImage* img = new proxyDisplay("c:/system-design");
    img->Display();
}
