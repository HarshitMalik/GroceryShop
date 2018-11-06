#include <iostream>
#include "Items.h"
using namespace std;

Items::Items()
{
	this->purchase_ID = 0;
	this->purchase_time = 0;
	this->location_X = 0;
	this->location_Y = 0;
}

Items::Items(int location_X, int location_Y)
{
	this->purchase_ID = 0;
	this->purchase_time = 0;
	this->location_X = location_X;
	this->location_Y = location_Y;
}

void Items::print()
{	
	time_t time = getPurchaseTime();
	char *cTime = ctime(&time);
	cout<<"\n Purchase ID :\t\t"<<getPurchaseID()<<endl;
	cout<<" Purchase Time : "<<cTime;
	cout<<" Location :\t\t( "<<getLocationX()<<" , "<<getLocationY()<<" )"<<endl;
}

/*template <typename T>
//T Items::getDistanceSqr(T t1, T t2)
template <typename T>
T Items::getDistanceSqr(T t1, T t2)
{
	return (t1*t1 + t2*t2);
}*/

long Items::getPurchaseID()
{
	return this->purchase_ID;
}

time_t Items::getPurchaseTime()
{
	return this->purchase_time;
}

int Items::getLocationX()
{
	return this->location_X;
}

int Items::getLocationY()
{
	return this->location_Y;
}

void Items::updatePurchaseID(long x)
{
	this->purchase_ID = x;
}

void Items::updatePurchaseTime(long x)
{
	this->purchase_time = x;
}

void Items::updateLocationX(int x)
{
	this->location_X = x;
}

void Items::updateLocationY(int x)
{
	this->location_Y = x;
}

char* Items::getType()
{;}
int Items::getPricePerUnt()
{;}
int Items::getpricePerKg()
{;}
void Items::updateData()
{;}
int Items::getNoOfUnt()
{
	return 0;
}
int Items::getAmntKg()
{
return 0;
}
int Items::getCalories()
{;}
void Items::updateNoOfUnt(int x)
{;}
void Items::updateAmntKg(int)
{;}
