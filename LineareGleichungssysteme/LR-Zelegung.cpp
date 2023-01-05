#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstdlib>

using namespace std;

int columncounter() {

    ifstream input("matrix");
    string line;
 	int columncounter = 0;
    while(getline(input,line))
      {
            columncounter++;
      }
    return columncounter;
}


int main()
{
std::cout << "LR-Zerlegung! \n  \n";

	// Initialize Matrix
	int columns = columncounter();
	double RightMatrix[columns][columns];
	double LeftMatrix[columns][columns];

	// Fill LeftMatrix
	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			if(spalte == zeile)
			LeftMatrix[spalte][zeile] = 1;
			else 
			LeftMatrix[spalte][zeile] = 0;
		}
	}


	// Fill RightMatrix
	ifstream input("matrix");
    string line;
	int zeile = 0;
    while(getline(input,line))
      	{
        	stringstream lineparser(line);

        	double element;
        	int spalte = 0;
        	
		while(lineparser >> element)
          	{
			RightMatrix[spalte][zeile] = element;
			spalte++;
          	}
		zeile++;
      	}
	
	
	
	std::cout << "Das Gleichungssystem sieht folgendermaßen aus: \n \n";	

	// Show Matrix
	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			std::cout << RightMatrix[spalte][zeile] << "\t";
		}
		std::cout << "\n";
	}


	for(int durchlauf = 0; durchlauf < columns -1; durchlauf++)
	{
		for(int zeile = durchlauf +1; zeile < columns; zeile++) 
		{
			double teiler = RightMatrix[durchlauf][zeile]/RightMatrix[durchlauf][durchlauf];
			if(teiler != 0)
			{
			for(int spalte = durchlauf; spalte <= columns; spalte++)
                {
					RightMatrix[spalte][zeile] -= teiler*RightMatrix[spalte][durchlauf];
					LeftMatrix[spalte][zeile] += teiler*LeftMatrix[spalte][durchlauf];
				}		
			}	
		}
	}	

	std::cout << "\n \nDie R-Matrix lautet: \n \n";	  

	// Show R-Matrix
	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			if(spalte == 0 && zeile != 0)
			std::cout << "0\t";
			else
			std::cout << RightMatrix[spalte][zeile] << "\t";
		}
		std::cout << "\n";
	}

	std::cout << "\n \nDie L-Matrix lautet: \n \n";	
	// Show L-Matrix
	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			std::cout << LeftMatrix[spalte][zeile] << "\t";
		}
		std::cout << "\n";
	}
}
  
