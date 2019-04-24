#include <SpecMath.h>
//All mesurements are in Inches
//Ultra Sonic Pins
#define leftUSPinOut 0;
#define leftUSPinIn 1 ;
#define rightUSPinOut 2;
#define rightUSPinIn 3;
//Haptic Sensor Pins - All digital
#define rightHandHaptic 4;
#define rightLegHaptic 5;
#define leftHandHaptic 6;
#define leftLegHaptic 7;
//Acclerometer Pins
#define headData 0;
#define rightHandData 1;
#define rightLegData 2;
#define leftHandData 3;
#define leftLegData 4;
#define clockline 5;
//Ultrasonic Stuff
double duration;
double rightUSDistance, leftUSDistance;
//Collision Box
int personHeight = 70;
double upperRightHeight=35,upperRightWidth=8;
double upperLeftHeight=35,upperLefttWidth=8;
double lowerRightHeight=35,lowerRightWidth=8;
double lowerLeftHeight=35,lowerLefttWidth=8;
int depth = 36;
//Object Matrices
double closeObjectsX[9];
double closeObjectsY[9];
double closeObjectsZ[9];
double midObjectsX[9];
double midObjectsY[9];
double midObjectsZ[9];
double farObjectsX[9];
double farObjectsY[9];
double farObjectsZ[9];
//Acclerometer Stuff
double headAngleX,headAngleY;
double leftHandVelocityX,leftHandVelocityY,leftHandVelocityZ;
double rightHandVelocityX,rightHandVelocityY,rightHandVelocityZ;
double leftLegVelocityX,leftLegVelocityY,leftLegVelocityZ;
double rightLegVelocityX,rightLegVelocityY,rightLegVelocityZ;
double maxThetaLeft = 180-(atan((depth/2)/upperRightWidth));
double maxThetaRight = atan((depth/2)/upperrightWidth);
double maxViewAngle = maxThetaLeft-maxThetaRight;

void setup() {
  Serial.begin(9600);
  pinMode(leftUSPinOut,OUTPUT);
  pinMode(leftUSPinIn,INPUT);
  pinMode(rightUSPinOut,OUTPUT);
  //pinMode(rightUSPinIn,INPUT);
  pinMode(rightHandHaptic,OUTPUT);
  pinMode(rightLegHaptic,OUTPUT);
  pinMode(leftLegHaptic,OUTPUT);
  pinMode(leftLegHaptic,OUTPUT);
  pinMode(headData,INPUT);
  pinMode(rightHandData,INPUT);
  pinMode(rightLegData,INPUT);
  pinMode(leftHandData,INPUT);
  pinMode(leftLegData,INPUT)
}

void loop() {
  //UltraSonicDistance
  // writes US trig pins low to insure they are off
  digitalWrite(leftUSPinOut,LOW);
  digitalWrite(rightUSPinOut,LOW);
  delayMicroseconds(30);
  //Finding Distance
  digitalWrite(leftUSPinOut,HIGH);
  digitalWrite(rightUSPinOut,HIGH);
  delayMicroseconds(10);
  digitalWrite(leftUSPinOut,LOW);
  digitalWrite(rightUSPinOut,LOW);
  duration = pulseIN(leftUSPinIn,HIGH);
  leftUSDistance = duration/(58.2*2.54);
  rightUSDistance - duration/(58.2*2.54);
  // Looking Left
  if (headAngleY>=maxThetaLeft&&headAngleY>maxThetaLeft-(maxViewAngle/3)){
    //Close
    if (leftUSDistance<=36){
      if(headAngleX<=90&&headAngleX>60){
        closeObjectsX[1] = SpecMath.distanceX(leftUSDistance,headAngleY);
        closeObjectsY[1] = SpecMath.distacneY(leftUSDistance,headAngleY);
        closeObjectsZ[1] = SpecMath.distanceZ(leftUSDistance,headAngleX, personHeight);
      }
      else if(headAngleX<=60&&headAngle>30){
        closeObjectsX[4] = SpecMath.distanceX(leftUSDistance,headAngleY);
        closeObjectsY[4] = SpecMath.distacneY(leftUSDistance,headAngleY);
        closeObjectsZ[4] = SpecMath.distanceZ(leftUSDistance,headAngleX, personHeight);
      }
      else if(headAngleX<=30){
        closeObjectsX[7] = SpecMath.distanceX(leftUSDistance,headAngleY);
        closeObjectsY[7] = SpecMath.distacneY(leftUSDistance,headAngleY);
        closeObjectsZ[7] = SpecMath.distanceZ(leftUSDistance,headAngleX, personHeight);
      }
    }
    //Mid
    else if (leftUSDistance>36&&leftUSDistance<=60){
      if(){
        midObjectsX[1] = SpecMath.distanceX(leftUSDistance,headAngleY);
        midObjectsY[1] = SpecMath.distacneY(leftUSDistance,headAngleY);
        midObjectsZ[1] = SpecMath.distanceZ(leftUSDistance,headAngleX, personHeight);
      }
    }
    //Far
    else if(leftUSDistance>50&&leftUSDistance<=84){
      if(){
        farObjectsX[1] = SpecMath.distanceX(leftUSDistance,headAngleY);
        farObjectsY[1] = SpecMath.distacneY(leftUSDistance,headAngleY);
        farObjectsZ[1] = SpecMath.distanceZ(leftUSDistance,headAngleX, personHeight);
      }
    }
  }
