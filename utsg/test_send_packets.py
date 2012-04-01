
def send(packet):
    print '<',repr(packet)

def send_packets(buffer, delim):
    packets = buffer.split(delim)
    ret=packets.pop(-1)
    if buffer[-1]==delim:
        print 'pop ret=', repr(ret)
        ret=''
    map(send, packets)
    return ret

test='one\ntwo\nthree\n'

for i in range(1,len(test)):
    print '----------------------'
    buf=test[0:i]
    print 'buffer=', repr(buf)
    buf = send_packets(buf, '\n')
    print 'ret=', repr(buf)