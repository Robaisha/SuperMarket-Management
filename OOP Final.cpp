#include <iostream>
#include <fstream>
#include<cctype>
#include<stdlib.h>
#include<iostream>
#include<cctype>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include <windows.h>
#include "interface.h"
#include "signup.h"
#include "login.h"

using namespace std;
static int cancel=0;
char chh='n' || 'N';
float sum=0;

signup::signup() {
	//name[]= "";
//	pass[100] = "";
}
signup::~signup() {}

bool signup::account_check(std::string username, std::string password) {
	std::string temp = "";
	std::string str = "";
	std::ifstream File("register.txt");
	while (getline(File, temp)) {
		for (int i = 0; i < temp.length(); ++i) {
			if (temp[i] == ',') {
				break;
			}
			str += temp[i];
		}
		if (str == username) {
			return true;
		}
	}
	File.close();
	return false;
}

bool signup::account_check2(std::string username, std::string password) {
	std::string temp = "";
	std::string str = "";
	std::ifstream File("admin.txt");
	while (getline(File, temp)) {
		for (int i = 0; i < temp.length(); ++i) {
			if (temp[i] == ',') {
				break;
			}
			str += temp[i];
		}
		if (str == username) {
			return false;
		}
	}
	File.close();
	return true;
}


int signup :: validate(char pass[100],char pass2[100], char num[100], int age){
	if (age != 0 && age > 0){
		
//		if (strcmp (pass, pass2)){
//			cout<<"ENTERED";
			if (strlen (num) == 11){
				return 1;
            }
			else{
				cout << "\n\nPlease enter valid Mobile Number.\n\n"; 
				return 0;
			}	
    }
	else {
		cout << "Enter valid age";
		return 0;
	}

}

signin::signin() {
	user = "";
	pass = "";
}
signin::~signin() {}
void signin::login(std::string user_1, std::string pass_1) {
	if (account_check(user_1, pass_1) == false) {
		std::cout << "user doesn't exit" << std::endl;
		return;
	}
	std::cout << "user Login" << std::endl;
	getch();
}
void signin::login2(std::string user_1, std::string pass_1) {
	if (account_check2(user_1, pass_1) == false) {
		std::cout << "user doesn't exit" << std::endl;
		return;
	}
	std::cout << "user Login" << std::endl;
	getch();
}


void signup::signup1(std::string username, std::string password) {
	if (account_check(username, password) != true) {
		std::ofstream File("register.txt", std::ios_base::app);
		File << username + ',' + password << std::endl;
		std::cout << "User Registered" << std::endl;
		return;
	}
	std::cout << "user already exited" << std::endl;
}
void signup::signup2(std::string username, std::string password) {
	if (account_check2(username, password) != false) {
		std::ofstream File("admin.txt", std::ios_base::app);
		File << username + ',' + password << std::endl;
		std::cout << "User Registered" << std::endl;
		return;
	}
	std::cout << "user already exited" << std::endl;
}

class Admin
{
	char itemName[40];
	float itemPrice;
	int itemNum;
	int quantity;
	friend class Customer;
    public:
	Admin()
	{
		strcpy(itemName, "no-name");
		itemPrice = 0;
		itemNum = 0;
		quantity = 0;
	}
	void func(int x){
		itemNum=x;
    }
	void func(float price){
	    itemPrice=price;
	}
		
	
	void add_item()
	{
		int n;
		int num;
		float price;
		system("cls");
		system("color 5f");
		char ch;
		fflush(stdin);
		cout << ("\n\n\t\t\t****************\n");
	    cout << ("\t\t\t- ADD PRODUCT -");
	    cout << ("\n\t\t\t*****************\n");

		cout << endl
			 << "Please Enter The Product Number: ";
		     cin >> num;
			 func(num);
		    
		cout << endl;
			cout << "Please Enter The Product Name: ";
		cin.ignore();
		cin.getline(itemName, 19);
		cout << endl
			 << "Please Enter The Price of The Product:  ";
		cin >> price;
	    func(price);
		cout << endl
			 << "Please Enter The Quantity of Product  ";
		cin >> quantity;
		
	}

	void showitemdata()
	{
		cout << "\n" << itemNum << "\t\t" << itemName << "\t\t" << itemPrice << "\t\t" << quantity;
	}

    int retpno() 
        {
            return itemNum;
        }

