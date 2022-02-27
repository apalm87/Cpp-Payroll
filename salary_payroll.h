#ifndef SALARY_PAYROLL_H
#define SALARY_PAYROLL_H
#include "payroll_data.h"

/**
 * @brief SalaryPayroll sub class
 */
class SalaryPayroll : public PayrollData{
private:

public:
    //constructors and destructor
    SalaryPayroll(){pay_rate_ = 0, first_name_ = "it is", last_name_ = "unknown";}
    SalaryPayroll(double pay_rate, std::string name);
    ~SalaryPayroll(){};

    //other methods
    double ComputeGross() const {return pay_rate_;}
    void WriteData(std::ostream &out) const;
    void WriteReport(std::ostream &out) const;


};

#endif