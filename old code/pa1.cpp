#include "pa1.h"

void sumOfRows(int **square, int n) {
	cout<< "Checking the sums of every row: ";
	int checksum =0;
	for(int p=0; p<(n);p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
}

void sumOfColumns(int **square, int n) {
	cout<< "\nChecking the sums of every column: ";
	int checksum =0;
	for(int p=0; p<n;p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[r][p];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
}

void sumOfDiagonals(int **square, int n) {
	cout<< "\nChecking the sums of every diagonal: ";
	//first diagonal
	int checksum =0;
	int checksum2 =0;
	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
			break;
		}
	}
	//second diagonal
	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum2=checksum2+square[r][p];
			break;
		}
	}
	cout<<checksum<<" "<<checksum2<<" ";
}
	
int main(){
	
	int n = 0;
 	cout << "Enter a size of a magic square: ";
 	cin >> n;

 	//Create a 2D array
 	int **square;
 	square = new int *[n];
 	for(int i = 0; i <10; i++)
    	square[i] = new int[10];

	//initialize square with all 0's
 	for(int i =0; i<n ; i++){
		for(int j=0; j<n ; j++){
			square[i][j]=0;
		}
	}
	
	//declare variables needed
 	int sum = n*(n*n+1)/2;
 	int row =0;
 	int col =0;
 	int temprow=0;
 	int tempcol=0;
 	int num =1;

	//square 1
	cout<<"Magic Square #1 is:\n";
	// set position for 1
	row =0;
 	col =(n)/2;
	square[row][col] = num;

 	//fill the square
 	for (num=2;num<=n*n;num++){
 		temprow=row;
 		tempcol=col;

	 		if (row==0){
	 			row=n-1;
	 		}
	 		else{
	 			row--;
	 		}

	 		if(col==n-1){
	 			col=0;
	 		}
	 		else{
	 			col++;
	 		}
	 		
	 	//check if already filled with number
	 		if (square[row][col] ==0){
	 			square[row][col] = num;
	 		}
	 	// go back one step using temp variables and go down one spot
	 		else{
	 			col=tempcol;
	 			row=temprow;
	 			if(temprow==n-1){
	 			 row=0;
	 			 square[row][col] = num;
	 			}
	 			else{
	 			 row++;
	 			 square[row][col] = num;
	 			}
	 		}
		}

	//print square
	for(int i =0; i<n ; i++){
		for(int j=0; j<n ; j++){
			cout<< square[i][j]<<"  ";
		}
		cout<< "\n";
	}

	//print stats
	sumOfRows(square, n);
	sumOfColumns(square, n);
	sumOfDiagonals(square, n);
   
   	//rotate for second square
 	cout<<"\nMagic Square #2 is:\n";
 	for(int i =0; i<n ; i++){
		for(int j=0; j<n ; j++){
			cout<< square[j][i]<<"  ";
		}
		cout<< "\n";
	}

	//print stats
	sumOfRows(square, n);
	sumOfColumns(square, n);
	sumOfDiagonals(square, n);

   
	//third square
   	cout<<"\nMagic Square #3 is:\n";
   	for(int i =n-1; i>=0 ; i--){
		for(int j=0; j<n ; j++){
			cout<< square[i][j]<<"  ";
		}
		cout<< "\n";
	}

	//print stats
	sumOfRows(square, n);
	sumOfColumns(square, n);
	sumOfDiagonals(square, n);
   
	//fourth square
	cout<<"\nMagic Square #4 is:\n";
   	for(int i =0; i<n ; i++){
		for(int j=n-1; j>=0 ; j--){
			cout<< square[i][j]<<"  ";
		}
		cout<< "\n";
	}
  
	//print stats
	sumOfRows(square, n);
	sumOfColumns(square, n);
	sumOfDiagonals(square, n);


}
//include computation of square
