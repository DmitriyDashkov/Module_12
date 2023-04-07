#include <iostream>
#include <string>
#include <exception>
using namespace std;

bool IsKPeriodic(string str, size_t k)
{
    if(!str.empty() && k>0) {
        string subStr{""};          //подстрока длиной К
        for(size_t i=0; i<k; ++i)
            subStr.push_back(str.at(i));

        if(str.length() % k) return false;

        for(size_t i=0; i<str.length()-k; i+=k) {
            if(str.substr(i, k)!=subStr)
                return false;
        }
        return true;
    }
    else if(k==0) throw 1;
    throw 2;
}

int main()
{
    string str = "khfcwhcjkwh"
                 "khfcwhcjkwh"
                 "khfcwhcjkwh"
                 "khfcwhcjkwh"
                 "khfcwhcjkwh"
                 "khfcwhcjkwh"
                 "khfcwhcjkwh"
                 "khfcwhcjkwh";
    size_t k = 11;
    try {
        if (IsKPeriodic(str, k))
            cout << "String " << endl << str << endl
                 << "HAS multiplicity equal to " << k << endl;

        else
            cout << "String " << endl << str << endl
                 << "does NOT have multiplicity equal to " << k << endl;
    }
    catch (int a) {
        switch (a) {
        case 1 :
            cout << "K cannot be zero!" << endl;
            break;
        case 2:
            cout << "Empty line!" << endl;
            break;
        }
    }
    return 0;
}