    float retprice() 
        {
            return itemPrice;
        }
        
    int retquantity()
        {
        	return quantity;
		}

    char * retname() 
        {
            return itemName;
        }
	int storeitem();
	void delete_item();
	void search_item();
	void inventory();
	void update_item();
	void admin_menu();
};

void Admin::update_item()
{
	system("cls");
	system("color 5f");
	cout << ("\n\n\t\t\t****************\n");
	cout << ("\t\t\t- UPDATE PRODUCT -");
	cout << ("\n\t\t\t*****************\n");
	fstream file;
	file.open("inventory.dat", ios::in | ios::out | ios::ate);
	file.seekg(0);
	char name[50];
	cout << "Enter name of the item you want to Update: ";
	cin.ignore();
	cin.getline(name, 49);
	file.read((char *)this, sizeof(*this));
	while (!file.eof())
	{
		if (strcmp(name, this->itemName) == 0)
		{
			add_item();
			file.seekp(file.tellp() - sizeof(*this));
			file.write((char *)this, sizeof(*this));
		}
		file.read((char *)this, sizeof(*this));
	}
}

void Admin::delete_item()
{
	system("cls");
	system("color 5f");
	cout << ("\n\n\t\t\t****************\n");
		cout << ("\t\t\t- DELETE PRODUCT -");
		cout << ("\n\t\t\t*****************\n");
	char ch, ch1;
	ifstream fin;
	ofstream fout;
	fin.open("inventory.dat", ios::in);
	if (!fin)
	{
		cout << "file not found";
	}
	else
	{
		char name[50];
		cout << "Enter name of the item you want to delete  ";
		cin.ignore();
		cin.getline(name, 49);
		cout << name << endl;

		fout.open("updated.dat", ios::out);
		fin.read((char *)this, sizeof(*this));

		while (!fin.eof())
		{
			if (strcmp(this->itemName, name))
			{
				fout.write((char *)this, sizeof(*this));
			}
			fin.read((char *)this, sizeof(*this));
		}

		fin.close();
		fout.close();
		remove("inventory.dat");
		rename("updated.dat", "inventory.dat");
	}
}
void Admin::search_item()
{

	char ch;
	system("cls");
	system("color 5f");
	char name[50];
	cout << ("\n\n\t\t\t****************\n");
		cout << ("\t\t\t- SEARCH PRODUCT -");
		cout << ("\n\t\t\t*****************\n");
	cout << "\nENTER THE NAME OF THE ITEM:  ";
	cin.ignore();
	cin.getline(name, 49);
	ifstream obj;
	int c = 0;
	obj.open("inventory.dat", ios::in);
	if (!obj)
	{
		cout << "file not found";
	}
	else
	{
		obj.read((char *)this, sizeof(*this));
		while (!obj.eof())
		{
			if (strcmp(name, this->itemName) == 0)
			{
				showitemdata();
				c++;
				break;
			}
			obj.read((char *)this, sizeof(*this));
		}
		if (c == 0)
		{
			cout << "record not found";
				PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
			obj.close();
		}
	}
}

