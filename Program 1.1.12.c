/* Write complete code for the required soluton */
#include <stdio.h>
#include<stdlib.h>
int count = 0;
int isSafe(int board[], int row, int col){
	for(int i=0; i<row; i++){
		if(board[i] == col || abs(board[i] - col) == row-i){
			return 0;
		}
	}
	return 1;
}
void solve(int board[], int row, int n){
	if(row==n){
		count++;
		return;
	}
	for(int col =0; col<n; col++){
		if(isSafe(board,row,col)){
			board[row] = col;
			solve(board,row+1,n);
		}
	}
}
int nQueen(int n){
	int board[10];
	count = 0;
	solve(board,0,n);
	return count;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",nQueen(n));
	return 0;
}
