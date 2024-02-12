const int buttonPin = 2;      // pins for button and LED

const int ledPin = 14;

const int outPutPinA = 3;

const int outPutPinB = 4;



// store button's status - initialize to OFF (this variable will change, so it's not a const)

int redButtonState = 0;

int greenButtonState = 0;

bool on = false;



void setup() {

  pinMode(buttonPin, INPUT);    // set button to input

  pinMode(outPutPinA , OUTPUT); 

  pinMode(outPutPinB , OUTPUT);        // LED to output

}



void loop() {

  

  // read the state of the button into our variable

  redButtonState = digitalRead(buttonPin);

  

  // test that state

  if (redButtonState == HIGH) {      // if button is pressed...

    digitalWrite(outPutPinA ,HIGH);

    digitalWrite(outPutPinB , LOW); 

    

  }

  else {

    digitalWrite(outPutPinA , LOW);   // toggle the LED

    digitalWrite(outPutPinB ,HIGH);

  } 

  


// save the previous button state
  greenButtonState = redButtonState;

  } 
