#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int number = 0;
        cin >> number;

        string number_str = to_string(number);
        string number_high(number_str);
        string number_low(number_str);

        for (int i = 0; i < number_str.size() - 1; i++) {
            for (int j = i + 1; j < number_str.size(); j++) {
                string temp(number_str);
                if (i == 0 && temp[j] == '0') continue;
                char temp_c = temp[i];
                temp[i] = temp[j];
                temp[j] = temp_c;
                if (temp > number_high) {
                    number_high = temp;
                }
                if (temp < number_low) {
                    number_low = temp;
                }
            }
        }

        cout << '#' << test_case << ' ' << stoi(number_low) << ' ' << stoi(number_high) << '\n';

    }
    return 0;
}