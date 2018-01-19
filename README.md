# ADC

This C++ program reads sampled signal values from a text file (`values.txt`) and calculates various properties of the signal, including minimum and maximum values, amplitude, DC offset, period, frequency, angular frequency, phase angle, RMS, and calculation time.

The program assumes uniform sampling at a fixed frequency (`f = 15000 Hz`).

## Features

* Reads sampled signal values from `values.txt`.
* Calculates:

  * Minimum and maximum values
  * Amplitude and DC offset
  * Period and frequency
  * Angular frequency
  * Phase angle relative to zero crossing
  * RMS value (AC and total including DC)
* Measures execution time.
* Prints all results in a clean formatted output.

## Notes

* Zero crossing detection may be inaccurate for noisy signals.
* `system("cls")` and `system("pause")` are Windows-specific.
* Sampling frequency is hardcoded.

