#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstdlib>

using namespace std;

void demonstrate_usage_of_vector_as_2d_array(int * matrix, int lines, int columns)
{
  for (int i=0; i<lines; ++i)
    {
      for (int j=0; j<columns; ++j)
        {
		if ( j+1 < columns)
        cout << matrix[i*columns + j] << "x" << j+1  << '\t'  ;
       		else
	cout << "=" <<  matrix[i*columns + j]  << '\t'  ;	
       	}
      cout << '\n';
    }
  cout << endl;
}

int main()
{
  
std::cout << "Lösen eines linearen Gleichungssystems! \n  \n \n Tragen Sie in die Datei ein linSystem Ihr lineares Gleichungs-System ein. \n Dabei steht die erste Spalte für die x1- Werte, die zweite Spalte für die x2-Werte, usw. Die letzte Spalte entspricht Ihrem Wert \n Im Ihr Gleichungssystem sieht folgendermaßen aus: \n";	
  
  vector<int> matrix;
  int lines,columns=-1;

  {   // Einlesen
    ifstream input("linSystem");
    string line;
    while(getline(input,line))
      {
        int columncounter=0;
        stringstream lineparser(line);
        int element;
        while(lineparser >> element) 
          {
            matrix.push_back(element);
            ++columncounter;
          }
        if (columns==-1) columns=columncounter;
  lines=matrix.size()/columns;
      }
  }  // Einlesen fertig

  demonstrate_usage_of_vector_as_2d_array(&matrix[0], lines, columns);

}
