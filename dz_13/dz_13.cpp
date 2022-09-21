#include <iostream>

#include "var.h"

using namespace std;

int main()
{
    var test_1 = "1str", test_2 = 52, test_3 = 5.2;

    cout << test_1 + test_2 << endl;
    cout << test_3 + test_2 << endl;

    cout << test_1 - test_2 << endl;
    cout << test_3 - test_2 << endl;

    test_1 += test_2;
    test_3 += test_2;

    test_1 -= test_2;
    test_3 -= test_2;
}