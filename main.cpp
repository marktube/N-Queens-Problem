//8 queens
#include <iostream>
#include <cstdlib>
using namespace std;
int x[9];//size undeclared
bool PlaceQueen(int row);
int main() {
  int N = 0, counter = 0, row = 0;
  while (cin >> N){
    counter = 0;
    row = 0;
    x[0] = 0;
    // memset(x,0,sizeof(x));//need to add header file
    while (row >= 0){
      while (x[row]<N && !PlaceQueen(row))
	x[row]++;
      if (x[row]<N){
	if (row == N - 1){
	  counter++;
	  x[row] = x[row] + 1;
	}
	else{
	  row++;
	  x[row] = 0;
	}
      }
      else{
	row--;
	x[row] = x[row] + 1;
      }
    }
    cout << counter << endl;
  }
  return 0;
}
bool PlaceQueen(int row){
  int i = 0;
  while (i<row){
    if ((x[row] == x[i]) || (abs(x[i] - x[row]) == row - i))
      return false;
    i++;
  }
  return true;
}                                 
