#include <iostream>
#include <fstream>
using namespace std;
void copy1D(int* a, int* b, int s) {
	for (int i = 0; i < s; i++)
	{
		a[i] = b[i];
	}
}

void cout1D(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}
void cout1D(float* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}
int sumRow1D(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum+=arr[i];
	}
	return sum;
}
void inputConsoleMD(int**arr, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cin>>arr[i][j];
        }
    }
}
void outputConsoleMD(int**arr, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<arr[i][j]<<", ";
        }
        cout<<endl;
    }
}
void inputFileMD(char*file, int**arr, int rows, int columns){
    ifstream fin(file);
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            fin>>arr[i][j];
        }
    }
    fin.close();
}
void outputFileMD(char*file, int**arr, int rows, int columns){
    ofstream fout(file);
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(j!=columns-1){
                fout<<arr[i][j]<<" ";
            }
            else{
                fout<<arr[i][j];
            }
        }
        fout<<endl;
    }
    fout.close();
}//ios mode
void outputFileMD(char*file, int i, int**arr, int rows, int columns){
    ofstream fout(file, ios::app);
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(j!=columns-1){
                fout<<arr[i][j]<<" ";
            }
            else{
                fout<<arr[i][j];
            }
        }
        fout<<endl;
    }
    fout.close();
}
int sumOfMatrix(int** arr, int rows, int columns) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
int productOfMatrix(int** arr, int rows, int columns) {
	int mul = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			mul *= arr[i][j];
		}
	}
	return mul;
}
float* rowWiseAverage(int** arr, int rows, int columns) {
	int sum;
	float* rowAverage = new float[rows];
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < columns; j++) {
			sum += arr[i][j];
		}
		rowAverage[i] = sum/(float)columns;
	}
	return rowAverage;
}
float* columnWiseAverage(int** arr, int rows, int columns) {
	int sum;
	float* columnAverage = new float[columns];
	for (int i = 0; i < columns; i++) {
		sum = 0;
		for (int j = 0; j < rows; j++) {
			sum += arr[j][i];
		}
		columnAverage[i] = sum / (float)rows;
	}
	return columnAverage;
}
float matrixAverage(int** arr, int rows, int columns) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sum += arr[i][j];
		}
	}
	return (sum / ((float)rows) * (columns));
}
int** sortRowBySum(int** arr, int rows, int columns) {
	int* temp = new int[rows];
	copy1D(temp, arr[0], rows);
	int greatest = sumRow1D(arr[0], rows);
	int currentSum;
	for (int i = 1; i < rows; i++)
	{
		currentSum = sumRow1D(arr[i], rows);
		if (currentSum > greatest) {

			greatest = currentSum;
		}
	}
}
int** sortColmunBySum(int** arr, int rows, int columns) {
	int *temp = new int[columns];
}
void mainMenu(int s){
    switch(s){
        case 1:
        cout << "";
    }
}
int main() {
    
}
