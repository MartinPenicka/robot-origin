class SensorUltrasound
{
 private:
    short         pinTriggerM;
    short            pinEchoM;
    unsigned int    durationM;
    unsigned int    distanceM;

 public:
    SensorUltrasound(short pinTrig, short pinEcho)
    {
        pinTriggerM = pinTrig;
        pinEchoM    = pinEcho;
    }

    void init()
    {
        pinMode(pinTriggerM, OUTPUT);
        pinMode(pinEchoM, INPUT);
    }

    void measure()
    {
        digitalWrite(pinTriggerM, LOW);
        delay(2);
        digitalWrite(pinTriggerM, HIGH);
        delay(10);
        digitalWrite(pinTriggerM, LOW);

        durationM = pulseIn(pinEchoM, HIGH);
        distanceM = durationM*0.034/2;
    }

    unsigned int get_distance() const
    {
        return distanceM;
    }
};
