#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Usage: $0 file1 file2"
    exit 1
fi
f1=$1
f2=$2
if [ ! -f "$f1" ] || [ ! -f "$f2" ]; then
    echo "One or both files do not exist."
    exit 1
fi
if cmp -s "$f1" "$f2"; then
    echo "Files $f1 and $f2 have same content."
    rm "$f2"
    echo "So $f2 is deleted."
else
    echo "Files $f1 and $f2 have different content."
