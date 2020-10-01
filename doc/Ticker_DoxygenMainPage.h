/**
 * @mainpage Ticker Arduino Library
 *
 * See the documentation of the main class, Ticker, or browse the modules
 * and examples using the sidebar on the left.
 *
 * The latest development version is available on [GitHub](https://github.com/JSC-electronics/Ticker).
 */

/**
 * @example TickerBlink.ino
 *
 * Turns on LED for one second, then off for one second, repeatedly.
 * 
 * This sketch was inspired by the Arduino Blink Sketch. The main difference is
 * that we don't use blocking calls to <code>delay()</code>. Instead, we
 * create a Timer instance, which tracks whether a time period has elapsed.
 * 
 * While Arduino is waiting, it can perform other tasks.
 */

/**
 * @example TickerBlinkV2.ino
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
 */
