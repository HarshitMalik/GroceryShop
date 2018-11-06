#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include "main_grocery.h"
using namespace std;

GroceryStore::GroceryStore()
{
	this->head = NULL;
	this->tail = NULL;
	this->itemCount = 0;
	this->p_ID_Index = pIDStartInd;
}

GroceryStore::~GroceryStore()
{
	cout<<" Have a nice Day !\n";
}

void GroceryStore::printItems()
{
	itemList *ptr;
	ptr = this->head;
	if(this->head == NULL)
		cout<<"\n List empty!\n";
	else
	{
		while(ptr!=NULL)
		{ 
			ptr->p->print();
			ptr = ptr->next;
		}
	}
}

void GroceryStore::printItems(long pId)
{
	itemList *ptr;
	int flag = 1;
	ptr = this->head;
	if(this->head == NULL)
		cout<<"\n List empty!\n";
	else
	{
		while(ptr!=NULL)
		{ 
			if((ptr->p)->getPurchaseID() == pId)
				{
					ptr->p->print();
					flag = 0;
					break;					
				}
			ptr = ptr->next;
		}
	}
	if(flag)
		cout<<" No matching id found !\n";
}

void GroceryStore::printItemCount()
{
	cout<<"\n Total items in store : "<<this->itemCount<<endl;
}

void GroceryStore::readFruitData()
{
	ifstream fp;
	fp.open("fruits.txt");
	if(!fp.is_open())
		cout<<"Fruit.txt file reading failed !\n";
	else
	{
		char type[20];
		int price_per_unt, calories, no_of_unt,location_X,location_Y;
		float wght_per_unt;		
		while(!fp.eof())
		{
			fp>>type>>location_X>>location_Y>>wght_per_unt>>price_per_unt>>calories>>no_of_unt;
		addFruit(type, price_per_unt, calories, no_of_unt, wght_per_unt,location_X,location_Y);
		}
		cout<<" Fruits added succesfully\n";	
	}
	fp.close();
}

void GroceryStore::readVegetableData()
{
	ifstream fp;
	fp.open("vegetables.txt");
	if(!fp.is_open())
		cout<<"Vegetable.txt file reading failed !\n";
	else
	{
		char type[20];
		int price_per_kg, calories, amnt_kg,location_X,location_Y;
		float vlm_per_unt;		
		while(!fp.eof())
		{
			fp>>type>>location_X>>location_Y>>price_per_kg>>vlm_per_unt>>calories>>amnt_kg;
		addVegetable(type, price_per_kg, calories, amnt_kg, vlm_per_unt,location_X,location_Y);
		}
		cout<<" Vegetables added succesfully\n";	
	}
	fp.close();
}

void GroceryStore::addItem()
{
	int ch;
	cout<<"\n What do you want to add ?\n";
	cout<<"   1) Fruits\n   2) Vegetables\n";
	cout<<" Enter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1 : 
				{
					char type[20];
					int price_per_unt, calories, no_of_unt, locationX, locationY;
					float wght_per_unt;	
					cout<<"Enter name of fruit  :  ";
					cin>>type;
					cout<<"Enter price per unit  :  ";
					cin>>price_per_unt;
					cout<<"Enter calories per unit  :  ";
					cin>>calories;
					cout<<"Enter number of unit  :  ";
					cin>>no_of_unt;
					cout<<"Enter weight per unit  :  ";
					cin>>wght_per_unt;		
					cout<<"Enter x co-ordinate of location  :  ";
					cin>>locationX;
					cout<<"Enter y co-ordinate	of location  :  ";
					cin>>locationY;	
					addFruit(type, price_per_unt, calories, no_of_unt, wght_per_unt,locationX,locationY);
					cout<<"\n Fruit added succesfully!";
					break;
				}
		case 2 :
				{
					char type[20];
					int price_per_kg, calories, amnt_kg, locationX, locationY;
					float vlm_per_unt;	
					cout<<"Enter name of Vegetable  :  ";
					cin>>type;
					cout<<"Enter price per Kg  :  ";
					cin>>price_per_kg;
					cout<<"Enter calories per unit  :  ";
					cin>>calories;
					cout<<"Enter amount in Kg  :  ";
					cin>>amnt_kg;
					cout<<"Enter Volume per unit  :  ";
					cin>>vlm_per_unt;	
					cout<<"Enter x co-ordinate of location  :  ";
					cin>>locationX;
					cout<<"Enter y co-ordinate	of location  :  ";
					cin>>locationY;					
					addVegetable(type, price_per_kg, calories, amnt_kg, vlm_per_unt, locationX, locationY);
					cout<<"\n Vegetable added succesfully!";
					break;
				}
 
		default : cout<<"Wrong choice !";
					break;
	}
}

