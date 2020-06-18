#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>

#include "../common/callback.h"

#define VERS 1
#define REVS 0

PSP_MODULE_INFO("HELLO_WORLD", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf

/// Notare: in pspDebugScreenSetXY, il primo parametro è la riga, il secondo la colonna.

int main(void)
{
	pspDebugScreenInit();
	setupExitCallback();

	while(isRunning())
	{
		pspDebugScreenSetXY(0, 0);
		printf("Hello World!");
		pspDebugScreenSetXY(0, 1);
		printf("Emilio è un genio!");
		sceDisplayWaitVblankStart();
	}

	sceKernelExitGame();

	return 0;
}
