#include <iostream>
#include <string>
#include "payroll_data.h"
#include "hourly_payroll.h"
#include "salary_payroll.h"
#include "commission_payroll.h"
#include "process_payroll.h"

using namespace std;

int main() {
  // create HourlyPayroll objects and use the associated methods
  cout << "The HourlyPayroll class demonstration.\n";

  // Create HourlyPayroll objects using the default and non-default
  // constructors.
  HourlyPayroll payroll1;
  HourlyPayroll payroll2 (40, 15.0, "Bruce Wayne");

  // Use the HourlyPayroll objects to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  payroll1.set_name("Barry Allen");
  payroll1.set_hours(50);
  payroll1.set_pay_rate(20.0);

  cout << payroll1.get_first_name() << endl;
  cout << payroll1.get_last_name() << endl;
  cout << payroll1.get_hours() << endl;
  cout << payroll1.get_pay_rate() << endl;

  cout << payroll2.get_first_name() << endl;
  cout << payroll2.get_last_name() << endl;
  cout << payroll2.get_hours() << endl;
  cout << payroll2.get_pay_rate() << endl;

  // Use the HourlyPayroll objects to call the ComputeGross method. Print
  // out the results to see that the method is doing what is expected.
  cout << payroll1.ComputeGross() << endl;
  cout << payroll2.ComputeGross() << endl;

  // Use the HourlyPayroll objects to call the WriteData and WriteReport
  // methods to see they are working as expected.
  payroll1.WriteData(cout);
  payroll2.WriteData(cout);
  payroll1.WriteReport(cout);
  payroll2.WriteReport(cout);

  // create SalaryPayroll objects and use the associated methods
  cout << "The SalaryPayroll class demonstration.\n";

  // Create SalaryPayroll objects using the default and non-default
  // constructors.
  SalaryPayroll salary1;
  SalaryPayroll salary2 (1995.50, "Clark Kent");

  // Use the SalaryPayroll objects to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // Notice that the SalaryPayroll does not define any new getters and
  // setters but still use the ones that are defined in the PayrollData class.
  salary1.set_pay_rate(2222);
  salary1.set_name("Arthur Curry");

  cout << salary1.get_first_name() << endl;
  cout << salary1.get_last_name() << endl;
  cout << salary1.get_pay_rate() << endl;

  cout << salary2.get_first_name() << endl;
  cout << salary2.get_last_name() << endl;
  cout << salary2.get_pay_rate() << endl;

  // Use the SalaryPayroll objects to call the ComputeGross method. Print
  // out the results to see that the method is doing what is expected.
  cout << salary1.ComputeGross() << endl;
  cout << salary2.ComputeGross() << endl;

  // Use the SalaryPayroll objects to call the WriteData and WriteReport
  // methods to see they are working as expected.
  salary1.WriteData(cout);
  salary1.WriteReport(cout);
  salary2.WriteData(cout);
  salary2.WriteReport(cout);

  // create CommissionPayroll objects and use the associated methods
  cout << "The CommissionPayroll class demonstration.\n";

  // Create CommissionPayroll objects using the default and non-default
  // constructors.
  CommissionPayroll com1;
  CommissionPayroll com2 (41.80, 12, 880, "Victor Stone");

  // Use the CommissionPayroll objects to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  com1.set_pay_rate(50.25);
  com1.set_how_many(20);
  com1.set_base_pay(900);
  com1.set_name("Diana Prince");

  cout << com1.get_first_name() << endl;
  cout << com1.get_last_name() << endl;
  cout << com1.get_pay_rate() << endl;
  cout << com1.get_how_many() << endl;
  cout << com1.get_base_pay() << endl;

  cout << com2.get_first_name() << endl;
  cout << com2.get_last_name() << endl;
  cout << com2.get_pay_rate() << endl;
  cout << com2.get_how_many() << endl;
  cout << com2.get_base_pay() << endl;

  // Use the CommissionPayroll objects to call the ComputeCommission method.
  //  Print out the results to see that the method is doing what is expected.
  cout << com1.ComputeCommission() << endl;
  cout << com2.ComputeCommission() << endl;

  // Use the CommissionPayroll objects to call the ComputeGross method. Print
  // out the results to see that the method is doing what is expected.
  cout << com1.ComputeGross() << endl;
  cout << com2.ComputeGross() << endl;

  // Use the CommissionPayroll objects to call the WriteData and WriteReport
  // methods to see they are working as expected.
  com1.WriteData(cout);
  com1.WriteReport(cout);
  com2.WriteData(cout);
  com2.WriteReport(cout);

  // run the ProcessPayroll function
  cout << "The ProcessPayroll function.\n";

  // In main, call the  ProcessPayroll function.
  // See that it is producing the expected report.

  string input = "../../payroll_week23.txt";
  string output = "../../payroll_out.txt";
  ProcessPayroll(input, output);


  return 0;
}