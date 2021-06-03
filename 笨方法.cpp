#include<iostream>
using namespace std; 

double** Matrix(int n, int m) 
{
    double** A = new double*[n];
    if (!A)			
        return NULL;				
    for (int i = 0; i < n; ++i) {
        A[i] = new double[m];
        if (!A[i])
            return NULL;
    }
    return A;
}

void DeleteMatrix(double** A, int n, int m) 
{
    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;  
    A = NULL;
}

double Det(double** A, int n) 
{
    if (n == 1)
        return A[0][0];
    if (n == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double det = 0;
    double** M = Matrix(n - 1, n - 1);

    // for all elements in the 0th row
    for (int a = 0; a < n; ++a) {
        // create minor matrix
        for (int i = 1, minor_i = 0; i < n; ++i, ++minor_i) {
            for (int j = 0, minor_j = 0; j < n; ++j) {
                if (j == a)
                    continue;
                M[minor_i][minor_j++] = A[i][j];
            }
        }

        // add up terms
        if (a % 2 == 0)
            det += A[0][a] * Det(M, n - 1);
        else
            det -= A[0][a] * Det(M, n - 1);
    }
    DeleteMatrix(M, n - 1, n - 1);
    return det;
}


int main()
{
	int i,j,k,l;
	int n ,answer,det0; 
	cout << "輸入行列式: "; 
	cin >>  det0; 
    cout << "輸入要計算的階數: ";
    cin >> n;
    cout << "將未知數輸入為零的矩陣: "<< endl; 
    double** A = Matrix(n, n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            cin >> A[i][j];
    cout<<"請輸入刪除未知數行列後的矩陣: ";
    double** B = Matrix(n, n);
	for (k = 0; k < n-1; ++k)
    	for (l = 0; l < n-1; ++l)
        	cin >> B[k][l];
    cout << (det0-Det(A, n))/Det(B,n-1);
}