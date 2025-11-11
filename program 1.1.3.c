#include <stdio.h>
void displaySubArray(int arr[],int low,int high){
	for(int i = low;i<=high;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int partition(int arr[],int low,int high){
	int pivot = arr[high];
	int i = low - 1,temp;

	for(int j = low; j < high;j++){
		if(arr[j]<=pivot){
			i++;
			temp = arr[i];
			arr[i]=arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1]=arr[high];
	arr[high]=temp;
	return i+1;
}
void quickSort(int arr[],int low,int high,int size){
	if(low < high){
		int pi = partition(arr,low ,high);

		printf("Pass: ");
		displaySubArray(arr,low,high);
		quickSort(arr,low,pi-1,size);
		quickSort(arr,pi + 1,high,size);
	}
}
void displayArray(int arr[],int n){
	for(int i = 0; i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[100],n;

	printf("number of elements: ");
	scanf("%d",&n);
	printf("elements: ");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original array: ");
	displayArray(arr,n);
	quickSort(arr,0,n-1,n);
	printf("Sorted array: ");
	displayArray(arr,n);
	return 0;
}
