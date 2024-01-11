#!/bin/bash

# Compile individual source files
gcc -c findpath.c -o findpath.o
gcc -c handle_errors.c -o handle_errors.o
gcc -c functions.c -o functions.o
gcc -c functions2.c -o functions2.o
gcc -c functions3.c -o functions3.o

# Create a static library archive
ar rcs lib.a handle_errors.o functions.o findpath.o functions2.o

# Compile the main program
gcc -c test.c -o test.o

# Link the main program with the library
gcc -o app test.o -L. lib.a

# Clean up object files (optional)
# rm *.o

# Print a message indicating successful completion
echo "Build completed successfully."

