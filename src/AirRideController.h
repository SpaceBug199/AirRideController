#ifndef AIRRIDECONTROLLER_H
#define AIRRIDECONTROLLER_H

#include "PositionController.h"

class AirRideController {
public:
    AirRideController(
        int frUpPin,                // suspension control output pin
        int frDownPin,              // suspension control output pin
        int flUpPin,                // suspension control output pin
        int flDownPin,              // suspension control output pin
        int rrUpPin,                // suspension control output pin
        int rrDownPin,              // suspension control output pin
        int rlUpPin,                // suspension control output pin
        int rlDownPin,              // suspension control output pin
        unsigned long timeout,      // timeout to complete the movement
        int getFRPosition,          // suspension position sensor
        int getFLPosition,          // suspension position sensor
        int getRRPosition,          // suspension position sensor
        int getRLPosition,          // suspension position sensor
        int deadZone);              // resting range of the system

    void moveTo(int frTarget, int flTarget, int rrTarget, int rlTarget);
    void moveTo(int frTarget, bool frInvert, int flTarget, bool flInvert, int rrTarget, bool rrInvert, int rlTarget, bool rlInvert);
    void moveTo(int targetHeight);
    void update();
    void setDeadZone(int deadZone);

private:
    PositionController _frController;
    PositionController _flController;
    PositionController _rrController;
    PositionController _rlController;
};

#endif
