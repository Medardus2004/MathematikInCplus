#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include <cmath>

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
	double choleskymatrix[columns+1][columns];


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
  
	std::cout << "\nEs handelt sich um ein System mit " <<  columns << " Variablen.\n \n";


	for(int zeile = 0; zeile < columns; zeile++) 
	{
		// double teiler = matrix[durchlauf][zeile]/matrix[durchlauf][durchlauf];
		for(int spalte = 0; spalte <= columns; spalte++)
        {
				if(zeile > spalte)
				choleskymatrix[spalte][zeile] = 0; 
				else if(spalte == zeile)
				{
				double difference = 0;
				for(int counter = 0; counter < zeile; counter++)
					{
						difference += pow(choleskymatrix[spalte][counter], 2);
					} 
				choleskymatrix[spalte][zeile] = sqrt(matrix[spalte][zeile]-difference);
				}
				else
				{
				double difference = 0;
				for(int counter = 0; counter <= zeile; counter++)
					{
						difference += choleskymatrix[zeile][counter]*choleskymatrix[spalte][counter];
					} 
				choleskymatrix[spalte][zeile] = (matrix[spalte][zeile]-difference)/choleskymatrix[zeile][zeile];
				}
		}	


				// Show Linear System

	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			std::cout << " + "  << choleskymatrix[spalte][zeile] << "x" << spalte+1;
		}
		std::cout << " = "  << choleskymatrix[columns][zeile] << "\n";
	}
			std::cout << " \n \n \n ";

	}	
		

	// Show Linear System

	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			std::cout << " + "  << choleskymatrix[spalte][zeile] << "x" << spalte+1;
		}
		std::cout << " = "  << choleskymatrix[columns][zeile] << "\n";
	}
}
  
