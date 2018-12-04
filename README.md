# Quadrotor
Custom quadrotor software

## Environment Setup
### Getting the tools
1. Install `avr-gcc`.
2. Install `avr-libc`.
3. Install `CMake`.

### Building the projcet
1. Create a build directory to hold all the CMake build files
2. Navigate to this directory and run `cmake ../`
3. Run `make`

Redefine `AVR_UPLOADTOOL_PORT` to be the port connected to the Arduino
(e.g. `COM3`, `/dev/tty.usbmodemX`, etc.) in the `CMakeCache.txt` file.
Redefine `AVR_MCU` to be the **M**icro**C**ontroller**U**nit of the
Arduino connected to the port in the `CMakeCache.txt` file.
Set `AVR_PROGRAMMER` to `arduino` in `CMakeCache.txt` as well.
