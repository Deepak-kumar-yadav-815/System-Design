#include<bits/stdc++.h>
using namespace std;

class DataBase{
    public:
        virtual void save()=0; 
};
class SQLDataBase:public DataBase{
    public:
        void save(){
            cout<<"saving to Sql Server";
        }
};
class MongoDB:public DataBase{
    public:
        void save(){
            cout<<"svaing it to MongoDb server";
        }
};
class DataBaseService{
    private:
        DataBase* DB;
    public:
        DataBaseService(DataBase* DB){
            this->DB=DB;
        }
        void save(){
            DB->save();
        }
};
signed main() {
    DataBaseService* Db = new DataBaseService(new SQLDataBase());
    Db->save();
}
