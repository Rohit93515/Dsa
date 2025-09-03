#include <iostream>
using namespace std;
struct Element {
    int row, col, val;
};

class Sparse {
    int rows, cols, terms;
    Element *data;

public:
    Sparse(int r, int c, int t) {
        rows = r;
        cols = c;
        terms = t;
        data = new Element[terms];
    }
void input() {
        cout << "Enter row, column, value for " << terms << " non-zero elements:\n";
        for (int i = 0; i < terms; i++) {
            cin >> data[i].row >> data[i].col >> data[i].val;
        }
    }

    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i].row << " " << data[i].col << " " << data[i].val << endl;
        }
    }

    Sparse transpose() {
        Sparse result(cols, rows, terms);
        int k = 0;
        for (int c = 0; c < cols; c++) {
            for (int i = 0; i < terms; i++) {
                if (data[i].col == c) {
                    result.data[k].row = data[i].col;
                    result.data[k].col = data[i].row;
                    result.data[k].val = data[i].val;
                    k++;
                }
            }
        }
        return result;
    }

    Sparse add(Sparse &s) {
        if (rows != s.rows || cols != s.cols) {
            cout << "Matrices cannot be added!" << endl;
            return Sparse(0, 0, 0);
        }
        Element *temp = new Element[terms + s.terms];
        int i = 0, j = 0, k = 0;
        while (i < terms && j < s.terms) {
            if (data[i].row < s.data[j].row ||
               (data[i].row == s.data[j].row && data[i].col < s.data[j].col))
                temp[k++] = data[i++];
            else if (s.data[j].row < data[i].row ||
                    (s.data[j].row == data[i].row && s.data[j].col < data[i].col))
                temp[k++] = s.data[j++];
            else {
                temp[k] = data[i];
                temp[k++].val = data[i++].val + s.data[j++].val;
            }
        }
        while (i < terms) temp[k++] = data[i++];
        while (j < s.terms) temp[k++] = s.data[j++];

        Sparse result(rows, cols, k);
        for (int x = 0; x < k; x++) result.data[x] = temp[x];
        return result;
    }

    Sparse multiply(Sparse &s) {
        if (cols != s.rows) {
            cout << "Matrices cannot be multiplied!" << endl;
            return Sparse(0, 0, 0);
        }
        Element *temp = new Element[rows * s.cols]; 
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < s.cols; j++) {
                int sum = 0;
                for (int a = 0; a < terms; a++) {
                    if (data[a].row == i) {
                        for (int b = 0; b < s.terms; b++) {
                            if (s.data[b].row == data[a].col && s.data[b].col == j) {
                                sum += data[a].val * s.data[b].val;
                            }
                        }
                    }
                }
                if (sum != 0) {
                    temp[k].row = i;
                    temp[k].col = j;
                    temp[k].val = sum;
                    k++;
                }
            }
        }
        Sparse result(rows, s.cols, k);
        for (int x = 0; x < k; x++) result.data[x] = temp[x];
        return result;
    }
};

int main() {
    int r, c, t;

    cout << "Enter rows, cols, and non-zero terms for Matrix A: ";
    cin >> r >> c >> t;
    Sparse A(r, c, t);
    A.input();

    cout << "\nMatrix A (Triplet form):\n";
    A.display();

    cout << "\nTranspose of A:\n";
    Sparse AT = A.transpose();
    AT.display();

    cout << "\nEnter rows, cols, and non-zero terms for Matrix B: ";
    cin >> r >> c >> t;
    Sparse B(r, c, t);
    B.input();

    cout << "\nMatrix B (Triplet form):\n";
    B.display();

    cout << "\nA + B:\n";
    Sparse C = A.add(B);
    C.display();

    cout << "\nA * B:\n";
    Sparse D = A.multiply(B);
    D.display();

    return 0;
}
