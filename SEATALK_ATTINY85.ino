/*
 * Initial attempts at exploring  software serial on ATTiny 85. 
 * Based on https://www.hackster.io/porrey/easy-serial-on-the-attiny-2676e6
 * 
 */
#include "SoftwareSerial.h" // use my local version in this code

// 
// ***
// *** Define the RX and TX pins. Choose any two
// *** pins that are unused. Try to avoid D0 (pin 5)
// *** and D2 (pin 7) if you plan to use I2C.
// ***
#define RX    3   // *** D3, Pin 2
#define TX    4   // *** D4, Pin 3
#define ST_in    0   // *** D4, Pin 3
#define LED 1
// ***
// *** Define the software based serial port. Using the
// *** name Serial so that code can be used on other
// *** platforms that support hardware based serial. On
// *** chips that support the hardware serial, just
// *** comment this line.
// ***


// do not call Serial, or digistump compiler will call its own version!
SoftwareSerial Serial_Port(RX, TX,false,false);
SoftwareSerial Seatalk(ST_in, TX,false,true); // modify  software serial to add 9 bit mode

// ***
// *** Pinout ATtiny25/45/85:
// *** PDIP/SOIC/TSSOP
// *** =============================================================================================
// ***
// ***        (PCINT5/RESET/ADC0/dW) PB5   [1]*  [8]   VCC
// *** (PCINT3/XTAL1/CLKI/OC1B/ADC3) PB3   [2]   [7]   PB2 (SCK/USCK/SCL/ADC1/T0/INT0/PCINT2)
// *** (PCINT4/XTAL2/CLKO/OC1B/ADC2) PB4   [3]   [6]   PB1 (MISO/DO/AIN1/OC0B/OC1A/PCINT1)
// ***                               GND   [4]   [5]   PB0 (MOSI/DI/SDA/AIN0/OC0A/OC1A/AREF/PCINT0)
// ***

// *****************************************
// ***
// *** For FTDI/232 Cable:
// *** https://www.adafruit.com/products/70
// ***
// *** Connect 3V  (red)    to Pin 8
// *** Connect GND (black)  to Pin 4
// *** Connect RX  (yellow) to Pin 3
// *** Connect TX  (orange) to Pin 2
// ***
// *****************************************

// *****************************************
// ***
// *** For Serial TTL Cable:
// *** https://www.adafruit.com/products/954
// ***
// *** Connect 3V  (red)   to Pin 8
// *** Connect GND (black) to Pin 4
// *** Connect RX  (white) to Pin 3
// *** Connect TX  (green) to Pin 2
// ***
// *****************************************



void setup()
{
  // ***
  // *** Initialize the Serial port
  // ***
  pinMode(LED, OUTPUT); //LED 
  Seatalk.begin(4800);
  Serial_Port.begin(9600);
  Serial_Port.println("starting Seatalk test");

 
  Serial_Port.println("Initialization complete.");
}

void loop()
{
  // ***
  // *** Keep track of the loop.
  // ***
  static uint32_t counter = 0;
  digitalWrite(LED, LOW);
 
  Serial_Port.print(counter); Serial_Port.print(": "); Serial_Port.print("testing...");

  // ***
  // *** Delay 2 seconds.
  // ***
  delay(2000);
  digitalWrite(LED, HIGH);
   delay(200);

  // ***
  // *** Increment the counter.
  // ***
  counter++;
}
