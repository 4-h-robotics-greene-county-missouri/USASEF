python utsg.py -p COM6 -b 19200 -d "<broadcast>" -u 9000 -P 9002 --spy
python utsg.py -p COM3 -b 19200 -d "<broadcast>" -u 9001 -P 9000 --spy -c --net-nl=CR --ser-nl=CRLF
pause