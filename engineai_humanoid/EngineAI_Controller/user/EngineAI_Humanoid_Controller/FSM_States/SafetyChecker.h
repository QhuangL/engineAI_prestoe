//
// Created by engineai on 2024/07/03.
//

#ifndef ZQ_HUMANOID_SAFETYCHECKER_H
#define ZQ_HUMANOID_SAFETYCHECKER_H

#include <iostream>

// Contains all of the control related data
#include "ControlFSMData.h"

/**
 * The SafetyChecker handles the checks requested by the ControlFSM.
 */
template <typename T>
class SafetyChecker
{
public:
    SafetyChecker(ControlFSMData<T> *dataIn) : data(dataIn) {};

    // Pre checks to make sure controls are safe to run
    bool checkSafeOrientation(); // robot's orientation is safe to control

    // Post checks to make sure controls can be sent to robot
    bool checkPDesFoot();         // desired foot position is not too far
    bool checkForceFeedForward(); // desired feedforward forces are not too large

    // Stores the data from the ControlFSM
    ControlFSMData<T> *data;

private:
};

#endif // ZQ_HUMANOID_SAFETYCHECKER_H
