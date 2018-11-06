#include <iostream>
#include "main_grocery.h"
#include "Items.h"
#include "Fruits.h"
#include "Vegetables.h"
using namespace std;

int main()
{
	GroceryStore gStore;
	cout<<"\n***** Welcome To Harshit Grocery Store *****\n\n";
	gStore.showMainMenu();
	return 0;
}