void GroceryStore::showMainMenu()
{
	int ch;
	char choice;
	do
	{
		cout<<"\n===== Main Menu =====\n";
		cout<<"\nWhat do you want to do ?\n";
		cout<<"\n 1) Add new item\n 2) Remove an item\n 3) Update Item details\n 4) Purchase an item";
		cout<<"\n 5) Check item count\n 6) Find item in desired area\n";
		cout<<" 7) Find maximum item with desired calories\n 8) Show latest item in store\n";
		cout<<" 9) View specific item details\n 10) View all items details\n 11) Exit\n";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		if(ch!= 1 && ch!=11 && this->head == NULL)
			cout<<" No item in store !\n Please add items first \n";
		else
		{	
			switch(ch)
			{
				case 1 : 
						{
							int c;
							cout<<"\n 1) Add from text file\n 2) Add manually\n";
							cin>>c;
							if(c == 2)							
								addItem();
							else if(c == 1)
							{
								readFruitData();	
								readVegetableData();
								printItemCount();
							}
							else{
								cout<<" Wrong choice !";
							}
							break;
						}
				case 2 : 
						{
							long pId;
							cout<<" Enter purchase ID of item to be removed : ";
							cin>>pId;
							removeItem(pId);
							cout<<" Item removed !\n";
							break;
						}
				case 3 :
						{	
							long pId;
							cout<<" Enter purchase ID of item to be updated : ";
							cin>>pId;
							updateItem(pId);
							break;
						}
				case 4 :
						{
							int ch;
							cout<<"\n Select your choice\n";
							cout<<"  1) Buy by purchase ID\n  2) Buy cheapest\n  3) Buy closest\n";
							cin>>ch;
							if(ch==1)
							{
								long pId;
								cout<<" Enter purchase ID of item to be updated : ";
								cin>>pId;
								purchaseItem(pId);
							}
							else if(ch==2)
								purchaseCheapItem();
							else if(ch==3)
								purchaseCloseItem();
							else
							{
								cout<<" Wrong item ";
							}
							break;
						}
				case 5 :
							checkItemCount();
							break;
				case 6 :
							itemsInArea();
							break;
				case 7 :
							maxItemCalorie();
							break;
				case 8 :
							showLatestItem();
							break;
				case 9 :	
						{
							long pId;
							cout<<" Enter purchase ID of item to be updated : ";
							cin>>pId;
							printItems(pId);
							break;
						}
				case 10 :
							printItems();
							break;
				case 11 :
							cout<<"\n Thank you for visiting our store.\n";
							exit(0);
							break;
				default:
							cout<<" Wrong choice!\n";
							break;
			}
			cout<<"\n Show main menu again ? (y/n)  :  ";
			cin>>choice;
		}
	}while(choice == 'y' ||choice == 'Y');
	cout<<"\n Thank you for visiting our store.\n";
}

