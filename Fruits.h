#ifndef FRUITS_H
#define FRUITS_H
#include "Items.h"

class Fruits : virtual public Items
{
	private:
		int price_per_unt, calories, no_of_unt;
		float wght_per_unt;
		char type[20];
	
	public:
		Fruits();						// Constructor
		Fruits(char *, int, int, int, float, int, int );
		
		int getPricePerUnt();
		int getCalories();
		int getNoOfUnt();
		float getWghtPerUnt();
		char* getType();
		
		void updatePricePerUnt(int);
		void updateCalories(int);
		void updateNoOfUnt(int);
		void updateWghtPerUnt(float);
		void updateType(char*);
		
		void print();		
		void updateData();
};

#endif
