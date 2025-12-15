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
    private: 
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
        //void print invoice
        void printInvoice(){
            cout<<"---------INVOICE---------";
            for(auto p :Items){
                cout<<p->name<<"     "<<p->price<<endl;
            }
            cout<<totalPrice();
        }

        void saveTOdb(){
            cout<<"Saved to db";
        }

};

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    shoppingCart* cart = new shoppingCart();
    cart->addproduct(new Product("shampoo",90));
    cart->addproduct(new Product("shampoo_1",90000));
    cart->addproduct(new Product("shampoo_2",900));
    cout<<cart->totalPrice();    
}