void Admin::inventory()
{
	system("cls");
	system("color 5f");
	cout << ("\n\n\t\t\t****************\n");
		cout << ("\t\t\t- INVENTORY -");
		cout << ("\n\t\t\t*****************\n");
	ifstream obj;
	obj.open("inventory.dat", ios::in);
	if (!obj)
	{
		cout << "file not found";
		return;
	}
	
	else
	{
		cout<<"Product ID\tProduct Name\tProduct Price\tProduct Quantity";
		obj.read((char *)this, sizeof(*this));
		while (!obj.eof())
		{

			Admin::showitemdata();
			obj.read((char *)this, sizeof(*this));
		}
		obj.close();
	}
}
int Admin::storeitem()
{
	add_item();
	if (this->itemPrice == 0)
	{
		cout << "Item not found";
		return 0;
	}
	ofstream obj;
	obj.open("inventory.dat", ios::app);
	obj.write((char *)this, sizeof(*this));
	obj.close();
	return 1;
}
void Admin::admin_menu()
{
    
    
	while (1)
	{
        
		system("cls");
		system("color 5f");
		char ch;
		cout << ("\n\n\t\t\t****************\n");
		cout << ("\t\t\t- ADMIN MENU -");
		cout << ("\n\t\t\t*****************\n");
		cout << "\t\t\tA-ADD PRODUCT\n";
		cout << "\t\t\tD-DELETE PRODUCT\n";
		cout << "\t\t\tS-SEARCH PRODUCT\n";
		cout << "\t\t\tU-UPDATE PRODUCT\n";
		cout << "\t\t\tI-DISPLAY INVENTORY\n";
		cout << "\t\t\tE-EXIT\n";
		PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\chooseoption.wav", NULL, SND_FILENAME);
		cout << "\n\t\tEnter your choice  ";
		cin >> ch;
		switch (toupper(ch))
		{
		case 'A':
			system("cls");
			storeitem();
			cout << "\nItem stored successfully!!";
			cout << endl
				 << "Press any key to continue..! ";
			getch();
			break;
		case 'S':
			search_item();
			cout << endl
				 << "Press any key to continue..! ";
			getch();
			break;
		case 'D':
			delete_item();
			cout << "Item deleted successfully!!";
			PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\Itemdeleted.wav", NULL, SND_FILENAME);
			cout << endl
				 << "Press any key to continue...";
			getch();
			break;
		case 'U':
			update_item();
			cout << "Item updated successfully!!";
			PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\Inventoryup.wav", NULL, SND_FILENAME);
			cout << endl
				 << "Press any key to continue...";
			getch();
			break;
		case 'I':
			inventory();
			cout << endl
				 << "Press any key to continue...";
			getch();
			break;
		case 'E':
			exit(1);
		default:
			admin_menu();
		}
	}
};



class Transaction
{
	protected:
		
	float total;
	float tax;
	float discount1;
	float discount2;
	float discount3;
	
	public:
		Transaction()
		{
			tax=14;
			discount1 = 5;
			discount1 = 10;
			discount1 = 15;
		}
		
		virtual float CalculateBill()=0;
		
		
};


class Customer:public Transaction
{
	int order_choice;
	int quantity;
	int item_choice;
	float sum;
	
	
	struct address
    {
	int house_no;
	    string block;
	    string area;
	    string city;
    };
	public:
		Admin a;
		struct address add[100];
		
