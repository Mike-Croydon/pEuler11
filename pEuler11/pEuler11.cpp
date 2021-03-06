// This program solves Project Euler problem 11: Largest Product in a Grid
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "EulerLib.h"

using namespace std; 

long int horizCheck(vector <vector<int>> myVec)
{
	long int max = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			long int product = myVec[i][j] * myVec[i][j + 1] * myVec[i][j + 2] * myVec[i][j + 3];
			product > max ? max = product : product;
		}
	}
	return max;
}

long int vertCheck(vector <vector<int>> myVec)
{
	long int max = 0;
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			long int product = myVec[i][j] * myVec[i+1][j] * myVec[i+2][j] * myVec[i+3][j];
			product > max ? max = product : product;
		}
	}
	return max;
}

long int rightDiagCheck(vector <vector<int>> myVec)
{
	long int max = 0;
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			long int product = myVec[i][j] * myVec[i + 1][j+1] * myVec[i + 2][j+2] * myVec[i + 3][j+3];
			product > max ? max = product : product;
		}
	}
	return max;
}

long int leftDiagCheck(vector <vector<int>> myVec)
{
	long int max = 0;
	for (int i = 0; i < 17; i++)
	{
		for (int j = 3; j < 20; j++)
		{
			long int product = myVec[i][j] * myVec[i + 1][j - 1] * myVec[i + 2][j - 2] * myVec[i + 3][j - 3];
			product > max ? max = product : product;
		}
	}
	return max;
}

int main()
{
	fstream gridFile;
	gridFile.open("grid.txt", ios::in);
	char temp[3];
	vector <vector<int>> grid (20, vector<int>(20));

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gridFile >> temp;
			grid[i][j] = (10*((int)temp[0]-48))+((int)(temp[1]-48));
		}
	}

	long int max, hmax, vmax, ldmax, rdmax, test;
	
	hmax = EulerLib::Misc::calcMaxHorizProduct(grid,4);
	vmax = EulerLib::Misc::calcMaxVertProduct(grid, 4);
	ldmax = EulerLib::Misc::calcMaxLDiagProduct(grid,4);
	rdmax = EulerLib::Misc::calcMaxRDiagProduct(grid,4);

	max = hmax;
	(vmax > max) ? max = vmax: max;
	(ldmax > max) ? max = ldmax : max;
	(rdmax > max) ? max = rdmax : max;

	cout << "The maximum product of 4 adjacent numbers in the grid is: " << max;
}

