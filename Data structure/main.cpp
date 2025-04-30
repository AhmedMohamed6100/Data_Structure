#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int rows, cols;

public:
    // دالة لإدخال المصفوفة
    void input() {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        mat.resize(rows, vector<int>(cols));

        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    // دالة لعرض المصفوفة
    void display() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // دالة لإضافة المصفوفات
    Matrix add(Matrix m) {
        Matrix result;
        if (rows != m.rows || cols != m.cols) {
            cout << "Error: Matrices must have the same dimensions for addition.\n";
            result.rows = result.cols = 0;
            return result;
        }
        result.rows = rows;
        result.cols = cols;
        result.mat.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
        return result;
    }

    // دالة لطرح المصفوفات
    Matrix subtract(Matrix m) {
        Matrix result;
        if (rows != m.rows || cols != m.cols) {
            cout << "Error: Matrices must have the same dimensions for subtraction.\n";
            result.rows = result.cols = 0;
            return result;
        }
        result.rows = rows;
        result.cols = cols;
        result.mat.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[i][j] = mat[i][j] - m.mat[i][j];
        return result;
    }

    // دالة لضرب المصفوفات
    Matrix multiply(Matrix m) {
        Matrix result;
        if (cols != m.rows) {
            cout << "Error: Number of columns in the first matrix must equal number of rows in the second.\n";
            result.rows = result.cols = 0;
            return result;
        }
        result.rows = rows;
        result.cols = m.cols;
        result.mat.resize(rows, vector<int>(m.cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
            }
        return result;
    }

    // دالة لتحويل المصفوفة (Transpose)
    Matrix transpose() {
        Matrix result;
        result.rows = cols;
        result.cols = rows;
        result.mat.resize(cols, vector<int>(rows));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[j][i] = mat[i][j];
        return result;
    }

    // دالة لإرجاع أبعاد المصفوفة
    int getRows() { return rows; }
    int getCols() { return cols; }
};

int main() {
    int numMatrices, choice;
    cout << "Enter the number of matrices to operator: ";
    cin >> numMatrices;

    vector<Matrix> matrices(numMatrices);

    // إدخال المصفوفات
    for (int i = 0; i < numMatrices; i++) {
        cout << "Enter matrix " << i + 1 << ":\n";
        matrices[i].input();
    }

    // اختيار العملية
    cout << "Choose an operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose\n";
    cout << "Choice: ";
    cin >> choice;

    Matrix result;

    if (choice == 1 || choice == 2 || choice == 3) {
        cout << "You will perform the operation between the first two matrices.\n";
        switch (choice) {
            case 1:
                result = matrices[0].add(matrices[1]);
                break;
            case 2:
                result = matrices[0].subtract(matrices[1]);
                break;
            case 3:
                result = matrices[0].multiply(matrices[1]);
                break;
            default:
                cout << "Invalid choice.\n";
                return 0;
        }
    } else if (choice == 4) {
        cout << "You will transpose the first matrix.\n";
        result = matrices[0].transpose();
    } else {
        cout << "Invalid choice.\n";
        return 0;
    }

    // عرض النتيجة
    cout << "Result:\n";
    result.display();

    return 0;
}
