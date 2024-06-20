#include"peripherals/rpi_mmu.h"

#define PM_PASSWORD 0x5a000000
#define PM_RSTC PHYS_TO_VIRT( 0x3F10001c)
#define PM_WDOG PHYS_TO_VIRT( 0x3F100024)

void set(long addr, unsigned int value) {
    volatile unsigned int* point = (unsigned int*)addr;
    *point = value;
}

void reset(unsigned int tick) {        // reboot after watchdog timer expire
    set(PM_RSTC, PM_PASSWORD | 0x20);  // full reset
    set(PM_WDOG, PM_PASSWORD | tick);  // number of watchdog tick
}

void cancel_reset() {
    set(PM_RSTC, PM_PASSWORD | 0);  // cancel reset
    set(PM_WDOG, PM_PASSWORD | 0);  // number of watchdog tick
}