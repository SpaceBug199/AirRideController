// Include the header file that defines the PositionController class
#include "PositionController.h"

// Constructor of the PositionController class
PositionController::PositionController(int upPin, int downPin, unsigned long timeout, int getPositionPin, int deadZone)
    : _upPin(upPin), _downPin(downPin), _timeout(timeout), _getPositionPin(getPositionPin), _deadZone(deadZone),
      _targetPosition(0), _startMillis(0), _isMoving(false), _moveDirection(0) {
    // Set the pin modes for input and output pins
    pinMode(_getPositionPin, INPUT);
    pinMode(_upPin, OUTPUT);
    pinMode(_downPin, OUTPUT);
}

// Method to move the controller to a specified target position
void PositionController::moveTo(int targetPosition, bool invertAxis = false) {
    _targetPosition = targetPosition;
    int currentPosition = getPosition(); // Get the current position from the sensor
    
    // If the difference between the current and target positions is within the dead zone, stop moving
    if (abs(currentPosition - _targetPosition) <= _deadZone) {
        _isMoving = false;
        onComplete();
        return;
    }

    // Determine the direction of movement based on current and target positions
                    // XOR the expression with invertAxis variable to invert the direction of travel
    _moveDirection = (!(currentPosition < _targetPosition) != !invertAxis) ? UP_DIRECTION : DOWN_DIRECTION;
   
    _startMillis = millis(); // Record the start time for timeout checking
    _isMoving = true;

    // Set output pins to move in the correct direction
    if (_moveDirection == UP_DIRECTION) {
        digitalWrite(_upPin, HIGH);
        digitalWrite(_downPin, LOW);
    } else {
        digitalWrite(_upPin, LOW);
        digitalWrite(_downPin, HIGH);
    }
}

// Method to update the controller's status and check if movement is complete
void PositionController::update() {
    Serial.println("position controller update");
    // If not moving, exit early
    if (!_isMoving) return;

    int currentPosition = getPosition(); // Get the current position from the sensor
    unsigned long currentMillis = millis(); // Get the current time

    // Check if movement is complete based on timeout or dead zone proximity
    if (currentMillis - _startMillis >= _timeout || abs(currentPosition - _targetPosition) <= _deadZone) {
        stopMovement();
        onComplete();
    }
}

// Method to stop the movement by setting both pins low
void PositionController::stopMovement() {
    digitalWrite(_upPin, LOW);
    digitalWrite(_downPin, LOW);
    _isMoving = false; // Indicate that movement has stopped
}

// Method to set the dead zone for position changes
void PositionController::setDeadZone(int deadZone) {
    _deadZone = deadZone;
}

// Callback method invoked when movement is complete
void PositionController::onComplete() {
    stopMovement(); // Stop all movement if all movement is complete
    //Serial.println("Movement complete"); // Output a message to the serial monitor
}

// Method to get the current position from the sensor pin
int PositionController::getPosition() {
    return analogRead(this->_getPositionPin); // Read the value from the specified pin
}
