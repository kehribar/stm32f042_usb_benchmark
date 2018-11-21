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
  sp = serial.Serial(port = sys.argv[1], baudrate = 999999999, timeout = 0.01)
  if(sp.isOpen() == True):
    sp.close()
  sp.open()

  # ...
  TEST_LEN = 2048

  # ...
  last_delta = 0
  bytes_total = 0
  t1 = datetime.now()

  # ...
  while True:

    # Generate random data
    buf = np.random.random(TEST_LEN) * 255
    buf = buf.astype(np.uint8)
    buf = bytearray(buf)

    # ...
    sp.write(buf)
    rbuf = sp.read(TEST_LEN)

    # ...
    if(rbuf == buf):
      bytes_total += len(rbuf)
      t2 = datetime.now()
      delta = t2 - t1
      delta = delta.total_seconds()
      if((delta - last_delta) > 1):
        speed = bytes_total / delta
        speed /= 1024
        print(speed, "kB/sec")
        last_delta = delta
    else:
      print("Data mismatch!")
      pass
