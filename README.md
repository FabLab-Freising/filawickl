# Filawickl
this project contains the firmware running the Filawickl filament extruder situated in the FabLab Freising.

## State
This system is currently in an experimental state and needs some more work to actually run in any capacity. The filament winding mechanism is working so far, taking input from the hall effect sensor mounted next to the spool to wind the filament in neat lanes.

Things that still need to be done include:
- PWM controlling the Brake in the front of the Winding mechanism
- PWM controlling the spool motor
- Somehow measuring the diameter of the filament (We might be using [InFiDEL](https://github.com/drspangle/infidel-sensor) for that)
- Writing the control algorithm that adjusts speeds according to the measured diameter

## Hardware
We are currently trying to get everything to run from an Arduino Due covered by a RAMPS shield. Further hardware may be added for UX improvements.

For the extruder we are running the [Noztek Pro](https://noztek.com/product/noztek-pro/). We then intend to cool the filament with 4 PC cooling fans, pinch it through longboard wheels to adjust extrusion speed and eventually roll it up with the winding mechanism.

The winding mechanism consists of a stepper motor which guides the filament onto a dc motor run spool that is mounted on tennis balls allowing it to slip whenever it needs to (because the new filament isn't comming in fast enough).

## Software
The entire project is running on Arduino-flavoured C++ managed by PlatformIO. All of the code is contained int [main.cpp](src/main.cpp) as of now - but that will soon change.