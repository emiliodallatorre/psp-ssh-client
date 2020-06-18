//
// Created by emiliodallatorre on 18/06/20.
//

#include "ui.h"

#include <pspctrl.h>

static SceCtrlData data;

int getJX() {
    return data.Lx;
}

int getJY() {
    return data.Ly;
}

void pollPad() {
    sceCtrlReadBufferPositive(&data, 1);
}


static SceCtrlLatch latch;

void pollLatch() {
    sceCtrlReadLatch(&latch);
}

int isKeyHold(int key) {
    return (latch.uiPress & key);
}

int isKeyDown(int key) {
    return (latch.uiMake & key);
}

int isKeyUp(int key) {
    return (latch.uiBreak & key);
}
