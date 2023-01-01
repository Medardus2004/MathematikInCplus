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
          cout << matrix[i*columns + j] << '\t';
        }
      cout << '\n';
    }
  cout << endl;
}

int main()
{
  
std::cout << "Lösen eines linearen Gleichungssystems! \n ";	
  vector<int> matrix;
  int lines,columns=-1;

  {   // Einlesen
    ifstream input("matrix");
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
        if (columns!=columncounter)
          {
            cerr << "Fehler: Unterschiedliche Spaltenzahl in mindestens zwei Zeilen" << endl;
            exit(1);
          }
      }
  lines=matrix.size()/columns;
  }  // Einlesen fertig

  demonstrate_usage_of_vector_as_2d_array(&matrix[0], lines, columns);

}
