#include <iostream>
#include <windows.h>

using namespace std;

double const ESPRESSO_PRICE = 1.50;
double const CAPUCCINO_PRICE = 2.00;
double const LATTE_PRICE = 2.20;
int const MAX_CUPS = 700;
int const SERVICE_PIN = 8814; 


void orderCoffee(double price);
void putCoin(int choice);
void showCoffeeMessage();
bool checkPIN();
void cupsRemains();
void reffillCups();
void takeCash();
void showGeneralMenu();
void showInsertCoinMenu();
void showItemMenuError();
void showServiceMenu();
void showAccountCash();
void showCupsMenu();
bool checkOrder(double price);
void insertCoin();
void showService();

double balance = 0.0;
double cash = 0.0;
int cups = 7;
int counter = 0;
int key = 0;

int main()
{	
	while (true) {
		showGeneralMenu();
		cout << "Your choice? ";
		int choice = 0;
		cin >> choice;
		if (choice == 1) {
			insertCoin();
		}
		else if (choice == 2) {
			orderCoffee(ESPRESSO_PRICE);
		}
		else if (choice == 3) {
			orderCoffee(CAPUCCINO_PRICE);
		}
		else if (choice == 4) {
			orderCoffee(LATTE_PRICE);
		}
		else if (choice == 5) {
			showService();
		}
		else {
			showItemMenuError();
		}
	}
	
	return 0;	
}

void showGeneralMenu() 
{	
	system("cls");
	cout << "Welcome to the CoffeeBox!" << endl << endl;
	cout << "You have " << balance << " BYN on balance" << endl;
	if (cups <= 3) {
		cout << "Warning! There are " << cups << " cups left in the coffee machine" << endl;
	}
	cout << "1 - Insert Coin" << endl;
	cout << "2 - Espresso (1.50 BYN)" << endl;
	cout << "3 - Capuccino (2.00 BYN)" << endl;
	cout << "4 - Latte (2.20 BYN)" << endl;
	cout << "5 - Service Menu" << endl;
}


void orderCoffee(double price)
{	 
	if (checkOrder(price)) {
		cash += price;
		balance -= price;
		cups--;
		showCoffeeMessage();
	} 
}

void showCoffeeMessage() 
{
	system("cls");
	cout << "Your coffee will be ready soon, just wait a bit!" << endl;
	Sleep(5000);
	cout << "Your coffee is ready! Have a good day!" << endl;
	cin >> key;
}


void showServiceMenu() 
{
	while (true) {
		system("cls");
		cout << "1 - Accounted cash" << endl;
		cout << "2 - Refill the cups" << endl;
		cout << "3 - Take cash" << endl;
		cout << "4 - Back" << endl;
		cout << "Your choice? ";
		int choice = 0;
		cin >> choice;
		if (choice == 1) 
			showAccountCash();
		else if (choice == 2)
			showCupsMenu();
		else if (choice == 3)
			takeCash();
		else if (choice == 4)
			break;		
		else 
			showItemMenuError();
	}
}

void showAccountCash()
{
	system("cls");
	cout << "Cash is: " << cash + balance << " BYN" << endl;
	cout << "Enter any key to continue" << endl;
	cin >> key;
}

void showCupsMenu()
{
	while (true) {
		system("cls");
		cout << "1 - Cups remains" << endl;
		cout << "2 - Refill cups" << endl;
		cout << "3 - Back" << endl;	
		cout << "Your choice? ";
		int choice = 0;
		cin >> choice;
		if (choice == 1)
			cupsRemains();	
		else if (choice == 2){
			reffillCups();
		} 
		else if (choice == 3) 
			break;
		else 
			showItemMenuError();
		}
}

void reffillCups()
{	
	system("cls");
	cout << "How much cups do you want to refill? " << endl;
	int newCups = 0;
	cin >> newCups;
	if (newCups < MAX_CUPS)
	{	
		cups += newCups;
		cout << "Cups refilled!" << endl;
		cout << "Enter any key to continue" << endl;
		cin >> key;
	} 
	else {
		cout << "You have exceeded the maximum capacity of ÑoffeeBox! (" << MAX_CUPS << ") cups";
	}
}

void showItemMenuError()
{
	system("cls");
	cout << "Please select the correct menu item" << endl;
	cout << "Enter any key to continue" << endl;
	cin >> key;
}

void putCoin(int choice)
{
	if (choice == 1) {
		balance += 0.10;
	} 
	else if (choice == 2) {
		balance += 0.20;
	} 
	else if (choice == 3) {
		balance += 0.50;
	} 
	else if (choice == 4) {
		balance += 1.0;
	} 
	else if (choice == 5) {
		balance += 2.0;
	}  
	else {
		showItemMenuError();
	}
}

void cupsRemains()
{
	system("cls");
	cout << "In the machine ramains " << cups << " cups" << endl;
	cout << "Enter any key to continue" << endl;
	cin >> key;
}

void takeCash()
{
	system("cls");
	cout << "The money is given out! You received " << cash + balance << " BYN" << endl;
	cash = 0.0;
	balance = 0.0;
 	cout << "Enter any key to continue" << endl;
	cin >> key;
}

bool checkOrder(double price)
{
	if (cups <= 0) {
		system("cls");
		cout << "Sorry, the coffee machine is out of cups" << endl;
		cout << "Enter any key to continue" << endl;
		cin >> key;
		return false;
	}
	if (balance < price) {
		system("cls");
		cout << "Insufficient funds, please insert coin" << endl;
		cout << "Enter any key to continue" << endl;
		cin >> key;
		return false;	
	}
	return true;
}

void insertCoin()
{
	while (true) {	
		system ("cls");
		cout << "You have " << balance << " BYN on balance" << endl;
		cout << "Please deposit a coin" << endl;
		cout << "1 - 10 Kopecs" << endl;
		cout << "2 - 20 Kopecs" << endl;
		cout << "3 - 50 Kopecks" << endl;
		cout << "4 - 1 BYN" << endl;
		cout << "5 - 2 BYN" << endl;
		cout << "6 - Back" << endl;			
		cout << "Your choice? ";
		int choice = 0;
		cin >> choice;
		if (choice == 6)
			break;
		else if (choice < 6)
			putCoin(choice);
		else 
			showItemMenuError();
	}
}

void showService()
{	
	while (true) {
		system("cls");
		cout << "Please enter the PIN to to access the service menu" << endl;
		cout << "1 - PIN" << endl;
		cout << "2 - Back" << endl;
		cout << "Your choice? ";
		int choice = 0;
		cin >> choice;
		if (choice == 1) {
			if (checkPIN()) {
				showServiceMenu();
			} 
			else 
				counter++;
		}
		else if (choice == 2) 
			break;
		else 
			showItemMenuError();
	}
}

bool checkPIN()
{
	system("cls");
	cout << "PIN: ";
	int pin = 0;
	cin >> pin;
	if (pin == SERVICE_PIN) 
		return true;
	else if (counter < 2) {
		cout << "Incorrect pin!" << endl;
		cout << "Enter any key to continue" << endl;
		cin >> key;
		return false;
	} 
	else {
		while (true) {
			system("cls");
			cout << "The number of attempts to enter the PIN has been exceeded. Access blocked" << endl;
			cin >> key;
		}
	}
}
