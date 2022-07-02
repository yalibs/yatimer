# YA-TIMER
yet another c++11 timer implementation. Header-only timer implementation

## Usage Notes
`ya::timer` cannot be "stopped", if you want to reset the timer just call `.start` again

The constructor takes an optional boolean argument whether to start at construction time or not. 
Default is `true` i.e. the timer starts automatically when constructed.

## Example Usage
```c++
#include <timer> // include the library
ya::timer<int> t{}; // construct the timer
/* Do something that takes some time */
auto ms = t.milliseconds_elapsed(); // fetch milliseconds since you started
```
