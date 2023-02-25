// CSCI 1300 Spring 2023
// Author: Jeremiah Heredia
// Recitation: 102  – Tuan Tran
// Project 1 - Problem # 3


#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//algorith makes sure the string input is valid

bool isValidNote(string spn){
    if (spn.length() == 2){
    // test to make sure the length of the string is 2
        if (spn[0] == 'A' || spn[0] == 'B' || spn[0] == 'C' || spn[0] == 'D' || spn[0] == 'E' || spn[0] == 'F' || spn[0] == 'G'){
        // test to make sure the first character in the string is one of the valid capital leters   
            if (spn[1] == '0' || spn[1] == '1' || spn[1] == '2' || spn[1] == '3' || spn[1] == '4' || spn[1] == '5' || spn[1] == '6' || spn[1] == '7' || spn[1] == '8' || spn[1] == '9'){
            // test to make sure the second chartacter in the string is a valid integer
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
    // if any test fails return false
}
// this algorithm checks if there are any valid pairs of notes in valid scientific pitch notation in the string entered.
int numValidNotes(string spn) {
    int count = 0;
    if (spn.length() <= 0) {
        return 0;
    }
    // for loop to test different places in the string and if the one next to it makes a valid note in scientific pitch notation
    for (int i = 0; i < spn.length()-1; i++) {
        string temp;
        temp += spn[i];
        temp += spn[i+1];
        // if the notes are valid then add to the count and redo the code to the next place in the string
        if (isValidNote(temp)) {
            count++;
        }
    }
    // output the count
    return count;
}
main (){
    //test case 1
    assert(numValidNotes ("I love Tommy Yeh") == 0);
    //test case 2 
    assert(numValidNotes ("A1b1c1") == 1);
    //test case 3
    assert(numValidNotes ("C2F4E90") == 3);
    //test case 4
    assert(numValidNotes ("") == 0);       
    //test case 5
    assert(numValidNotes ("AA2B3") == 2);         
    //test case 6
    assert(numValidNotes ("ADB3M7G4F") == 2);        
    //test case 7
    assert(numValidNotes ("B3N4F9") == 2);  
}
         
