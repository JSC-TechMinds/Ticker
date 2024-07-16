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
 * Copyright 2020-2024 JSC TechMinds
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
#define BLINK_PERIOD_MS 1000 // Blink once per second

// Make sure the code builds.
#ifndef LED_BUILTIN
#define LED_BUILTIN 1
#endif

jsc::Ticker blinkTicker(BLINK_PERIOD_MS);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Time has elapsed, turn on 
  if (blinkTicker.elapsedTicks() > 0) {
    blinkTicker.restart();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
