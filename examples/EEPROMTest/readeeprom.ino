/*
  MicrowireEEPROM Example Sketch
 Reads and writes a Microwire EEPROM.
 Written by Timo Schneider <timos@perlplexity.org> 
 Modified by 5ch4um1
 This code is in the public domain.
*/


#include "MicrowireEEPROM.h"


// Microwire needs four wires (apart from VCC/GND) DO,DI,CS,CLK
// configure them here, note that DO and DI are the pins of the
// EEPROM, so DI is an output of the uC, while DO is an input
// Modified this to fit what seems to be the most common pin configuration on an arduino nano:
int CS=10; int CLK=13; int DI=11; int DO=12;

// EEPROMS have different sizes. Also the number of bits per page varies.
// We need to configure the page size in bits (PGS) and address bus width
// in bits (ADW). The speed at which the clock is run is configured in
// microseconds.
int PGS=16; int ADW=8; int SPD=200;

// initialize the library
MicrowireEEPROM ME(CS, CLK, DI, DO, PGS, ADW, SPD); 

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read 512 bytes
  for (int addr=0; addr < 255; addr++) {
   
   
    // read the value
   unsigned int r = ME.read(addr);
    
    // give some debug output
    Serial.print("Address "); 
    Serial.print(addr, HEX);
    Serial.print(" read ");
    Serial.print(r, HEX);
    Serial.println();
    
    // EEPROMS wear out, so don't write too fast
    delay(1000);
  }
  
}
