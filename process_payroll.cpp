#include <iostream>
#include "process_payroll.h"
#include <fstream>
#include <string>
#include <vector>
#include "commission_payroll.h"
#include "hourly_payroll.h"
#include "payroll_data.h"
#include "salary_payroll.h"

/**
 * @brief ProcessPayroll- Method that takes two string parameters, reads from
 * input, and writes to output
 * @param inputFile
 * @param outputFile
 */
void ProcessPayroll(std::string inputFile, std::string outputFile){
    //If file is not found
    std::ifstream in(inputFile);
    if (in.fail()){
        std::cout << "Unable to open file" << std::endl;
        return;
    }
    std::vector<PayrollData*> payroll_data_1;

    //values
    std::string type;
    double pay_rate;
    double hours;
    int how_many;
    double base_pay;
    std::string name;

    //while loop with nested if statements to read the input file
    while (in >> type){
        if (type == "H"){
            in >> hours;
            in >> pay_rate;
            in.ignore();
            std::getline(in,name);
            payroll_data_1.push_back(new HourlyPayroll(hours, pay_rate, name));

        } else if (type == "S"){
            in >> pay_rate;
            in.ignore();
            std::getline(in,name);
            payroll_data_1.push_back(new SalaryPayroll(pay_rate, name));
        } else if (type == "C"){
            in >> pay_rate;
            in >> how_many;
            in >> base_pay;
            in.ignore();
            std::getline(in,name);
            payroll_data_1.push_back(new CommissionPayroll(pay_rate,how_many,base_pay, name));
        }
    }

    //range for loop to write data to output file
    std::ofstream out(outputFile);
    for(PayrollData* one_ptr: payroll_data_1){
        one_ptr->WriteReport(out);
    }

    //range for loop to delete each data, and replace with NULL
    for(PayrollData* &one_ptr: payroll_data_1){
        delete one_ptr;
        one_ptr = NULL;
    }


}