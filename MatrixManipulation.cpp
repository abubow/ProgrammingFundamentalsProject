#include <iostream>
#include <fstream>
using namespace std;
void copy1D(int* a, int* b, int s) {
	for (int i = 0; i < s; i++)
	{
		a[i] = b[i];
	}
}
void copy1D(double* a, double* b, int s) {
	for (int i = 0; i < s; i++)
	{
		a[i] = b[i];
	}
}
void cout1D(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1) {
			cout << arr[i] << ", ";
		}
		else {
			cout << arr[i] << ".\n";
		}
	}
	cout << endl;
}
void cout1D(double* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1) {
			cout << arr[i] << ", ";
		}
		else {
			cout << arr[i] << ".\n";
		}
	}
	cout << endl;
}
double** create2D(int rows, int columns) {
	double** arr = new double* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new double[columns];
	}
	return arr;
}
void inputConsoleMD(int** arr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cin >> arr[i][j];
		}
	}
}
void inputConsoleMD(double** arr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cin >> arr[i][j];
		}
	}
}
void outputConsoleMD(int** arr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}
}
void outputConsoleMD(double** arr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}
}
void inputFileMD(char* file, int** arr, int rows, int columns) {
	ifstream fin(file);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			fin >> arr[i][j];
		}
	}
	fin.close();
}
void outputFileMD(char* file, int** arr, int rows, int columns) {
	ofstream fout(file);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (j != columns - 1) {
				fout << arr[i][j] << " ";
			}
			else {
				fout << arr[i][j];
			}
		}
		fout << endl;
	}
	fout.close();
}//ios mode
void outputFileMD(char* file, int i, int** arr, int rows, int columns) {
	ofstream fout(file, ios::app);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (j != columns - 1) {
				fout << arr[i][j] << " ";
			}
			else {
				fout << arr[i][j];
			}
		}
		fout << endl;
	}
	fout.close();
}
double sumRow1D(double* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double sumOfMatrix(double** arr, int rows, int columns) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
double productOfMatrix(double** arr, int rows, int columns) {
	double mul = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			mul *= arr[i][j];
		}
	}
	return mul;
}
double averageWholeMatrix(double** arr, int rows, int columns) {
	int sum = sumOfMatrix(arr, rows, columns);
	return sum / ((double)(columns * rows));
}
double* rowWiseAverage(double** arr, int rows, int columns) {
	double sum;
	double* rowAverage = new double[rows];
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < columns; j++) {
			sum += arr[i][j];
		}
		rowAverage[i] = sum / columns;
	}
	return rowAverage;
}
double* columnWiseAverage(double** arr, int rows, int columns) {
	int sum;
	double* columnAverage = new double[columns];
	for (int i = 0; i < columns; i++) {
		sum = 0;
		for (int j = 0; j < rows; j++) {
			sum += arr[j][i];
		}
		columnAverage[i] = sum / (double)rows;
	}
	return columnAverage;
}

