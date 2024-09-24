/*
  protoneer_3.xx_map.h - driver code for STM32F411 ARM processor on a Nucleo-F411RE board

  Part of grblHAL

  Copyright (c) 2020-2024 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 3
#error "Axis configuration is not supported!"
#endif

#if TRINAMIC_ENABLE
#error "Trinamic plugin not supported!"
#endif

#define BOARD_NAME "Protoneer v3 dtech"
#define BOARD_URL "https://blog.protoneer.co.nz/arduino-cnc-shield/"

#undef PROBE_ENABLE
#define PROBE_ENABLE 0

#define SERIAL_PORT     2   // GPIOA: TX = 2, RX = 3
#define I2C_PORT        1   // GPIOB: SCL = 8, SDA = 9
#define IS_NUCLEO_BOB
//#define PROTONEER_SPINDLE_PWM // Uncomment to use PA5 (D13) as spindle PWM output instead of spindle direction

#if ETHERNET_ENABLE
#define SPI_PORT                2 // GPIOB, SCK_PIN = 13, MISO_PIN = 14, MOSI_PIN = 15
#endif

// input output mesin milling
#define HAS_IOPORTS
#if HYDRAULIC_ENABLE // aktifkan di platformio.ini
#define AUXOUTPUT0_PORT GPIOB
#define AUXOUTPUT0_PIN 15 // hydraulic
#else
#define AUXOUTPUT0_PORT GPIOC
#define AUXOUTPUT0_PIN 5 // atc A
#endif
#ifdef HAS_IOPORTS
#define AUXOUTPUT1_PORT GPIOC
#define AUXOUTPUT1_PIN 12 // relase error

#define AUXINPUT0_PORT GPIOA
#define AUXINPUT0_PIN 11 // untuk input vfd error
#define AUXINPUT1_PORT GPIOA
#define AUXINPUT1_PIN 12 // untuk input motor warning
#endif

#if SPINDLE_ENABLE & (1 << SPINDLE_PWM0)
#undef SPINDLE_ENABLE
#undef DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_ENABLE SPINDLE_PWM0_NODIR
#define DRIVER_SPINDLE_DIR_ENABLE 0
#endif

// Define step pulse output pins.
#define X_STEP_PORT             GPIOA // D2
#define X_STEP_PIN              10
#define Y_STEP_PORT             GPIOB // D3
#define Y_STEP_PIN              3
#define Z_STEP_PORT             GPIOB // D4
#define Z_STEP_PIN              5
#define STEP_OUTMODE            GPIO_BITBAND
//#define STEP_PINMODE            PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT        GPIOB // D5
#define X_DIRECTION_PIN         4
#define Y_DIRECTION_PORT        GPIOB // D6
#define Y_DIRECTION_PIN         10
#define Z_DIRECTION_PORT        GPIOA // D7
#define Z_DIRECTION_PIN         8
#define DIRECTION_OUTMODE       GPIO_BITBAND
//#define DIRECTION_PINMODE       PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define STEPPERS_ENABLE_PORT    GPIOA // D8
#define STEPPERS_ENABLE_PIN     9
//#define STEPPERS_ENABLE_PINMODE PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT            GPIOC // D9
#define X_LIMIT_PIN             7
#define Y_LIMIT_PORT            GPIOB // D10
#define Y_LIMIT_PIN             6
#define Z_LIMIT_PORT            GPIOA // D11
#define Z_LIMIT_PIN             7 //di firmware se
#define LIMIT_INMODE            GPIO_BITBAND
#define Z_LIMIT_POLL

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 1
#define M3_AVAILABLE
#define M3_STEP_PORT            GPIOA
#define M3_STEP_PIN             6
#define M3_DIRECTION_PORT       GPIOA
#define M3_DIRECTION_PIN        5
#endif

#define AUXOUTPUT0_PORT         GPIOA // Spindle PWM or spindle direction
#define AUXOUTPUT0_PIN          2
#define AUXOUTPUT1_PORT         GPIOA // Spindle enable
#define AUXOUTPUT1_PIN          6

// Define driver spindle pins
#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PORT     AUXOUTPUT1_PORT
#define SPINDLE_ENABLE_PIN      AUXOUTPUT1_PIN
#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_PORT        AUXOUTPUT0_PORT
#define SPINDLE_PWM_PIN         AUXOUTPUT0_PIN
#elif DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PORT  AUXOUTPUT0_PORT
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT0_PIN
#endif
#endif //DRIVER_SPINDLE_ENABLE

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT      GPIOB // A3
#define COOLANT_FLOOD_PIN       0

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
#define CONTROL_PORT            GPIOA // A0
#define RESET_PIN               0
#define FEED_HOLD_PIN           1 // A1
#define CYCLE_START_PIN         4 // A2
#define CONTROL_INMODE          GPIO_MAP

// Spindle PWM & encoder pins.
// NOTE: these pins are not available on the Protoneer board!
#if SPINDLE_ENCODER_ENABLE
#define SPINDLE_PWM_PORT_BASE   GPIOA_BASE
#define SPINDLE_PWM_PIN         11
#define SPINDLE_INDEX_PORT      GPIOC
#define SPINDLE_INDEX_PIN       9
#define SPINDLE_PULSE_PORT      GPIOD
#define SPINDLE_PULSE_PIN       2
#endif

#if ETHERNET_ENABLE
#undef SPI_ENABLE
#define SPI_ENABLE              1
#define SPI_CS_PORT             GPIOB
#define SPI_CS_PIN              12
#define SPI_IRQ_PORT            GPIOB
#define SPI_IRQ_PIN             2
#define SPI_RST_PORT            GPIOB
#define SPI_RST_PIN             1
#endif

/**/
