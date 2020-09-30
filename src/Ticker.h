#ifndef TICKER_H
#define TICKER_H

#include <Arduino.h>
#define DEFAULT_TICKER_PERIOD 10 // ms

class Ticker {
private:
    uint16_t tickerTime = 0;
    unsigned long timeSample = 0;
    uint16_t counter = 0;
    bool timeSamplingTriggered = true;

public:
    Ticker(uint16_t tickerTime);
    uint16_t perform();
    void clear();
};
#endif // TICKER_H