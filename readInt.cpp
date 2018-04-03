//
//  readInt.cpp
//  HW3_2
//
//  Created by Rachel Wofford on 2/21/18.
//  Copyright © 2018 Rachel Wofford. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "readInt.h"
#include <stdexcept>
#include <sstream>

using namespace std;

int read_int(const string &prompt, int low, int high)

{
    if (low <= -2147483647 || high >= 2147483647)
    {
        throw range_error("Input is out of range");
    }
    else if (low >= high)
    {
        throw invalid_argument("Low value can not be greater than high value");
    }
    
    cin.exceptions(ios_base::failbit);
    
    int input = 0;
    
    while (true)
    {
        try {
            cout << prompt;
            cin >> input;
            
            if (input <= low || input >= high)
            {
                throw range_error("Input is not within range");
            }
            else
            {
                return input;
            }
        }
        catch (range_error)
        {
            cout << "Input is not within range, please try again. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        catch (ios_base::failure& e)
        {
            cout << "Input is invalid, please try again. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    }
    return input;
}
