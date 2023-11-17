# Input: Employee Name and Gross Amount
import pyflowchart
employee_name = input("Enter Employee Name: ")
gross_amount = float(input("Enter Gross Amount: $"))

# Calculate various deductions
federal_income_tax = gross_amount * 0.15
state_tax = gross_amount * 0.035
social_security_tax = gross_amount * 0.0575
medicare_medicaid_tax = gross_amount * 0.0275
pension_plan = gross_amount * 0.05
health_insurance = 75.00  # Fixed amount

# Calculate total deductions
total_deductions = (
    federal_income_tax + state_tax + social_security_tax +
    medicare_medicaid_tax + pension_plan + health_insurance
)

# Calculate net pay
net_pay = gross_amount - total_deductions

# Display the paycheck details
print("Employee Name:", employee_name)
print(f"Gross Amount: ${gross_amount:.2f}")
print(f"Federal Income Tax Deduction: ${federal_income_tax:.2f}")
print(f"State Tax Deduction: ${state_tax:.2f}")
print(f"Social Security Tax Deduction: ${social_security_tax:.2f}")
print(f"Medicare/Medicaid Tax Deduction: ${medicare_medicaid_tax:.2f}")
print(f"Pension Plan Deduction: ${pension_plan:.2f}")
print(f"Health Insurance Deduction: ${health_insurance:.2f}")
print(f"Total Deductions: ${total_deductions:.2f}")print(f"Net Pay: ${net_pay:.2f}")