void GroceryStore::removeItem(long pId)
{
	itemList *tempItem;
	tempItem = this->head;
	int flag =1;
	if( this->head->p->getPurchaseID() == pId)
	{
		if(this->head->next == NULL)
		{
			this->head = NULL;
			this->tail = NULL;
		}
		else
			this->head = this->head->next;
		(this->itemCount)--;
	}
	else
	{
		while((tempItem->next)!=NULL)
		{
			if((tempItem->next->p)->getPurchaseID() == pId)
			{
				itemList *ptr = tempItem->next;
				tempItem->next = tempItem->next->next;
				free(ptr);
				(this->itemCount)--;
				break;
			}
			else
				tempItem = tempItem->next;
		}
	}
}

void GroceryStore::updateItem(long pId)
{
	itemList *tempItem;
	tempItem = this->head;
	int flag =1;
	while(tempItem!=NULL)
	{
		if((tempItem->p)->getPurchaseID() == pId)
		{
			tempItem->p->updateData();
			flag = 0;
			break;
		}
		tempItem = tempItem->next;
	}
	if(flag)
		cout<<"\nNo match found for given purchase ID\n";
	else
		cout<<"\n Item details updated\n";
}

itemList* GroceryStore::getClosest(char *type)
{
	int minDistSqr = 10000,corX,corY;	
	itemList *ptr,*minPtr;
	ptr = this->head;
	minPtr = NULL;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->p->getType(), type)==0)
		{
			corX= ptr->p->getLocationX();
			corY= ptr->p->getLocationY();
			if((ptr->p->getDistanceSqr(corX,corY)) < minDistSqr)
			{
				minDistSqr = ptr->p->getDistanceSqr(corX,corY);
				minPtr = ptr;
			}
		}
		ptr=ptr->next;
	}
	return minPtr;
}

itemList* GroceryStore::getCheapest(char *type, bool category)
{
	int minPrice = 1000;	
	itemList *ptr,*minPtr;
	ptr = this->head;
	minPtr = NULL;
	if(category)
	{
		while(ptr!=NULL)
		{
			if(strcmp(ptr->p->getType(), type)==0)
			{
				if((ptr->p->getpricePerKg()) < minPrice)
				{
					minPrice = ptr->p->getpricePerKg();
					minPtr = ptr;
				}
			}
			ptr=ptr->next;
		}
	}
	else
	{
		while(ptr!=NULL)
		{
			if(strcmp(ptr->p->getType(), type)==0)
			{
				if((ptr->p->getPricePerUnt()) < minPrice)
				{
					minPrice = ptr->p->getPricePerUnt();
					minPtr = ptr;
				}
			}
			ptr=ptr->next;
		}
	}
	return minPtr;
}

void GroceryStore::purchaseItem(long pID)
{
	int max_amnt,amnt;
	itemList *ptr;
	ptr = this->head;
	while(ptr!=NULL)
	{
		if(ptr->p->getPurchaseID() == pID)
		{
			if(ptr->p->getAmntKg() !=0)
			{
				max_amnt = ptr->p->getAmntKg();
				cout<<" Total "<<ptr->p->getType()<<" available is "<<max_amnt<<" kg"<<endl;
				cout<<" Enter amount you want to purchase : ";
				cin>>amnt;
				if(amnt > max_amnt)
					cout<<"Invalid amount\n";
				else
				{
					cout<<" You have to pay : "<<amnt*(ptr->p->getpricePerKg());	
					char ch;
					cout<<" buy ? (y/n)";
					cin>>ch;
					if(ch == 'y' || ch=='Y')
					{	
						ptr->p->updateAmntKg(max_amnt-amnt);
						if(max_amnt == amnt)
						removeItem(ptr->p->getPurchaseID());
					}
				}			
			}
			else
			{
				max_amnt = ptr->p->getNoOfUnt();
				cout<<" Total "<<ptr->p->getType()<<" available is "<<max_amnt<<" units"<<endl;
				cout<<" Enter amount you want to purchase : ";
				cin>>amnt;
				if(amnt > max_amnt)
					cout<<"Invalid amount\n";
				else
				{
					cout<<" You have to pay : "<<amnt*(ptr->p->getPricePerUnt());	
					char ch;
					cout<<" buy ? (y/n)";
					cin>>ch;
					if(ch == 'y' || ch=='Y')
					{	
						ptr->p->updateNoOfUnt(max_amnt-amnt);
						if(max_amnt == amnt)
						removeItem(ptr->p->getPurchaseID());
					}
				}
			}			
		return;	
		}
		ptr = ptr->next;
	}
	cout<<"\n No matching purchase ID found !\n";
}

