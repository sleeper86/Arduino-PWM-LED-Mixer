/*************************** 
Author: Seth Leeper, 2010
Version: 1 
Purpose: To cycle the tri-color LED 
contained within the Sparkfun starter kit 
through every available color combination with 
a fade in/fade out effect. 
************************************/ 

int RED = 9;    // RED pin of the LED to PWM pin 9 
int GREEN = 10;  // GREEN pin of the LED to PWM pin 10 
int BLUE = 11;   // BLUE pin of the LED to PWM pin 11 

int DELAY_TIME = 10;  //changes speed of fading 
int MAX_BRIGHT = 255; //sets maximum brightness, 255 max brightness 
int COLOR_MIX = 0; //variable to change the colors that are mixed in switch statement 

void fade_in(int x) //loop that gradually turns the LED on using PWM 
{ 
    int counter; 
    
    for(counter = 0; counter < x; counter++) 
    { 
        led_mixer(COLOR_MIX, counter); 
        delay(DELAY_TIME); 
    } 
} 

void fade_out(int x) //loop that gradually turns the LED off using PWM 
{ 
    int counter; 
    
    for(counter = x; counter > 0; counter--) 
    { 
        led_mixer(COLOR_MIX, counter); 
        delay(DELAY_TIME); 
    } 
} 

void led_mixer(int color, int x) //uses switch statement to mix color combinations 
{ 
    switch(color) 
    { 
      case 0: 
        analogWrite(RED, x); 
        break; 
      case 1: 
        analogWrite(GREEN, x); 
        break; 
      case 2: 
        analogWrite(BLUE, x); 
        break; 
      case 3: 
        analogWrite(BLUE, x); 
        analogWrite(GREEN, x); 
        break; 
      case 4: 
        analogWrite(RED, x); 
        analogWrite(BLUE, x); 
        break; 
      case 5: 
        analogWrite(RED, x); 
        analogWrite(GREEN, x); 
        break; 
      default: 
        analogWrite(GREEN, x); 
        analogWrite(BLUE, x); 
        analogWrite(RED, x); 
      break; 
    } 
} 

void setup() 
{ 
  // nothing for setup 
} 

void loop() //loop forever 
{ 
  fade_in(MAX_BRIGHT); //gradually turn the LED on to max brightness 
  fade_out(MAX_BRIGHT); //gradually turn off the LED 
  COLOR_MIX++; //increment to the next color combination 
  
  if(COLOR_MIX == 7) //if all color combinations have been displayed, reset the cycle 
  { 
    COLOR_MIX = 0; 
  } 
}