#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include <pigpio.h>

/*
gpio_timing.c
based on freq_count_1 example from PigPIO library https://abyz.me.uk/rpi/pigpio/code/freq_count_1.zip

make
$ sudo ./gpio_timing 4
make clean

This program uses the gpioSetAlertFunc function to request
a callback (the same one) for each gpio to be monitored.

*/

// Using current StateMachine code toggles GPIO 3 times per interaction
// Simply pulls io 25 down at notable times, resetting in between. Specifically when voice is told to play something audible
//    1. Play tone indicating hot word detected
//    2. Play tone indicating no more audio being collected
//    3. Play response audio based on the command
// 1->2 audio collection time
// 2->3 processing time
#define PULSES_PER_INTERACTION 3

#define MAX_GPIOS 32

#define OPT_P_MIN 1
#define OPT_P_MAX 1000
#define OPT_P_DEF 20

#define OPT_R_MIN 1
#define OPT_R_MAX 300
#define OPT_R_DEF 100

#define OPT_S_MIN 1
#define OPT_S_MAX 10
#define OPT_S_DEF 5

typedef struct
{
   uint32_t first_tick;
   uint32_t last_tick;
   uint32_t pulse_count;
} gpioData_t;

static volatile gpioData_t g_gpio_data[MAX_GPIOS];
static volatile gpioData_t l_gpio_data[MAX_GPIOS];

static volatile int g_reset_counts[MAX_GPIOS];

static uint32_t g_mask;

static int g_num_gpios;
static int g_gpio[MAX_GPIOS];

static int g_opt_p = OPT_P_DEF; // period
static int g_opt_r = OPT_R_DEF; // refresh rate (reset)
static int g_opt_s = OPT_S_DEF; // sample rate
static int g_opt_t = 0;

void usage()
{
   fprintf(stderr,
           "\n"
           "Usage: sudo ./gpio_timing gpio_num\n"
           "\nEXAMPLE\n"
           "sudo ./gpio_timing 4\n"
           "Monitor gpio 4\n"
           "\n");
}

void fatal(int show_usage, char *fmt, ...)
{
   char buf[128];
   va_list ap;

   va_start(ap, fmt);
   vsnprintf(buf, sizeof(buf), fmt, ap);
   va_end(ap);

   fprintf(stderr, "%s\n", buf);

   if (show_usage)
      usage();

   fflush(stderr);

   exit(EXIT_FAILURE);
}

void edges(int gpio, int level, uint32_t tick)
{

   if (level == 0)
   {
      // Logic for matrix voice
      // On PULSES_PER_INTERACTION pulse reset to 0
      // On first pulse set initial time
      if (l_gpio_data[gpio].pulse_count == PULSES_PER_INTERACTION)
      {
         l_gpio_data[gpio].pulse_count = 0;
      }
      if (l_gpio_data[gpio].pulse_count == 0)
      {
         l_gpio_data[gpio].first_tick = tick;
      }
      l_gpio_data[gpio].last_tick = tick;
      l_gpio_data[gpio].pulse_count++;
      printf("logic level change to low\n\tcount: %d\n\ttime: %d\n",
             l_gpio_data[gpio].pulse_count,
             
             l_gpio_data[gpio].last_tick - l_gpio_data[gpio].first_tick);
   }

   if (g_reset_counts[gpio])
   {
      g_reset_counts[gpio] = 0;
      l_gpio_data[gpio].first_tick = tick;
      l_gpio_data[gpio].last_tick = tick;
      l_gpio_data[gpio].pulse_count = 0;
   }
}

int main(int argc, char *argv[])
{
   int i, rest, g, wave_id, mode, diff, tally;
   gpioPulse_t pulse[2];
   int count[MAX_GPIOS];

   /* get the gpios to monitor */

   g_num_gpios = 0;

   for (i = 1; i < argc; i++)
   {
      g = atoi(argv[i]);
      if ((g >= 0) && (g < 32))
      {
         g_gpio[g_num_gpios++] = g;
         g_mask |= (1 << g);
      }
      else
         fatal(1, "%d is not a valid g_gpio number\n", g);
   }

   if (!g_num_gpios)
      fatal(1, "At least one gpio must be specified");

   printf("Monitoring gpios");
   for (i = 0; i < g_num_gpios; i++)
      printf(" %d", g_gpio[i]);
   printf("\nSample rate %d micros, refresh rate %d deciseconds\n",
          g_opt_s, g_opt_r);

   gpioCfgClock(g_opt_s, 1, 1);

   if (gpioInitialise() < 0)
      return 1;

   gpioWaveClear();

   pulse[0].gpioOn = g_mask;
   pulse[0].gpioOff = 0;
   pulse[0].usDelay = g_opt_p;

   pulse[1].gpioOn = 0;
   pulse[1].gpioOff = g_mask;
   pulse[1].usDelay = g_opt_p;

   gpioWaveAddGeneric(2, pulse);

   wave_id = gpioWaveCreate();

   /* monitor g_gpio level changes */

   for (i = 0; i < g_num_gpios; i++)
      gpioSetAlertFunc(g_gpio[i], edges);

   mode = PI_INPUT;

   if (g_opt_t)
   {
      gpioWaveTxSend(wave_id, PI_WAVE_MODE_REPEAT);
      mode = PI_OUTPUT;
   }

   for (i = 0; i < g_num_gpios; i++)
      gpioSetMode(g_gpio[i], mode);

   while (1)
   {
      // TODO add breakout based on condition
   }

   gpioTerminate();
}
