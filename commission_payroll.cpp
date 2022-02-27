#include <iostream>
#include <iomanip>
#include "commission_payroll.h"

/**
 * @brief setter to set the value of how_many_. If how_many_ is
 * less than 0, how_many_ will be set to equal to 0.
 * @param how_many" the parameter value sent to set how_many.
 */
void CommissionPayroll::set_how_many(int how_many){
    how_many_ = how_many;
    if (how_many_ < 0){
        how_many_ = 0;
    }
}

/**
 * @brief setter to set the value of base_rate_. If base_rate_ is
 * less than 0, base_rate_ will be set to equal to 0.
 * @param base_pay" the parameter value sent to set base_rate_.
 */
void CommissionPayroll::set_base_pay(double base_pay){
    base_rate_ = base_pay;
    if (base_rate_ < 0){
        base_rate_ = 0;
    }

}

/**
 * @brief: CommissionPayroll default constructor
 * @param pay_rate: parameter value of sent pay rate
 * @param how_many: parameter value of sent how many
 * @param base_pay: parameter value of sent base pay
 * @param name: paramet value of sent name
 */
CommissionPayroll::CommissionPayroll(double pay_rate, int how_many,
                                     double base_pay, std::string name){
    set_pay_rate(pay_rate);
    set_how_many(how_many);
    set_base_pay(base_pay);
    set_name(name);
}

/**
 * @brief ComputeComission: method that returns the total value by
 * pay_rate * how_many_
 * @return total: the value that is equal to pay_rate * how_many.
 */
double CommissionPayroll::ComputeCommission() const{
    double total = pay_rate_ * how_many_;
    return total;
}

/**
 * @brief ComputeCross - method with no sent parameters that calculates total
 * gross pay
 * @return gross_pay
 */
double CommissionPayroll::ComputeGross() const{
    double gross_pay;
    gross_pay = base_rate_ + ComputeCommission();

    return gross_pay;
}

/**
 * @bried: Write Data - writes Comission information
 * @param out - writes the data
 */
void CommissionPayroll::WriteData(std::ostream &out) const{

    out << std::fixed << std::setprecision(2)
        << "C " << pay_rate_ << " " << how_many_ << " " << base_rate_ << " "
        << ComputeGross() << "\n" << last_name_ << ", " << first_name_ << "\n";
}

/**
 * Write Data - writes Comission report
 * @param out - writes the data
 */
void CommissionPayroll::WriteReport(std::ostream &out) const{

    out << std::fixed << std::setprecision(2)
        << first_name_ << " " << last_name_ << "\n"
        << "   " << "Pay Rate: $" << pay_rate_ << "\n"
        << "   " << "How Many: " << how_many_ << "\n"
        << "   " << "Commission: $" << ComputeCommission() << "\n"
        << "   " << "Base Pay: $" << base_rate_ << "\n"
        << "   " << "Gross Pay: $" << ComputeGross() << "\n";
}



