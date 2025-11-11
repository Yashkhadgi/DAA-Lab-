#include <stdio.h>
void printArray(int arr[],int size){
	for(int i = 0; i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void merge(int a[],int l,int mid,int r){
	int arr[r-l +1];
	for(int i=l,j=mid+1,k=0;k<=r-l;) arr[k++]=(a[i]<a[j]&&i<=mid)||j>r?a[i++]:a[j++];
	printf("Pass: ");
	for(int i=l,k=0;k<=r-l;a[i++]=arr[k++]) printf("%d ",arr[k]);
	printf("\n");
}
void mergeSort(int arr[],int l, int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main(){
	int n;
	printf("no of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	printf("Given array:\n");
	printArray(arr,n);
	mergeSort(arr,0,n-1);
	printf("Sorted array:\n");
	printArray(arr,n);
	return 0 ;
}
