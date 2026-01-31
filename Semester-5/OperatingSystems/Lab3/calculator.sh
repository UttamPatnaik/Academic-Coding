#!/bin/bash
if [ $# -ne 3 ]; then
    echo "Invalid input"
    echo "Enter input in following format: op1 operator op2"
    exit 1
fi
op1=$1
operator=$2
op2=$3
case $operator in
    "+") result=$((op1 + op2)) ;;
    "-") result=$((op1 - op2)) ;;
    "x") result=$((op1 * op2)) ;;
    "/") 
        if [ $op2 -eq 0 ]; then
            echo "Division by zero error"
            exit 1
        fi
        result=$((op1 / op2)) ;;
    "%") result=$((op1 % op2)) ;;
    "^") 
        result=1
        for ((i=1; i<=op2; i++)); do
            result=$((result * op1))
        done ;;
    *) echo "Invalid operator"; exit 1 ;;
esac
echo "$op1 $operator $op2 = $result"
