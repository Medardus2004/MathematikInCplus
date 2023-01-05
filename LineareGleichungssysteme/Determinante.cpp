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
std::cout << "Determinante! \n  \n";

	// Initialize Matrix
	int columns = columncounter();
	double Matrix[columns][columns];
	int vektor[columns];

	// Fill Matrix
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
			Matrix[spalte][zeile] = element;
			spalte++;
          	}
		zeile++;
      	}
	
	std::cout << "Die Matrix sieht folgendermaßen aus: \n \n";	

	// Show Matrix
	for(int zeile = 0; zeile < columns; zeile++) 
	{
		for(int spalte = 0; spalte < columns; spalte++) 		 
		{
			std::cout << Matrix[spalte][zeile] << "\t";
		}
		std::cout << "\n";
	}


	for(int durchlauf = 0; durchlauf < columns -1; durchlauf++)
	{

		for(int zeile = durchlauf +1; zeile < columns; zeile++) 
		{

			int counter = durchlauf+1;
			while(Matrix[durchlauf][durchlauf] == 0 && counter <= columns)
			{
				for(int spalte = 0; spalte < columns; spalte++)
                	{
					vektor[spalte] 				= Matrix[spalte][durchlauf];
					Matrix[spalte][durchlauf] 	= Matrix[spalte][counter];
					Matrix[spalte][counter] 	= vektor[durchlauf];
					}
					counter++;
			} 
		}



		for(int zeile = durchlauf +1; zeile < columns; zeile++) 
		{
			double teiler = Matrix[durchlauf][zeile]/Matrix[durchlauf][durchlauf];
			if(teiler != 0)
			{
			for(int spalte = durchlauf; spalte <= columns; spalte++)
                {
					Matrix[spalte][zeile] -= teiler*Matrix[spalte][durchlauf];
				}		
			}	
		}
	}	

	double Determinante = 0;
	for(int n = 0; n < columns ; n++)
	{
		Determinante += Matrix[n][n];
	}

	std::cout << "\n \nDie Determinante lautet: " <<  Determinante << "/n /n";	  
}
  
