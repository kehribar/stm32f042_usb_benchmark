# -----------------------------------------------------------------------------
# 
# -----------------------------------------------------------------------------
import serial
import sys
import time
import numpy as np
from datetime import datetime

# -----------------------------------------------------------------------------
if __name__ == '__main__':

  # ...
  READ_SIZE = 1024

  # ...
  sp = serial.Serial(port = sys.argv[1], baudrate = 999999999, timeout = 0.01)
  if(sp.isOpen() == True):
    sp.close()
  sp.open()

  # ...
  last_delta = 0
  bytes_total = 0
  t1 = datetime.now()

  # ...
  while True:

    # ...
    rbuf = sp.read(READ_SIZE)
    bytes_total += len(rbuf)

    # ...
    t2 = datetime.now()
    delta = t2 - t1
    delta = delta.total_seconds()
    if((delta - last_delta) > 1):
      speed = bytes_total / delta
      speed /= 1024
      print(speed, "kB/sec")
      last_delta = delta
