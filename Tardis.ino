/*
 Tardis Fade
 */
 
  //Trigger Button
 //Button Schematic http://arduino.cc/en/uploads/Tutorial/button_schem.png
const int buttonPin = 5;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
int led = 0;           // the pin that the LED is attached to
int led2 = 1;
int led3 = 4;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int buttonPressed = 0;

// the setup routine runs once when you press reset:
void setup()  { 
// initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {   
    buttonPressed = 510;
  }  
  
  
  //IDLE STATE
  else {
    if (buttonPressed > 0){
         // set the brightness of pin LEDs:
        analogWrite(led, brightness);   
        analogWrite(led2, brightness); 
        analogWrite(led3, brightness);  

        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade: 
        if (brightness == 0 || brightness == 255) {
          fadeAmount = -fadeAmount ; 
            }     
        // wait for 30 milliseconds to see the dimming effect    
        delay(30); 
        buttonPressed--;
        }
        // turn LEDs ON:
      analogWrite(led, 255);   
      analogWrite(led2, 255); 
      analogWrite(led3, 255);  
      }
}

