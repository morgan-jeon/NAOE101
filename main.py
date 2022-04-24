from machine import Pin, PWM
import utime

MID = 1500000
MIN = 1000000
MAX = 2000000

motor = Pin(14, Pin.OUT)
pwm = PWM(Pin(15))

pwm.freq(50)
pwm.duty_ns(MID)

def start(time):
	if time==0:
		motor.high()
	elif time == -1:
		motor.low()
	else:
		motor.high()
		utime.sleep(time)
		motor.low()

def left(angle):
	pwm.duty_ns()
	start()

def right(angle):
	pwm.duty_ns()
	start()

def scan():

def process():


while True:
	scan()
	process()
