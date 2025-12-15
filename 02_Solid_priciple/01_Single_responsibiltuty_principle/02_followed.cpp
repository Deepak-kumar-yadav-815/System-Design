#include<bits/stdc++.h>
using namespace std;
class Product{
    public:
        string name;
        int price;
        Product(string name ,int price){
            this ->name=name;
            this-> price= price;
        }
};
class shoppingCart{
    public: 
        vector<Product*>Items;
    public:
        void addproduct(Product* item){
            Items.push_back(item);
        }
        int totalPrice(){
            int total =0;
            for(auto p : Items){
                total+=p->price;
            }
            return total;
        }
};
class InvoicePrinter{
    private:
        shoppingCart* cart;
    public:
        InvoicePrinter(shoppingCart* cart){
            this->cart=cart;
        }
        void printInvoice(){
            cout<<"---------INVOICE---------"<<endl;
            for(auto p :cart->Items){
                cout<<p->name<<"     "<<p->price<<endl;
            }
            cout<<cart->totalPrice()<<endl;
        }
};

class saveToDB{
    private:
        shoppingCart* cart;
    public:
        saveToDB(shoppingCart* cart){
            this->cart=cart;
        }
        void savetoDatabase(){
            cout<<"saved to db";
        }
};
signed main() {
    freopen("output.txt","w",stdout);
    shoppingCart* cart = new shoppingCart();
    cart->addproduct(new Product("shampoo",90));
    cart->addproduct(new Product("shampoo_1",90000));
    cart->addproduct(new Product("shampoo_2",900));
    cout<<cart->totalPrice()<<endl;    

    InvoicePrinter* pt = new InvoicePrinter(cart);
    pt->printInvoice();
    saveToDB* DB= new saveToDB(cart);
    DB->savetoDatabase();
}
