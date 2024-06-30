#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
/*-----------------------------------------------------------------------------------*/
using namespace std;
/*-----------------------------------------------------------------------------------*/

class Point {
public:
	Point( int row, int col ) : rowNum(row), colNum(col) {
		if( row < 0 || col < 0 )
			throw invalid_argument( "Point(): rows/columns can't be smaller than 0" );
	}
	
	void print() { cout << "Row: " << rowNum << ", Column: " << colNum; }
	
	int getRowNum() { return rowNum; }
	int getColNum() { return colNum; }
	
private:
	int rowNum;
	int colNum;
};

// copy constructor and assignment operator overload are missing
class Matrix {
public:
	Matrix( int numOfRows, int numOfColumns ) : rows(numOfRows), cols(numOfColumns) {
		if( numOfRows < 1 || numOfColumns < 1 )
			throw invalid_argument( "Matrix(): rows/columns can't be smaller than 1" );
		
		matrix = new vector< vector<int>* >(numOfRows);
		for( int i = 0; i < numOfRows; ++i )
			matrix->at(i) = new vector<int>(numOfColumns);
	}
	
	~Matrix() {
		for( int i = 0; i < getRows(); ++i )
			delete matrix->at(i);
		
		delete matrix;
	}
	
	void print() const {
		cout << setw(4) << left << "";
		
		for ( int k = 0; k < getCols(); ++k )
			cout << setw(3) << k;
		
		cout << endl << endl;
		
		for( int i = 0; i < getRows(); ++i ) {
			cout << setw(4) << left << i;
			
			for( int j = 0; j < getCols(); ++j ) {
				cout << setw(3) << left << (*this)[i][j];
			}
			cout << endl;
		}
	}
	
	void randomize() {
		random_device rd;
		uniform_int_distribution<int> dist(0, 99);
		
		for( int i = 0; i < getRows(); ++i )
			for( int j = 0; j < getCols(); ++j )
				(*this)[i][j] = dist(rd);
	}
	
	Point findPeak() const {
		if( getCols() == 1 ) {
			vector<int> v( getRows() );
			
			for ( int i = 0; i < v.size(); ++i )
				v[i] = (*this)[i][0];
			
			Point p( findPeak( v ), 0 );
			return p;
		}
		
		if( getRows() == 1 ) {
			Point p( 0, findPeak( (*this)[0] ) );
			return p;
		}
		
		return findPeak( 0, getRows() - 1 );
	}
	
	vector<int>& operator[]( int index ) const { return *( (*matrix)[index] ); }
	
	int getRows() const { return rows; }
	int getCols() const { return cols; }
	
private:
	Point findPeak( const int startRow, const int endRow ) const {
		if( endRow - startRow == 1 ) {
			return findPeakFromTwoRows( startRow, endRow );
		}
		
		int midRow = (startRow + endRow) / 2;
		int maxOfMidRow = max( (*this)[ midRow ] ); // index of the max
		
		//if lower element is bigger
		if( (*this)[ midRow+1 ][ maxOfMidRow ] > (*this)[ midRow ][ maxOfMidRow ] ) {
			return findPeak( midRow, endRow );
		}
		
		//if upper element is bigger
		if( (*this)[ midRow-1 ][ maxOfMidRow ] > (*this)[ midRow ][ maxOfMidRow ] ) {
			return findPeak( startRow, midRow );
		}
		
		// neither lower element is smaller nor upper, so we have got our answer
		Point p( midRow, maxOfMidRow );
		return p;
	}
	
	Point findPeakFromTwoRows( int rowA, int rowB ) const {
		vector<int> maxOfTheRows( getCols() ); // getCols() == row length for the matrix
		
		for ( int i = 0; i < maxOfTheRows.size(); ++i ) {
			maxOfTheRows[i] = (*this)[rowA][i] > (*this)[rowB][i] ? (*this)[rowA][i] : (*this)[rowB][i];
		}
		
		int colNum = findPeak( maxOfTheRows );
		int rowNum = (*this)[rowA][colNum] > (*this)[rowB][colNum] ? rowA : rowB;
		
		Point p( rowNum, colNum );
		return p;
	}
	
	int findPeak( const vector<int>& v ) const {
		return findPeak( v, 0, v.size() - 1 );
	}
	
	int findPeak( const vector<int>& v, int left, int right ) const {
		if( left == right )
			return left;
		
		if( v[left] >= v[left+1] )
			return left;
		
		if( v[right] >= v[right-1] )
			return right;
		
		int middle = (left + right) / 2;
		
		if( v[middle+1] > v[middle] )
			return findPeak( v, middle, right );
		
		if( v[middle-1] > v[middle] )
			return findPeak( v, left, middle );
		
		return middle;
	}
	
	int max( const vector<int>& v ) const { //returns index of max element
		int temp = 0;
		
		for ( int i = 1; i < v.size(); ++i )
			temp = v[temp] < v[i] ? i : temp;
		
		return temp;
	}
	
	int rows;
	int cols;
	vector< vector<int>* >* matrix;
};

/*-----------------------------------------------------------------------------------*/

int main() {
	random_device rd;
	uniform_int_distribution<int> dist( 5, 10 );
	Matrix matrix( dist( rd ), dist( rd ));
	
	matrix.randomize();
	
	matrix.print();
	
	Point p = matrix.findPeak();
	p.print();
	cout << " : " << matrix[p.getRowNum()][p.getColNum()] << endl;
}

/*-----------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------*/



