#include <iostream>
#include <iomanip>
#include "payroll_data.h"

using namespace std;

/**
 * @brief method that sets pay rate
 * @param pay_rate - sent double value of pay rate
 */
void PayrollData::set_pay_rate(double pay_rate){
    if (pay_rate >= 0){
        pay_rate_ = pay_rate;
    } else {
        pay_rate_ = 0;
    }
}

/**
 * @brief set_name - parameter for setting name
 * @param name - sent string of an employees name
 */
void PayrollData::set_name(std::string name){
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

/**
 * @brief PayrollData non default constructor
 * @param pay_rate - sent double value of pay rate
 * @param name -sent string value of name
 */
PayrollData::PayrollData(double pay_rate, std::string name){
    set_pay_rate(pay_rate);
    set_name(name);
}
