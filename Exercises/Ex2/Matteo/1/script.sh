#!/bin/bash

mkdir -p output

for i in {1..10}; do
    ./hello_world $i > output/output_$i.txt &
done

wait
echo "All jobs completed."
