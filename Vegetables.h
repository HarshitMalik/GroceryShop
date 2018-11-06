#ifndef VEGETABLES_H
#define VEGETABLES_H
#include "Items.h"

class Vegetables :virtual public Items
{
	private:
		int price_per_kg, calories, amnt_kg;
		float vlm_per_unt;
		char type[20];
	public:
		Vegetables();							// Constructor
		Vegetables(char *, int, int, int, float, int, int );

		int getpricePerKg();
		int getCalories();
		int getAmntKg();
		float getVlmPerUnt();
		char* getType();

		void updatePricePerKg(int);
		void updateCalories(int);
		void updateAmntKg(int);
		void updateVlmPerUnt(float);
		void updateType(char*);
		
		void print();
		void updateData();
		void read_vegi_data();
};

#endif
