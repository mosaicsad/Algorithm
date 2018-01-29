///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 3 in homework assignmnet #3. 
//    2. Implement function GetStudentName.
//    3. Implement function SplitMessage.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_3.h") and results ("solution_3.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

// Required libraries.
#include <string>
#include<vector>
#include<iostream>
using namespace std;

// You can include standard C++ libraries here.


// This function should return your name.
// The name should match your name in Canvas.
void GetStudentName(std::string& your_name)
{
   // Replace the placeholders "Firstname" and "Lastname"
   // with you first name and last name.
    your_name.assign("Yunfei Gao");
}

//This is the function you need to implement.
int SplitMessage(std::string message, int packet_size)
{
//return your result here
    if(message.empty()){//Judge the boundary conditions
        return 0;
    }

    int num = 0;
    int sub_length_total = 0;
    int sub_length = 0;
    int i = 0;
    vector<int> Position;
    Position.clear();
    for(i = 0; i < message.length(); i++){//get the position of each space
        if(isspace(message[i])){
            Position.push_back(i);
        }
    }
    Position.push_back(message.length());//add the last position(the whole length of message) into this vector
    i = 0;
    while(i < Position.size()){// while loop to do the greedy algorithm
        if(i == 0){//the first position is exactly the length of the first word
            sub_length = Position[i];
        }
        else{//the difference of two neighbering position is words with spaces
            sub_length = Position[i] - Position[i - 1];
        }
        sub_length_total += sub_length;
        if(sub_length_total > packet_size){// if the length of our string is larger than pack_size,
                                           // pack number++, and next string length will begin at Position[i] - Position[i - 1] - 1
            num++;
            sub_length_total = Position[i] - Position[i - 1] - 1;
        }
        if(sub_length_total != packet_size){//
            if(sub_length > packet_size){// if some words are longer than pack_size, return 0
                return 0;
            }
        }
        i++;
    }
    return num + 1;//the last past of string must shorter than pack_size, and they are not counted into pack number
                    //so, we have to add the last part here.
}
