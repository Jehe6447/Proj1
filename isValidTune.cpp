// CSCI 1300 Spring 2023
// Author: Jeremiah Heredia
// Recitation: 102  – Tuan Tran
// Project 1- Problem # 2


#include <iostream>
#include <string>
#include <cassert>
using namespace std;


bool isValidNote(string spn){
    if (spn.length() == 2){
    // test to make sure the string length is 2
        if (spn[0] == 'A' || spn[0] == 'B' || spn[0] == 'C' || spn[0] == 'D' || spn[0] == 'E' || spn[0] == 'F' || spn[0] == 'G'){
        // test to make sure the first character is one of the valid capital letters
            if (spn[1] == '0' || spn[1] == '1' || spn[1] == '2' || spn[1] == '3' || spn[1] == '4' || spn[1] == '5' || spn[1] == '6' || spn[1] == '7' || spn[1] == '8' || spn[1] == '9'){
            // test to make sure the second character in the string is a valid integer    
                return true;
                // if all tests pass return true
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
    // if any of the tests fail return false 
}

bool isValidTune(string spn){
    if (spn.length()%2 == 0){
    // test to make sure the string has an even number of characters by getting the remainder when dividing by 2
        for (int i = 0; i < spn.length(); i += 2){
        // for loop to check the validity of each note (itterate by 2 through the tune because each note has 2 characters)
            string temp;
            temp += spn[i];
            temp += spn[i+1];
            // makes the temporary string that holds the value of the 2 characters that make up a note (Letter Number) 
            
            if (isValidNote(temp) == false){           
                return false;
            }
            // if isValidNote returns false then the return false
            
        }
        return true;
        // if the loop runs a complete itteration then return true and the tune is valid
    }
    return false;
    // if the lenght of the string is odd the tune is invalid and return false
}
main(){
    assert(isValidTune("A3B4C9") == true);
    assert(isValidTune("A3b1CC") == false);
    assert(isValidTune("F612A5") == false);
    assert(isValidTune("123456") == false);
    assert(isValidTune("ABCDEF") == false);
    assert(isValidTune("a1b3c5") == false);
    assert(isValidTune("A3B5c1") == false);
}
