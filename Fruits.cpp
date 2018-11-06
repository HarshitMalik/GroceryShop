#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Fruits.h"
using namespace std;

Fruits::Fruits()
{
	this->price_per_unt = 0;
	this->calories = 0;
	this->no_of_unt = 0;
	this->wght_per_unt = 0.0;
	strcpy(this->type,"None");
}

Fruits::Fruits(char *type, int price_per_unt, int calories, int no_of_unt, float wght_per_unt, int location_X, int location_Y)
{
	Items();
	this->location_X = location_X;
	this->location_Y = location_Y;
	this->price_per_unt = price_per_unt;
	this->calories = calories;
	this->no_of_unt = no_of_unt;
	this->wght_per_unt = wght_per_unt;
	strcpy(this->type,type);
}

void Fruits::print()
{
	Items::print();
	cout<<" Price per unit :\t"<<getPricePerUnt()<<endl;
	cout<<" Calories per unit :\t"<<getCalories()<<endl;
	cout<<" Numbers of unit :\t"<<getNoOfUnt()<<endl;
	cout<<" Weight per unit :\t"<<getWghtPerUnt()<<endl;
	cout<<" Fruit Type :\t\t"<<getType()<<endl;
}

void Fruits::updateData()
{
	int ch,var;
	char c;
	do
	{
		cout<<"\n Updating Data Portal\n";
		cout<<"   1) Update Purchase ID\n";
		cout<<"   2) Update Purchase Time\n";
		cout<<"   3) Update Location\n";
		cout<<"   4) Update Type\n";
		cout<<"   5) Update Price per Unit\n";
		cout<<"   6) Update Calories\n";
		cout<<"   7) Update Number of Unit\n";
		cout<<"   8) Update Weight per Unit\n";
		cout<<" Enter your choice :\n";
		cin >> ch;
		switch(ch)
		{
			case 1 :
				cout<<"Enter new purchase ID :\n";
				cin>>var;
				updatePurchaseID(var);
				cout<<"Purchase ID updated succesfully\n";
				break;
			case 2 :
				cout<<"Enter new purchase time:\n";
				cin>>var;
				updatePurchaseTime(var);
				cout<<"Purchase Time updated succesfully\n";
				break;
			case 3 :
				cout<<"Enter new x coordinate :\n";
				cin>>var;
				updateLocationX(var);
				cout<<"Enter new y coordinate :\n";
				cin>>var;
				updateLocationY(var);
				cout<<"Location updated succesfully\n";
				break;
			case 4 :
				char newType[20];
				cout<<"Enter type :\n";
				cin>>newType;
				updateType(newType);
				cout<<"Type updated succesfully\n";
				break;
			case 5 :
				cout<<"Enter new price per unit :\n";
				cin>>var;
				updatePricePerUnt(var);
				cout<<"price per unit updated succesfully\n";
				break;
			case 6 :
				cout<<"Enter new calories value :\n";
				cin>>var;
				updateCalories(var);
				cout<<"calories value updated succesfully\n";
				break;
			case 7 :
				cout<<"Enter new number of units :\n";
				cin>>var;
				updateNoOfUnt(var);
				cout<<"number of units updated succesfully\n";
				break;
			case 8 :
				float newWght;
				cout<<"Enter new weight per unit :\n";
				cin>>newWght;
				updatePurchaseID(newWght);
				cout<<"weight per unit updated succesfully\n";
				break;
			default :
				cout<<"You have entered wrong choice !\n";
				break;
		}
		cout<<"\n Update more ? (y/n)\n";
		cin>>c;
	}while(c=='y'||c=='Y');
}

/*
long Fruits::getPurchaseID()
{
	return this->purchase_ID;
}

long Fruits::getPurchaseTime()
{
	return this->purchase_time;
}

int Fruits::getLocationX()
{
	return this->location_X;
}

int Fruits::getLocationY()
{
	return this->location_Y;
}
*/
int Fruits::getPricePerUnt()
{
	return this->price_per_unt;
}

int Fruits::getCalories()
{
	return this->calories;
}

int Fruits::getNoOfUnt()
{
	return this->no_of_unt;
}

float Fruits::getWghtPerUnt()
{
	return this->wght_per_unt;
}

char* Fruits::getType()
{
	return this->type;
}

void Fruits::updatePricePerUnt(int x)
{
	this->price_per_unt = x;
}

void Fruits::updateCalories(int x)
{
	this->calories = x;
}

void Fruits::updateNoOfUnt(int x)
{
	this->no_of_unt = x;
}

void Fruits::updateWghtPerUnt(float x)
{
	this->wght_per_unt = x;
}

void Fruits::updateType(char * x)
{
	strcpy(this->type,x);
}

