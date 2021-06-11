// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
std::string name;
//int option;
int balance = 100;

//declare function
void getName();
int displayMenu();
int displaySecondaryMenu();
int loopOptions(int option);
void deposit();
void withdraw();
void checkBalance();


int main()
{
    //request name
	getName();
	//display main menu
	int choice= displayMenu();
	//perform specific task
	loopOptions(choice);
	
}


void getName() {
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Welcome, " << name<<std::endl;
}

int displayMenu() {
	int option;
	std::cout<<std::endl
		<< "1. Deposit" << std::endl
		<< "2. Withdraw" << std::endl
		<< "3. Check Balance" << std::endl
		<< "4. Exit" << std::endl
		<< "Choose an operation: ";
	std::cin >> option;
	return option;
}

int displaySecondaryMenu() {
	int option;
	std::cout << std::endl
		<< "1. Back to menu" << std::endl
		<< "Other Keys to Exit" << std::endl
		<< "Choose an operation: ";
	std::cin >> option;
	return option;
}

int loopOptions(int option) {
	switch (option)
	{
	case (1):
	{
		deposit();
		int choice = displaySecondaryMenu();
		if (choice == 1)
		{
			int menu =displayMenu();
			loopOptions(menu);
		}
		else
		{
			return 0;
		}
		break;
	}
	case (2):
	{
		withdraw();
		int choice = displaySecondaryMenu();
		if (choice == 1)
		{
			int menu = displayMenu();
			loopOptions(menu);
		}
		else
		{
			return 0;
		}
		break;
	}
	case (3):
	{
		checkBalance();
		int choice = displaySecondaryMenu();
		if (choice == 1)
		{
			int menu = displayMenu();
			loopOptions(menu);
		}
		else
		{
			return 0;
		}
		break;
	}
	case (4):
	{
		return 0;
		break;
	}
	default:
		std::cout << "Wrong choice selected. Please try again " << std::endl;
		int menu = displayMenu();
		loopOptions(menu);
		break;
	}
}

void deposit() {
	int amount;
	std::cout << "How much would you like to deposit: ";
	std::cin >> amount;
	balance += amount;
	std::cout << "Your new balance is: " << balance << std::endl;

}

void withdraw() {
	int amount;
	std::cout << "How much would you like to withdraw: ";
	std::cin >> amount;
	if (amount<balance)
	{
		balance -= amount;
		std::cout << "Your new balance is: " << balance << std::endl;
	}
	else
		std::cout << "You attempted to withdraw more than your limit" << std::endl;
}


void checkBalance() {
	std::cout << "Your balance is: " << balance << std::endl;
}