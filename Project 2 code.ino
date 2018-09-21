#include <Mouse.h>
#include <Keyboard.h>



// Arduino has already programmed
// all of the functions for the capacitive sensor for you in the
// <CapacitiveSensor.h> library. You just have to initialize it.
#include <CapacitiveSensor.h>




//initialize the number of samples you will take from the capacitive sensor
#define COMMON_PIN      9    // The common 'send' pin for all keys
#define NUM_OF_SAMPLES  100   // Higher number gives more consistent readings,
                             // but also makes things take longer


// Now create a capacitance sensor object. 
#define CS(Y) CapacitiveSensor(9, Y)  //common 'send' pin is pin 9

// And, then define the receive pin that the capacitor/aluminum foil is connected to:
CapacitiveSensor touch1[] ={CS(8)};  //pin 8   //Asia => F
CapacitiveSensor touch2[] ={CS(10)}; //pin 10  //Europe => D
CapacitiveSensor touch3[] ={CS(11)}; //pin 11  //North America => C
CapacitiveSensor touch4[] ={CS(12)}; //pin 12  //Africa => B
CapacitiveSensor touch5[] ={CS(7)};  //pin 7   //Oceania => E
CapacitiveSensor touch6[] ={CS(6)};  //pin 6   //Antarctica => A
CapacitiveSensor touch7[] ={CS(5)};  //pin 5   //South America => G

char ctrlKey = KEY_LEFT_GUI;
//  char ctrlKey = KEY_LEFT_CTRL;  

char F5 = KEY_F5;
//  char F5 = KEY_F5; 

char enter = KEY_RETURN;
//  char enter = KEY_RETURN; 

char shift = KEY_LEFT_SHIFT;
//  char shift = KEY_LEFT_SHIFT; 

//check for first time click
  int one = 0;
  int two = 0;
  int three = 0;
  int four = 0;
  int five = 0;
  int six = 0;
  int seven = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
 touch1[0].set_CS_AutocaL_Millis(0);
 touch2[0].set_CS_AutocaL_Millis(0);
 touch3[0].set_CS_AutocaL_Millis(0);
 touch4[0].set_CS_AutocaL_Millis(0);
 touch5[0].set_CS_AutocaL_Millis(0);
 touch6[0].set_CS_AutocaL_Millis(0);
 touch7[0].set_CS_AutocaL_Millis(0);
 
 //begin keyboard
  Keyboard.begin();
}




void loop() {

 
  // read the lag time or time constant from the touch sensor
  int lagtime1 = touch1[0].capacitiveSensor(NUM_OF_SAMPLES);
  int lagtime2 = touch2[0].capacitiveSensor(NUM_OF_SAMPLES);
  int lagtime3 = touch3[0].capacitiveSensor(NUM_OF_SAMPLES);
  int lagtime4 = touch4[0].capacitiveSensor(NUM_OF_SAMPLES);
  int lagtime5 = touch5[0].capacitiveSensor(NUM_OF_SAMPLES);
  int lagtime6 = touch6[0].capacitiveSensor(NUM_OF_SAMPLES);
  int lagtime7 = touch7[0].capacitiveSensor(NUM_OF_SAMPLES);
  
    // print out the state of the button:
    Serial.print(lagtime1);
    Serial.print("\t");
    Serial.print(lagtime2);
    Serial.print("\t");
    Serial.print(lagtime3);
    Serial.print("\t");
    Serial.print(lagtime4);
    Serial.print("\t");
    Serial.print(lagtime5);
    Serial.print("\t");
    Serial.print(lagtime6);
    Serial.print("\t");
    Serial.println(lagtime7);
  
  if(lagtime1 > 500){
    if(one < 1){
      Keyboard.press('F');
      Keyboard.releaseAll();
      delay(1000);
      Mouse.click();
      delay(10000);
      Keyboard.press(ctrlKey);
      Keyboard.press(shift);
      Keyboard.press(F5);
      delay(1000);
      Keyboard.releaseAll(); 
      one = one + 1;  
      two = 0; three = 0; four = 0; five = 0; six = 0; seven = 0;
    }else{
      Keyboard.press(enter);
      Keyboard.releaseAll();
    }
  }
  
  if(lagtime2 > 500){
    if(two < 1){
      Keyboard.press('D');
      Keyboard.releaseAll();
      two = two + 1;  
      one = 0; three = 0; four = 0; five = 0; six = 0; seven = 0;
    }else{
      Keyboard.press(enter);
      Keyboard.releaseAll();
    }
  }
  
  if(lagtime3 > 500){
    if(three < 1){
      Keyboard.press('C');
      Keyboard.releaseAll();
      three = three + 1;  
      two = 0; two = 0; four = 0; five = 0; six = 0; seven = 0;
    }else{
      Keyboard.press(enter);
      Keyboard.releaseAll();
    }
  }
  
  if(lagtime4 > 500){
    if(four < 1){
      Keyboard.press('B');
      Keyboard.releaseAll();
    
      four = four + 1;  
      one = 0; three = 0; two = 0; five = 0; six = 0; seven = 0;
    }else{
      Keyboard.press(enter);
      Keyboard.releaseAll();
    }
  }
  
  if(lagtime5 > 500){
    if(five < 1){
      Keyboard.press('D');
      Keyboard.releaseAll(); 
      five = five + 1;  
      one = 0; three = 0; four = 0; two = 0; six = 0; seven = 0;
    }else{
      Keyboard.press(enter);
      Keyboard.releaseAll();
    }
  }
  
  if(lagtime6 > 500){
    if(six < 1){
      Keyboard.press('C');
      Keyboard.releaseAll();
      six = six + 1;  
      two = 0; two = 0; four = 0; five = 0; three = 0; seven = 0;
    }else{
      Keyboard.press(enter);
      Keyboard.releaseAll();
    }
  }
  
  if(lagtime7 > 500){
    if(seven < 1){
      Keyboard.press('B');
      Keyboard.releaseAll();
      seven = seven + 1;  
      one = 0; three = 0; two = 0; five = 0; six = 0; four = 0;
    }else{
      Keyboard.press(enter);
      Keyboard.releaseAll();
    }
  }
  

    delay(500);        // delay in between reads for stability = 500 ms = 1/2 second
}