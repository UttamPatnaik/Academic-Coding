#!/bin/bash
echo -n "Enter basic salary: "
read basic
da=$((basic * 40 / 100))
hra=$((basic * 30 / 100))
gross=$((basic + da + hra))
echo "Basic Salary: $basic"
echo "Dearness Allowance (40%): $da"
echo "House Rent Allowance (30%): $hra"
echo "Gross Salary: $gross"
