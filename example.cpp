#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;
struct myDatas{
    int id;
    string name;
    float price;
    string visibility; 
};
class myShop{
    vector<myDatas> datavector;
    
    
    const string filename="Rafiz.txt";
    public:
    void setter(){
        ifstream fin(filename);
        string aline="";
        while(getline(fin,aline)){
            string  temp;
            string fst=aline.substr(0,aline.find(","));
            temp=aline.substr(aline.find(",")+1);
            string scd=temp.substr(0,temp.find(","));
            temp=temp.substr(temp.find(",")+1);
            string thd=temp.substr(0,temp.find(","));
            temp=temp.substr(temp.find(",")+1);
            string frth=temp.substr(0,temp.find(","));
            myDatas m;
            m.id=stoi(fst);
            m.name=scd;
            m.price=stof(thd);
            m.visibility=frth;
            datavector.push_back(m);
        }
    }
    void printer(){
        for(auto i:datavector){
            if(i.visibility=="1"){
        cout<<"ID=> "<<i.id<<" Name=> "<<i.name<<" Price=> "<<i.price<<endl;
            }
        }
    }
    void edit(int id,string name,float price,string visibility){
        datavector[id-1].name=name;
        datavector[id-1].price=price;
        datavector[id-1].visibility=visibility;
       
    }
    void visibility(int id){
        datavector[id-1].visibility="0";
    }
    void add(string name,float price){
        myDatas md;
        md.id=(datavector.empty())?1:datavector.back().id+1;
        md.name=name;
        md.price=price;
        md.visibility="1";
        datavector.push_back(md);
    }
    void writer(){
        ofstream fout(filename);
        for(auto i:datavector){
            fout<<i.id<<","<<i.name<<","<<i.price<<","<<i.visibility<<"\n";
        }
    }
};
int main(){
 
    myShop ms;
    cout<<"1. Show\n"
    <<"2. Entry\n"
    <<"3. Edit\n"
    <<"4. Remove\n";
    int choice;
    cin>>choice;
    switch(choice){
        case 1: ms.setter(); ms.printer(); break;
        case 2: {
                ms.setter();
                string name=""; 
                float price;
                cout<<"Enter name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter price: ";
                cin>>price;
                ms.add(name,price);
                ms.writer();
                cout<<"Item Added!\n";
                break;
        }
        case 3: 
                {ms.setter(); ms.printer(); 
                cout<<"Now choose which id you wanna edit: ";
                int id;
                cin>>id;
                string Name; float Price;
                cout<<"Enter new name: ";
                cin.ignore();
                getline(cin,Name);
                cout<<"Enter new price: ";
                cin>>Price;
                ms.edit(id,Name,Price,"1");
                ms.writer();
                cout<<"Item Edited!\n";
                break;}

        case 4:{
                ms.setter(); ms.printer(); 
                cout<<"Now choose which id you wanna edit: ";
                int id;
                cin>>id;
                ms.visibility(id);
                ms.writer();
                cout<<"Item Removed!\n";
                break;
        }

    }

    return 0;
}
