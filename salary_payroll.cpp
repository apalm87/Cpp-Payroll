#include <iostream>
#include <iomanip>
#include "salary_payroll.h"

/**
 * @brief: SalaryPayroll default constructor
 * @param pay_rate - parameter value of sent pay
 * @param name  - parameter value of sent name
 */
SalaryPayroll::SalaryPayroll(double pay_rate, std::string name){
    set_pay_rate(pay_rate);
    set_name(name);
}

/**
 * @bried: Write Data - writes Salary information
 * @param out - writes the data
 */
void SalaryPayroll::WriteData(std::ostream &out) const{

    out << std::fixed << std::setprecision(2)
        << "S " << ComputeGross()
        << "\n" << last_name_ << ", " << first_name_ << "\n";
}

/**
 * Write Data - writes Salary report
 * @param out - writes the data
 */
void SalaryPayroll::WriteReport(std::ostream &out) const{

    out << std::fixed << std::setprecision(2)
        << first_name_ << " " << last_name_ << "\n"
        << "   " << "Pay Rate: $" << pay_rate_ << "\n"
        << "   " << "Gross Pay: $" << ComputeGross() << "\n";
}