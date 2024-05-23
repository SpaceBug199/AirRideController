#ifndef AIRRIDECONTROLLER_H
#define AIRRIDECONTROLLER_H

#include "PositionController.h"

class AirRideController {
public:
    AirRideController(int frUpPin, int frDownPin, int flUpPin, int flDownPin, int rrUpPin, int rrDownPin, int rlUpPin, int rlDownPin,
                      unsigned long timeout, int (*getFRPosition)(), int (*getFLPosition)(), int (*getRRPosition)(), int (*getRLPosition)(), int deadZone);

    void moveTo(int frTarget, int flTarget, int rrTarget, int rlTarget);
    void update();
    void setDeadZone(int deadZone);

private:
    PositionController _frController;
    PositionController _flController;
    PositionController _rrController;
    PositionController _rlController;
};

#endif
