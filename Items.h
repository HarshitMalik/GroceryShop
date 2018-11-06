#ifndef ITEMS_H
#define ITEMS_H
#include <ctime>

class Items
{
	protected:
		long purchase_ID;
		time_t purchase_time;
		int location_X,location_Y;
	public:
		Items();																// Constructor
		Items(int location_X, int location_Y);
		long getPurchaseID();
		time_t getPurchaseTime();
		int getLocationX();
		int getLocationY();
		void updatePurchaseID(long);
		void updatePurchaseTime(time_t);
		void updateLocationX(int);
		void updateLocationY(int);

		virtual void print();											// Virtual Function
		virtual void updateData();		
		virtual char* getType();
		virtual int getPricePerUnt();
		virtual int getpricePerKg();
		virtual int getNoOfUnt();
		virtual int getAmntKg();
		virtual int getCalories();
		virtual void updateNoOfUnt(int);
		virtual void updateAmntKg(int);

		bool operator < (Items i)										// Operator overloading
		{
			if(this->getPurchaseTime() < i.getPurchaseTime())
				return 1;
			else
				return 0;
		}

		template <typename T>											// Function Template 
		T getDistanceSqr(T t1, T t2)
		{	
			return (t1*t1 + t2*t2);
		}
};

#endif
