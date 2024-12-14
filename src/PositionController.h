#ifndef POSITIONCONTROLLER_H
#define POSITIONCONTROLLER_H
#define UP_DIRECTION 1
#define DOWN_DIRECTION -1

#include <Arduino.h>

class PositionController {
public:
    PositionController(int upPin, int downPin, unsigned long timeout, int getPositionPin, int deadZone);

    void update();
    void moveTo(int targetPosition);
    void setDeadZone(int deadZone);
    int getPosition();

private:

    int _upPin;
    int _downPin;
    unsigned long _timeout;
    int _deadZone;
    int _targetPosition;
    unsigned long _startMillis;
    bool _isMoving;
    int _moveDirection;
    int _getPositionPin;


    void onComplete();  
    void stopMovement();

};

#endif
