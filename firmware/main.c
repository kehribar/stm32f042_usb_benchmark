// ----------------------------------------------------------------------------
// 
// 
// ----------------------------------------------------------------------------
#include <stdlib.h>
#include "usb.h"

// ----------------------------------------------------------------------------
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

// ---------------------------------------------------------------------------
void hardware_init();

// ---------------------------------------------------------------------------
int main()
{
  hardware_init();
  
  // Mockup data 
  uint8_t buf[64];
  uint8_t buflen = 64;
  for(int32_t i=0;i<buflen;i++)
  {
    buf[i] = i;
  }

  // ...
  while(1) 
  {

    // ...
    usb_poll();

    // ------------------------------------------------------------------------
    // Loopback test
    // ------------------------------------------------------------------------
    #if 1
      if(usb_isConnected())
      {
        int32_t amount = usb_rxDataAmount();

        if(amount > 0)
        {
          if(amount > 64)
          {
            amount = 64;
          }
          usb_rxData(buf, amount);
          usb_txData(buf, amount);
        }
      }
    // ------------------------------------------------------------------------
    // Transmit test
    // ------------------------------------------------------------------------
    #else
      if(usb_isConnected())
      {
        usb_txData(buf, buflen);
      }
    #endif
    // ------------------------------------------------------------------------
  }
}

// ---------------------------------------------------------------------------
void hardware_init()
{
  // ...
  rcc_clock_setup_in_hsi_out_48mhz();

  // ...
  usb_init();

  // Initialise onboard LED 
  rcc_periph_clock_enable(RCC_GPIOB);
  gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO3);
}
