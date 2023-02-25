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


double tuneSimilarity(string tune1, string tune2) {
    if (tune1.length() != tune2.length()) {
        return 0;
    }
  
    double NumMatchNotes = 0;
    double NumMatchNotesPitches = 0;
    double NumDiffNotesPitches = 0;
    double simmilarityScore = 0;
    
    if (numValidNotes(tune1) == numValidNotes(tune2)){
        int index = 0;
        while (index < tune1.length()) {
            if (tune1[index] == tune2[index]) {
                NumMatchNotes++;
            }
            if ((tune1[index] == tune2[index]) && (tune1[index+1] == tune2[index+1])) {
                NumMatchNotesPitches++;
            }
            if ((tune1[index] != tune2[index]) && (tune1[index+1] != tune2[index+1])) {
                NumDiffNotesPitches++;
            }
            
            index += 2;
        }
    }
    simmilarityScore = (NumMatchNotes/numValidNotes(tune1))+NumMatchNotesPitches-NumDiffNotesPitches;
    return simmilarityScore;
}


double bestSimilarity(string inputTune, string targetTune) {
    if (inputTune.length() < targetTune.length()) {
        return 0;
    } 
    
    double bestScore = -999;
    
    for (int i = 0; i < inputTune.length()-targetTune.length()+1; i++) {
        string inputPart = inputTune.substr(i,i+targetTune.length());
        
        if (inputPart.length() > targetTune.length()) {
            inputPart.resize(targetTune.length());
        }
      
        if (i == 0){
            bestScore = tuneSimilarity(inputPart,targetTune);
        }
        
        else if (bestScore < tuneSimilarity(inputPart,targetTune)) {
            bestScore = tuneSimilarity(inputPart,targetTune);
        }
    }
    return bestScore;
}
