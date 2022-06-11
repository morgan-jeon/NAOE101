from machine import Pin, PWM
import utime

DC_HIGH = 17
DC_LOW = 16
SERVO = 21
TRIG = [0, 4, 8] # left, center, right
ECHO = [1, 5, 9]

servo_pwm = PWM(Pin(SERVO))
dc_high = PWM(Pin(DC_HIGH))
dc_high = PWM(Pin(DC_LOW))
trigger = [Pin(TRIG[i], Pin.OUT) for i in range(0,3)]
echo = [Pin(ECHO[i], Pin.IN) for i in range(0,3)]

def dc_init():
    dc_high.freq(50)
    dc_low.freq(50)
    dc_high.duty_u16(0)
    dc_low.duty_u16(0)

def dc_setSpeed(speed=0):
    dc_high.duty_u16(0)
    dc_low.duty_u16(0)
    utime.sleep(0.5)
    if speed > 0:
    	dc_high.duty_u16(speed) # 0-65535
    	dc_low.duty_u16(0)
    else speed < 0:
    	dc_low.duty_u16(speed) # 0-65535
    	dc_high.duty_u16(0)
    utime.sleep(1)
    
def servo_init():
    servo_pwm.freq(50)
    servo_pwm.duty_u16(5000)
    utime.sleep(0.5)

def servo_angle(angle: int):
    servo_pwm.duty_ns(5000 + angle*100)
    utime.sleep(0.5)

def ultra(number):
    trigger[number].low()
    utime.sleep_us(2)
    trigger[number].high()
    utime.sleep_us(5)
    trigger[number].low()
    while echo[number].value() == 0:
        signaloff = utime.ticks_us()
    while echo[number].value() == 1:
        signalon = utime.ticks_us()
    timepassed = signalon - signaloff
    distance = (timepassed * 0.0343) / 2
    return distance # CM단위

def isin(a):
    if 30 > a > 0:
        return True
    else:
        return False

def track():
    if isin(ultra(0)) or isin(ultra(1)) or isin(ultra(2)):
        dc_setSpeed(0)
    if isin(ultra(1)) and isin(ultra(0)): # left, center
        pass
    elif isin(ultra(1)) and isin(ultra(2)): # right, center
        pass
    else:
        pass

def main():
    dc_init()
    servo_init()
    servo_angle(0)
    dc_setSpeed(0)
    while True:
        print(f'{ultra(0)}, {ultra(1)}, {ultra(2)}')
        # track()
main()
