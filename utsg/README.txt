UTSG

UDP
To
Serial
Gateway


This program connects a serial port to a series of UDP datagrams.

Data read from the serial port may be buffered until a complete line is ready, and each line is transmitted as a UDP packet.

Each UDP packet received is written to the serial port.  (See the section Newline Settings below for details)

INSTALLATION:

python setup.py install
or with the windows installer utsg-1.0.win32.exe



Usage: python -m utsg [options] [port [baudrate]]

Simple Serial to Network (UDP/IP) redirector.

Options:
  -h, --help            show this help message and exit
  -q, --quiet           suppress non error messages
  --spy                 peek at the communication and print all data to the
                        console

  Serial Port:
    Serial port settings

    -p PORT, --port=PORT
                        port, a number (default 0) or a device name
    -b BAUDRATE, --baud=BAUDRATE
                        set baud rate, default: 9600
    --parity=PARITY     set parity, one of [N, E, O], default=N
    --rtscts            enable RTS/CTS flow control (default off)
    --xonxoff           enable software flow control (default off)
    --rts=RTS_STATE     set initial RTS line state (possible values: 0, 1)
    --dtr=DTR_STATE     set initial DTR line state (possible values: 0, 1)

  Network settings:
    Network configuration.

    -P RECV_PORT, --recv_port=RECV_PORT
                        local receive UDP port
    -d DEST_HOST, --dest_host=DEST_HOST
                        destination hostname or '<broadcast>'
                        default=127.0.0.1
    -u DEST_PORT, --dest_port=DEST_PORT
                        destination UDP port

  Newline Settings:
    Convert newlines between network and serial port. Conversion is
    normally disabled and can be enabled by --convert.

    -c, --convert       enable newline conversion (default off)
    --net-nl=NET_NEWLINE
                        type of newlines that are expected on the network
                        (default: LF)
    --ser-nl=SER_NEWLINE
                        type of newlines that are expected on the serial port
                        (default: CR+LF)

NOTE: no security measures are implemented. Anyone can remotely connect to
this service over the network.  Any UDP datagrams arriving on the listen port
are sent to the serial device.    Data transmitted by the serial device are
sent to the destination host and port.

