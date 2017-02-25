from gpiozero import LED, PWMLED, Button
from signal import pause
from time import sleep


def toggle_led():
    led = LED(2)
    led.on()
    sleep(.5)
    led.off()
    sleep(.5)


def blink_led():
    led = LED(2)
    led.blink()
    pause()


def button_led():
    led = LED(2)
    button = Button(3)
    button.when_pressed = led.on
    button.when_released = led.off
    pause()


def button_led2():
    led = LED(2)
    button = Button(3)
    while True:
        button.wait_for_press()
        sleep(.1)
        led.toggle()
        sleep(.1)


def pwmled():
    pwmled = PWMLED(2)
    button = Button(3)

    i = 0
    p = True
    quit = False

    while not quit:

        pwmled.value = i / 500.0
        if(p):
            i += 1
        else:
            i -= 1
        if(i >= 500):
            p = False
        elif(i <= 0):
            p = True

        if button.is_pressed:
            quit = True
        sleep(0.002)

    pwmled.value = 0


def main():
    pwmled()

if __name__ == '__main__':
    main()
