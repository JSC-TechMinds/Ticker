/**
 * @file       Ticker.h
 * Project     Ticker
 * @brief      A helper library to hide complexity of computing time differences in pseudo-multitasking projects
 * @author     JSC electronics
 * License     Apache-2.0 - Copyright (c) 2020 JSC electronics
 *
 * @section License
 *
 * Copyright (c) 2020 JSC electronics
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TICKER_H
#define TICKER_H

#ifdef __cplusplus

#include <Arduino.h>

namespace jsc {
    /** Duration of a single tick */
    constexpr static unsigned int DEFAULT_TICKER_PERIOD_MS = 10;

    class Ticker {
    public:
        /**
         * Default constructor. You can specify a custom ticker period.
         * If it's not specified, <code>DEFAULT_TICKER_PERIOD_MS</code> will be used.
         */
        Ticker(uint16_t tickerTime = DEFAULT_TICKER_PERIOD_MS);

        /**
         * Captures current time and tracks whether a time period has elapsed.
         * For example, if a ticker period is 10 ms, and 30 ms passed since first call
         * to <code>Ticker#perform()</code>, this method captured three ticks, and returns 3.
         * 
         * In most cases, however, you can specify the duration of a single tick, and once
         * this method returns a value greater than 0, you know that your defined period has passed.
         * 
         * @return number of ticks since the Ticker was started.
         */
        uint16_t perform();

        /**
         * Reset Ticker to initial state
         */
        void clear();

    private:
        /** Ticker period for one tick. After this value elapses, Ticker increments its counter.*/
        uint16_t tickerTime;
        unsigned long timeSample = 0;

        /**
         * Internal counter. It holds ticks since Ticker was first started,
         * or since it was re-set by the <code>Ticker#clear()</code> method.
         */
        uint16_t counter = 0;

        /**
         * If it's set to <code>true</code>, Ticker will capture current time returned by <code>millis()</code>.
         * Otherwise, Ticker will wait until the TICKER_PERIOD elapses, and increments the counter.
         * 
         * This variable is set up to <code>true</code> after Ticker initialization and after calling <code>Ticker#clear()</code>.
         */
        bool timeSamplingTriggered = true;
    };
}

#endif
#endif // TICKER_H
