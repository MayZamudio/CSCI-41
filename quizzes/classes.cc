    #include <iostream>
    #include <cmath>
    #include <algorithm>
    #include <vector>
    using namespace std;
    //PODS
    class SSN_Record {
        public:
            long long SSN = 0;
            string name, address;
            vector<double> income_history;
    };
  
    int main() {
        vector<SSN_Record> vec;
        while (true) {
            cout << "Please enter a SSN, name, and address to add to our database:\n";
            long long SSN;
            string name, address;
            cin >> SSN >> name >> address;
            if (!SSN) break; //Break if SSN is 0
            SSN_Record temp = {SSN,name,address};
			vec.push_back(temp);
        }
        cout << "Please enter a record number to look up:\n";
        size_t index = 0;
        cin >> index;
        cout << "SSN: " << vec.at(index).SSN << endl;
        cout << "Name: " << vec.at(index).name << endl;
        cout << "Address: " << vec.at(index).address << endl;
    }
