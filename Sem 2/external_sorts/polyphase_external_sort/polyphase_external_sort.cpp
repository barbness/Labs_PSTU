#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string SEP = "/";

int strToInt(const string& s) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (s.size() > 0 && s[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; i < (int)s.size(); i++) {
        result = result * 10 + (s[i] - '0');
    }

    return result * sign;
}

int countSeries(const string& filename) {
    ifstream file(filename.c_str());

    int last;
    int current;

    if (!(file >> last)) {
        return 0;
    }

    int count = 1;

    while (file >> current) {
        if (current < last) {
            count++;
        }

        last = current;
    }

    return count;
}

bool writeNaturalSeries(ifstream& source, ofstream& out, int& current, bool& hasCurrent) {
    if (!hasCurrent) {
        if (!(source >> current)) {
            return false;
        }

        hasCurrent = true;
    }

    int last = current;
    out << current << ' ';

    int next;

    while (source >> next) {
        if (next >= last) {
            out << next << ' ';
            last = next;
        } else {
            current = next;
            hasCurrent = true;
            out << SEP << ' ';
            return true;
        }
    }

    hasCurrent = false;
    out << SEP << ' ';

    return true;
}

void distribute(
    const string& sourceName,
    const string& file1Name,
    const string& file2Name,
    int file1Series,
    int file2Series,
    int realSeries
) {
    ifstream source(sourceName.c_str());
    ofstream file1(file1Name.c_str());
    ofstream file2(file2Name.c_str());

    int dummy = file1Series + file2Series - realSeries;

    while (dummy > 0 && file1Series > 0) {
        file1 << SEP << ' ';
        file1Series--;
        dummy--;
    }

    while (dummy > 0 && file2Series > 0) {
        file2 << SEP << ' ';
        file2Series--;
        dummy--;
    }

    int current = 0;
    bool hasCurrent = false;

    for (int i = 0; i < file1Series; i++) {
        writeNaturalSeries(source, file1, current, hasCurrent);
    }

    for (int i = 0; i < file2Series; i++) {
        writeNaturalSeries(source, file2, current, hasCurrent);
    }
}

bool readSeriesValue(ifstream& file, int& value) {
    string token;

    if (!(file >> token)) {
        return false;
    }

    if (token == SEP) {
        return false;
    }

    value = strToInt(token);
    return true;
}

void mergeOneSeries(ifstream& file1, ifstream& file2, ofstream& out) {
    int x;
    int y;

    bool hasX = readSeriesValue(file1, x);
    bool hasY = readSeriesValue(file2, y);

    while (hasX && hasY) {
        if (x <= y) {
            out << x << ' ';
            hasX = readSeriesValue(file1, x);
        } else {
            out << y << ' ';
            hasY = readSeriesValue(file2, y);
        }
    }

    while (hasX) {
        out << x << ' ';
        hasX = readSeriesValue(file1, x);
    }

    while (hasY) {
        out << y << ' ';
        hasY = readSeriesValue(file2, y);
    }

    out << SEP << ' ';
}

void copyWithoutSeparators(const string& from, const string& to) {
    ifstream input(from.c_str());
    ofstream output(to.c_str());

    string token;

    while (input >> token) {
        if (token != SEP) {
            output << token << ' ';
        }
    }
}

void polyphaseSort(const string& filename) {
    string names[3] = {
        "A.txt",
        "B.txt",
        "C.txt"
    };

    int realSeries = countSeries(filename);

    if (realSeries <= 1) {
        return;
    }

    int firstSeries = 1;
    int secondSeries = 1;

    while (firstSeries + secondSeries < realSeries) {
        int temp = firstSeries;
        firstSeries = firstSeries + secondSeries;
        secondSeries = temp;
    }

    distribute(
        filename,
        names[1],
        names[2],
        firstSeries,
        secondSeries,
        realSeries
    );

    int series[3];

    series[0] = 0;
    series[1] = firstSeries;
    series[2] = secondSeries;

    ifstream readers[3];

    readers[1].open(names[1].c_str());
    readers[2].open(names[2].c_str());

    while (true) {
        int nonEmpty = 0;
        int resultIndex = -1;

        for (int i = 0; i < 3; i++) {
            if (series[i] > 0) {
                nonEmpty++;
                resultIndex = i;
            }
        }

        if (nonEmpty == 1 && series[resultIndex] == 1) {
            break;
        }

        int outIndex = -1;
        int in1 = -1;
        int in2 = -1;

        for (int i = 0; i < 3; i++) {
            if (series[i] == 0) {
                outIndex = i;
            } else if (in1 == -1) {
                in1 = i;
            } else {
                in2 = i;
            }
        }

        int mergeCount;

        if (series[in1] < series[in2]) {
            mergeCount = series[in1];
        } else {
            mergeCount = series[in2];
        }

        ofstream out(names[outIndex].c_str());

        for (int i = 0; i < mergeCount; i++) {
            mergeOneSeries(readers[in1], readers[in2], out);
        }

        out.close();

        readers[outIndex].clear();
        readers[outIndex].open(names[outIndex].c_str());

        series[in1] -= mergeCount;
        series[in2] -= mergeCount;
        series[outIndex] = mergeCount;

        if (series[in1] == 0) {
            readers[in1].close();
            readers[in1].clear();
        }

        if (series[in2] == 0) {
            readers[in2].close();
            readers[in2].clear();
        }
    }

    for (int i = 0; i < 3; i++) {
        if (readers[i].is_open()) {
            readers[i].close();
        }
    }

    int resultIndex = -1;

    for (int i = 0; i < 3; i++) {
        if (series[i] == 1) {
            resultIndex = i;
        }
    }

    if (resultIndex == 0) {
        copyWithoutSeparators(names[0], "TMP_RESULT.txt");
        copyWithoutSeparators("TMP_RESULT.txt", filename);
    } else {
        copyWithoutSeparators(names[resultIndex], filename);
    }
}

int main() {
    string filename = "A.txt";

    ofstream input(filename.c_str());

    int n;

    cout << "Enter amount of numbers: ";
    cin >> n;

    cout << "Enter numbers:" << endl;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input << x << ' ';
    }

    input.close();

    cout << "Before sorting:" << endl;

    ifstream before(filename.c_str());
    int x;

    while (before >> x) {
        cout << x << ' ';
    }

    before.close();

    cout << endl;

    polyphaseSort(filename);

    cout << "After sorting:" << endl;

    ifstream after(filename.c_str());

    while (after >> x) {
        cout << x << ' ';
    }

    after.close();

    cout << endl;

    return 0;
}