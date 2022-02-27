#ifndef COMMISSION_PAYROLL_H
#define COMMISSION_PAYROLL_H
#include "payroll_data.h"

/**
 * @brief ComissionPayroll sub class
 */
class CommissionPayroll: public PayrollData{
private:
    int how_many_;
    double base_rate_;

public:
    //constructors and destructor
    CommissionPayroll(){pay_rate_ = 0, first_name_ = "it is", last_name_ = "unknown",
                        how_many_ = 0, base_rate_ = 0;}
    CommissionPayroll(double pay_rate, int how_many, double base_pay,
                      std::string name);
    ~CommissionPayroll(){};

    //getters
    int get_how_many() const {return how_many_;}
    double get_base_pay()const {return base_rate_;}

    //setters
    void set_how_many(int how_many);
    void set_base_pay(double base_pay);

    //other methods
    double ComputeCommission() const;
    double ComputeGross() const;
    void WriteData(std::ostream &out) const;
    void WriteReport(std::ostream &out) const;

};

#endif