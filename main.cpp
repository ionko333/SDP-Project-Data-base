#include <iostream>
#include "Create.h"
#include "Delete.h"
#include "Update.h"
#include "ShowOffsetLimit.h"
#include "Optimize.h"
#include "Searching.h"

using namespace std;

int main()
{
	string userInput;
	long long int cntRecords = getRecordsCnt();
	bool isOptimized = false;
	while (true)
	{
		cout << "Please type your command \n";
		cin >> userInput;
		if (userInput == "create")
		{

			cout << "Please type the new record's desired Id\n";
			unsigned long long int Id;
			cin >> Id;
			cin.ignore();
			if (cntRecords > 0)
			{
				long long int a = recordPosition(Id);
				if (a > -1)
				{
					cout << "A record with this Id already exists in the data base\n";
				}
				else
				{
					createRecord(Id, cntRecords);
				}
			}
			else
			{
				createRecord(Id, cntRecords);
				isOptimized = false;
			}
		}
		else if (userInput == "delete")
		{
			if (cntRecords == 0)
			{
				cout << "Cannot delete from an empty data base\n";
			}
			else
			{
				cout << "Please type the Id of the record you want to delete\n";
				unsigned long long int Id;
				cin >> Id;
				cin.ignore();
				if (recordPosition(Id) == -1)
				{
					cout << "A record with such Id does not exist\n";
				}
				else
				{
					DeleteRecord(Id,cntRecords,recordPosition(Id));
					isOptimized = false;
				}
			}
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
		else if (userInput == "exit")
		{
			break;
		}
	}
	return 0;
}
