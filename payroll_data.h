#ifndef PAYROLL_DATA_H
#define PAYROLL_DATA_H

#include <string>

/**
 * @brief PayrollData: Base Class. Pure virtual, unable to create PayrollData
 * objects.
 */
class PayrollData{
//protected data members, acts like private data members, but sub classes
// can access
protected:
    double pay_rate_;
    std::string first_name_; //may contain first and middle
    std::string last_name_;//only last, no spaces

public:
    //Constructors and Destructor
    PayrollData() {pay_rate_ = 0, first_name_ = "it is", last_name_ = "unknown";}
    PayrollData(double pay_rate, std::string name);
    ~PayrollData(){};

    //Getters
    double get_pay_rate() const {return pay_rate_;}
    std::string get_first_name() const {return first_name_;}
    std::string get_last_name() const{return last_name_;}

    //Setters
    void set_pay_rate(double pay_rate);
    void set_name(std::string name);

    //pure virtual method declarations
    virtual double ComputeGross() const = 0;
    virtual void WriteData(std::ostream &out) const = 0;
    virtual void WriteReport(std::ostream &out) const = 0;
};

#endif