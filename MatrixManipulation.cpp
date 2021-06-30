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
double sumRow1D(double* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum+=arr[i];
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
double matrixAverage(double** arr, int rows, int columns) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sum += arr[i][j];
		}
	}
	return (sum / ((double)rows) * (columns));
}
double* rowWiseAverage(double** arr, int rows, int columns) {
	int sum;
	double* rowAverage = new double[rows];
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < columns; j++) {
			sum += arr[i][j];
		}
		rowAverage[i] = sum/(double)columns;
	}
	return rowAverage;
}
double* columnWiseAverage(int** arr, int rows, int columns) {
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
double** sortRowBySum(double** arr, int rows, int columns) {
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
double** addMatrixs(double*** arrs, int num, int rows, int columns) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<rows;j++){
            ans[i][j]=0;
        }
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<rows;j++){
            for(int k=0; k<rows;k++){
                ans[j][k]+=arrs[i][j][k];
            }
        }
    }
    return ans;
}
double** addScalarMatrixs(double** arrs, int rows, int columns, double num) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<columns;j++){
            ans[i][j]=num;
        }
    }
    for(int j=0; j<rows;j++){
        for(int k=0; k<columns;k++){
            ans[j][k]+=arrs[i][j][k];
        }
    }
    return ans;
}
double** subtractMatrixs(double*** arrs, int num, int rows, int columns) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<rows;j++){
            ans[i][j]=arrs[0][i][j];
        }
    }
    for(int i=1; i<rows;i++){
        for(int j=0; j<rows;j++){
            for(int k=0; k<rows;k++){
                ans[j][k]-=arrs[i][j][k];
            }
        }
    }
    return ans;
}
double** subtractScalarMatrixs(double** arrs, int rows, int columns, double num) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<columns;j++){
            ans[i][j]=num;
        }
    }
    for(int j=0; j<rows;j++){
        for(int k=0; k<columns;k++){
            ans[j][k]=arrs[i][j][k] - ans[j][k];
        }
    }
    return ans;
}
double** multiplyMatrixs(double*** arrs, int num, int rows, int columns) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<rows;j++){
            ans[i][j]=1;
        }
    }
    for(int i=1; i<rows;i++){
        for(int j=0; j<rows;j++){
            for(int k=0; k<rows;k++){
                ans[j][k]*=arrs[i][j][k];
            }
        }
    }
    return ans;
}
double** multiplyScalarMatrixs(double** arrs, int rows, int columns, double num) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<columns;j++){
            ans[i][j]=num;
        }
    }
    for(int j=0; j<rows;j++){
        for(int k=0; k<columns;k++){
            ans[j][k]=arrs[i][j][k]*ans[j][k];
        }
    }
    return ans;
}
double** divideMatrixs(double*** arrs, int num, int rows, int columns) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<rows;j++){
            ans[i][j]=arrs[0][i][j];
        }
    }
    for(int i=1; i<rows;i++){
        for(int j=0; j<rows;j++){
            for(int k=0; k<rows;k++){
                ans[j][k]/=arrs[i][j][k];
            }
        }
    }
    return ans;
}
double** divideScalarMatrixs(double** arrs, int rows, int columns, double num) {
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int i=0; i<rows;i++){
        for(int j=0; j<columns;j++){
            ans[i][j]=num;
        }
    }
    for(int j=0; j<rows;j++){
        for(int k=0; k<columns;k++){
            ans[j][k]=arrs[i][j][k]/ans[j][k];
        }
    }
    return ans;
}
double** transpose(double**arr,int rows,int columns){
    double**ans =new double[rows];
    for(int i=0; i<rows;i++){
        ans[i]= new double[columns];
    }
    for(int j=0; j<rows;j++){
        for(int k=0; k<columns;k++){
            ans[k][j]=arr[j][k];
        }
    }
    return ans;
}
double** subMatrix(double** arr, int size,int x,int y){
    double** sub= new double[size-1];
    int ii=0,ij=0;
    for(int i=0;i<size-1; i++){
        sub[ii] =new double[size-1];
        ij=0;
        if(ii!=x){
            for(int j=0; j<size;j++){
                sub[ii][ij] = arr[i][j];
                ij++;
            }
            ii++;
        }
    }
    return sub;
}
void mainMenuChoice(int s){
    switch(s){
        case 1:
        cout << "";
    }
}
void showMainMenuOptions(){
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
}
int main() {
    
}