		int Initial(void)
		{
			system("cls");
			
			cout<<"Welcome to Sahulat Bazaar!!"<<endl<<endl;
			
		    while(1)
		        {
					cout<<endl<<"What would you like to do: "<<endl<<endl;
					PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\chooseoption.wav", NULL, SND_FILENAME);
					cout<<"1. Place Order"<<endl<<"2. Update Order"<<endl<<"3. Cancel Order"<<endl<<"4. Track Order"<<endl<<"5. Exit"<<endl;
					cin>>order_choice;
					switch(order_choice)
					{
						case 1:
						{
							system("cls");
							Menu();
							break;
						}
						case 2:
						{
							UpdateOrder();
							break;
						}
						case 3:
						{
							CancelOrder();
							break;
						}
						case 4:
						{
							TrackOrder();
							break;
						}
						case 5:
						{
							return(0);
						}
						default:
						{
							cout<<endl<<endl<<"Please enter a valid choice."<<endl;
							PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
							break;
						}
					}
					}
	    	
		}
		void Menu(void)
		{
		    Admin a;
		     	cout<<"Here is a list of different items: "<<endl;
		     	fstream fp;
				fp.open("inventory.dat", ios:: in );
                while (fp.read((char * ) & a, sizeof(Admin))) 
                {
                   a.showitemdata();
                  cout << "\n====================================";
                  }
                 fp.close();
				PlaceOrder();
		}
		int PlaceOrder(void)
		{
			int item_no[100];
			int quantity[100];
			int i=0;
			int sure=0;
			char ch='Y';
			cancel++;
			Admin a;
			float product;
			
			
		    while(1)
		    {
		    	do
                {
                cout <<endl<<"Enter the product no of the product you want to order: ";
                cin >> item_no[i];
                cout <<endl<<"Quantity in number : ";
                cin >> quantity[i];
                i++;
                cout << "\nDo you want to order another product ? (y/n)";
                cin >> ch;
                
                if(ch=='n' || ch=='N')
                {
                	break;	
				}	
				else if(ch=='y' || ch=='Y')
                {
                	continue;
				}		
                else if(ch!='y' || ch!='Y' || ch!='n' || ch!='N')
                {
                	cout<<endl<<"Please enter correct choice."<<endl;
                	PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
                	getch();
                	Menu();
                	break;
				}
                }
                while (ch == 'y'||ch=='Y');
                
                
                
            cout << "\n\nThank You For Placing The Order";
            getch();
            ifstream fp;
            ofstream fp1;
	        system("cls");
         	cout<<"Order Details: "<<endl<<endl;
         	cout <<"\nPODUCT NO.\tNAME\t\tQUANTITY\tPRICE";
        	for (int x = 0; x < i; x++) 
            {
            	fp1.open("Orders.txt",ios::app);
                fp.open("inventory.dat", ios:: in );
                fp.read((char * ) & a, sizeof(Admin));
                while (!fp.eof()) 
                {
                    if (a.retpno() == item_no[x]) 
                    {
                        if(a.retquantity() >= quantity[x])
                        {
                        	cout <<"\n" <<item_no[x] << "\t\t" << a.retname() <<"\t\t" << quantity[x] << "\t\t" << a.retprice();
                        product = quantity[x]*a.retprice();
                        sum = sum + product;
                        //fp1.write((char *)this, sizeof(*this));
                        fp1<<"\n" <<item_no[x] << "\t" << a.retname() <<"\t" << quantity[x] << "\t\t" << a.retprice();
						}
						else 
						{ 
						int ans;
						cout<<endl<<"Sorry for the inconvinence! We dont have this many quantity in the store.";
						cout<<endl<<endl<<"If you want to place a different order, press 1 else press 0 to exit."<<endl;
						cin>>ans;
						switch(ans)
						{
							case 1:
								{
									Menu();
									break;
								}
							case 0:
								{
									return(0);
									break;
								}
							default:
								{
									cout<<endl<<"Enter corrrect choice."<<endl;
									PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
								}
						}
						}
                        
                    }
                    
                   fp.read((char * ) & a, sizeof(Admin));
                }
				fp1.close();
                fp.close();
            }
            
            cout<<endl<<endl<<"Please Confirm your order, by selecting the correct option:"<<endl;
            PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\plsconfirm.wav", NULL, SND_FILENAME);
			cout<<"1. Confirm Order"<<endl<<"2. Order Again"<<endl<<"3. Cancel Order"<<endl<<"4. Add more items to order"<<endl<<"5. Exit"<<endl;
            int orderconfirm;
			cin>>orderconfirm;
			switch(orderconfirm)
			{
				case 1:
					{
						system("cls");
						AdditionalInformation();
						break;
						return(0);
					}
				case 2:
					{
						system("cls");
						Menu();
						break;
					}
				case 3:
					{
						cout<<"Are you sure you want to cancel order."<<endl<<"1. Yes"<<endl<<"2. No"<<endl;
						cin>>sure;
						if(sure==1)
						{
							chh= 'y';
							CancelOrder();
							return(0);
						}
						else if(sure==0)
						{
							system("cls");
							AdditionalInformation();
						}
						break;
					}
				case 4:
					{
						system("cls");
						UpdateOrder();
						break;
					}
				case 5:
					{
						return(0);
						break;
					}
				default:
					{
						cout<<"Enter correct choice."<<endl;
						PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
					}
			}
			return(0);
			
		}
	}	
		void UpdateOrder(void)
		{
			int item_no[100];
			int quantity[100];
			int i=0;
			char ch='Y';
			Admin a;
			float product;
			
			if(cancel==0)
		    {
		    	cout<<endl<<"You havent placed a order yet."<<endl;
		    	Initial();
			}
			else if(cancel==1)
			{
				cout<<endl<<"Please specify what other item do you want to add: "<<endl<<endl;
				cout<<"List of different items being displayed again: "<<endl;
		     	fstream fp7;
				fp7.open("inventory.dat", ios:: in );
                while (fp7.read((char * ) & a, sizeof(Admin))) 
                {
                   a.showitemdata();
                  cout << "\n====================================";
                  }
                 fp7.close();
      			do
                {
                    cout <<endl<<endl<<"Enter the product no. of the product : ";
                    cin >> item_no[i];
                    cout <<endl<<"Quantity in number : ";
                    cin >> quantity[i];
                    i++;
                    cout << "\nDo you want to order another product ? (y/n)";
                    cin >> ch;
                    if(ch=='n' || ch=='N')
                    {
                	break;	
	     			}	
	     			else if(ch=='y' || ch=='Y')
                    {
                     	continue;
	     			}		
                    else if(ch!='y' || ch!='Y' || ch!='n' || ch!='N')
                    {
                     	cout<<endl<<"Please enter correct choice."<<endl;
                     	PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
                    	getch();
                    	PlaceOrder();
                     	break;
		     		}
                }
			while (ch == 'y'||ch=='Y') ;
			
            cout << "\n\nYour order has been updated."<<endl<<endl;
            PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\orderup.wav", NULL, SND_FILENAME);
            ifstream fp;
            ofstream fp3;
            for (int x = 0; x < i; x++) 
            {
            	fp3.open("Orders.txt", ios::app);
                fp.open("inventory.dat", ios:: in );
                fp.read((char * ) & a, sizeof(Admin));
                while (!fp.eof()) 
                {
                    if (a.retpno() == item_no[x]) 
                    {
                        fp3<<"\n" <<item_no[x] << "\t" << a.retname() <<"\t" << quantity[x] << "\t\t" << a.retprice();
                        product = quantity[x]*a.retprice();
                        sum = sum + product;
                    }
                   fp.read((char * ) & a, sizeof(Admin));
                }
				fp3.close();
                fp.close();
            }
            
			getch();
			system("cls");
			AdditionalInformation();
     	}
     }
     
