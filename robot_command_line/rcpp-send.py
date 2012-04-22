#!/usr/bin/env python

import rcpp
import sys

script, port, data = sys.argv

sender=rcpp.Sender(int(port))
sender.send(data)
