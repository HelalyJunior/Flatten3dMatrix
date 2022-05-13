#include <vector>
#include <iostream>

using namespace std;


/*
* Solver class that internally has the functionality of flattening a 3d matrix.
* Institiate an object from this class and use it to flatten the matrix , you can then use
* the same object to convert the indices.
*/
class Solver
{
    public:
        int rows;
        int columns;

        vector<int> flatten(vector<vector<vector<int>>> matrix3d)
        {
            rows=matrix3d[0][0].size();
            columns=matrix3d[0].size();
            vector<int> flattened;
            for(int i=0;i<3;i++)
            {
                for (int j=0;j<matrix3d[0].size();j++)
                {
                    for(int k=0;k<matrix3d[0][0].size();k++)
                    {
                        flattened.push_back(matrix3d[i][j][k]);
                    }
                }
            }
            return flattened;
        }
        int getIndexFlattened(int i , int j , int k)
        {
            return i*rows*columns + j*rows + k;
        }
};


/*
* Helper Functions for better debugging 
*/
void fill3dMatrix(vector<vector<vector<int>>>& matrix3d,int channels,int row,int column)
{
    int counter=0;
    for(int i=0;i<channels;i++)
    {
        vector<vector<int>> temp2d;
        for(int j=0;j<row;j++)
        {
            vector<int> tempRow;
            for(int k=0;k<column;k++)
            {
                tempRow.push_back(counter);
                counter++;
            }
            temp2d.push_back(tempRow);
        }
        matrix3d.push_back(temp2d);
    }
    return;
}

void print3dMatrix(vector<vector<vector<int>>>& matrix3d)
{
    for(int i=0;i<matrix3d.size();i++)
    {
        for (int j=0;j<matrix3d[0].size();j++)
        {
            for(int k=0;k<matrix3d[0][0].size();k++)
            {
                cout << matrix3d[i][j][k] ;
                cout << " ,  ";
            }
            cout <<endl;
        }
        cout<<endl << endl ; 
    }
}

void printFlattened(vector<int>& flattened)
{
    for(int i=0;i<flattened.size();i++)
    {
        cout << flattened[i] << ",";
    }
    cout << endl;
}



int main()
{
    Solver solver;
    vector<vector<vector<int>>> matrix3d;
    fill3dMatrix(matrix3d,12,5,7); // the matrix is of size 12*5*7
    print3dMatrix(matrix3d);
    vector<int> flattened = solver.flatten(matrix3d);
    printFlattened(flattened);
    cout << flattened[solver.getIndexFlattened(1,1,2)];
}