#!/bin/bash
echo -n "Enter day: "
read day
case $day in
    Monday|monday)
        echo "DOS Class: 10:00 AM - 12:00 PM, Room: CL-101";;
    Wednesday|wednesday)
        echo "DOS Class: 2:00 PM - 4:00 PM, Room: CL-203";;
    Friday|friday)
        echo "DOS Class: 11:00 AM - 1:00 PM, Room: Lab-301";;
    Sunday|sunday)
        echo "Holiday";;
    *)
        echo "No class on $day";;
esac
