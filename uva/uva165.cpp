#include <iostream>
#include <string>
using namespace std;

string rv[9][9];



int main(){

rv[1][0]=" ->  0";
rv[1][1]="  1 ->  1";
rv[1][2]="  1  2 ->  2";
rv[1][3]="  1  2  3 ->  3";
rv[1][4]="  1  2  3  4 ->  4";
rv[1][5]="  1  2  3  4  5 ->  5";
rv[1][6]="  1  2  3  4  5  6 ->  6";
rv[1][7]="  1  2  3  4  5  6  7 ->  7";
rv[1][8]="  1  2  3  4  5  6  7  8 ->  8";
rv[2][0]=" ->  0";
rv[2][1]="  1 ->  2";
rv[2][2]="  1  2 ->  4";
rv[2][3]="  1  3  4 ->  8";
rv[2][4]="  1  3  5  6 -> 12";
rv[2][5]="  1  3  5  7  8 -> 16";
rv[2][6]="  1  2  5  8  9 10 -> 20";
rv[2][7]="  1  2  5  8 11 12 13 -> 26";
rv[3][0]=" ->  0";
rv[3][1]="  1 ->  3";
rv[3][2]="  1  3 ->  7";
rv[3][3]="  1  4  5 -> 15";
rv[3][4]="  1  4  7  8 -> 24";
rv[3][5]="  1  4  6 14 15 -> 36";
rv[3][6]="  1  3  7  9 19 24 -> 52";
rv[4][0]=" ->  0";
rv[4][1]="  1 ->  4";
rv[4][2]="  1  3 -> 10";
rv[4][3]="  1  5  8 -> 26";
rv[4][4]="  1  3 11 18 -> 44";
rv[4][5]="  1  3 11 15 32 -> 70";
rv[5][0]=" ->  0";
rv[5][1]="  1 ->  5";
rv[5][2]="  1  4 -> 14";
rv[5][3]="  1  6  7 -> 35";
rv[5][4]="  1  4 12 21 -> 71";
rv[6][0]=" ->  0";
rv[6][1]="  1 ->  6";
rv[6][2]="  1  4 -> 18";
rv[6][3]="  1  7 12 -> 52";
rv[7][0]=" ->  0";
rv[7][1]="  1 ->  7";
rv[7][2]="  1  5 -> 23";
rv[8][0]=" ->  0";
rv[8][1]="  1 ->  8";
int a,b;
while(cin>>a>>b){
      if(a==0&&b==0)
		  break;
	  cout<<rv[a][b]<<endl;
}
    
	return 0;
}