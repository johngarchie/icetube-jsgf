/***************************************************************************
 Ice Tube Clock firmware August 13, 2009
 (c) 2009 Limor Fried / Adafruit Industries

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/


#define halt(x)  while (1)

#define DEBUG 1
#define DEBUGP(x)  if (DEBUG) {putstring_nl(x);}

#define BRITE_MIN	30
#define BRITE_MAX	90
#define BRITE_STEP	5

#define REGION_US 0
#define REGION_EU 1

// date format
#define DATE 0  // mm-dd-yy
#define DAY 1   // thur jan 1

#define DISPLAYSIZE 9

#define MAXSNOOZE 600 // 10 minutes
#define INACTIVITYTIMEOUT 10 // how many seconds we will wait before turning off menus


#define BEEP_8KHZ 5
#define BEEP_4KHZ 10
#define BEEP_2KHZ 20
#define BEEP_1KHZ 40

#define SEC_FULL 0
#define SEC_DIAL 1
#define SEC_AMPM 2
#define SEC_NONE 3

#define DAY_SUN		(1 << 0)
#define DAY_MON		(1 << 1)
#define DAY_TUE		(1 << 2)
#define DAY_WED		(1 << 3)
#define DAY_THUR	(1 << 4)
#define DAY_FRI		(1 << 5)
#define DAY_SAT		(1 << 6)

#define DAYS_WEEKEND	(DAY_SAT | DAY_SUN)
#define DAYS_WEEK	(DAY_MON | DAY_TUE | DAY_WED | DAY_THUR | DAY_FRI)
#define DAYS_ALL	(DAYS_WEEKEND | DAYS_WEEK)

#define EE_YEAR 1
#define EE_MONTH 2
#define EE_DAY 3
#define EE_HOUR 4
#define EE_MIN 5
#define EE_SEC 6
#define EE_ALARM_HOUR 7 
#define EE_ALARM_MIN 8
#define EE_ALARM_DAYS 9
#define EE_VOLUME 10
#define EE_REGION 11
#define EE_SNOOZE 12
#define EE_SECONDMODE 13
#define EE_MORNINGHR 14
#define EE_EVENINGHR 15
#define EE_DAYBRITE 16
#define EE_NIGHTBRITE 17
#define EE_DRIFT 18

#define DRIFT_MIN	(-64)
#define DRIFT_MAX	(64)

void delay(uint16_t delay);

void (*app_start)(void) = 0x0000;

void initbuttons(void);
void boost_init(void);
void speaker_init(void);

typedef uint8_t (transition_t)(uint8_t *);
void display_str(const char *s);
void display_str_trans(const char *s, transition_t *trans);

void set_time(void);
void set_alarm(void);
void set_date(void);
void set_brightness(void);
void set_volume(void);
void set_region(void);

void beep(uint16_t freq, uint8_t times);
void tick(void);

#define BOOST PD6
#define BOOST_DDR DDRD
#define BOOST_PORT PORTD

#define BUTTON1 PD5
#define BUTTON2 PB0
#define BUTTON3 PD4

#define VFDSWITCH PD3
#define VFDSWITCH_DDR DDRD
#define VFDSWITCH_PORT PORTD
#define VFDCLK PB5
#define VFDCLK_DDR DDRB
#define VFDCLK_PORT PORTB
#define VFDDATA PB3
#define VFDDATA_DDR DDRB
#define VFDDATA_PORT PORTB
#define VFDLOAD PC0
#define VFDLOAD_DDR DDRC
#define VFDLOAD_PORT PORTC
#define VFDBLANK PC3
#define VFDBLANK_DDR DDRC
#define VFDBLANK_PORT PORTC

#define ALARM PD2
#define ALARM_DDR DDRD
#define ALARM_PORT PORTD
#define ALARM_PIN PIND

#define SPK1 PB1
#define SPK2 PB2
#define SPK_PORT PORTB
#define SPK_DDR DDRB

#define SEG_A 19
#define SEG_B 17
#define SEG_C 14
#define SEG_D 13
#define SEG_E 15
#define SEG_F 18
#define SEG_G 16
#define SEG_H 11

#define DIG_1 4
#define DIG_2 12
#define DIG_3 5
#define DIG_4 10
#define DIG_5 6
#define DIG_6 9
#define DIG_7 8
#define DIG_8 7
#define DIG_9 3


#define NELEM(a)	(sizeof(a) / sizeof(*a))
