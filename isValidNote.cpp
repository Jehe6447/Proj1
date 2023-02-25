// CSCI 1300 Spring 2023
// Author: Jeremiah Heredia
// Recitation: 102  – Tuan Tran
// Project 1 - Problem # 1



bool isValidNote(string spn){
    if (spn.length() == 2){ 
    // test to make sure the length of the string is 2
        if (spn[0] == 'A' || spn[0] == 'B' || spn[0] == 'C' || spn[0] == 'D' || spn[0] == 'E' || spn[0] == 'F' || spn[0] == 'G'){
        // test to make sure the first character in the string is one of the valid capital letters
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
    // if any tests fail return false 
}

main(){
    //test case 1
    assert(isValidNote ("A7") == true);
    //test case 2
    assert(isValidNote ("helloworld") == false);
    //test case 3
    assert(isValidNote ("d1") == false);
    //test case 4
    assert(isValidNote ("GG") == false);
    //test case 5
    assert(isValidNote ("J10") == false);
    //test case 6
    assert(isValidNote ("FF") == false);
    //test case 7
    assert(isValidNote ("G") == false);
    //test case 8
    assert(isValidNote ("16") == false);
    
