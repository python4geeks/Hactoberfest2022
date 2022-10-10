#include<iostream>
using namespace std;
int main () {
   int a[10][10] = { {0, 0, 9} , {5, 0, 8} , {7, 0, 0} };
   int i, j, count = 0;
   int row = 3, col = 3;
   for (i = 0; i < row; ++i) {
      for (j = 0; j < col; ++j){
         if (a[i][j] == 0)
         count++;
      }
   }
   cout<<"The matrix is:"<<endl;
   for (i = 0; i < row; ++i) {
      for (j = 0; j < col; ++j) {
         cout<<a[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<"The number of zeros in the matrix are "<< count <<endl;
   if (count > ((row * col)/ 2))
   cout<<"This is a sparse matrix"<<endl;
   else
   cout<<"This is not a sparse matrix"<<endl;
   return 0;
}
Output
The matrix is:
0 0 9
5 0 8
7 0 0
The number of zeros in the matrix are 5
This is a sparse matrix
In the above program, a nested for loop is used to count the number of zeros in the matrix. This is demonstrated using the following code snippet.

for (i = 0; i < row; ++i) {
   for (j = 0; j < col; ++j) {
      if (a[i][j] == 0)
      count++;
   }
}
After finding the number of zeros, the matrix is displayed using a nested for loop. This is shown below.

cout<<"The matrix is:"<<endl;
for (i = 0; i < row; ++i) {
   for (j = 0; j < col; ++j) {
      cout<<a[i][j]<<" ";
   }
   cout<<endl;
}
Finally, the number of zeroes are displayed. If the count of zeros is more than half the elements in the matrix, then it is displayed that the matrix is a sparse matrix otherwise the matrix is not a sparse matrix.

cout<<"The number of zeros in the matrix are "<< count <<endl;
if (count > ((row * col)/ 2))
cout<<"This is a sparse matrix"<<endl;
else
cout<<"This is not a sparse matrix"<<endl;