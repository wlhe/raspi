/* main.c
 * linux frame buffer
 * clone from https://github.com/littlevgl/lv_boards/blob/master/linux_frame_buffer/main.c
*/
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_examples/lv_apps/demo/demo.h"
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*Add a display the LittlevGL sing the frame buffer driver*/
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.disp_flush = fbdev_flush;      /*It flushes the internal graphical buffer to the frame buffer*/
    lv_disp_drv_register(&disp_drv);

    /*Create a Demo*/
    demo_create();


    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_tick_inc(1);
        lv_task_handler();
        usleep(1000);
    }

    return 0;
}