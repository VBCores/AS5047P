# AS5047P - Arduino Library

## Contents

- [AS5047P - Arduino Library](#as5047p---arduino-library)
  - [Contents](#contents)
  - [Tl;Dr](#tldr)
  - [Project Status ToDo's](#project-status-todos)
  - [About the AS5047P](#about-the-as5047p)

## Tl;Dr
An Arduino library for the AS5047P high-resolution rotary position sensor.

## Project Status ToDo's

- [X] Read / Write functions for all registers implemented.
- [X] Doxygen comments added.
- [X] [BasicReadAngle.ino](examples/BasicReadAngle/BasicReadAngle.ino) successfully tested on an Arduino Mega & Adafruit Feather M0
- [X] [keywords.txt](keywords.txt) updated for main library functions.
- [ ] [keywords.txt](keywords.txt) updated for all library functions.
- [ ] Parity check on incoming data.
- [ ] Sensor status output as string.
- [ ] Adding a CI pipline.
- [ ] Build & deploy doxygen documentation for the library.
- [ ] [Readme.md](README.md) update.
- [ ] Additional examples.
- [ ] Implementation & test of programming the one time programmable register of the AS5047P.

## About the AS5047P

The AS5047P datesheet can be found [here](https://ams.com/documents/20143/36005/AS5047P_DS000324_2-00.pdf/a7d44138-51f1-2f6e-c8b6-2577b369ace8).