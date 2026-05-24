#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<fstream>
using namespace std;
void withdrawl();
void deposit();
void view();
void save_Details();
void loadData();
void home(){
	int opt,i;
	while (i != 1){
		system("cls");
		cout<<"\tState Bank of India\n";
		cout<<"-----------------------------------\n";
		cout<<"\t1. Deposit Amout\n\t2. Withdrawl Amount\n\t3. View Account Details\n\t4. Exit\n";
		cout<<"Enter your Option [1/2/3/4] :";
		cin.ignore();
		cin>>opt;
		Beep(700,300);
	
		switch (opt) {
			case 1:deposit();break;
			case 2:withdrawl();break;
			case 3:view();break;
			case 4:save_Details();i=1;break;
		}
	}
}
class account {
	public:
		int accno,withdrawn,accp,deposited,enter;
		int balance = 20000;
		char accna[20];
		char city[20];
		char state[20];
		
		void getName() {
			cin>>ws;
			cin.getline(accna,20);
			Beep(700,300);
		}
		void getCity() {
			cin>>ws;
			cin.getline(city,20);
			Beep(700,300);
		}
		void getState() {
			cin>>ws;
			cin.getline(state,20);
			Beep(700,300);
		}
		void getAccno() {
			cin>>accno;
			Beep(700,300);
		}
		void getAccp() {
			cin.ignore();
			cin>>accp;
			Beep(700,300);
		}
		void getWithdrawn() {
			cin>>withdrawn;
			Beep(700,300);
		}
		void getDeposited() {
			cin>>deposited;
			Beep(700,300);
		}
		void getEnter() {
			cin>>enter;
			Beep(700,300);
		}
};
account a;
int main() {
	SetConsoleTitle("Bank Account Manager");
	system("color 0B");
	int choice;
cout << "Do you want to load existing account? (1 = Yes / 0 = No): ";
cin >> choice;
if (choice == 1) {
    loadData();
} else {
    // Ask for new account details
    cout<<"\tState Bank of India\t\t\n";
	cout<<"-----------------------------------\n";
	cout<<"Enter your Name :";
	a.getName();
	cout<<"Enter Name of City :";
	a.getCity();
	cout<<"Enter Name of State :";
	a.getState();
	cout<<"Enter Account Number :";
	a.getAccno();
	cout<<"Enter A Strong password :";
	a.getAccp();
	cout<<"Account Created Successfully !\n";
	system("pause");
	Beep(700,300);
	home();
	}
}
void deposit(){
	system("cls");
    cout<<"Enter your 4-Digit pin to Continue :";
    a.getEnter();
    if(a.enter == a.accp){
        system("cls");
        cout<<"         DEPOSIT AMOUNT         \n";
        cout<<"--------------------------------\n\n";
        cout<<"Enter amount to be deposited : ";
        a.getDeposited();
        a.balance = a.balance + a.deposited;
        cout<<"Transaction Successful!\nBalance: "<<a.balance<<"\n";
        Beep(700,300);
    } else {
        cout<<"Incorrect pin ! Try Again\n";
        Beep(700,300);
    }
    system("pause");
    Beep(700,300);
    home();
}
void withdrawl(){
	system("cls");
    cout<<"Enter your 4-Digit pin to Continue :";
    a.getEnter();
    if(a.enter == a.accp){
            system("cls");
            cout<<"        AMOUNT WITHDRAWL        \n";
            cout<<"--------------------------------\n\n";
            cout<<"Enter amount to be withdrawn : ";
            a.getWithdrawn();
            if(a.withdrawn > a.balance){
                cout<<"ERROR : Not Enough Amount in Account.\n";
                Beep(700,300);
            } else {
            a.balance = a.balance - a.withdrawn;
            cout<<"Transaction Successful!\nBalance: "<<a.balance<<"\n";
            Beep(700,300);
            }
    } else {
        cout<<"Incorrect pin ! Try Again\n";
        Beep(700,300);
    }
    system("pause");
    Beep(700,300);
    home();
}
void view() {
	system("cls");
    cout<<"Enter your 4-Digit pin to Continue :";
    a.getEnter();
    if(a.enter == a.accp){
		cout<<"        ACCOUNT DETAILS        \n";
    	cout<<"-------------------------------\n\n";
    	cout<<"ACCOUNT NAME:       "<<a.accna<<"\n";
    	cout<<"ACCOUNT NUMBER :    "<<a.accno<<"\n";
    	cout<<"ACCOUNT PASSWORD :  "<<a.accp<<"\n";
    	cout<<"NAME OF CITY:       "<<a.city<<"\n";
    	cout<<"NAME OF STATE:      "<<a.state<<"\n";
    	cout<<"BALANCE AMOUNT:     "<<a.balance<<"\n";
    	cout<<"-------------------------------\n";
	}
	else{
		cout<<"ERROR! : Wrong Password !\n";
		Beep(700,300);
	}
	system("pause");
	Beep(700,300);
	home();
}

void save_Details() {
	ofstream file("Bank_Details.txt");
	if (file.is_open()) {
		file << a.accna << endl;
		file << a.accno << endl;
		file << a.withdrawn << endl;
		file << a.accp << endl;
		file << a.deposited << endl;
		file << a.balance << endl;
		file << a.city << endl;
		file << a.state << endl;
		file.close();
		cout << "Data saved successfully.\n";
	} else {
		cout << "Error opening file!\n";
	}
}

void loadData() {
	ifstream file("Bank_Details.txt");
	if (file.is_open()) {
		file.getline(a.accna, 20);
		file >> a.accno;
		file >> a.withdrawn;
		file >> a.accp;
		file >> a.deposited;
		file >> a.balance;
		file.ignore(); // To skip newline before getline
		file.getline(a.city, 20);
		file.getline(a.state, 20);
		file.close();
		cout << "Data loaded successfully.\n";
		home();
	} else {
		cout << "No saved data found.\n";
	}
}

