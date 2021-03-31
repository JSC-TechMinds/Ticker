/**
 * @brief Blink
 *
 * Turns on LED for one second, then off for one second, repeatedly.
 * 
 * This sketch was inspired by the Arduino Blink Sketch. The main difference is
 * that we don't use blocking calls to <code>delay()</code>. Instead, we
 * create a Timer instance, which tracks whether a time period has elapsed.
 * 
 * While Arduino is waiting, it can perform other tasks.
 * 
 * Note: This sketch is almost identical to the TickerBlink.ino. The main
 * difference is a way, how we measure that a time period has elapsed.
 * 
 * In this exmaple, Ticker works with a period of 10 ms. When we want
 * to find out when our period of 1 second elapsed, we need to count
 * how many periods of 10 ms are there in 1 second.
 * 
 * In this case, after Ticker returns counter value >= 100, we know
 * that the time has elapsed.
 * 
 * Copyright 2020 JSC electronics
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

#include <Ticker.h>

// Increment counter each 10 ms
jsc::Ticker blinkTicker;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Change LED state after one second
  // (expressed as a count of 10 ms intervals)
  if (blinkTicker.elapsedTicks() > (1000 / 10)) {
    blinkTicker.restart();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
