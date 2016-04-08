// Tony Yeung

#include <iostream>
#include <iomanip>
using namespace std;

bool rageQuit(int);

int getHighestNumberGrades(int*, int);

int main()
{
	cout << "ENTER THE DATA NIGGUH\n\n\n";
	int percent = 0;
	int weight = 0;
	int stupidCount = 0;
	int numSections;
	double grade;
	int min, max;
	bool rage = false;
	cout << "How many sections are there? (Homeworks, Quizes, Tests, etc...): ";
	cin >> numSections;
	double *weightedMult = new double[numSections];
	double *weightedGradeTable = new double[numSections];
	
	cout << "\n\nENTER IN PERCENTAGES WITHOUT THE PERCENTAGE SIGN\n\n";

	for (int section = 1; section <= numSections; section++)
	{
		cout << "Enter the weight of Section " << section << ": ";
		cin >> weight;
		while (weight >= 100 || weight < 0)
		{
			cout << "Invalid Weight\n";
			cout << "Enter the weight of Section " << section << ": ";
			cin >> weight;
		}
		percent += weight;
		weightedMult[section - 1] = (static_cast<double>(weight) / 100);
	}
	while (percent < 100 && percent >= 0 && !rage)
	{ 
		percent = 0;
		cout << "The Percentages don't add up to 100\n";
		for (int section = 1; section <= numSections; section++)
		{
			cout << "Enter the weight of Section " << section << ": ";
			cin >> weight;
			while (weight > 100 || weight < 0)
			{
				/*if (percent > 100)
				{
					percent -= weight;
					cout << "The total weight is now greater than 100, you can't add nigga\n";
					if (rageQuit(++stupidCount))
					{
						rage = true;
						cout << "I'm tired of yo ass dumb mistakes, I ain't calculating yo shit no more, bitch. I don't know how yo ass got in college\n";
						break;
					}
					cout << "Enter the weight of Section " << section << ": ";
					cin >> weight;
					percent += weight;
				}
				else
				{
					break;
				}
				*/
				cout << "Invalid Weight\n";
				cout << "Enter the weight of Section " << section << ": ";
				cin >> weight;
			}
			percent += weight;
			weightedMult[section - 1] = (static_cast<double>(weight) / 100);
		}
		
	}
	int *numAssignments = new int[numSections];
	for (int index = 0; index < numSections && !rage; index++)
	{
		numAssignments[index] = 0;
	}

	for (int index = 0; index < numSections && !rage; index++)
	{
		cout << "How many grades are in Section " << index + 1 << "? ";
		cin >> numAssignments[index];
		while (numAssignments[index] < 0)
		{
			cout << "Stop...\n";
			if (rageQuit(++stupidCount))
			{
				rage = true;
				cout << "I'm tired of yo ass dumb mistakes, I ain't calculating yo shit no more, bitch. I don't know how yo ass got in college\n";
				break;
			}
			cout << "How many grades are in Section " << index + 1 << "? ";
			cin >> numAssignments[index];
		}
	}
//	int highestNumberGrades = getHighestNumberGrades(numAssignments, numSections);
	double **gradeTable = new double*[numSections];
	double *averageGradeTable = new double[numSections];

	for (int index = 0; index < numSections; index++)
	{
		gradeTable[index] = new double[numAssignments[index]];
	}

//	cout << "ENTER THE NUMBER OF POINTS YOU GOT FOLLOWED BY A SPACE THEN TOTAL NUMBER OF POINTS FOR EACH ASSIGNMENT\n";
	for (int row = 0; row < numSections; row++)
	{
		cout << "Section " << row + 1 << endl;
		for (int column = 0; column < numAssignments[row]; column++)
		{
			cout << setw(5) << ' ' << "Assignment " << column + 1 << endl;
			cout << setw(10) << ' ' << setw(8) << "Earned: ";
			cin >> min;
			cout << setw(10) << ' ' << setw(8) << "Out of: ";
			cin >> max;
			while (min < 0 || max <= 0 || (static_cast<double>(min) / max) > 1.5)
			{
				cout << "nigga...\n";
				cout << setw(5) << ' ' << "Assignment " << column + 1 << endl;
				cout << setw(10) << ' ' << setw(8) << "Earned: ";
				cin >> min;
				cout << setw(10) << ' ' << setw(8) << "Out of: ";
				cin >> max;
			}
			grade = (static_cast<double>(min) / max);
			gradeTable[row][column] = grade;
		}
		cout << endl << endl;
	}

	for (int section = 0; section < numSections; section++)
	{
		double totalGrade = 0;
		for (int index = 0; index < numAssignments[section]; index++)
		{
			totalGrade += gradeTable[section][index];
		}
		averageGradeTable[section] = totalGrade / numAssignments[section];
	}
	
	for (int index = 0; index < numSections; index++)
	{
		weightedGradeTable[index] = averageGradeTable[index] * weightedMult[index];
	}

	double finalAverage = 0;
	for (int index = 0; index < numSections; index++)
	{
		finalAverage += weightedGradeTable[index] * 100;
	}

	cout << "\n\nYour average is: " << finalAverage << endl;

	system("pause");
	return 0;
}

bool rageQuit(int stupidCount)
{
	return stupidCount >= 3 ? true : false;
}

/*
int getHighestNumberGrades(int *numAssignments, int numSections)
{
	int highest = 0;
	for (int index = 0; index < numSections; index++)
	{
		if (numAssignments[index] > highest)
		{
			highest = numAssignments[index];
		}
	}
	return highest;
}
*/