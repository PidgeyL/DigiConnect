import argparse
import base64
import serial
import time


if __name__ == '__main__':
    _ap = argparse.ArgumentParser(description='Transfer script for the DigiConnect cable')
    _ap.add_argument('data', type=str,                         help='Input file')
    _ap.add_argument('-s',   type=str, default='/dev/ttyACM0', help='Serial interface')
    _ap.add_argument('-w',   type=str, default='js',           help='wrapper type [js]')
    args = _ap.parse_args()

    data = open(args.data, 'rb').read()
    base = base64.b64encode(data).decode("utf-8")
    if args.w.lower() == 'js':
        text = "<html><head><script>function r(){l=document.createElement('a');l.setAttribute('id','i');l.download='file';l.href='data:application/octet-stream;charset=utf-8;base64,%s;document.body.appendChild(l);i=document.getElementById('i');i.click();i.remove()}</script></head><body><button onclick='r()'>Get File</button></body></html>"%base
    else:
        text = base

    ser = serial.Serial(args.s, 9600, timeout=.5)
    for ch in text:
        ser.write(ch.encode("utf-8"))
        time.sleep(.02)
    ser.close()
    
