#include<bits/stdc++.h>
using namespace std;
bool isPossible(int arr[], int n, int m, int curr_min) ;
int min_pages(int arr[], int n, int m) ;
int main(){
   int n ;
   cin>>n;
   cout<<endl;

   int books[n];
   //cout<<"The number of page in books are :\n";
   for(int i = 0 ; i< n; i++){
      cin>>books[i];
   }
   int m = 2;
   cout<<min_pages(books, n, m)<<endl;
   return 0;
}
bool isPossible(int arr[], int n, int m, int curr_min){
   int studentsRequired = 1;
   int curr_sum = 0;
   for (int i = 0; i < n; i++){
      if (arr[i] > curr_min)
         return false;
      if (curr_sum + arr[i] > curr_min){
         studentsRequired++;
         curr_sum = arr[i];
         if (studentsRequired > m)
            return false;
      }
      else
         curr_sum += arr[i];
   }
   return true;
}
int min_pages(int arr[], int n, int m){
   long long sum = 0;
   if (n < m)
      return -1;
   for (int i = 0; i < n; i++)
      sum += arr[i];
   int minimum = 0, maximum = sum;
   int result = INT_MAX;
   while (minimum <= maximum){
      int mid = (minimum + maximum) / 2;
      if (isPossible(arr, n, m, mid)){
         result = min(result, mid);
         maximum = mid - 1;
      }
      else
         minimum = mid + 1;
   }
   return result;
}
