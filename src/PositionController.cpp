#include "PositionController.h"

PositionController::PositionController(int upPin, int downPin, unsigned long timeout, int (*getPositionFunc)(), int deadZone)
    : _upPin(upPin), _downPin(downPin), _timeout(timeout), _getPositionFunc(getPositionFunc), _deadZone(deadZone),
      _targetPosition(0), _startMillis(0), _isMoving(false), _moveDirection(0) {}

void PositionController::moveTo(int targetPosition) {
    _targetPosition = targetPosition;
    int currentPosition = _getPositionFunc();
    
    if (abs(currentPosition - _targetPosition) <= _deadZone) {
        _isMoving = false;
        onComplete();
        return;
    }

    _moveDirection = (currentPosition < _targetPosition) ? 1 : -1;
    _startMillis = millis();
    _isMoving = true;

    if (_moveDirection == 1) {
        digitalWrite(_upPin, HIGH);
        digitalWrite(_downPin, LOW);
    } else {
        digitalWrite(_upPin, LOW);
        digitalWrite(_downPin, HIGH);
    }
}

void PositionController::update() {
    if (!_isMoving) return;

    int currentPosition = _getPositionFunc();
    unsigned long currentMillis = millis();

    if (currentMillis - _startMillis >= _timeout || abs(currentPosition - _targetPosition) <= _deadZone) {
        stopMovement();
        onComplete();
    }
}

void PositionController::stopMovement() {
    digitalWrite(_upPin, LOW);
    digitalWrite(_downPin, LOW);
    _isMoving = false;
}

void PositionController::setDeadZone(int deadZone) {
    _deadZone = deadZone;
}

void PositionController::onComplete() {
    Serial.println("Movement complete");
}
