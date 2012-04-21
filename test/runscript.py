#!/usr/bin/env python

import rcpp
import time

sender = rcpp.Sender(9000)

sender.send('m+10+10')
time.sleep(2)
sender.send('m+00+00')
time.sleep(1)
sender.send('m-10-10')
time.sleep(2)
sender.send('m+00+00')

