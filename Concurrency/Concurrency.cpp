// Concurrency.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int f_int()
{
	return 1;
}

int main()
{
	task<int> aTask{create_task(f_int)};
	if (aTask.is_done())
	{
		cout << "Done, but how?\n";
	}
	else
	{
		cout << aTask.get();
	}
	if (aTask.is_done())
	{
		cout << "Done, everything as expected\n";
	}
	else
	{
		cout << "Not done, something isn't right.";
	}
    return 0;
}

