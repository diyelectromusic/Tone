// Tone Chords - This plays multiple tones using all four timers
// on an ATmega32U4 based board, such as the Arduino Leonardo.
//
// Contributed by Kevin (@diyelectromusic)
//
// Timer 0 is used for delay() and millis() and will be chosen
// last if selected after timers 1, 3 and 4 (there is no timer 2).
//
// But this means we can't rely on these functions.  In fact, if
// you try to use them after initialising the note player to use
// all timers, then delay() will simply hang.
//
// For a non timer AVR delay function we can use the _delay_ms()
// function from util/delay.h which (as I understand it) uses
// the timing of CPU instructions to give a (less accurate) delay.
//
#include <Tone.h>
#include <util/delay.h>

Tone notePlayer[4];

void setup(void)
{
  // Create tones on pins 2, 3, 4, 5.
  notePlayer[0].begin(2);
  notePlayer[1].begin(3);
  notePlayer[2].begin(4);
  notePlayer[3].begin(5);
}

void loop(void)
{
  // Suspense...
  notePlayer[0].play(NOTE_G3);
  notePlayer[1].play(NOTE_B3);
  notePlayer[2].play(NOTE_D4);
  notePlayer[3].play(NOTE_F4);
  _delay_ms(3000);

  // ... and resolution
  notePlayer[0].play(NOTE_C3);
  notePlayer[1].play(NOTE_G3);
  notePlayer[2].play(NOTE_C4);
  notePlayer[3].play(NOTE_E4);
  _delay_ms(3000);
}
