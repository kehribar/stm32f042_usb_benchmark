// ----------------------------------------------------------------------------
// 
// 
// ----------------------------------------------------------------------------
#include "usb.h"
#include "systick_delay.h"
#include <libopencm3/cm3/systick.h>

// ----------------------------------------------------------------------------
static volatile uint32_t m_tickVal;

// ----------------------------------------------------------------------------
void systick_delay_init()
{  
  static const uint32_t F_CPU = 48000000;

  systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);

  systick_set_reload((F_CPU / 1000) - 1);

  m_tickVal = 0;

  systick_interrupt_enable();
  
  systick_counter_enable();
}

// ----------------------------------------------------------------------------
void sys_tick_handler(void)
{
  if(m_tickVal)
  {
    m_tickVal -= 1;
  }
}

// ----------------------------------------------------------------------------
void _delay_ms(uint32_t arg)
{
  m_tickVal = arg;

  while(m_tickVal);
}
