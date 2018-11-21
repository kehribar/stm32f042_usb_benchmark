
# STM32F042 USB Benchmark

STM32F042 is a cheap microcontroller in TSSOP20 packet with onboard USB peripheral. 

I wanted to benchmark the data transfer speed of the microcontroller with libopencm3 framework.

Even though libopencm3 doesn't utilize the 'Double Buffering' capabilities of the USB peripheral, library API is very clean and achievable speeds are not too far away from the theoretical maximum; so it is worth using.

I started with the cdc_acm example in the libopencm3 repository and added couple of helper methods and circular buffers to ease application development a little more.

## Results

**TX only speed:** 600 kBytes / sec

In this test, fixed data packet with 64 bytes of data continuously sent in an infinite loop. 

**Loopback speed:** 293 kBytes / sec 

In this test, host generates 2048 bytes length random data packet and sends it over USB, then waits for a response and checks the data is exactly the same or not.