		void AdditionalInformation(void)
		{
			static int id=0;
			string message, address;
			cout<<"Please specify if you want to add any additional information."<<endl<<endl;
			cin>>message;
			cout<<endl<<endl;
			cout<<"Enter your full address: "<<endl;
			cout<<"\nEnter your House no:";
     		cin>>add[id].house_no;
	    	cout<<"Enter your Block:";
    		cin>>add[id].block;
            cout<<"Enter your Area:";
            cin>>add[id].area;
            cout<<"Enter your City Name:";
            cin>>add[id].city;
			
			cout<<endl<<endl<<"Address Confirmation: "<<endl;
			cout<<"\n\nYour Address:"<<endl<<"House No."<<add[id].house_no<<", Block - "<<add[id].block<<", "<<add[id].area<<", "<<add[id].city;
			
			cout<<endl<<endl<<"Your Order has been Confirmed."<<endl;
			PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\orderconfirmed.wav", NULL, SND_FILENAME);
			getch();
			CalculateBill();
			
			
		}
		int CancelOrder()
		{
		    if(cancel==0)
		    {
		    	cout<<endl<<"You havent placed a order yet."<<endl;
		    	Initial();
			}
			else if(cancel==1)
			{
				if(chh == 'y' || chh=='Y')
		        {
		        	cout<<"Order has been cancelled."<<endl;
		        	PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\ordercancelled.wav", NULL, SND_FILENAME);
		        	cout<<"Redirecting you to the main page."<<endl;
		        	getch();
		        	system("cls");
		        	return(0);
	    		}
	    		else if(chh=='n' || chh== 'N')
	    		{
	    			
	    			return(1);
	    		}
			}
		      
        }
        
		TrackOrder()
		{
			
		
				cout<<endl<<"Your order will be delieverd in next 7 working days."<<endl;
				cout<<"If it takes longer than that, you can contact us via email or our contact number.";
				cout<<endl<<"for that please refer to Customer Help"<<endl;
				getch();
			
		}
		
		//pure vitual function
		float CalculateBill()
		{
			float final,final1;
			total=sum;
			cout<<endl<<"Total Bill: "<<sum;
			if(total>100 && total<2000)
			{
				cout<<endl<<endl<<"Congratulations!! You have recieved 5% discount."<<endl;
				getch();
				final1 = (5*total)/100;
				final = (114*final1)/100;
			    DisplayBill(final);
			}
			else if(total>2000 && total<3000)
			{
				cout<<endl<<endl<<"Congratulations! You have recieved 10% discount."<<endl;
				getch();
				final1 = (discount2*total)/100;
				final = (114*final1)/100;
				DisplayBill(final);
			}
			else if(total>3000)
			{
				cout<<endl<<endl<<"Congratulations! You have recieved 15% discount."<<endl;
				getch();
				final1 = (discount3*total)/100;
				final = (114*final1)/100;
				DisplayBill(final);
			}
			else
			{
				total;
				DisplayBill(total);
			}
		}
		
