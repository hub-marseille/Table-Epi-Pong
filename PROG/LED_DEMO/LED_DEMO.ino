#define WS2811_PIN  35
#define NUMLED  66 

unsigned char pixels[NUMLED*3];

void setup(void)
{
        pinMode(WS2811_PIN, OUTPUT);
        digitalWrite(WS2811_PIN, LOW);

        pixels[0] = 0xFF;  // LED #1 - red
        pixels[1] = 0xFF;  // LED #1 - blue
        pixels[2] = 0xFF;  // LED #1 - green
        pixels[3] = 0xCF;  // LED #2 - red
        pixels[4] = 0x00;  // LED #2 - blue
        pixels[5] = 0x8F;  // LED #2 - green
}

void loop()
{
        ws2811();
        delay(10);
}



#if F_CPU == 180000000
        #define DELAY_T0H       6
        #define DELAY_T0L       42
        #define DELAY_T1H       24
        #define DELAY_T1L       26
#elif F_CPU == 96000000
        #define DELAY_T0H       3
        #define DELAY_T0L       23
        #define DELAY_T1H       12
        #define DELAY_T1L       13
#elif F_CPU == 48000000
        #define DELAY_T0H       1
        #define DELAY_T0L       13
        #define DELAY_T1H       7
        #define DELAY_T1L       7
#elif F_CPU == 24000000
        #error "24 MHz not supported, use 48 or 96 MHz"
#endif

static inline void delayShort(uint32_t) __attribute__((always_inline, unused));
static inline void delayShort(uint32_t num)
{
        asm volatile(
                "L_%=_delayMicroseconds:"               "\n\t"
                "subs   %0, #1"                         "\n\t"
                "bne    L_%=_delayMicroseconds"         "\n"
                : "+r" (num) :
        );
}

void ws2811() {
        noInterrupts();
        for (unsigned char *p = pixels; p < pixels + sizeof(pixels); p++) {
                unsigned char n = *p;
                for (int mask = 0x80; mask; mask >>= 1) {
                        if (n & mask) {
                                digitalWriteFast(WS2811_PIN, HIGH);
                                delayShort(DELAY_T1H);
                                digitalWriteFast(WS2811_PIN, LOW);
                                delayShort(DELAY_T1L);
                        } else {
                                digitalWriteFast(WS2811_PIN, HIGH);
                                delayShort(DELAY_T0H);
                                digitalWriteFast(WS2811_PIN, LOW);
                                delayShort(DELAY_T0L);
                        }
                }
        }
        interrupts();
        delayMicroseconds(50);
}

