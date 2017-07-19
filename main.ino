#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms to be detected
  delay(500);

  // Press win + r
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  
  // Write download url and press enter
  Keyboard.print(F("http://downloads.tuxfamily.org/dc4lan/Euskal%20Encounter%2025/Windows/Preconfigurados/EE25_AirDCpp_x64.zip\n"));
 // Wait for download to end
  delay(25000);
  
  //Close browser tab
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(KEY_F4);
  delay(50);
  Keyboard.release(KEY_F4);
  delay(50);
  Keyboard.release(KEY_LEFT_ALT);
  
  //Uncompress the file in the desktop
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print(F("PowerShell\n"));
  delay(500);
  Keyboard.print(F("Expand-Archive -Path $env:USERPROFILE/Downloads/EE25_AirDCpp_x64.zip -DestinationPath $env:USERPROFILE/Desktop; exit\n"));

  // Wait til file is uncompressed
  delay(10000);
 
  // Open config guide
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print(F("%userprofile%/Desktop/EE25_AirDCpp_x64/Guia configuracion tres pasos EE25_AirDCpp.pdf\n"));

 // Wait to avoid failures on last key press
  delay(2000);
  
  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
