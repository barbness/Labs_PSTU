#include "Dialog.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    Dialog dialog;
    dialog.Execute();

    return 0;
}