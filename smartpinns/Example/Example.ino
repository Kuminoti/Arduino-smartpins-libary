/*Example code for my Libary:
 * this Libary is able to set up all pinns you want automaticly.
 * You need 2 variables int start and int stop the Numbers represent 
 * the pin you want to declare in your code in this case pin 3 to pin 13.
 * 
 * WARNING: DONT FORGET TO PUT THE & IN FRONT OF IT WITHOUT IT WILL NOT WORK
 * 
 * After you declared the pinns you can get them with the getPin function.
 * 
 */


#include"inputlib.h"

int start = 3;
int stopp = 13;

void setup() {
  Serial.begin(9600);
  out(&start, &stopp); //Use the out function to define your outputs
  // in();             //Use the  in funktion to define your inputs
  //in_pl()            //Use the in_pl funtion to deklare input with pullups
}

void loop() {
  
    digitalWrite(getPin(13), HIGH); // use getPin() to control the OUTPUTS
                                        
    delay(1000);
    digitalWrite(getPin(13), LOW); 
    delay(1000);
    //digitalRead(readPin(//))        //use the readPin or read_pl function to control your inputs
}
