#include "motor.cc"
#include "ultrasound.cc"

const short led = 31;
const short button = 7;
const short pinButtonLed = 2;
const short stop_dist = 20;
const short baseSpeed = 100;
short speed = 0;

// timing
// This function should be used instead delay() to perform all operations that must be done regulary
//
void sleep(short time)
{
    
}

short buttonState = 0;
short motorState = 0;

Motor motorRight(12, 3);
Motor motorLeft(13, 11);
SensorUltrasound ultrasound(19, 16);

void setup()
{
    Serial.begin(9600);  
    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
    pinMode(pinButtonLed, OUTPUT);

    ultrasound.init();
    motorLeft.init();
    motorRight.init();

    motorLeft.front();
    motorRight.front();

    digitalWrite(led, HIGH);
}

void loop()
{
    ultrasound.measure();

    if(ultrasound.get_distance() <= stop_dist)
    {
        digitalWrite(led, LOW);
        motorLeft.stop();
        motorRight.stop();

        /*
        motorLeft.stop();
        motorRight.stop();
        // turn left and go little bit
        motorLeft.go_back(baseSpeed);
        motorRight.go_front(baseSpeed);

        delay(250);
        motorLeft.stop();
        motorRight.stop();
        // turn right
        motorLeft.go_front(baseSpeed);
        motorRight.go_back(baseSpeed);
        // go a little bit
                
        delay(250);
        motorLeft.stop();
        motorRight.stop();
        */
    }
    else
    {
        digitalWrite(led, HIGH);
        motorLeft.go(speed);
        motorRight.go(speed);
    }
    buttonState = digitalRead(button);
    if(buttonState == HIGH)
    {
        Serial.println("Button press!");
        if(motorState == 0)
        {
            motorState = 1;
            speed = baseSpeed;
        }
        else
        {
            motorState = 0;
            speed = 0;
        }
    }

    digitalWrite(pinButtonLed, motorState);
    delay(500);
    Serial.print("Distance: ");
    Serial.println(ultrasound.get_distance());
}
