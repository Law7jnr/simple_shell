#!/bin/bash

# Accessing command-line argument for command
command=$1

# Check if command exists in PATH
if [ "$command" = "exit" ]; then
  echo "Exiting the shell."
  exit 0
fi

# Check if command exists in PATH
if ! command -v "$command" > /dev/null; then
  echo "Error: Command '$command' not found."
  exit 1
fi

# Execute the command
"$@"
