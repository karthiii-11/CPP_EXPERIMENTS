#include <iostream>
using namespace std;
class Matrix{
private:
    int data[2][2];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix operator+(const Matrix &m){
        Matrix result;

        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix &m){
        Matrix result;

        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++){
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }

    int* operator[](int index){
        return data[index];
    }

    friend ostream& operator<<(ostream &out, const Matrix &m){
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                out << m.data[i][j] << " ";
            }
            out << endl;
        }

        return out;
    }
};

int main()
{
    int num1, num2, num3, num4;
    int num5, num6, num7, num8;

    cout << "Enter numbers for matrix A:" << endl;
    cout << "Enter a number for [1][1]: ";
    cin >> num1;
    cout << "Enter a number for [1][2]: ";
    cin >> num2;
    cout << "Enter a number for [2][1]: ";
    cin >> num3;
    cout << "Enter a number for [2][2]: ";
    cin >> num4;

    cout << "Enter numbers for matrix B:" << endl;
    cout << "Enter a number for [1][1]: ";
    cin >> num5;
    cout << "Enter a number for [1][2]: ";
    cin >> num6;
    cout << "Enter a number for [2][1]: ";
    cin >> num7;
    cout << "Enter a number for [2][2]: ";
    cin >> num8;

    Matrix A(num1, num2, num3, num4);
    Matrix B(num5, num6, num7, num8);

    Matrix sum = A + B;
    Matrix product = A * B;

    cout << "\nMatrix A:" << endl;
    cout << A;
    cout << "Matrix B:" << endl;
    cout << B;
    cout << "Addition of Matrices:" << endl;
    cout << sum;
    cout << "Multiplication of Matrices:" << endl;
    cout << product;
    return 0;
}