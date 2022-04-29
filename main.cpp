#include <iostream>
#include<fstream>   //for file handling, fstream is a class provided by c++
using namespace std;

class Shopping
{
private:
    int pcode;    //product code
    float price; // price of product
    float dis;  //discount
    string pname; // name of product
public:
    void Menu();
    void Administrator();
    void Buyer();
    void Add();
    void Edit();
    void Remove();
    void List();
    void Receipt();
};




void Shopping :: Menu()  //defining Menu method by scope resolution symbol ::
{
start:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t__________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t     WELCOME TO SUPERMARKET       \n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t__________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t|  1) Administrator   |\n";
    cout<<"\t\t\t\t|  2) Buyer           |\n";
    cout<<"\t\t\t\t|  3) Exit            |\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"Select your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"\t\t\t please Login  \n";
        cout<<"\t\t\t Enter Email:  ";
        cin>>email;
        cout<<"\t\t\t Enter Password:  ";
        cin>>password;
        if(email=="rakesh@gmail.com" && password=="Rakesh@41")
        {
            Administrator();
        }
        else
        {
            cout<<"Invalid Email or Password";
        }
        break;

    case 2:
        Buyer();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout<<"Select a valid option!";
    }
    goto start;


}



void Shopping ::Administrator()
{
start:
    int choice;
    cout<<"\n\n\t\t\tAdministrator Menu \n";
    cout<<"\n\t\t\t|___ 1) Add the Product ______|";
    cout<<"\n\t\t\t|___ 2) Modify the Product ___|";
    cout<<"\n\t\t\t|___ 3) Delete the Product ___|";
    cout<<"\n\t\t\t|___ 4) Back to main menu ____|";
    cout<<"\t\t\t\t                             \n";
    cout<<"Select your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        Add();
        break;

    case 2:
         Edit();
        break;
    case 3:
        Remove();
        break;
    case 4:
        Menu();
        break;
    default:
        cout<<"Select a valid option!";
    }
    goto start;

}



void Shopping :: Buyer()
{
start:
    int choice;
    cout<<"\n\n\t\t\t        Buyer Menu         \n";
    cout<<"\n\t\t\t|_____ 1) Buy Product ________|";
    cout<<"\n\t\t\t                               ";
    cout<<"\n\t\t\t|_____ 2) Go Back ____________|";
    cout<<"\n\t\t\t                               ";
    cout<<"Select your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        Receipt();
        break;
    case 2:
        Menu();
        break;
    default:
        cout<<"Select a valid option!";
    }
    goto start;

}




void Shopping :: Add()
{
first:
    fstream data;  //data is the name of the object of fstream class
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\t Product code of the Product: ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product: ";
    cin>>pname;
    cout<<"\n\n\t Price of the product: ";
    cin>>price;
    cout<<"\n\n\t Discount on the product: ";
    cin>>dis;

    data.open("database.txt",ios::in); //ios::in open the file in reading mode and ios::out will open the file in writing mode
    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);//ios::app is append mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<"\n";  //appending the data
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d; //initializing the index of file

        while(!data.eof())   //eof is end of file that is while loop is checking every content of file by iterating it
        {
            if(c==pcode)
            {
                token++;  //checking the duplicacy
            }
            data>>c>>n>>p>>d;

        }
        data.close();

    if(token==1)
        goto first;
    else
    {
        data.open("database.txt", ios::app|ios::out);//ios::app is append mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<"\n";  //appending the data
        data.close();
    }
    }
    cout<<"\n\n\t\t Record inserted !";

}



void Shopping::Edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify th record ";
    cout<<"\n\t\t\t Enter product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't Exist!";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out); //we will save edited file to this file that is oroginal file/updated
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the Product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discout :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited!";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<"  "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\n Record not found Sorry!";

        }
    }
}




void Shopping::Remove()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product ";
    cout<<"\n\n\t Enter Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't Exist!";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out); //we will save edited file to this file that is oroginal file/updated
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t Product deleted Succesfully!";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<"  "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\n Record not found Sorry!";

        }


    }

}



void Shopping::List()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n__________________________________________________\n";
    cout<<"Product Code\t Name\t\tPrice\n";
    cout<<"\n__________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}




void Shopping::Receipt()
{
    fstream data;
    int arrc[100]; //array of product code
    int arrq[100]; //array of quantity
    char choice;
    int c=0; //counter variable
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in); //file open
    if(!data)
    {
        cout<<"\n\n Empty Database!";
    }
    else
    {
        data.close();   //if data present then close the file
        List();  //to show the list of items available in supermarket
        cout<<"\n_______________________________________\n";
        cout<<"\n        Please Place the Order         \n";
        cout<<"\n_______________________________________\n";
        do
        {
        initial:
            cout<<"\n\n Enter Product code :";
            cin>>arrc[c];  //initially counter variable c=0 as earlier initialized
            cout<<"\n\n Enter Quantity of Product :";
            cin>>arrq[c];   //initially counter variable c=0 as earlier initialized then it will increase below
            for(int i=0;i<c;i++)   //if product code enter by the user if already chosen then displaying below message
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product code. Please try again!";
                    goto initial;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? Press y for YES or n for NO: ";
            cin>>choice;

        }
        while(choice == 'y');

        cout<<"\n\n\t\t\t _________________RECEIPT__________________\n";
        cout<<"\nProduct Code\tProduct Name\tQuantity\tPrice\t\tAmount\t\tAmount with discount\n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;  //initializing the file
            //correction
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
            //till here
            data.close();
        }

    }
    cout<<"\n\n---------------------------------";
    cout<<"\n Total Amount : "<<total;

}




int main()
{
    Shopping sh;
    sh.Menu();


    return 0;
}