void GroceryStore::purchaseCloseItem()
{
	int ch,amnt, max_amnt, price = 0, flag = 1;
	char type[20];
	itemList *ptr;
	cout<<" What do you want to purchase ?";
	cout<<"\n  1) Fruits\n  2) Vegetables\n";
	cout<<" Enter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1 :
			flag =1;
			cout<<"\n Enter fruit name : ";
			cin>>type;
			ptr = getClosest(type);
			max_amnt = ptr->p->getNoOfUnt();
			cout<<" Enter units you want to purchase : ";
			cin>>amnt;
			while( amnt > 0 && ptr !=NULL)
			{
				if(amnt < max_amnt)
				{
					price += amnt*(ptr->p->getPricePerUnt());
					ptr->p->updateNoOfUnt(max_amnt-amnt);
					cout<<amnt<<" "<<type<<" of price "<<ptr->p->getPricePerUnt()<<" per unit\n";
					flag = 0;					
					break;
				}
				else
				{
					cout<<max_amnt<<" "<<type<<" of price "<<ptr->p->getPricePerUnt()<<" per unit\n";
					price += max_amnt*(ptr->p->getPricePerUnt());
					amnt -= max_amnt; 
					removeItem(ptr->p->getPurchaseID());
					ptr = getClosest(type);	
					max_amnt = ptr->p->getNoOfUnt();
				}
			}
			if(flag)
				cout<<" Sorry, That many "<<type<<" are not available.";
			else
				cout<<" You have to pay : "<<price;	
			break;
		case 2 :
			flag =1;
			cout<<"\n Enter vegetable name : ";
			cin>>type;
			ptr = getClosest(type);
			max_amnt = ptr->p->getAmntKg();
			cout<<" Enter amount in kg you want to purchase : ";
			cin>>amnt;
			while( amnt > 0 && ptr !=NULL)
			{
				if(amnt < max_amnt)
				{
					price += amnt*(ptr->p->getpricePerKg());
					ptr->p->updateAmntKg(max_amnt-amnt);
					cout<<amnt<<" "<<type<<" of price "<<ptr->p->getpricePerKg()<<" per Kg\n";
					flag = 0;					
					break;
				}
				else
				{
					cout<<max_amnt<<" "<<type<<" of price "<<ptr->p->getpricePerKg()<<" per Kg\n";
					price += max_amnt*(ptr->p->getpricePerKg());
					amnt -= max_amnt; 
					removeItem(ptr->p->getPurchaseID());
					ptr = getClosest(type);	
					max_amnt = ptr->p->getAmntKg();
				}
			}
			if(flag)
				cout<<" Sorry, That many "<<type<<" are not available.";
			else
				cout<<" You have to pay : "<<price;	
			break;
		default :
			cout<<"\nWrong Input\n";
			break;
	}
}

