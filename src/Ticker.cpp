/**
 *  @file       Ticker.cpp
 *  @brief      Counter which checks timeout of project subjects.
 *  @author     JSC electronics
 */

#include "Ticker.h"

Ticker::Ticker(uint16_t tickerTime){
    this->tickerTime = tickerTime;
}

uint16_t Ticker::perform(){
    if(timeSamplingTriggered){
        timeSample = millis();
        timeSamplingTriggered = false;
    }

    if(timeSample + tickerTime < millis()){
        counter++;
        timeSamplingTriggered = true;
    }

    return counter;
}

void Ticker::clear(){
    counter = 0;
    timeSamplingTriggered = true;
    timeSample = 0;
}