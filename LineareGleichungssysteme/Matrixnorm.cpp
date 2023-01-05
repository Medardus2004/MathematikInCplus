#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include <cmath>
#include <algorithm>

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
std::cout << "Matrixnorm! \n  \n";

	// Initialize Matrix
	int columns = columncounter();
	double Matrix[columns][columns];
	double vektor[columns];

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

  for(int zeile = 0; zeile < columns; zeile++) 
		{
			vektor[zeile] = 0;
		}

	for(int zeile = 0; zeile < columns; zeile++) 
		{
			for(int spalte = 0; spalte < columns; spalte++)
                {
					vektor[zeile] += abs(Matrix[spalte][zeile]);
				}		
		}	

	

	std::cout << "Die Zeilensummennorm ||A||inf sieht folgendermaßen aus: " <<  *std::max_element(vektor, vektor+columns) << " \n \n";	
 
 for(int zeile = 0; zeile < columns; zeile++) 
		{
			vektor[zeile] = 0;
		}

 	for(int zeile = 0; zeile < columns; zeile++) 
		{
			for(int spalte = 0; spalte < columns; spalte++)
                {
					vektor[spalte] += abs(Matrix[spalte][zeile]);
				}		
		}	


	std::cout << "Die Spaltensummennorm ||A||1 sieht folgendermaßen aus: " <<  *std::max_element(vektor, vektor+columns) << " \n \n";	
}
  
