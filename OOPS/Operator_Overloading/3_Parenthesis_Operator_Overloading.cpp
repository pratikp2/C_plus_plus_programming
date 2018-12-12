/***********************************************    Key Points    *******************************************************

1) No limit to number of arguments
2) Has to declare member Function (Not as a friend Function)

 ************************************************************************************************************************/
# include <iostream>
using namespace std;

class Matrix
{
	private :
		int a[2][2];
		int b[3];
	
	public :
	    Matrix(){}
	        
		Matrix (int A,int B,int C)
		{
			b[0] = A;
			b[1] = B;
			b[2] = C;
		}
		
		int & operator () (int i, int j) 	// Parenthesis Operator
		{
			return (a[i][j]); 
			// will return the reference of the a(i,j)	
		}
		
		int operator [] (int index)			// Array Subscripting Operator
		{
			return b[index];
		}
		
		void printMatrix()
		{
			int i,j;
			for (i=0; i<=1; i++)
			{
				for(j=0; j<=1; j++)
				{
					cout << a[i][j] << " ";
				}
			cout << endl;
			}
		}
};

int main ()
{
	Matrix ObjMatrix;
	Matrix ObjArray(31,58,39);

	ObjMatrix(0,0) = 0;
	ObjMatrix(0,1) = 1;
	ObjMatrix(1,0) = 2;
	ObjMatrix(1,1) = 3;
	ObjMatrix.printMatrix();

	cout << endl;
	cout << ObjArray[0] << endl;
    cout << ObjArray[1] << endl;
    cout << ObjArray[2] << endl;
    
	return 0;
}

// a (0,0) = 3
// i,e. obj.operator () (0,0) will return the reference of the position a (0,0) and 3 will be stored in it.
