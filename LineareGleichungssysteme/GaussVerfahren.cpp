#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstdlib>

using namespace std;

int columncounter() {

    ifstream input("linSystem");
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
std::cout << "Lösen eines linearen Gleichungssystems! \n  \n";

  
//  int lines,columns=-1;

    
	// Initialize Matrix
	int columns = columncounter();
	double matrix[columns+1][columns];
	double vektor[columns];

	// Fill Matrix
	ifstream input("linSystem");
    string line;
	
	int zeile = 0;
    while(getline(input,line))
      	{
        	stringstream lineparser(line);

        	double element;
        	int spalte = 0;
        	
		while(lineparser >> element)
          	{
			matrix[spalte][zeile] = element;
			spalte++;
          	}
		zeile++;
      	}
	
	std::cout << "Das Gleichungssystem sieht folgendermaßen aus: \n \n";	

	// Show Linear System
	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			std::cout << " + "  << matrix[spalte][zeile] << "x" << spalte+1;
		}
		std::cout << " = "  << matrix[columns][zeile] << "\n";
	}
  
	std::cout << "\nEs handelt sich um ein System mit " <<  columns << " Variablen. \nEs sind also " << columns-1 <<" Durchläufe nötig \n \n";


	for(int durchlauf = 0; durchlauf < columns -1; durchlauf++)
	{
		std::cout << "\nDurchlauf " << durchlauf+1 << "\n \n";

		for(int zeile = durchlauf +1; zeile < columns; zeile++) 
		{

			int counter = durchlauf+1;
			while(matrix[durchlauf][durchlauf] == 0 && counter <= columns)
			{
				for(int spalte = 0; spalte <= columns; spalte++)
                	{
					vektor[spalte] 			= matrix[spalte][durchlauf];
					matrix[spalte][durchlauf] 	= matrix[spalte][counter];
					matrix[spalte][counter] = vektor[durchlauf];
					}
					counter++;
			} 
		}
		for(int zeile = durchlauf +1; zeile < columns; zeile++) 
		{
			double teiler = matrix[durchlauf][zeile]/matrix[durchlauf][durchlauf];
			if(teiler != 0)
			{
			for(int spalte = durchlauf; spalte <= columns; spalte++)
                	{
			
					matrix[spalte][zeile] -= teiler*matrix[spalte][durchlauf];
			}		
			}	
		}

	// Show Linear System

		for(int zeile = 0; zeile < columns; zeile++) 
		{
			for(int spalte = 0; spalte < columns; spalte++) 		 
			{
				std::cout << " + "  << matrix[spalte][zeile] << "x" << spalte+1;
			}
			std::cout << " = "  << matrix[columns][zeile] << "\n";
		}
		}
}
  
