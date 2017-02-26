#include <bcm2835.h>

int main(int argc, char **argv)
{
    if (!bcm2835_init())
    {
        return 1;
    }

    bcm2835_gpio_fsel(RPI_GPIO_P1_11, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_fsel(RPI_GPIO_P1_05, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(RPI_GPIO_P1_05, BCM2835_GPIO_PUD_UP);

    bcm2835_gpio_write(RPI_GPIO_P1_11, HIGH);

    while (bcm2835_gpio_lev(RPI_GPIO_P1_05) != 0)
        ;

    bcm2835_gpio_write(RPI_GPIO_P1_11, LOW);

    bcm2835_close();

    return 0;
}