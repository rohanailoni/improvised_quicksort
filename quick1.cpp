#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono> 
using namespace std;
void swap(double &p,double &q){
    double temp=p;
    p=q;
    q=temp;

}
int partition (double arr[], int low, int high,int *p2) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1);
     *p2=0;
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++; 
            swap(arr[i], arr[j]); 
              
        } 
    } 
    swap(arr[i + 1], arr[high]);
    
    for(int j=i+1;j>-1;j--){
        if(arr[j]!=pivot){
            *p2=j+1;
            break;
        }
    }
    
    return (i + 1); 
} 
void quickSort(double arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int part2;
        int part1;
        part1=partition(arr,low,high,&part2);  
        
        quickSort(arr, low, part2-1); 
        quickSort(arr, part1+1, high); 
    } 
}

int main(){
    double arr[]={2,3,7,3,5,6,6,6,6,2,5,7,7,7,8,7,6,4,4,4,3,3,7,9,6,8,9,1,5,7,8,6,7,6,5,6,7,8,7,6,5,1};
    int part2;
    int part1;
    int n = sizeof(arr) / sizeof(arr[0]);  
    auto start = chrono::high_resolution_clock::now(); 
    
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    auto end = chrono::high_resolution_clock::now(); 
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
  
    time_taken *= 1e-9; 
  
    cout << "Time taken by program is normal sort   : " << fixed  
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
    
    
    
}