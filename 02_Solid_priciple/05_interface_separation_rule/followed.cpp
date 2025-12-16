#include<bits/stdc++.h>
using namespace std;
class shape {
    public :
        virtual int Area()=0;
};
class TwoDshape : public shape{
    public:
        int hieght;
        int base;
        TwoDshape(int hieght,int base){
            this->hieght=hieght;
            this->base=base;
        }
        int Area(){
            return hieght*base;
        }
};
class ThreeDshape:public shape{
    public:
        int height;
        int base;
        int length;
    public:
        ThreeDshape(int height,int base,int length){
            this->height=height;
            this->base=base;
            this->length=length;
        }
        virtual int Area()=0;
        virtual int Volume()=0;
};
class cuboid:public ThreeDshape{
    public:
        cuboid(int side):ThreeDshape(side,side,side){}
        int Area(){
            return 6*(height*height);
        }
        int Volume(){
            return height*height*height;
        };
};
signed main() {
    freopen("output.txt","w",stdout);
    TwoDshape* rectangle = new TwoDshape(5,4);
    cout<<rectangle->Area();

    ThreeDshape* cuboi = new cuboid(9);
    cout<<cuboi->Volume();
}
