import argparse
import serial

parser = argparse.ArgumentParser(description='Read from serial and echo message')
parser.add_argument('-d', '--device', help='path to serial device', required=True)
parser.add_argument('-r', '--rate', help='rate of serial communication', type=int, required=True)
parser.add_argument('-w', '--wait', help='seconds to wait before shutdown', type=int, required=True)
parser.add_argument('-s', '--sleep', help='seconds to sleep', type=int, required=True)
args = parser.parse_args()

DEVICE = args.device
RATE = args.rate
WAIT = args.wait
SLEEP = args.sleep

print 'Waiting for %d seconds, then shutting down for %d seconds ...' % (WAIT, SLEEP)

ser = serial.Serial(DEVICE, RATE)

cmd = 'SLEEP %d %d' % (WAIT, SLEEP)

cmd = cmd.strip() + '\n'

ser.write(cmd.encode())

