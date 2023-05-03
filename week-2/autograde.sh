#!/bin/sh

# Run make to build the project
make

# Check if make completed successfully
if [ $? -eq 0 ]; then
    # Run the output file
    echo -e "\n============================================="
    echo -e "\nTesting ECNumbers\n"

    ./UnitTests.o

    echo -e "\n============================================="
    echo -e "\nTesting ECRemoveSpace\n"

    ./ECRemoveSpace.o

    # Clean up the build
    echo -e "\n============================================="
    make clean
else
    # Make failed, print an error message
    echo "Build failed"
fi