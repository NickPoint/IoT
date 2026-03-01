# Module 2

## Task 1 - Breadboards and Electronic Prototyping Intro

This task was executed by my partner. It covered electric circuit fundamentals, breadboard usage, LED wiring, diode behavior, and basic prototyping principles.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-1---breadboards-and-electronic-prototyping-intro).

## Task 2 - Collect Hardware

This task was executed by my partner. It involved collecting and documenting the required IoT hardware components for subsequent prototyping tasks.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-2---collect-hardware).

## Task 3 - “Hello World” Electronic Prototyping

This task was executed by my partner. It involved building and documenting a basic LED circuit using the Wemos D1 Mini and a breadboard.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-3----hello-world-electronic-prototyping).

## Task 4 - Fritzing, SimulIDE, or Cirkit Designer

This task was executed by my partner. It involved creating a schematic of the prototype using an electronic design tool.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-4---fritizing-simulide-or-cirkit-designer).

## Task 5 - Blink on the Wemos D1 Mini

This task was executed by my partner. It involved configuring the Wemos D1 Mini, flashing the Blink example, and controlling LEDs on multiple GPIO pins.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-5---blink-on-the-wemos-d1-mini).

## Task 6 - Toggle LED with Button

This task was executed by my partner. It involved implementing button-controlled LED toggling using digital input handling and pull-up configuration.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-6---toggle-led-with-button).

## Task 7 - Relay-Lock Button

This task was executed by my partner. It involved controlling a solenoid lock via a relay module using timed logic, serial commands, and button input.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-7---relay-lock-button).

## Task 8 - LED Fade (Optional)

This task was executed by my partner. It involved implementing PWM-based LED fading and analyzing timing and brightness behavior.
It is [here](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md#task-8---led-fade-optional-task-for-advanced-students).

## Task 9 - Getting to Know the IoT Cart, Devices and Peripheral Communication

In this task the goal was to understand what devices are available, how they work, and how they communicate with the Wemos D1 Mini microcontroller.

The following components were collected:

### DS18B20 (Dallas Temperature Sensor)

This is a digital temperature sensor. It measures temperature and sends digital data using the OneWire communication protocol.  
It is accurate and only needs one data pin.

**Use:** temperature measurement in IoT projects.

### DHT22 Sensor

The DHT22 measures temperature and humidity.  
It uses a single digital data line and communicates directly with a GPIO pin.

**Use:** indoor climate monitoring.

### MPR121 Touch Sensor

The MPR121 is a capacitive touch sensor controller.  
It allows multiple touch inputs (our has 12 electrodes).

**Communication:** I2C bus.

**Use:** touch buttons or interactive interfaces.

### Gesture Sensor

The gesture sensor detects hand movements such as left, right, up, and down gestures.

**Communication:** I2C bus.

**Use:** touchless control systems.

### RFID Reader (+ Tag)

The RFID reader reads information from RFID cards or tags.

**Communication:** SPI in most common cases, but also I2C, UART.

**Use:** access control, identification systems.

### RGB LED

An RGB LED contains red, green, and blue LEDs in one component.

## 3. Peripheral Communication

Different devices communicate using different communication buses.  
A bus is a method used by electronic devices to exchange data with the microcontroller.

The Wemos D1 Mini (ESP8266) supports several communication methods.

### 4.1 Direct GPIO (Digital Input/Output)

Direct GPIO means a device connects directly to a digital pin.

Example:
- DHT22 sensor

**Wiring example:**

| Device Pin | Wemos Pin |
|------------|-----------|
| DATA | D4 |
| VCC | 3V3 |
| GND | G |

The microcontroller reads digital signals directly.

### 4.2 OneWire

OneWire uses only one data wire for communication.

Example:
- DS18B20 temperature sensor

**Wiring example:**

| Device Pin | Wemos Pin |
|------------|-----------|
| DATA | D2 |
| VCC | 3V3 |
| GND | G |

A pull-up resistor (4.7kΩ) is required between DATA and VCC. In our case shild aready had built in resistor.

---

### 4.3 I2C Bus

I2C uses two wires:
- SDA (data)
- SCL (clock)

Multiple devices can share the same bus.

Examples:
- MPR121 touch sensor
- Gesture sensor
- RFID

**Wiring example:**

| Device Pin | Wemos Pin |
|------------|-----------|
| SDA | D2 |
| SCL | D1 |
| VCC | 3V3 |
| GND | G |

### 4.4 I3C

I3C is a newer version of I2C with higher speed and better efficiency.  
It is backward compatible with I2C devices, but most IoT Cart devices still use standard I2C.

### 4.5 SPI Bus

SPI is a fast communication protocol using multiple wires.

Pins:
- MOSI (Master Out Slave In)
- MISO (Master In Slave Out)
- SCK (Clock)
- CS (Chip Select)

Example:
- RFID reader

**Wiring example:**

| SPI Signal | Wemos Pin |
|------------|-----------|
| SCK | D5 |
| MISO | D6 |
| MOSI | D7 |
| CS | D8 |
| VCC | 3V3 |
| GND | G |

---

### 4.6 UART / RS232 / RS485

UART is serial communication using TX and RX pins.

Differences:
- UART: logic-level serial communication
- RS232: higher voltage serial standard
- RS485: industrial long-distance communication using differential signals

Example use:
- debugging via Serial Monitor
- some sensors or modules

### 4.7 PWM (Pulse Width Modulation)

PWM controls analog-like output using digital signals.

Example:
- RGB LED brightness control.

**Wiring example:**

| LED Color | Wemos Pin |
|-----------|-----------|
| Red | D5 |
| Green | D6 |
| Blue | D7 |
| Common | GND |

Each color uses a resistor.

PWM changes brightness by adjusting signal duty cycle.

## Code

[DS18B20 code](ds18b20/ds18b20.ino)

[MRP121 code](mpr121/mpr121.ino) - we didn't got this code to work. The MRP121 just don't recognises any touches.

[RGB LED](https://github.com/pauljurgens11/iot/blob/main/Module02/README.md) - did my teammate Paul


## Reflection 2

## Reflection 3
