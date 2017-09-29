class Motor
{
 private:
    short  directionPinM;
    short      speedPinM;

    short     directionM;
    short         speedM;

 public:
    Motor(short dirPin, short speedPin)
    {
        directionPinM =   dirPin;
        speedPinM     = speedPin;
    }

    void init()
    {
        pinMode(directionPinM, OUTPUT);
    }

    void stop()
    {
        analogWrite(speedPinM, 0);
    }

    void go(short speed)
    {
        analogWrite(speedPinM, speed);
    }

    void go_front(short speed)
    {
        digitalWrite(directionPinM, LOW);
        analogWrite(speedPinM, speed);
    }

    void go_back(short speed)
    {
        digitalWrite(directionPinM, HIGH);
        analogWrite(speedPinM, speed);
    }

    void front()
    {
        digitalWrite(directionPinM, LOW);
    }

    void back()
    {
        digitalWrite(directionPinM, HIGH);
    }
};

/*
class MotorController
{
 private:
    
}
*/
