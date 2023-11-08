#!/bin/bash

# Accessing command-line arguments
first_argument=$1
second_argument=$2
all_arguments=("$@")
argument_count=$#

# Using arguments in the script
echo "The first argument is: $first_argument"
echo "The second argument is: $second_argument"
echo "All arguments are: ${all_arguments[@]}"
echo "Total number of arguments: $argument_count"

# Additional script logic using arguments
echo "Hello, $first_argument! Welcome to the world of scripting."
echo "You provided $second_argument as an additional argument."
