#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[10][10];
    int rows, cols;

public:
    void input() {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
    }

    void display() const {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << "\t";
            cout << endl;
        }
    }

    Matrix add(const Matrix &m) const {
        Matrix result;
        if (rows != m.rows || cols != m.cols) {
            cout << "Error: Matrices must have the same dimensions for addition.\n";
            result.rows = result.cols = 0;
            return result;
        }
        result.rows = rows;
        result.cols = cols;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
        return result;
    }

    Matrix subtract(const Matrix &m) const {
        Matrix result;
        if (rows != m.rows || cols != m.cols) {
            cout << "Error: Matrices must have the same dimensions for subtraction.\n";
            result.rows = result.cols = 0;
            return result;
        }
        result.rows = rows;
        result.cols = cols;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[i][j] = mat[i][j] - m.mat[i][j];
        return result;
    }

    Matrix multiply(const Matrix &m) const {
        Matrix result;
        if (cols != m.rows) {
            cout << "Error: Number of columns in the first matrix must equal number of rows in the second.\n";
            result.rows = result.cols = 0;
            return result;
        }
        result.rows = rows;
        result.cols = m.cols;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
            }
        return result;
    }

    Matrix transpose() const {
        Matrix result;
        result.rows = cols;
        result.cols = rows;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[j][i] = mat[i][j];
        return result;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    cout << "***** Matrix Calculator *****\n";

    int numMatrices;
    do {
        cout << "Enter the number of matrices to operatore: ";
        cin >> numMatrices;
        if (numMatrices < 2) {
            cout << "Please enter more than 1 matrix to perform the operation.\n";
        }
    } while (numMatrices < 2);

    Matrix matrices[10]; // تدعم حتى 10 مصفوفات
    for (int i = 0; i < numMatrices; i++) {
        cout << "\nEnter Matrix " << i + 1 << ":\n";
        matrices[i].input();
    }

    int choice;
    cout << "\nChoose an operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose (only for the first matrix)\n";
    cout << "Choice: ";
    cin >> choice;

    Matrix result = matrices[0];

    if (choice == 4) {
        result = matrices[0].transpose();
    } else {
        for (int i = 1; i < numMatrices; i++) {
            if (choice == 1)
                result = result.add(matrices[i]);
            else if (choice == 2)
                result = result.subtract(matrices[i]);
            else if (choice == 3)
                result = result.multiply(matrices[i]);
            else {
                cout << "Invalid choice.\n";
                return 0;
            }
        }
    }

    cout << "\nResult:\n";
    result.display();

    return 0;
}
