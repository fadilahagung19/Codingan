// File Program 2 : LibDataProgram.h
// buat class Data untuk ditampung nilai sensor
class DataVDC {
  public:
    int current;
    float voltage = 0.0, power;
};

class DataVAC {
  public: float V, I, P, E, Freq, pF;
};

// deklarasi variabel interval program berjalan
long interval_1 = 1000; // 1000ms = 1 detik
long interval_2 = 1000; // 1000ms = 1 detik
long interval_3 = 1000; // 1000ms = 1 detik

// deklarasi variabel millis waktu sebelum jalannya program
unsigned long waktuSebelum_1 = 0;
unsigned long waktuSebelum_2 = 0;
unsigned long waktuSebelum_3 = 0;