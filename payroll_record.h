#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>

class PayrollRecord{
public:
    //default constructor
    PayrollRecord() {hours_ = 0, pay_rate_ = kMinimumWage,
                     first_name_ = "it is", last_name_ = "unknown";}

    //non-default constructor
    PayrollRecord(double hours, double pay_rate, std::string name);

    //Destructor
    ~PayrollRecord(){};

    //public static members
    static const double kMinimumWage;
    static const double kRegularHours;
    static const double kOvertimeRate;

    //Getters
    //set to const since none of them will make changes to the actual object
    double get_hours() const {return hours_;}
    double get_pay_rate() const {return pay_rate_;}
    std::string get_first_name() const {return first_name_;}
    std::string get_last_name() const{return last_name_;}

    //Setters
    void set_hours(double hours);
    void set_pay_rate(double pay_rate);
    void set_name(std::string name);

    //method for weekly payroll
    double ComputeGross() const;

    //writing methods
    void WriteData(std::ostream &out) const;
    void WriteReport(std::ostream &out) const;

//private data members
private:
    double hours_;
    double pay_rate_;
    std::string first_name_; //may contain first and middle
    std::string last_name_;//only last, no spaces
};



#endif