# Ticker
[![Build Status](https://travis-ci.com/JSC-electronics/Ticker.svg?branch=master)](https://travis-ci.com/JSC-electronics/Ticker)
[![GitHub release](https://img.shields.io/github/release/JSC-electronics/Ticker.svg?maxAge=3600)](https://github.com/JSC-electronics/Ticker/releases)
[![License: Apache 2.0](https://img.shields.io/badge/license-Apache--2.0-green.svg)](https://github.com/JSC-electronics/Ticker/blob/master/LICENSE)
[![Donate](https://img.shields.io/badge/donate-PayPal-blueviolet.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=SESX9ABM7V8KA&source=url)

Ticker is a helper library, which allows you to write non-blocking Arduino code without calls to `delay()`.

There are two common ways, how to use the library. Let's say you want to trigger an event after five seconds:

```cpp
#include <Ticker.h>

#define TRIGGER_PERIOD 5000 // milliseconds

// Create a ticker
jsc::Ticker ticker(TRIGGER_PERIOD);

void setup() {
    ...
}

void loop() {
    if (ticker.elapsedTicks() > 0) {
        // TODO: Trigger an event

        // Reset ticker
        ticker.restart();
    }
}
```

In another example, we want to trigger an event after five seconds, as in first case. However, Ticker will increment its counter after 10 milliseconds, which is a default value. To determine, whether a time period has elapsed, you need to divide overall time period by partial time periods. This value represents expected counter value. Let's see an example:

```cpp
#include <Ticker.h>

// Create a ticker with a tick period of 10 ms
jsc::Ticker ticker();

void setup() {
    ...
}

void loop() {
	// Trigger an event after five seconds
    if (ticker.elapsedTicks() > (5000 / 10)) {
        // TODO: Trigger an event

        // Reset ticker
        ticker.restart();
    }
}
```

## Documentation
- [GitHub Wiki][ticker-wiki]
- [Extended Doxygen Documentation][object-button-doxygen]
- [Examples](examples)

## Contributing
There are many ways in which you can participate in the project, for example:

* [Submit bugs and feature requests](https://github.com/JSC-electronics/Ticker/issues), and help us verify as they are checked in
* Review [source code changes](https://github.com/JSC-electronics/Ticker/pulls)
* Review the [documentation](https://github.com/JSC-electronics/Ticker/wiki) and make pull requests for anything from typos to new content

Please read [contributing rules](CONTRIBUTING.md) for more details.

## License

Copyright © 2020-2023 JSC electronics. All rights reserved.

Licensed under the [Apache-2.0](LICENSE) license.

## Support

We hope our library helped to speed up your project development. You can support our effort to convert coffe and pizza into a code with a small donation. Any support is much appreciated.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=SESX9ABM7V8KA&source=url)

[//]: # (Used references)
[ticker-wiki]: https://github.com/JSC-electronics/Ticker/wiki
[object-button-doxygen]: https://jsc-electronics.github.io/Ticker