/*
double** sortRowBySum(double** arr, int rows, int columns) {
double* temp = new double[rows];
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
*/
double** addMatrixs(double*** arrs, int num, int rows, int columns) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			ans[i][j] = 0;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < rows; k++) {
				ans[j][k] += arrs[i][j][k];
			}
		}
	}
	return ans;
}
double** addScalarMatrixs(double** arrs, int rows, int columns, double num) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			ans[i][j] = num;
		}
	}
	for (int j = 0; j < rows; j++) {
		for (int k = 0; k < columns; k++) {
			ans[j][k] += arrs[j][k];
		}
	}
	return ans;
}
double** subtractMatrixs(double*** arrs, int num, int rows, int columns) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			ans[i][j] = arrs[0][i][j];
		}
	}
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < rows; k++) {
				ans[j][k] -= arrs[i][j][k];
			}
		}
	}
	return ans;
}
double** subtractScalarMatrixs(double** arrs, int rows, int columns, double num) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			ans[i][j] = num;
		}
	}
	for (int j = 0; j < rows; j++) {
		for (int k = 0; k < columns; k++) {
			ans[j][k] = arrs[j][k] - ans[j][k];
		}
	}
	return ans;
}
double** multiplyMatrixs(double*** arrs, int num, int rows, int columns) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			ans[i][j] = 1;
		}
	}
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < rows; k++) {
				ans[j][k] *= arrs[i][j][k];
			}
		}
	}
	return ans;
}
double** multiplyScalarMatrixs(double** arrs, int rows, int columns, double num) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			ans[i][j] = num;
		}
	}
	for (int j = 0; j < rows; j++) {
		for (int k = 0; k < columns; k++) {
			ans[j][k] = arrs[j][k] * ans[j][k];
		}
	}
	return ans;
}
double** divideMatrixs(double*** arrs, int num, int rows, int columns) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			ans[i][j] = arrs[0][i][j];
		}
	}
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < rows; k++) {
				ans[j][k] /= arrs[i][j][k];
			}
		}
	}
	return ans;
}
double** divideScalarMatrixs(double** arrs, int rows, int columns, double num) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			ans[i][j] = num;
		}
	}
	for (int j = 0; j < rows; j++) {
		for (int k = 0; k < columns; k++) {
			ans[j][k] = arrs[j][k] / ans[j][k];
		}
	}
	return ans;
}
double** transpose(double** arr, int rows, int columns) {
	double** ans = new double* [rows];
	for (int i = 0; i < rows; i++) {
		ans[i] = new double[columns];
	}
	for (int j = 0; j < rows; j++) {
		for (int k = 0; k < columns; k++) {
			ans[k][j] = arr[j][k];
		}
	}
	return ans;
}
double** subMatrix(double** arr, int size, int x, int y) {
	double** sub = new double* [size - 1];
	int ii = 0, ij = 0;
	for (int i = 0; i < size - 1; i++) {
		sub[ii] = new double[size - 1];
		ij = 0;
		if (ii != x) {
			for (int j = 0; j < size; j++) {
				sub[ii][ij] = arr[i][j];
				ij++;
			}
			ii++;
		}
	}
	return sub;
}
void mainMenuChoice(int s) {
	int numberOfArrays, rows, columns, inputType;
	double** arr;
	switch (s) {
	case 1:
		cout << "Enter number of rows of matrix:";
		cin >> rows;
		cout << "Enter number of columns of matrix:";
		cin >> columns;
		cout << "Which of the following methods do you prefer to use to read the array?\n";
		cout << "1. Console Input.\n2. Read File.\n\n";
		do {
			cin >> inputType;
			if (inputType != 1 && inputType != 2) {
				cout << "Invalid Input, Choose a valid option." << endl;
			}
		} while (inputType != 1 && inputType != 2);
		arr = create2D(rows, columns);
		cout << "Enter arr:\n";
		inputConsoleMD(arr, rows, columns);
		cout << "\nSum of matrix is: " << sumOfMatrix(arr, rows, columns) << "." << endl << endl;
		break;
	case 2:
		cout << "Enter number of rows of matrix:";
		cin >> rows;
		cout << "Enter number of columns of matrix:";
		cin >> columns;
		arr = create2D(rows, columns);
		cout << "Enter arr:\n";
		inputConsoleMD(arr, rows, columns);
		cout << "\nProduct of matrix is: " << productOfMatrix(arr, rows, columns) << "." << endl << endl;
		break;
	case 3:
		cout << "Enter number of rows of matrix:";
		cin >> rows;
		cout << "Enter number of columns of matrix:";
		cin >> columns;
		arr = create2D(rows, columns);
		cout << "Enter arr:\n";
		inputConsoleMD(arr, rows, columns);
		cout << "\nRow-wise average: ";
		cout1D(rowWiseAverage(arr, rows, columns), rows);
		break;
	case 4:
		cout << "Enter number of rows of matrix:";
		cin >> rows;
		cout << "Enter number of columns of matrix:";
		cin >> columns;
		arr = create2D(rows, columns);
		cout << "Enter arr:\n";
		inputConsoleMD(arr, rows, columns);
		cout << "\nColumn-wise average: ";
		cout1D(columnWiseAverage(arr, rows, columns), columns);
		break;
	}
}
void showMainMenuOptions() {
	cout << "1. Sum of Matrix (sum of all values)\n";
	cout << "2. Product of Matrix (product of all values)\n";
	cout << "3. Row-wise Average\n";
	cout << "4. Column-wise Average\n";
	cout << "5. Average or whole Matrix\n";
	cout << "6. Row-wise sorting of Matrix\n";
	cout << "7. Column-wise sorting of Matrix\n";
	cout << "8. Scalar Matrix Addition\n";
	cout << "9. Addition of two Matrices\n";
	cout << "10. Scalar Matrix Subtraction\n";
	cout << "11. Subtraction of two Matrices\n";
	cout << "12. Scalar Matrix Multiplication\n";
	cout << "13. Multiplication of two Matrices\n";
	cout << "14. Scalar Matrix Division\n";
	cout << "15. Matrix transpose\n";
	cout << "16. Matrix determinant\n";
	cout << "17. Matrix Inverse\n";
}
int main() {
	int s;
	char buffer;
	do{
		do {
			showMainMenuOptions();
			cout << "\nEnter Choice: ";
			cin >> s;
			if (s < 1 && s>17) {
				cout << "Invalid Input, Choose a valid option." << endl;
			}
		} while (s < 1 && s>17);
		mainMenuChoice(s);
		do {
			cout << "Continue? y/n\n";
			cin >> buffer;
			if (buffer != 'n' && buffer != 'y') {
				cout << "Invalid Input, Choose a valid option." << endl;
			}
		} while (buffer != 'n' && buffer != 'y');
	} while (buffer!='n');
}
