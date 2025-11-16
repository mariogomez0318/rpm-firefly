# rpm-firefly
Real-Time Embedded Framework for PWM Motor Actuation and Encoder-Based Speed Measurement Using a PIC24F Microcontroller

This project presents an embedded control implementation for a DC motor system integrating real-time speed measurement, temperature monitoring, and serial data acquisition within a PIC24F microcontroller architecture. The framework employs a PWM-based actuation scheme using Output Compare modules, coupled with an analog feedback channel for TMP36-driven reference input. Motor rotational velocity is computed through a high-resolution incremental encoder interfaced via hardware interrupts, while a 100-ms sampling interval—maintained through Timer1—enables robust estimation of shaft speed in revolutions per minute.

Additionally, the design incorporates a calibrated linear temperature-sensing model derived from a TMP36 transducer, enabling continuous thermal characterization of the system. The Peripheral Pin Select (PPS) subsystem is fully abstracted for modularity, providing deterministic mapping of UART, PWM, and interrupt resources to physical I/O pins.

The complete implementation emphasizes clarity, portability, and deterministic execution timing, offering a reproducible platform for undergraduate mechatronics experimentation, closed-loop control research, or instructional demonstrations of mixed analog-digital embedded systems.
