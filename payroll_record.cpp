#include <iostream>
#include <iomanip>
#include "payroll_record.h"

using namespace std;

//setting public static members
const double PayrollRecord::kMinimumWage = 7.25;
const double PayrollRecord::kRegularHours = 40;
const double PayrollRecord::kOvertimeRate = 1.5;

//method for payroll hours
void PayrollRecord::set_hours(double hours) {
    if (hours >= 0 && hours <= 168 ){
        hours_ = hours;
    } else {
        hours_ = 0;
    }
}

//method for pay rate
void PayrollRecord::set_pay_rate(double pay_rate) {
    if (pay_rate >= kMinimumWage){
        pay_rate_ = pay_rate;
    } else {
        pay_rate_ = kMinimumWage;
    }
}

//method for name
void PayrollRecord::set_name(std::string name) {

    //local variables
    int comma = name.find(",");
    int space = name.find_last_of(' ');

    //first if statement find the last name, first name format, and sets first
    //and last name variables
    if (comma != std::string::npos) {
        last_name_ = name.substr(0, comma);
        first_name_ = name.erase(0, comma + 2);
    }
    //else statement to take first name last name format and sets first and last
    //name variables
    else {
        last_name_ = name.substr(space + 1, name.length());
        first_name_ = name.substr(0, space);
    }
}

//non constructor
PayrollRecord::PayrollRecord(double hours, double pay_rate, std::string name) {
    set_hours(hours);
    set_pay_rate(pay_rate);
    set_name(name);
}

//method for gross pay
double PayrollRecord::ComputeGross() const {
    double gross_pay;
    double overtime_hours;

    if (hours_ >= kRegularHours){
        overtime_hours = hours_ - kRegularHours;
        gross_pay = (kRegularHours * pay_rate_)
                + (overtime_hours * pay_rate_ * kOvertimeRate);
    } else {
        gross_pay = hours_ * pay_rate_;
    }

    return gross_pay;
}

//payroll data, name format is last, first
void PayrollRecord::WriteData(std::ostream &out) const {

    out << fixed << setprecision(2)
    << hours_ << " " << pay_rate_ << " "<< ComputeGross() << "\n"
    << last_name_ << ", " << first_name_ << "\n";
}

//payroll report, name format first name last name
void PayrollRecord::WriteReport(std::ostream &out) const {

    out << fixed << setprecision(2)
        << first_name_ << " " << last_name_ << "\n"
        << "   " << "Hours Worked: " << hours_ << "\n"
        << "   " << "Pay Rate: $" << pay_rate_ << "\n"
        << "   " << "Gross Pay: $" << ComputeGross() << "\n";
}