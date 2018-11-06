#ifndef MAIN_GROCERY_H
#define MAIN_GROCERY_H
#include <ctime>
#include "struct.h"
#include "Fruits.h"
#include "Vegetables.h"
#define pIDStartInd 1001;

class GroceryStore
{
	private :
		itemList *head;
		itemList *tail;
		int p_ID_Index;
		int itemCount;
	public :
		GroceryStore();								// Constructor
		~GroceryStore();								// Destructor
		void showMainMenu();
		void addItem();
		void removeItem(long);
		void updateItem(long);
		void purchaseItem(long);
		void purchaseCheapItem();
		void purchaseCloseItem();
		void checkItemCount();
		void itemsInArea();
		void maxItemCalorie();
		void showLatestItem();
		itemList* getMinCalItem(int);
		itemList* getClosest(char *);
		itemList* getCheapest(char *, bool);
		void readFruitData();
		void readVegetableData();
		void printItems();							// Function Overloading
		void printItems(long);						// Function Overloading
		void printItemCount();
		void addFruit(char *, int, int, int, float, int, int );
		void addVegetable(char *, int, int, int, float, int, int );
};

#endif
