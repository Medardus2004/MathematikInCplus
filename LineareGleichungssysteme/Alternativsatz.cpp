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
  
std::cout << "Lösen eines linearen Gleichungssystems! \n  \n \n Tragen Sie in die Datei ein linSystem Ihr lineares Gleichungs-System ein. \n Dabei steht die erste Spalte für die x1- Werte, die zweite Spalte für die x2-Werte, usw. Die letzte Spalte entspricht dem Ergebnis \n Ihr Gleichungssystem sieht folgendermaßen aus: \n";	
  
//  int lines,columns=-1;

    
	// Initialize Matrix
	int columns = columncounter();
	double matrix[columns+1][columns];
	// Fill Matrix
	ifstream input("linSystem");
    	string line;
	int zeile = 0;
    	while(getline(input,line))
      	{
        	stringstream lineparser(line);

        	double element;
        	int row = 0;
        	
		while(lineparser >> element)
          	{
			matrix[row][zeile] = element;
			row++;
          	}
		zeile++;
      	}
	

	// Show Linear System
	for(int i = 0; i < columns; i++) 
	{
		for(int j = 0; j < columns; j++) 		 
		{
			std::cout << " + "  << matrix[j][i] << "x" << j+1;
		}
		std::cout << " = "  << matrix[columns][i] << "\n";
	}
  

	for(int durchlauf = 0; durchlauf < columns -1; durchlauf++)
	{
		std::cout << " Nun wird jede Zeile durch den Wert von x" << durchlauf+1 << " geteilt \n";
		for(int i = durchlauf; i < columns; i++) 
		{
			double teiler = matrix[durchlauf][i];
			for(int j = durchlauf; j < columns; j++)
                	{
				matrix[j][i] /= teiler;
                        	std::cout << " + "  << matrix[j][i] << "x" << j+1; 
               	 	}
			matrix[columns][i] /= teiler;
                	std::cout << " = "  << matrix[columns][i] << "\n";
		}

		std::cout << " und abgezogen \n";
		for( int i = durchlauf; i < columns; i++)
        	{
                	for(int j = durchlauf; j < columns; j++)
                	{
                        	matrix[j][i+1] -= matrix[j][durchlauf];
                        	std::cout << " + "  << matrix[j][i] << "x" << j+1;
                	}
                	matrix[columns][i+1] -= matrix[columns][durchlauf];
                	std::cout << " = "  << matrix[columns][i] << "\n";
        	}
	}
	// Präsentieren der Lösung
	for(int durchlauf = columns; durchlauf > columns -1; durchlauf--)
        {
		std::cout << "x" << durchlauf << " = " << matrix[columns][durchlauf-1] / matrix[durchlauf-1][durchlauf-1] << " \n \n " ;
	}
}  
