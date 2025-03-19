/* MIT License

Copyright (c) 2022 Asger Gitz-Johansen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef YATIMER_TIMER_H
#define YATIMER_TIMER_H
#include <chrono>

namespace ya {
    template<typename T>
    class timer {
    private:
        using clock = std::chrono::high_resolution_clock;
        using us = std::chrono::duration<T, std::micro>;
        using ms = std::chrono::duration<T, std::milli>;
        using sec = std::chrono::duration<T, std::chrono::seconds>;

        clock::time_point epoch;

    public:
        explicit timer(bool initialize_on_construction = true) : epoch{} { if(initialize_on_construction) start(); }
        void start() {
            epoch = clock::now();
        }
        clock::duration time_elapsed() const {
            return clock::now() - epoch;
        }
        T microseconds_elapsed() const {
            us my_us = std::chrono::duration_cast<us>(time_elapsed());
            return my_us.count();
        }
        T milliseconds_elapsed() const {
            ms my_ms = std::chrono::duration_cast<ms>(time_elapsed());
            return my_ms.count();
        }
        T seconds_elapsed() const {
            sec my_s = std::chrono::duration_cast<sec>(time_elapsed());
            return my_s.count();
        }
    };
}

#endif //YATIMER_TIMER_H