		void DisplayBill(float x)
		{
			system("cls");
			int cash,c;
			char credit_num[20];
			float cash_amount1;
			int cash_amount2;
			float total=x;
			cout<<endl<<"FINAL BILL DETAILS:"<<endl<<endl;
			cout<<"Total bill: "<<x<<endl<<"Tax included: 14%";
			
			cout<<"\nSelect a Payment Options:\n"; 
			PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\paymentoption.wav", NULL, SND_FILENAME);
            cout<<"\n1)Cash on Delivery"; 
            cout<<"\n2)Via Credit card\n\n"; 
            cin>>cash;
            switch(cash)
            {
            	case 1:
            		{
            			cout<<"\n\nThank You for your order!!\n\n";
                     	return;
                     	break;
					}
				case 2:
					{
						cout<<"\n\nEnter Credit card number: \n";
	        	    	cin>>credit_num;
         		    	if(strlen(credit_num) == 12)
		              	{
         		    		cout<<"\nEnter cash amount: "<<endl<<"1. Cents included"<<endl<<"2. No cents included"<<endl;
	                 		cin>>c;
	        	         	switch(c)
        	    			{
	             				case 1:
       	    					{
	          						cout<<"Enter full amount:"<<endl;
	                     			cin.ignore();
             	          			cin>>cash_amount1;
             	    	    		MoneyReturn(cash_amount1,x);
             	    	    		system("cls");
	                 		    	return;
	                 			    break;
      							}
        				 		case 2:
		    					{
			    					cout<<"Enter full amount:"<<endl;
	                 				cin.ignore();
               	        			cin>>cash_amount2;
               	        			MoneyReturn(cash_amount2,x);
               	    	   	    	return;
               	    	   	    	system("cls");
               	    	    		break;
						    	}
	          					default:
			      				{
				       				cout<<endl<<"Enter correct choice."<<endl;
				       				getch();
		                   			CalculateBill();
		                   			break;
		       					}
				
	                  	    }
         				}
        				else
        				{
         					cout<<endl<<"Enter correct Credit Card number."<<endl;
         					PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
	        			}
	    		
					}
				default:
					{
						cout<<endl<<endl<<"Please enter a valid payment method."<<endl;
						PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\tryagain.wav", NULL, SND_FILENAME);
						getch();
						CalculateBill();
					}
			}
        }
        
        template <class T>
        float MoneyReturn(T cash, float total)
        {
        	T change;
        	change=cash-total;
        	cout<<"Change you will recieve: "<<change<<endl<<endl;
	    	cout<<"\n\nPayment process completed.\n\n";
	    	cout<<"\n\nThank You for your order!!\n\n";
	    	getch();
	    	PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\thankyou.wav", NULL, SND_FILENAME);
		}
		
		

};

class CustomerHelp: public Customer
{

