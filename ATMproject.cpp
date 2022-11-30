#include<conio.h>
#include<iostream>
#include<string>
using namespace std;
class atm
{
private: //member variable: only used within the class
	int PIN;
	int Account_no;
	string Name;
	double Balance;
	string Mobile_no;
public: //member function: could be used outside the class
	void setdata(int _PIN, int _Account_no, string _Name, double _Balance, string _Mobile_no)
	{
		PIN = _PIN;
		Account_no = _Account_no;
		Name = _Name;
		Balance = _Balance;
		Mobile_no = _Mobile_no;
	}
	int getPIN()
	{
		return PIN;
	}
	int getAccountno()
	{
		return Account_no;
	}
	string getName()
	{
		return Name;
	}
	double getBalance()
	{
		return Balance;
	}
	string getMobileno()
	{
		return Mobile_no;
	}
	void setMobileno(string _oldMobileno, string _newMobileno)
	{
		if (_oldMobileno == Mobile_no)
		{
			Mobile_no = _newMobileno;
			cout << "Successfully update your Mobile no ";
			_getch();
		}
		else
		{
			cout << "incorrect mobile number¡I ";
			_getch();
		}
	}
	void cashwithdraw(int _ammount)
	{
		if (_ammount < Balance && _ammount > 0)
		{
			Balance -= _ammount;
			cout << "Please collect your cash" << endl;
			cout << "Your Balance is:" << Balance << endl;
			_getch();
		}
		else
		{
			cout << "invaild ammount input or insuffcient Balance";
			_getch();
		}
	}
};

int main()
{
	int choice = 0, enterAccountno, enterPIN;
	//clean terminal
	system("cls");
	//create object
	atm user1;
	//set default data
	user1.setdata(12345, 850318, "Gary", 1200000, "0975408844");
	do
	{
		system("cls");
		cout << "***Welcome to ATM***" << endl;
		cout << "Please enter your Account no: " << endl;
		cin >> enterAccountno;
		cout << "Please enter your PIN: " << endl << endl;
		cin >> enterPIN;
		//check Account no and PIN 
		if ((enterAccountno == user1.getAccountno()) && (enterPIN == user1.getPIN()))
		{
			do
			{
				int ammount = 0;
				string oldMobileno, newMobileno;
				//user interface
				//1. Check Balance
				//2. Cash Withdraw
				//3. User Details
				//4. Update Mobile No.
				//5. Exit
				system("cls");
				cout << "***Welcome to ATM***" << endl;
				cout << "Select your options: " << endl;
				cout << "1.Check Balance" << endl;
				cout << "2.Cash Withdraw" << endl;
				cout << "3.Show User Details" << endl;
				cout << "4.Update Mobile No." << endl;
				cout << "5.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Your Balance is: " << user1.getBalance();
					_getch(); //holding the screen utill user key in
					break;
				case 2:
					cout << "enter the ammount: " << endl;
					cin >> ammount;
					user1.cashwithdraw(ammount);
					break;
				case 3:
					cout << "Your Account no is: " << user1.getAccountno() << endl;
					cout << "Your Name is: " << user1.getName() << endl;
					cout << "Your Balance is: " << user1.getBalance() << endl;
					cout << "Your Mobile no is: " << user1.getMobileno() << endl;
					_getch();
					break;
				case 4:
					cout << "Enter your old mobile no: ";
					cin >> oldMobileno;
					cout << "Enter your new mobile no: ";
					cin >> newMobileno;
					user1.setMobileno(oldMobileno, newMobileno);
					break;
				case 5:
					exit(0);
				default:
					cout << "Enter invaild number ";
				}
			} while (1);
		}
		else
		{
			cout << "Enter the invaild input ";
			_getch();
		}
	} while (1);
}