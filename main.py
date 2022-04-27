from machine import Pin, PWM
import utime

DC_HIGH = 10
DC_LOW = 8
SERVO = 6

servo_pwm = PWM(Pin(SERVO))
dc_high = PWM(Pin(DC_HIGH))
dc_high = PWM(Pin(DC_LOW))

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

def main():
    dc_init()
    servo_init()

    dc_setSpeed(30000)
    
    servo_angle(30)
    utime.sleep(1)
    
    servo_angle(0)
    utime.sleep(1)
    
    servo_angle(-30)
	utime.sleep(1)
    
    servo_angle(0)
    
    dc_setSpeed(0)

main()
