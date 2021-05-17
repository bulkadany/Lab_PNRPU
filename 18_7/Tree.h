#pragma once
#include "Object.h"
#include "Event.h"
class Tree
{
public:
	Tree(void);
	Tree(int);
	~Tree(void);
	void Add();
	void Del();
	void Show();
	void Show_unit(int);
	int operator() ();
	void Handle_Event(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};

