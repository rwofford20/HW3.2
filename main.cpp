//
//  main.cpp
//  readIntTest
//
//  Created by Rachel Wofford on 2/21/18.
//  Copyright © 2018 Rachel Wofford. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include "readInt.h"
#include "gtest/gtest.h"

using namespace std;

//Test 1: Invalid input
TEST(readIntTest, Test1) {
    
    // Open a string stream to set up a buffer with the input
    
    stringstream ss;
    
    ss << "Hello\n1";
    
    ss.seekg(0, ios::beg);
    
    /* Only needed for file I/O
    // Replace "UnitTester" with the name of your Native Unit Test project
    ifstream ss("smb://cs1/students/2020/rwofford20/CS-273-1/HW03/HW3_2/HW3UnitTest.txt");
    
    // Check if we opened the file stream successfully
    if (ss.fail()){
        throw int(-1); // throw an integer with value -1
    }*/
    
    // Replace the cin read buffer with the read buffer from the file stream
    streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
    
    // Perform the read_int() test.
    // cin will now read from your file and not from the keyboard.
    // We expect the correct value returned is 0, ignoring the Hello string.
    
    EXPECT_EQ(0, read_int("My prompt: ", -3, 3));
              
    // Restore cin to the way it was before
    cin.rdbuf(orig_cin);
              
    /* Only needed for file I/O
    // Close the file stream
    ss.close();*/
    
}

//Test 2: Incorrect arguments
TEST(readIntTest, Test2) {
 
    //Since I am in XCode, I don't need to use the func code
    //This will catch the invalid_argument exception that is expected to be thrown
    EXPECT_THROW(read_int("My prompt: ", 5, 1), invalid_argument);
    
}

//Test 3: Invalid range
TEST(readIntTest, Test3) {
    
    // Open a string stream to set up a buffer with the input
    
    stringstream ss;
    
    //ss << "-3\n5\n10\n-2\n";
    ss << "-3\n";
    ss << "5\n";
    ss << "10\n";
    ss << "-2\n";
    ss << "3";
    
    ss.seekg(0, ios::beg);
    
    // Replace the cin read buffer with the read buffer from the file stream
    streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
    
    // Perform the read_int() test.
    // cin will now read from your file and not from the keyboard.
    // We expect the correct value returned is 3, ignoring the Hello string.
    
    EXPECT_EQ(3, read_int("My prompt: ", 0, 4));
    
    // Restore cin to the way it was before
    cin.rdbuf(orig_cin);

}

//Test 4: Incorrect arguments
TEST(readIntTest, Test4) {
    
    // This will catch the invalid_argument exception that is expected to be thrown
    EXPECT_THROW(read_int("My prompt: ", 0, 0), invalid_argument);
}

int main(int argc, char *argv[]) {
    
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
