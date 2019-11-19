#include <iostream>
#include "height.h"

using namespace std;

int main()
{
    Height h(5, 10);
    cout << "Height h is " << h.toString() << endl;
    h.add(2);
    cout << "Height h is " << h.toString() << endl;
    h.setHeight(4, 11);
    cout << "Height h is " << h.toString() << endl;
    return 0;
}
