// File Program 2 : program_arduino.ino
#include <ACS712.h>
#include <PZEM004Tv30.h>
#include "LibDataProgram.h"

/* Keterangan : 
 * Sensor 1 : untuk PV
 * Sensor 2 : Untuk Battery
 * Relay 1 : Switch ke sumber battery
 * Relay 2 : Switch ke sumber PV
 * Relay 3 : Switch ke sumber PLN
 * Relay 4 : Switch ke sumber Inverter
 */
  
// define sensor analog input
#define sensor_voltage_1 A0
#define sensor_voltage_2 A1
#define sensor_current_1 A3
#define sensor_current_2 A4

// define relay output
#define relay_1 8     // RELAY BATTERY (8)
#define relay_2 11    // RELAY PV (11)
#define relay_3 12    // RELAY PLN
#define relay_4 13    // RELAY INVERTER
#define HIDUP LOW
#define MATI HIGH

// define Serial Communication PZEM004T
#define rx_1 4
#define tx_1 5
#define rx_2 6
#define tx_2 7

// define Reset Button
#define ResetButton 3
int nilaiReset;

// deklarasi object ACS712
/* Kode untuk type sensor
 * 5A   : ACS712_05B (185mV)
 * 20A  : ACS712_20A (100mV)
 * 30A  : ACS712_30A (66mV)
 */
#define ACS712TYPE 100
ACS712 acs_sensor_1(sensor_current_1, 5.0, 1023, ACS712TYPE);
ACS712 acs_sensor_2(sensor_current_2, 5.0, 1023, ACS712TYPE);

// deklarasi object PZEM004T
PZEM004Tv30 pzem_1(rx_1, tx_1);
PZEM004Tv30 pzem_2(rx_2, tx_2);

/* deklarasi object DataVDC untuk 
 * ditampung nilai Analog DC voltage & current 
 */
DataVDC PV;
DataVDC Battery;

// buat object DataVAC untuk ditampung nilai sensor PZEM
DataVAC Inverter;
DataVAC PLN;

void setup() {
  /* set kecepatan transfer data dari atmega328p ke 
   * serial monitor sebesar 9600 bps (bit per seconds)
   */
  Serial.begin(9600);
  
  // memanggil fungsi setup relay dan sensor acs712
  setupRelay();
  acs_autoMidPoin();
}

void loop() {
  // memanggil fungsi program main / program tester
  // funcMain();
  // funcTester();
}
