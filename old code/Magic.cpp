# include <iostream>
using namespace std;
	
int main(){
	
	int n = 0;
 	cout << "Enter a size of a magic square: ";
 	cin >> n;

 	int square [n][n];
 	for(int i =0; i<n ; i++){
		for(int j=0; j<n ; j++){
			square[i][j]=0;
		}
	}
	
 	int sum = n*(n*n+1)/2;
 	int row =0;
 	int col =0;
 	int temprow=0;
 	int tempcol=0;
 	int num =1;

//square 1
	cout<<"Majic Square #1 is:\n";
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
	 		
	 	//check if already filled	
	 		if (square[row][col] ==0){
	 			square[row][col] = num;
	 		}
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
	cout<< "Checking the sums of every row: ";
	int checksum =0;
	int checksum2 =0;
	for(int p=0; p<(n);p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	
	cout<< "\nChecking the sums of every column: ";
	for(int p=0; p<n;p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[r][p];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	cout<< "\nChecking the sums of every diagonal: ";
	//first diagonal
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
   
   //rotate for second square
 cout<<"Majic Square #2 is:\n";
 for(int i =0; i<n ; i++){
		for(int j=0; j<n ; j++){
			cout<< square[j][i]<<"  ";
		}
		cout<< "\n";
	}

   cout<< "Checking the sums of every row: ";
	checksum =0;
	checksum2 =0;
	for(int p=0; p<(n);p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	
	cout<< "\nChecking the sums of every column: ";
	for(int p=0; p<n;p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[r][p];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	cout<< "\nChecking the sums of every diagonal: ";

	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
			break;
		}
	}

	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum2=checksum2+square[r][p];
			break;
		}
	}
	cout<<checksum<<" "<<checksum2<<" ";
//third square
   cout<<"Majic Square #3 is:\n";
   for(int i =n-1; i>=0 ; i--){
		for(int j=0; j<n ; j++){
			cout<< square[i][j]<<"  ";
		}
		cout<< "\n";
	}
   
    cout<< "Checking the sums of every row: ";
	checksum =0;
	checksum2 =0;
	for(int p=0; p<(n);p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	
	cout<< "\nChecking the sums of every column: ";
	for(int p=0; p<n;p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[r][p];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	cout<< "\nChecking the sums of every diagonal: ";

	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
			break;
		}
	}

	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum2=checksum2+square[r][p];
			break;
		}
	}
	cout<<checksum<<" "<<checksum2<<" ";

   
//fourth square
	cout<<"Majic Square #4 is:\n";
   for(int i =0; i<n ; i++){
		for(int j=n-1; j>=0 ; j--){
			cout<< square[i][j]<<"  ";
		}
		cout<< "\n";
	}
  
	 cout<< "Checking the sums of every row: ";
	checksum =0;
	checksum2 =0;
	for(int p=0; p<(n);p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	
	cout<< "\nChecking the sums of every column: ";
	for(int p=0; p<n;p++){
		for(int r=0; r<n;r++){
			checksum=checksum+square[r][p];
		}
		cout<<checksum<<" ";
		checksum=0;
	}
	cout<< "\nChecking the sums of every diagonal: ";

	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum=checksum+square[p][r];
			break;
		}
	}
	
	for(int p=(n-1); p>=0;p--){
		for(int r=0; r<n;r++){
			checksum2=checksum2+square[r][p];
			break;
		}
	}
	cout<<checksum<<" "<<checksum2<<" ";


}
//include computation of square
