//
// Created by emiliodallatorre on 18/06/20.
//

#ifndef UI_H
#define UI_H

#endif

int getJX();
int getJY();

void pollPad();
void pollLatch();
int isKeyHold(int key); // Restituisce 1 se il tasto è premuto.

int isKeyDown(int key);
int isKeyUp(int key);