	int ch;
	public:
	void choice()
	{
		system("cls");
		cout<<endl<<"Email Address: sahulatbazaar@gmail.com"<<endl<<"Contact Number: 021-3421675"<<endl<<endl;
		cout<<"HI ! HOW CAN WE HELP? \n\n\n";
		cout << "\t\t\t1-HOW TO PLACE AN ORDER\n\n";
		cout << "\t\t\t2-HOW TO CANCEL ORDER\n\n";
		cout << "\t\t\t3-HOW TO UPDATE YOUR EXISTING ORDER\n\n";
		cout << "\t\t\t4-HOW TO TRACK ORDER\n\n";
		cout << "\t\t\t5-EXIT\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				Menu();
			case 2:
				CancelOrder();
			case 3:
				UpdateOrder();
			case 4:
				TrackOrder();
			case 5:
				exit(1);
		}
    }
		
};
int main(){
	int choice;
	int choice1;
	int choice2;
	int choice3;
	string  name, fname, lname;
	char pass[100], pass2[100], ch1, ch2,num[100], id[100];
	int i, age;
	signup s1;
	signin s2;
	interface1();
	getch();
	system("cls");
	
	
	
	while (1)
	{
	cout<<endl<<"WELCOME TO SAHULAT BAZAAR"<<endl<<endl;	
	cout << "1.Signup"<<endl;
	//gotoxy(52,7);
	cout << "2,Login" << endl;
	cout<<"3.Exit"<<endl;
	PlaySound("C:\\Users\\Masoo\\Desktop\\Media\\welcomesb.wav", NULL, SND_FILENAME);
	//gotoxy(60,8);
	cin >> choice2;
	
	switch (choice2){
	case 1: {
		//gotoxy(52,9);
		int C;
		C:
		cout << "Enter 1 FOR ADMIN"<<endl;
		//gotoxy(52,7);
		cout << "Enter 2 FOR CUSTOMER" << endl;
		cin >>choice3;
		cout << "Enter First Name: ";
		cin >> fname;
		cout << "Enter Last Name: ";
		cin >> lname;
		cout << "Enter Username: " << endl;
		cin >> id;
		//gotoxy(60,10); 
		cout << "Enter your age: ";
		cin >> age;
		//gotoxy(52,11);
		cout << "Enter Password (atleast 8 digits): " << endl;
		//gotoxy(60,12);
		for (i=0; i<8; i++){
			ch1 = getch();
        	pass[i] = ch1;
        	ch1 = '*' ;
        	cout << ch1;
        }
        cout << endl;
       
		cout << "Confirm Password: " << endl;
        for (i=0; i<8; i++){
			ch2 = getch();
        	pass2[i] = ch2;
        	ch2 = '*' ;
        	cout << ch2;
        }
       
        cout << endl;
		cout << "Enter Mobile Number: " << endl;
		cin >> num;
		int val=s1.validate(pass, pass2, num, age);
		cout<< val;
		if(val==1){
			if(choice3==2){
				s1.signup1(id, pass);
			}
			else if(choice3==1){
				s1.signup2(id, pass);
			}
			
		}
		else{
		///	cout<<"ELSE";
			goto C;
		}
		
		
	}
	case 2: {
		cout << "Enter 1 FOR ADMIN"<<endl;
		//gotoxy(52,7);
		cout << "Enter 2 FOR CUSTOMER" << endl;
		cin >> choice3;
		if(choice3==2){
			cout << "Enter Username: " << endl;
			//gotoxy(60,10);
			cin >> id;
			//gotoxy(52,11);
			cout << "Enter Password: " << endl;
			//gotoxy(60, 12);
			for (i=0; i<8; i++){
				ch1 = getch();
        		pass[i] = ch1;
        		ch1 = '*' ;
        		cout << ch1;
        	}
        	cout << endl;
			
			s2.login(id, pass);
			break;
		}
		else{
			cout << "Enter Username: " << endl;
			//gotoxy(60,10);
			cin >> id;
			//gotoxy(52,11);
			cout << "Enter Password: " << endl;
			//gotoxy(60, 12);
			for (i=0; i<8; i++){
				ch1 = getch();
    	    	pass[i] = ch1;
    	    	ch1 = '*' ;
    	    	cout << ch1;
    	    }
    	    cout << endl;
			s2.login2(id, pass);
		break;
		}
		//gotoxy(52,9);
		cout << "Enter Username: " << endl;
		//gotoxy(60,10);
		cin >> id;
		//gotoxy(52,11);
		cout << "Enter Password: " << endl;
		//gotoxy(60, 12);
		for (i=0; i<8; i++){
			ch1 = getch();
        	pass[i] = ch1;
        	ch1 = '*' ;
        	cout << ch1;
        }
        cout << endl;
		
		s2.login(id, pass);
		break;
	} // case 2 bracket
	case 3:
		{
			return(0);
			break;
		}
	default:
		{
			cout<<endl<<"Enter correct choice."<<endl;
		}
	}//switch bracket
	
	switch(choice3)
	    {
	    	case 1:
	    		{
	    			Admin a1;
					a1.admin_menu();
					break;
				}
			case 2:
				{
					Customer c1, c2;
	    			system("cls");
	    			cout<<"Direct to.."<<endl<<"1. Main Page"<<endl<<"2. Customer Help"<<endl;
	    			cin>>choice1;
	    			("cls");
	    			switch(choice1)
	    			{
	    				case 1:
	    					{
	    						
	    						c1.Initial();
	    						break;
							}
						case 2:
							{
								CustomerHelp ch;
								ch.choice();
								break;
							}
							default:
								{
									cout<<endl<<"Enter correct choice.";
									main();
								}
					}
	    			break;
				}
			case 3:
				{
					return(0);
				}
			default:
				{
					cout<<endl<<endl<<"Enter correct choice."<<endl;
				}
		}	
	
}
}
	
