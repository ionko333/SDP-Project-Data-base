#include <iostream>
#include "Create.h"
#include "Delete.h"
#include "Update.h"
#include "ShowOffsetLimit.h"
#include "Optimize.h"
#include "Searching.h"
#include "Print.h"

using namespace std;

int main()
{
	string userInput;
	bool isOptimized = false;
	while (true)
	{
		cout << "Please type your command \n";
		cin >> userInput;
		cin.ignore();
		if (userInput == "create")
		{
			createRecord();
			isOptimized = false;
		}
		else if (userInput == "delete")
		{
			DeleteRecord();
		}
		else if (userInput == "update")
		{
			updateAttribute(isOptimized);
		}
		else if (userInput == "show")
		{
			showOffsetLimit();
		}
		else if (userInput == "optimize")
		{
			optimize(isOptimized);
		}
		else if (userInput == "search")
		{
			if (isOptimized)
			{
				optimalSearch();
			}
			else
			{
				normalSearch();
			}
		}
		else if (userInput == "print")
		{
			printAll();
		}
		else if (userInput == "exit")
		{
			break;
		}
		else
                {
                        cout << "Invalid command \n";
                }
	}
	return 0;
}