void GroceryStore::purchaseCheapItem()
{
	int ch,amnt, max_amnt, price=0, flag;
	char type[20];
	itemList *ptr;
	cout<<" What do you want to purchase ?";
	cout<<"\n  1) Fruits\n  2) Vegetables\n";
	cout<<" Enter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1 :
			flag = 1;
			cout<<"\n Enter fruit name : ";
			cin>>type;
			ptr = getCheapest(type,0);
			max_amnt = ptr->p->getNoOfUnt();
			cout<<" Enter units you want to purchase : ";
			cin>>amnt;
			while( amnt > 0 && ptr !=NULL)
			{
				if(amnt < max_amnt)
				{
					price += amnt*(ptr->p->getPricePerUnt());
					ptr->p->updateNoOfUnt(max_amnt-amnt);
					cout<<amnt<<" "<<type<<" of price "<<ptr->p->getPricePerUnt()<<" per unit\n";
					flag = 0;					
					break;
				}
				else
				{
					cout<<max_amnt<<" "<<type<<" of price "<<ptr->p->getPricePerUnt()<<" per unit\n";
					price += max_amnt*(ptr->p->getPricePerUnt());
					amnt -= max_amnt; 
					removeItem(ptr->p->getPurchaseID());
					ptr = getCheapest(type,0);	
					max_amnt = ptr->p->getNoOfUnt();
				}
			}
			if(flag)
				cout<<" Sorry, That many "<<type<<" are not available.";
			else
				cout<<" You have to pay : "<<price;	
			break;
		case 2 :
			flag = 1;
			cout<<"\n Enter vegetable name : ";
			cin>>type;
			ptr = getCheapest(type,1);
			max_amnt = ptr->p->getAmntKg();
			cout<<" Total "<<type<<" available is "<<max_amnt<<" kg."<<endl;
			cout<<" Enter amount in kg you want to purchase : ";
			cin>>amnt;
			while( amnt > 0 && ptr !=NULL)
			{
				if(amnt < max_amnt)
				{
					price += amnt*(ptr->p->getpricePerKg());
					ptr->p->updateAmntKg(max_amnt-amnt);
					cout<<amnt<<" "<<type<<" of price "<<ptr->p->getpricePerKg()<<" per Kg\n";
					flag = 0;					
					break;
				}
				else
				{
					cout<<max_amnt<<" "<<type<<" of price "<<ptr->p->getpricePerKg()<<" per Kg\n";
					price += max_amnt*(ptr->p->getpricePerKg());
					amnt -= max_amnt; 
					removeItem(ptr->p->getPurchaseID());
					ptr = getCheapest(type,1);	
					max_amnt = ptr->p->getAmntKg();
				}
			}
			if(flag)
				cout<<" Sorry, That many "<<type<<" are not available.";
			else
				cout<<" You have to pay : "<<price;	
			break;
		default :
			cout<<"\nWrong Input\n";
			break;
	}
}

void GroceryStore::checkItemCount()
{
	char type[20];
	int ch, count = 0;
	cout<<"\nEnter type :\n";
	cout<<" 1) Fruits\n 2) vegetables\n";
	cout<<"Enter your choice : ";
	cin>>ch;	
	cout<<"\nEnter type :  ";
	cin>>type;
	itemList *ptr;
	ptr = this->head;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->p->getType(), type)==0)
		{
			if(ch == 1)
				count+=(ptr->p->getNoOfUnt());
			else
				count+=(ptr->p->getAmntKg());
		}
		ptr=ptr->next;
	}
	if(ch == 1)
		cout<<"\n Total "<<type<<" available : "<<count<<" units"<<endl;
	else
		cout<<"\n Total "<<type<<" available : "<<count<<" kgs"<<endl;
}
	
void GroceryStore::itemsInArea()
{
	int x1,x2,y1,y2,count=0;
	cout<<" Enter co-ordinates of desired area (0<x1<x2 & 0<y1<y2) :\n";
	cout<<" Enter x1 : ";
	cin>>x1;
	cout<<" Enter x2 : ";
	cin>>x2;
	cout<<" Enter y1 : ";
	cin>>y1;
	cout<<" Enter y2 : ";
	cin>>y2;
	itemList *ptr;
	ptr = this->head;
	cout<<" Follwing items are present in given area with purchase id :\n";
	while(ptr!=NULL)
	{
		if((ptr->p->getLocationX())>x1 && (ptr->p->getLocationX())<x2)
		{
			if((ptr->p->getLocationY())>y1 && (ptr->p->getLocationY())<y2)
				{
					count++;
					ptr->p->print();
				}
		}
		ptr=ptr->next;
	}
	cout<<"\n Total "<<count<<" items";
}

