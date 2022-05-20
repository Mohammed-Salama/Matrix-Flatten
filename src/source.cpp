#include <bits/stdc++.h>
using namespace std;

/*
 * Class Matrix3D
 * */
template <typename T>
class Matrix3D {
    int n;
    int m;
    int p;
    vector<vector<vector<T>>> matrixData;
public:
    /*
     * constructor to initialize matrix size and matrix data with initial value
     */
    Matrix3D(int n , int m , int p , T init_value){
        this->n = n;
        this->m = m;
        this->p = p;
        matrixData = vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T> (p , init_value)));
    }
    /*
     * function for setting the matrix data form cmd
     */
    void inputMatrixData (){
        for (int i = 0 ; i < n ; i++){
            for (int j = 0; j < m ; j++){
                for (int k = 0 ; k < p ; k++ ){
                    cin>>matrixData[i][j][k];
                }
            }
        }
    }

    /*
     * function to flatten matrix in 1D vector
     */
    vector<T> flattenMatrix(){
        vector<T> flattened ;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0; j < m ; j++){
                for (int k = 0 ; k < p ; k++ ){
                    flattened.push_back(matrixData[i][j][k]);
                }
            }
        }
        return flattened;
    }

    /*
     * Function that returns index in flattened matrix in O(1)
     */
    int indexInFlattenedMatrix(int i , int j , int k){
        return (i * (m*p) + j*(p)+k);
    }

    /*
     * Function to get n
     */
    int getN(){
        return n;
    }

    /*
     * Function to get m
     */
    int getM(){
        return m;
    }

    /*
     * Function to get p
     */

    int getP(){
        return p;
    }

    /*
     * Function to get matrix data
     */

    vector<vector<vector<T>>> getMatrixData(){
        return  matrixData;
    }

};
/*
 * Function that tests that indexInFlattenedMatrix works will
 */
template <typename T>
bool Test(Matrix3D<T> matrix ){
    vector<T> flattenedMatrix1D = matrix.flattenMatrix();
    int n = matrix.getN();
    int m = matrix.getM();
    int p = matrix.getP();
    vector<vector<vector<T>>> matrixData = matrix.getMatrixData();
    bool Equal = true;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < m ; j++){
            for (int k = 0 ; k < p ; k++ ){
                cout<<matrixData[i][j][k]<<" "<<flattenedMatrix1D[matrix.indexInFlattenedMatrix(i,j,k)]<<"\n";
                if (matrixData[i][j][k] != flattenedMatrix1D[matrix.indexInFlattenedMatrix(i,j,k)]){
                    Equal = false;
                }
            }
        }
    }
    return Equal;
}

/*
 * main function 
 */
int main() {
    int n , m , p;
    cin>>n>>m>>p;
    Matrix3D<int> matrix (n,m,p,0);
    matrix.inputMatrixData();
    bool test = Test(matrix);
    if (test == true){
        cout<<"All tests passed\n";
    }
    else{
        cout<<"some tests failed\n";
    }
    return 0;
}