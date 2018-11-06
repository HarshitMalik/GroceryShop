#ifndef STRUCT_H
#define STRUCT_H
#include "Items.h"

struct itemList
{
	Items *p;
	itemList *next;
};

#endif
