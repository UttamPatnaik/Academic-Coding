#!/bin/bash
echo -n "First Integer: "
read a
echo -n "Second Integer: "
read b
echo "Addition: $((a+b))"
echo "Subtraction: $((a-b))"
echo "Multiplication: $((a*b))"
echo "Division: $((a/b))"
echo "Modulo: $((a%b))"
