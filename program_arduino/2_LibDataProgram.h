// File Program 1 : LibDataProgram.h
// buat class Data untuk ditampung nilai sensor
class DataVDC {
  public:
    int current;
    float voltage = 0.0, power;
};

class DataVAC {
  public: float V, I, P, E, Freq, pF;
};

// deklarasi variabel cutoff dan ref_voltage_system
const float cutoff             = 11.5;
const float ref_voltage_system = 4.25;

// deklarasi variabel interval program berjalan
const long interval_1 = 1000;   // 1000ms = 1 detik
const long interval_2 = 1000;   // 1000ms = 1 detik
const long interval_3 = 1000;   // 1000ms = 1 detik
const long interval_4 = 10;    // 100ms = 0.1 detik

// deklarasi variabel millis waktu sebelum jalannya program
unsigned long waktuSebelum_1 = 0;
unsigned long waktuSebelum_2 = 0;
unsigned long waktuSebelum_3 = 0;
unsigned long waktuSebelum_4 = 0;

char perintah = 0;
