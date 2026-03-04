#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void printMap(int arr[10][10],int n){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]==1){
                
                cout <<  arr[i][j] << " ";
                continue;
            }
            SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|BACKGROUND_GREEN);
            // SetConsoleTextAttribute(hConsole,44);
            cout << arr[i][j] << " ";   
            SetConsoleTextAttribute(hConsole,7);
        }
        cout << endl;
    }
}
int printMatrix(int arr[10][10], int n, int x, int y) {
    Sleep(100); 
    system("cls");
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == x && j == y) {     
                SetConsoleTextAttribute(hConsole, 5);
                cout << arr[i][j] << " ";
                SetConsoleTextAttribute(hConsole, 7);
                continue;
            }
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    if(x==9 && y==9){
        cout<<"DESTINATION REACHD!!" << endl;
    }
}

bool isPossible(int arr[10][10], int x, int y, int n) {
    if (x < n && y < n && arr[x][y] == 1) {
        return true;
    }
    return false;
}

bool path(int arr[10][10], int x, int y, int n) {
  if (x==n-1&&y==n-1) {
    printMatrix(arr,n,x,y);
    return true;
  }

  if (isPossible(arr,x,y,n)) {
    printMatrix(arr,n,x,y);
    int originalX = x;

    if (x<n-1 && path(arr,x+1,y,n)) {
      return true;
    } 
    else {
      x = originalX; 
    }

    if (y<n-1 && path(arr, x, y+1,n)) {
      return true;
    }
  }

  return false;
}

int main() {
    int n = 10;
    int arr[10][10];
    cout << "ENTER THE MAZE"<< endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int x = 0;
    int y = 0;
    cout <<"MAP" << endl;
    printMap(arr,n);
    cout << "PROCEED:(Y)" << endl;
    char in;
    cin >> in;
    if(in=='Y'){
    if (!path(arr, x, y, n)) {
        cout << "No path found." << endl;
    }
    return 0;
}
}