echo -n "Enter a year: "
read year
if [ -z "$year" ]; then
    year=$(date +%Y)
    echo "No year entered. Using current year: $year"
fi
if [ $((year % 4)) -eq 0 ] && { [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; }; then
    echo "$year is a leap year"
else
    echo "$year is not a leap year"
fi
