// This program solves Project Euler problem 11: Largest Product in a Grid
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

int main()
{
	fstream gridFile;
	gridFile.open("grid.txt", ios::in);
	char temp[2];
	vector <vector<int>> grid (20, vector<int>(20));

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gridFile >> temp;
			int k = temp[0];
			grid[i][j] = (int)temp[1];
			
		}
	}

}

