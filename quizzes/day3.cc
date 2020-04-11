#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void generate_name(string *target) {
    *target = "Bob";
}

int main () {
    string *names;
    cout << "How many random names do you want to make?" << endl;
    size_t count = 0;
    cin>> count;
    names = new string[count];
    // for (auto it = vec.begin(); it !=vec.end;it++)

    // for (int i = 0; i < 16; i++)
        //cout << *temp << endl;

    // Berkeley - range based for loop
    for (string *temp = names; temp < (names+count); temp++)
        generate_name(temp);
    if (count > 2)
        cout << names[2] << endl;
    delete[] names;
}
