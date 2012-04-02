start cmd /k python -m utsg -p COM6 -b 19200 --convert --ser-nl=CRLF -d "<broadcast>" -u 9000 -P 9002 --spy
start cmd /k python -m utsg -p COM3 -b 19200 --convert --ser-nl=CRLF -d "<broadcast>" -u 9001 -P 9000 --spy
