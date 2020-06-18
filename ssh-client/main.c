#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <common/ui.h>

#include <libssh.h>


#include "../common/callback.h"

#define VERS 1
#define REVS 0

PSP_MODULE_INFO("HELLO_WORLD", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf
/// Notare: in pspDebugScreenSetXY, il primo parametro è la colonna, il secondo la riga.

int count;

void updateCount(int increase) {
    if (increase) count += 1;
    else if (count != 0) count -= 1;
}

int main(void) {
    setupExitCallback();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    count = 0;
    pspDebugScreenSetTextColor(1348628);

    printf("Avvio programma...");

    while (isRunning()) {
        sceDisplayWaitVblankStart();
        // pspDebugScreenClear();
        pspDebugScreenSetXY(0, 2);

        printf("%d", count);

        pollPad();
        pollLatch();

        if (isKeyDown(PSP_CTRL_UP))
            updateCount(1);
        if (isKeyUp(PSP_CTRL_DOWN))
            updateCount(0);

        // printf("%d,%d", getJX(), getJY());
    }

    sceKernelExitGame();

    return 0;
}


