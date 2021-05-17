#pragma once
#include "Tree.h"
#include "Event.h"

class Dialog :public Tree
{
public:
	Dialog(void);
	virtual ~Dialog(void);
	virtual void Get_Event(TEvent& event);
	virtual int Execute();
	virtual void Handle_Event(TEvent& event);
	virtual void Clear_Event(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

