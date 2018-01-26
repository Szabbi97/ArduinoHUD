int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"


void setup() {               
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
  Serial.begin(9600);
}

void displayDigit(int digit)
{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);
 
 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);
 
 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);
 
 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);
 
 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);
 
 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
 
}

void displayLetter(char letter)
{
  if(letter == 'n')
  {
    digitalWrite(e,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
  }
  else if(letter == 'r')
  {
    digitalWrite(e,HIGH);
    digitalWrite(g,HIGH);
  }
}

void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void loop() {
  String incomingByte = "";
  // send data only when you receive data:
  if (Serial.available() > 0) {
    turnOff();
     // read the incoming byte:
     incomingByte = Serial.read();

     if(incomingByte == "45")
     {
      displayLetter('r');
     }
     else if(incomingByte == "48")
     {
      displayLetter('n');
     }
     else if(incomingByte == "49")
     {
      displayDigit(1);
     }
     else if(incomingByte == "50")
     {
      displayDigit(2);
     }
     else if(incomingByte == "51")
     {
      displayDigit(3);
     }
     else if(incomingByte == "52")
     {
      displayDigit(4);
     }
     else if(incomingByte == "53")
     {
      displayDigit(5);
     }
     else if(incomingByte == "54")
     {
      displayDigit(6);
     }
     else if(incomingByte == "55")
     {
      displayDigit(7);
     }
     else if(incomingByte == "56")
     {
      displayDigit(8);
     }
     else
     {
      displayDigit(9);
     }
  }
}