itemList* GroceryStore::getMinCalItem(int minCal)
{
	int cal=1000;
	itemList *ptr,*minPtr;
	ptr = this->head;
	minPtr = NULL;
	while(ptr!=NULL)
	{
		if((ptr->p->getCalories())> minCal && (ptr->p->getCalories())< cal)
		{
			cal = (ptr->p->getCalories());
			minPtr = ptr;
		}
		ptr=ptr->next;
	}
	return minPtr;
}

void GroceryStore::maxItemCalorie()
{
	int calories,min_calories = 0, max_amnt,max_item=0;
	cout<<"\n Enter maximum calories : ";
	cin>>calories;
	itemList *ptr;
	ptr = getMinCalItem(0);
	min_calories = ptr->p->getCalories();
	max_amnt = (ptr->p->getNoOfUnt()) + (ptr->p->getAmntKg());
	while( calories > 0 && ptr !=NULL)
	{
		if( (max_amnt*min_calories) >= calories )
		{
			max_item += (int)(calories/min_calories);
			cout<<(int)(calories/min_calories)<<" "<<ptr->p->getType()<<" with calories "<<min_calories<<" each\n";
			break;
		}
		else
		{
			calories -= (max_amnt*min_calories);
			cout<<max_amnt<<" "<<ptr->p->getType()<<" with calories "<<min_calories<<" each\n";
			max_item += max_amnt;
			ptr = getMinCalItem(min_calories);
			max_amnt = (ptr->p->getNoOfUnt()) + (ptr->p->getAmntKg());
			min_calories = ptr->p->getCalories();
		}
	}
}

void GroceryStore::showLatestItem()
{
	itemList *ptr, *latPtr;
	ptr = this->head;
	latPtr = ptr;
	ptr = ptr->next;
	while(ptr!=NULL)
	{
		if((*(latPtr->p)) < (*(ptr->p)))
			latPtr = ptr;
		ptr = ptr->next;
	}
	cout<<"\n Latest item is : \n";
	latPtr->p->print();
}

void GroceryStore::addFruit(char *type, int price_per_unt, int calories, int no_of_unt, float wght_per_unt, int location_X, int location_Y)
{
	Items *tempFruit = new Fruits(type, price_per_unt, calories, no_of_unt, wght_per_unt, location_X, location_Y);
	tempFruit->updatePurchaseID(p_ID_Index);
	tempFruit->updatePurchaseTime(time(0));
	p_ID_Index++;	
	itemList *tempItem = new itemList;
	tempItem->next = NULL;
	tempItem->p = tempFruit;
	if(this->head == NULL && this->tail == NULL)
		{
			this->head = tempItem;
			this->tail = tempItem;
		}
	else
		{
			(this->tail)->next = tempItem;
			this->tail = tempItem;
		}
	(this->itemCount)++;
}

void GroceryStore::addVegetable(char *type, int price_per_kg, int calories, int amnt_kg, float vlm_per_unt, int location_X, int location_Y)
{
	Items *tempVeg = new Vegetables(type, price_per_kg, calories, amnt_kg, vlm_per_unt,location_X,location_Y);
	tempVeg->updatePurchaseID(p_ID_Index);
	tempVeg->updatePurchaseTime(time(0));
	p_ID_Index++;
	itemList *tempItem = new itemList;
	tempItem->next = NULL;
	tempItem->p = tempVeg;
	if(this->head == NULL && this->tail == NULL)
		{
			this->head = tempItem;
			this->tail = tempItem;
		}
	else
		{
			(this->tail)->next = tempItem;
			this->tail = tempItem;
		}
	(this->itemCount)++;
}
