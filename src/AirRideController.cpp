#include "AirRideController.h"

AirRideController::AirRideController(int frUpPin, int frDownPin, int flUpPin, int flDownPin, int rrUpPin, int rrDownPin, int rlUpPin, int rlDownPin,
                                     unsigned long timeout, int getFRPosition, int getFLPosition, int getRRPosition, int getRLPosition, int deadZone)
    : _frController(frUpPin, frDownPin, timeout, getFRPosition, deadZone),
      _flController(flUpPin, flDownPin, timeout, getFLPosition, deadZone),
      _rrController(rrUpPin, rrDownPin, timeout, getRRPosition, deadZone),
      _rlController(rlUpPin, rlDownPin, timeout, getRLPosition, deadZone) {}

void AirRideController::moveTo(int frTarget, int flTarget, int rrTarget, int rlTarget) {
    _frController.moveTo(frTarget);
    _flController.moveTo(flTarget);
    _rrController.moveTo(rrTarget);
    _rlController.moveTo(rlTarget);
}

void AirRideController::moveTo(int targetHegith){
    Serial.println(" MOVE TO STARTED !!!!!!!");
    _frController.moveTo(targetHegith);
    _flController.moveTo(targetHegith);
    _rrController.moveTo(targetHegith);
    _rlController.moveTo(targetHegith);
}

void AirRideController::update() {
    _frController.update();
    _flController.update();
    _rrController.update();
    _rlController.update();
}

void AirRideController::setDeadZone(int deadZone) {
    _frController.setDeadZone(deadZone);
    _flController.setDeadZone(deadZone);
    _rrController.setDeadZone(deadZone);
    _rlController.setDeadZone(deadZone);
}
