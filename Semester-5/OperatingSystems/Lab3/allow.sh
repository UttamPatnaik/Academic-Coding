#!/bin/bash
echo -n "Enter internal mark: "
read mark
echo -n "Enter attendance percentage: "
read attend
if [ $mark -ge 20 ] && [ $attend -ge 75 ]; then
    echo "Allowed for Semester"
else
    echo "Not allowed"
fi
