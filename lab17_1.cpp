#include<iostream>
using namespace std;

int main(){
    int nA,nB;
    int *A,*B,**C; // Change C to pointer to pointer
	
    cout << "Length of A: ";
    cin >> nA;
    
    A = new int[nA]; // Allocate memory for array A
    cout << "Input Array A: ";
    for(int i=0; i < nA; i++) cin >> A[i];
    
    cout << "Length of B: ";
    cin >> nB;
    
    B = new int[nB]; // Allocate memory for array B
    cout << "Input Array B: ";
    for(int i=0; i < nB; i++) cin >> B[i];
    
    C = new int*[nA]; // Allocate memory for array of pointers for C
    for(int i=0; i < nA; i++) {
        C[i] = new int[nB]; // Allocate memory for each row of C
    }
    
    for(int i=0; i < nA; i++){
        for(int j=0; j < nB; j++) {
            C[i][j] = A[i]*B[j]; // Store the product in correct position of C
        }
    }
    
    cout << "\t";
    for(int i=0; i < nB; i++){
        cout << B[i] << "\t";
    }
    cout << "\n-----------------------------\n";
    
    for(int i=0; i < nA; i++){
        cout << A[i] << "\t";
        for(int j=0; j < nB; j++) {
            cout << C[i][j] << "\t";
        }
        cout << "\n";
    }

    // Deallocate memory
    delete[] A;
    delete[] B;
    for(int i=0; i < nA; i++) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}
