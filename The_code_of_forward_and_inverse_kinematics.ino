#include <Servo.h> //Arduino servo motor library

//configure the servo motors
Servo servo1;
Servo servo2;

const float pi = 3.1415926;
const float L1 = 8; // Length between the first motor and the second motor (in cm)
const float L2 = 5; // Length between the second motor and the end of arm (in cm)
float x; 
float y; 
float q1; // Angle of the first motor (in radian)
float q1_deg; // Angle of the first motor (in degree)
float q2; // Angle of the second motor (in radian)
float q2_deg; // Angle of the second motor (in degree)
float q; // Sum of in radian (q1+q2), it called theta
float q_deg; // Sum of in degree (q1_deg + q2_deg)
float x_sq ; // X square
float y_sq ; // // Y square
float L1_sq ; // L1 square
float L2_sq ; // L2 square
const int btn1 = 6;
const int btn2 = 7;
int btn1value = LOW; // For forward kinematics
int btn2value = LOW; // For inverse kinematics


void setup() {
  
servo1.attach(2);
servo2.attach(3);

pinMode (btn1 ,INPUT);
pinMode (btn2 ,INPUT);

Serial.begin(9600); 

}

void loop() {
  

btn1value = digitalRead(btn1);
btn1value = digitalRead(btn2);

if (btn1value == HIGH) // if button 1 is pressed (case of forward kinematic)
{
  //assume the values of the angles
  q1_deg = 50; 
  q2_deg = 35;
  q_deg = q1_deg + q2_deg; 
  
  q1 = q1_deg*pi/180;// convert the angle from degree to radian
  q2 = q2_deg*pi/180;// convert the angle from degree to radian
  q = q_deg*pi/180; // convert the angle from degree to radian
  
  x = L1*cos(q1) + L2*cos(q); // The expected value with respect to X axis 
  y = L1*sin(q1) + L2*sin(q);  // The expected value with respect to Y axis 
  
  servo1.write(q1_deg); 
  servo2.write(q2_deg);
  
}

if (btn2value == HIGH) // if button 2 pressed (case of inverse kinematic)
{
  //assume the point on X and Y axes, and the value of theta
  x = 5; 
  y = 5; 
  q_deg = 115;
  q = q_deg*pi/180; // convert the angle from degree to radian
  
  x_sq = pow(x,2); 
  y_sq = pow(y,2); 
  L1_sq = pow(L1,2); 
  L2_sq = pow(L2,2); 
  
  q1 = acos((x_sq + y_sq - (L1_sq + L2_sq))/(2*L1*L2)); 
  q2 = q - q1 ; 
  
  q1_deg = q1*180/pi ; // convert the angle from radian to degree
  q2_deg = q2*180/pi; // convert the angle from radian to degree
  servo1.write(q1_deg); 
  servo2.write(q2_deg); 
  
  }
}
