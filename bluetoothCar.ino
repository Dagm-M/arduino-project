int enB = 10; // Enable input for back motor
int in3 = 4; // Signal input 3 for back motor
int in4 = 5; // Signal input 4 for back motor

int enA = 3; // Enable input for front motor
int in1 = 2; // Signal input 1 for front motor
int in2 = 7; // Signal input 2 for front motor

char data;

void setup() {
  // Begin the serial commuication with baudrate of 9600
  Serial.begin(9600);
  
  //Set the pin modes to Output for back motor
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  //Set the pin modes to Output for front motor
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() 
{

  //Initalize the back motor
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  //Initialize the front motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  if(Serial.available() > 0) //Check if any data is being transferred
   {     
      data= Serial.read(); // Reading the data received from the bluetooth module

      switch(data)
      {
         case 'F': // Rotate back motor forward
               goForward();
               break;
             
         case 'B': //Rotate back motor backward
               goBackward();
               break;
               
         case 'L': //Turn front motor left
                turnLeft();
                break;
                
         case 'R': //Turn front motor right
                turnRight();
                break;

         case 'S': //Stop both motors
                Stop();
                break;
      } 
      Serial.println(data);
   }

    delay(30); //Set delay for 50 milliseconds
//    if(!(Serial.available() > 0)){
//          toCentre(); // Recentering both motors
//    }
    data = '\0'; // Setting the value of data to null character
   // Serial.println(data);
     
}

void goForward() 
{
  analogWrite(enB, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void goBackward()
{
   analogWrite(enB, 255);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
}

void turnLeft()
{
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void turnRight()
{
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void Stop()
{
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void toCentre()
{
  if(data == 'R') 
  {
    analogWrite(enA, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(20);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  else if(data == 'L')
  {
    analogWrite(enA, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(15);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);    
  }
  
}
