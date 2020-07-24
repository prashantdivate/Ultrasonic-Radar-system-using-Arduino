%%%%% Arduino IDE code %%%%%
#include<Servo.h>	//Includes the Servo library
Servomyservo;	//Creates a servo object for controlling the servomotor 
const int trigPin=10;//Defines Tirg and Echo pins of the Ultrasonic Sensor
const int echoPin=11;
long duration;	//Variables for the duration and the distance
intdistance;
intpos=0;


voidsetup(){
pinMode(trigPin, OUTPUT);//Sets the trig Pin as an Output
pinMode(echoPin, INPUT);// Sets the echoPin as an Input
pinMode(13,OUTPUT);
Serial.begin(9600);
myservo.attach(9);	//Defines on which pin is the servomotor attached
}
voidloop(){
//rotates the servomotor from 0 to 180 degrees 
for(pos=0;pos<=180;pos++)
 {
    //goes from 0 degrees to 180 degrees
    //in steps of 1 degree
   myservo.write(pos);		//tell servo to go to position in variable'pos'
   delay(60);	//waits 60ms for the servo to reach the position
   distance=calculateDistance();//Calls a function for calculating the distance measured by the Ultrasonic sensor for eachdegree
   Serial.print(pos);	//Sends the current degree into the SerialPort
   Serial.print(",");//Sends addition character right next to the previous value needed later in the Processing IDE for indexing
   Serial.print(distance);//Sends the distance value into the Serial Port
   Serial.print(".");//Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  if(distance<40)
   {

     digitalWrite(13,HIGH);delay(40);
   }
  elsedigitalWrite(13,LOW);delay(30);
 }
    //Repeats the previous lines from 180 to 0 degrees
  for(pos=180;pos>=0;pos--)
  {
    //goes from 180 degrees to 0 degrees
    myservo.write(pos);		//tell servo to goto position in variable'pos'
    delay(60);	//waits 60ms for the servo to reach the position 
    distance=calculateDistance();
Serial.print(pos);
Serial.print(",");
Serial.print(distance);
Serial.print(".");
if(distance<40)
{

digitalWrite(13,HIGH);
delay(40);
}
elsedigitalWrite(13,LOW);
delay(30);}}
//FunctionforcalculatingthedistancemeasuredbytheUltrasonicsensorintcalculateDistance(){
digitalWrite(trigPin,LOW);delayMicroseconds(2);
//SetsthetrigPinonHIGHstatefor10microsecondsdigitalWrite(trigPin,HIGH);
delayMicroseconds(10);digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);//ReadstheechoPin,returnsthesoundwavetraveltimeinmicroseconds
distance=duration*0.034/2;returndistance;
}

