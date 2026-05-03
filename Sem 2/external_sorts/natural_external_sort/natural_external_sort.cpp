#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int toInt(const string& s) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (s[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; i < (int)s.size(); i++) {
        result = result * 10 + (s[i] - '0');
    }

    return result * sign;
}

void printFile() {
    fstream A;
    A.open("A.txt", ios::in);

    int x;

    while (A >> x) {
        cout << x << ' ';
    }

    cout << endl;

    A.close();
}

int splitFile(fstream& A, fstream& B, fstream& C) {
    int segments = 0;
    bool flag = true;

    A.close();
    A.open("A.txt", ios::in);

    B.close();
    B.open("B.txt", ios::out);

    C.close();
    C.open("C.txt", ios::out);

    int current_elem;
    int previous_elem;

    if (!(A >> previous_elem)) {
        return 0;
    }

    segments = 1;

    if (flag) {
        B << previous_elem << ' ';
    } else {
        C << previous_elem << ' ';
    }

    while (A >> current_elem) {
        if (current_elem < previous_elem) {
            if (flag) {
                B << "/ ";
            } else {
                C << "/ ";
            }

            flag = !flag;
            segments++;
        }

        if (flag) {
            B << current_elem << ' ';
        } else {
            C << current_elem << ' ';
        }

        previous_elem = current_elem;
    }

    if (flag) {
        B << "/ ";
    } else {
        C << "/ ";
    }

    return segments;
}

void Merge(fstream& A, fstream& B, fstream& C) {
    A.close();
    A.open("A.txt", ios::out);

    B.close();
    B.open("B.txt", ios::in);

    C.close();
    C.open("C.txt", ios::in);

    string elementB;
    string elementC;

    bool flagB = static_cast<bool>(B >> elementB);
    bool flagC = static_cast<bool>(C >> elementC);

    while (flagB || flagC) {
        while ((flagB && elementB != "/") || (flagC && elementC != "/")) {
            bool takeFromB = false;

            if (!flagB || elementB == "/") {
                takeFromB = false;
            }
            else if (!flagC || elementC == "/") {
                takeFromB = true;
            }
            else {
                if (toInt(elementB) <= toInt(elementC)) {
                    takeFromB = true;
                } else {
                    takeFromB = false;
                }
            }

            if (takeFromB) {
                A << elementB << ' ';
                flagB = static_cast<bool>(B >> elementB);
            } else {
                A << elementC << ' ';
                flagC = static_cast<bool>(C >> elementC);
            }
        }

        if (flagB && elementB == "/") {
            flagB = static_cast<bool>(B >> elementB);
        }

        if (flagC && elementC == "/") {
            flagC = static_cast<bool>(C >> elementC);
        }
    }
}

void naturalExternalSort(fstream& A, fstream& B, fstream& C) {
    int segments = -1;

    while (segments != 1) {
        segments = splitFile(A, B, C);

        if (segments != 1) {
            Merge(A, B, C);
        }
    }
}

int main() {
    int n;

    cout << "Enter number count: ";
    cin >> n;

    fstream A, B, C;

    A.open("A.txt", ios::out);

    for (int i = 0; i < n; i++) {
        int elem = rand() % 101;
        A << elem << ' ';
    }

    A.close();

    cout << "Before sorting:" << endl;
    printFile();

    naturalExternalSort(A, B, C);

    cout << "After sorting:" << endl;
    printFile();

    A.close();
    B.close();
    C.close();

    return 0;
}