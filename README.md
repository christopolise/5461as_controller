# 5461as 4 digit 7 segment Controller

This is an experimental library to control the sevenseg part marked 5461as in my Elegoo Arduino Kit. (R3?) The part itself does *****NOT** come with a backpack, which means everything is controlled directly by the Arduino. Future ICs to facilitate a SPI or I2C connection to the microcontroller as to preserve more pins is always welcomed.

```bash

      7  8  9  10 11 12
      |  |  |  |  |  | 
    --------------------
    |                  |
    |      5461as      |
    |                  |
    --------------------
      |  |  |  |  |  |
      1  2  3  4  5  6

```

## Pinout
As far as I have been able to figure, the pins on the 5461as, as numbered above, have the following functions:

| Pin           | Segment     | Digit   |           
| ------------- |-------------|----------|
| 1      | E | | 
| 2      | D  | |
| 3      | decimal point | |
| 4      | c | |
| 5      | G | |
| 6      | | 1 |
| 7      | | 2 |
| 8      | A | |
| 9      | F | |
| 10     | | 3 |
| 11     | | 4 |
| 12     | B | |
