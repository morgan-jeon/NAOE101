from machine import Pin, PWM
import utime

DC_HIGH = 
DC_LOW = 
SERVO = 
TRIG = 
ECHO = 

servo_pwm = PWM(Pin(SERVO))
dc_high = PWM(Pin(DC_HIGH))
dc_high = PWM(Pin(DC_LOW))
trigger = Pin(TRIG, Pin.OUT)
echo = Pin(ECHO, Pin.IN)

def dc_init():
    dc_high.freq(1000)
    dc_low.freq(1000)
 
    dc_high.low()
    dc_low.low()

def dc_setSpeed(speed=0):
    dc_high.low()
    dc_low.low()
    utime.sleep(0.5)
    if speed > 0:
    	dc_high.duty_u16(speed) # 0-65535
    	dc_low.low()
    else speed < 0:
    	dc_low.duty_u16(speed) # 0-65535
    	dc_high.low()
    
def servo_init():
    servo_pwm.freq(1000)
    servo_pwm.duty_ns(1500000)

def servo_angle(angle: int):
    servo_pwm.duty_ns(1500000 + angle*10000)
    utime.sleep(0.5)

def ultra():
    trigger.low()
    utime.sleep_us(2)
    trigger.high()
    utime.sleep_us(5)
    trigger.low()
    while echo.value() == 0:
        signaloff = utime.ticks_us()
    while echo.value() == 1:
        signalon = utime.ticks_us()
    timepassed = signalon - signaloff
    distance = (timepassed * 0.0343) / 2
    return distance # CM단위

def left():
    servo_angle(30)
    utime.sleep(0.7)


def right():
    servo_angle(-30)
    utime.sleep(0.7)

def center():
    servo_angle(0)
    utime.sleep(0.7)

def main():
    dc_init()
    servo_init()
    servo_angle(0)
    dc_setSpeed(10000)
    while True:
        if ultra() < 10:
            dc_setSpeed(0)
            left()
            dc_setSpeed(10000)
            center()
            right()
            center()
        utime.sleep(0.5)

main()
