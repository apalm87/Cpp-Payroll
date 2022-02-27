#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "payroll_record.h"

using namespace std;

int main() {

    //setting array size
    const int kMaxSize = 32;

    //variable for file name
    std::string file_name;

    //user input
    cout << "Please type in file name\n";
    cin >> file_name;
    cout << endl;

    //read from file
    ifstream input ("../../" + file_name);

    //if file doesn't exist
    if (input.fail()){
        cout << "Unable to open file. Closing program.\n";

        return 1;
    }

    //input file array
    array<PayrollRecord, kMaxSize> payroll_array;

    //read data from input file
    int index = 0;
    double hours, pay_rate;
    std::string name;
    while (index <= kMaxSize && input >> hours){
        input >> pay_rate;
        input.ignore();
        getline(input, name);

        //store in an array
        payroll_array[index] = PayrollRecord(hours,pay_rate,name);

        index ++;
    }

    //close file
    input.close();

    ofstream data ("../../payroll_data.txt");
    for (int i =0; i < index; i++){
        payroll_array[i].WriteData(data);
    }


    ofstream report ("../../payroll_report.txt");
    for (int j = 0; j < index; j++){
        payroll_array[j].WriteReport(report);
    }



  return 0;
}
