//#define is used to give a name to a constant value i.e we have given pin 6 a name buzz.
# define buzz 6
#define trig 12
#define echo 13
// runs only one time 
void setup()
{
pinMode(trig,OUTPUT);//Trigger

pinMode(echo,INPUT);//EchoA

pinMode(buzz,OUTPUT);//Buzzer

Serial.begin(9600); //for starting communication with serial monitor

}

void buzz1() //beeps fast
{
  digitalWrite(buzz, HIGH);
  delay(100);
  digitalWrite(buzz, LOW);
  delay(100);
  Serial.println("beep faster");
}

void buzz2() // beeps slowly
{
  digitalWrite(buzz, HIGH);
  delay(400);
  digitalWrite(buzz, LOW);
  delay(400);
  Serial.println("beep slowly");
}

//main function which runs in loop
void loop()
{

long duration; //for storing the duration taken for the pulse to comeback to echo  thrown from trig
long distance; //for storing the calculated distance value
digitalWrite(trig,LOW);

delayMicroseconds(2);

digitalWrite(trig,HIGH);

delayMicroseconds(10);

digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH); //pulsein is the function which gives the time taken for pulse to comeback

distance=(duration/2)/29.1; //calculating distance using duration

Serial.println(distance); //printing the distance for checking in serial monitor
//if else if condition for beeps according to obstacle distance 
if (distance > 30 && distance < 45)     //if obstacle found between 30 to 45cm 
{
buzz2();
}
else if (distance < 30 && distance > 20)     // if obstacle found between 20 to 30cm 
{
buzz1(); //calling the function 
}
else if (distance > 0 && distance < 20)    // if obstacle found between 0 to 20cm 
{
digitalWrite(buzz,HIGH);
Serial.println("continuous beep");
} 
else 
{
// when greater than 45cm
digitalWrite(buzz,LOW); 
}
 delay(500); //delay for 0.5 seconds

}
