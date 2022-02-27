#ifndef HOURLY_PAYROLL_H
#define HOURLY_PAYROLL_H
#include "payroll_data.h"

/**
 * @brief HourlyPayroll sub class
 */
class HourlyPayroll : public PayrollData{
private:
    double hours_;

public:
    //static constant data members
    static const double kMinHours;
    static const double kMaxHours;
    static const double kRegularHours;
    static const double kOvertimeRate;
    static const double kMinWage;

    //constructors and destructor
    HourlyPayroll(){pay_rate_ = kMinWage, hours_ = kMinHours;}
    HourlyPayroll(double hours_worked, double pay_rate, std::string name);
    ~HourlyPayroll(){};

    //getter
    double get_hours() const {return hours_;}

    //setters
    void set_pay_rate(double pay_rate);
    void set_hours(double hours_worked);

    double ComputeGross() const;
    void WriteData(std::ostream &out) const;
    void WriteReport(std::ostream &out) const;

};

#endif