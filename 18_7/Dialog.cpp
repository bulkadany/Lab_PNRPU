#include "Dialog.h"
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

Dialog::Dialog(void) :Tree()
{
	EndState = 0;
}
Dialog::~Dialog(void)
{
}
void Dialog::Get_Event(TEvent& event)
{
	string OpInt = "+-skqzm";
	string s;
	string param;
	char code;
	cout << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':
			event.command = cmMake; break;
		case '+':
			event.command = cmAdd; break;
		case '-':
			event.command = cmDel; break;
		case 's':
			event.command = cmShow; break;
		case 'z':
			event.command = cmShow_unit; break;
		case 'q':
			event.command = cmQuit; break;
		case '/':
			event.command = cmGet; break;
		}
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else event.what = evNothing;

}
int Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		Get_Event(event);
		Handle_Event(event);
	} while (!Valid());
	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::Clear_Event(TEvent& event)
{
	event.what = evNothing;
}
void Dialog::EndExec()
{
	EndState = 1;
}
void Dialog::Handle_Event(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			size = event.a;
			beg = new Object * [size];
			cur = 0;
			Clear_Event(event);
			break;
		case cmAdd:
			Add();
			Clear_Event(event);
			break;
		case cmDel:
			Del();
			Clear_Event(event);
			break;
		case cmShow:
			Show();
			Clear_Event(event);
			break;
		case cmShow_unit:
			Show_unit(event.a);
			Clear_Event(event);
			break;
		case cmQuit:
			EndExec();
			Clear_Event(event);
			break;
		default:
			Tree::Handle_Event(event);
		};
	};
}
