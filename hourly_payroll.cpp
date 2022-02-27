#include <iostream>
#include <iomanip>
#include "hourly_payroll.h"

using namespace std;

/**
 * @brief Public static members
 */
const double HourlyPayroll::kMinHours = 0;
const double HourlyPayroll::kMaxHours = 168;
const double HourlyPayroll::kRegularHours = 40;
const double HourlyPayroll::kOvertimeRate = 1.5;
const double HourlyPayroll::kMinWage = 7.25;

/**
 * @brief set_pay_rate method- method that sets pay_rate_ to the parameter
 * pay_rate. if payrate is greater than kMinWage, set pay_rate_ to pay_rate.
 * else set pay_rate_ equal to kMinWage
 * @param pay_rate - sent pay_rate value parameter
 */
void HourlyPayroll::set_pay_rate(double pay_rate){
    if (pay_rate >= kMinWage){
        pay_rate_ = pay_rate;
    } else{
        pay_rate_ = kMinWage;
    }
}

/**
 * @brief set_hours- Method that sets hours. if parameter hours is less than
 * kMinHours, hours_ equals to kMinHours. Else if hours is greater than
 * kMaxHours, set hours_ to kMaxHours
 * @param hours - sent parameter number of hours
 */
void HourlyPayroll::set_hours(double hours){
    hours_ = hours;
    if (hours < kMinHours ){
        hours_ = kMinHours;
    } else if (hours > kMaxHours) {
        hours_ = kMaxHours;
    }
}

/**
 * @brief HourlyPayroll - non default constructor
 * @param hours_worked - sent double parameter of hours worked
 * @param pay_rate - sent double parameter of pay_rate
 * @param name - sent string parameter of string
 */
HourlyPayroll::HourlyPayroll(double hours_worked, double pay_rate,
                             std::string name){
    set_hours(hours_worked);
    set_pay_rate(pay_rate);
    set_name(name);
}

/**
 * @brief Compute Gross - Method that calculates gross pay
 * @return gross pay
 */
double HourlyPayroll::ComputeGross() const{
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

/**
 * @brief WriteData method that writes data for hourly payroll
 * @param out
 */
void HourlyPayroll::WriteData(std::ostream &out) const{
    out << fixed << setprecision(2)
        << "H " << hours_ << " " << pay_rate_ << " "<< ComputeGross()
        << "\n" << last_name_ << ", " << first_name_ << "\n";
}

/**
 * @brief WriteReport - Method that writes reports for hourlypayroll
 * @param out
 */
void HourlyPayroll::WriteReport(std::ostream &out) const{
    out << fixed << setprecision(2)
        << first_name_ << " " << last_name_ << "\n"
        << "   " << "Hours Worked: " << hours_ << "\n"
        << "   " << "Pay Rate: $" << pay_rate_ << "\n"
        << "   " << "Gross Pay: $" << ComputeGross() << "\n";
}

