#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Vegetables.h"
using namespace std;

Vegetables::Vegetables()
{
	this->price_per_kg = 0;
	this->calories = 0;
	this->amnt_kg = 0;
	this->vlm_per_unt = 0.0;
	strcpy(this->type,"None");
}

Vegetables::Vegetables(char *type, int price_per_kg, int calories, int amnt_kg, float vlm_per_unt,int location_X, int location_Y)
{
	Items();
	this->location_X = location_X;
	this->location_Y = location_Y;
	this->price_per_kg = price_per_kg;
	this->calories = calories;
	this->amnt_kg = amnt_kg;
	this->vlm_per_unt = vlm_per_unt;
	strcpy(this->type,type);
}

void Vegetables::print()
{
	Items::print();
	cout<<" Price per Kg :\t\t"<<getpricePerKg()<<endl;
	cout<<" Calories per unit :\t"<<getCalories()<<endl;
	cout<<" Amount in kg :\t\t"<<getAmntKg()<<endl;
	cout<<" Volume per unit :\t"<<getVlmPerUnt()<<endl;
	cout<<" Vegetable Type :\t"<<getType()<<endl;
}

void Vegetables::updateData()
{
	int ch,var;
	char c;
	do
	{
		cout<<"\n Updating Vgetable Data Portal\n";
		cout<<"   1) Update Purchase ID\n";
		cout<<"   2) Update Purchase Time\n";
		cout<<"   3) Update Location\n";
		cout<<"   4) Update Type\n";
		cout<<"   5) Update Price per Kg\n";
		cout<<"   6) Update Calories\n";
		cout<<"   7) Update Amount of Kg\n";
		cout<<"   8) Update Volume per Unit\n";
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
				cout<<"Enter new price per kg :\n";
				cin>>var;
				updatePricePerKg(var);
				cout<<"price per kg updated succesfully\n";
				break;
			case 6 :
				cout<<"Enter new calories value :\n";
				cin>>var;
				updateCalories(var);
				cout<<"calories value updated succesfully\n";
				break;
			case 7 :
				cout<<"Enter new amount of kg :\n";
				cin>>var;
				updateAmntKg(var);
				cout<<"amount of kg updated succesfully\n";
				break;
			case 8 :
				float newVlm;
				cout<<"Enter new volume per unit :\n";
				cin>>newVlm;
				updateVlmPerUnt(newVlm);
				cout<<"volume per unit updated succesfully\n";
				break;
			default :
				cout<<"You have entered wrong choice !\n";
				break;
		}
		cout<<"\n Update more ? (y/n)\n";
		cin>>c;
	}while(c=='y'||c=='Y');
}

int Vegetables::getpricePerKg()
{
	return this->price_per_kg;
}

int Vegetables::getCalories()
{
	return this->calories;
}

int Vegetables::getAmntKg()
{
	return this->amnt_kg;
}

float Vegetables::getVlmPerUnt()
{
	return this->vlm_per_unt;
}

char* Vegetables::getType()
{
	return this->type;
}

void Vegetables::updatePricePerKg(int x)
{
	this->price_per_kg = x;
}

void Vegetables::updateCalories(int x)
{
	this->calories = x;
}

void Vegetables::updateAmntKg(int x)
{
	this->amnt_kg = x;
}

void Vegetables::updateVlmPerUnt(float x)
{
	this->vlm_per_unt = x;
}

void Vegetables::updateType(char * x)
{
	strcpy(this->type,x);
}
