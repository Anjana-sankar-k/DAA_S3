#include<iostream>
using namespace std;

void insertionsort(int arr[], int size){
     for(int i = 0; i < size; i++){ 
		    int key = arr[i];
		    int j = i - 1;
		    while(j >= 0 && arr[j] > key){
		          arr[j+1] = arr[j];
		          j--;
		    }
		    arr[j+1] = key;
     }
            
}

int main(){
        int n;
	cout<<"enter the size of the array: "<<endl;
	cin>>n;
        int arr[n];
	cout<<"enter the elements of the array: "<<endl;
	for(int i = 0; i < n; i++){
	cin>>arr[i];
	}

	cout<<"given array: "<<endl;
	for(int i = 0; i < n; i++){
	cout<<arr[i]<<" ";
	}
	cout<<endl;

	insertionsort(arr,n);

	cout<<"sorted array: "<<endl;
	for(int i = 0; i < n; i++){
	cout<<arr[i]<<" ";
	}
	cout<<endl;

}
