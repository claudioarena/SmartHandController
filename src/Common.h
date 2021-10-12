#pragma once

#include <Arduino.h>

#include "Constants.h"
#include "lib/constants/Constants.h"
#include "locales/Locales.h"
#include "../Config.h"
#include "../Extended.config.h"
#include "HAL/HAL.h"
#include "pinmaps/Models.h"
#include "lib/serial/Serial_ST4_Slave.h"

extern bool connected;

#if DEBUG != OFF
  #if DEBUG == REMOTE
    // echo strings to OnStep debug interface (supports embedded spaces and cr/lf)
    extern void debugPrint(const char* s);

    #define D(x)       { if (connected) { SERIAL_A.print(":EC"); SERIAL_A.print(x); SERIAL_A.print("#"); } }
    #define DF(x)      { if (connected) { SERIAL_A.print(":EC"); debugPrint(x); SERIAL_A.print("#"); } }
    #define DL(x)      { if (connected) { SERIAL_A.print(":EC"); SERIAL_A.print(x); SERIAL_A.print("&#"); } }
    #define DLF(x)     { if (connected) { SERIAL_A.print(":EC"); debugPrint(x); SERIAL_A.print("&#"); } }
  #else
    #define D(x)       SERIAL_DEBUG.print(x)
    #define DF(x)      SERIAL_DEBUG.print(F(x))
    #define DL(x)      SERIAL_DEBUG.println(x)
    #define DLF(x)     SERIAL_DEBUG.println(F(x))
  #endif
#else
  #define D(x)
  #define DF(x)
  #define DL(x)
  #define DLF(x)
#endif
#if DEBUG == VERBOSE || DEBUG == REMOTE
  #define V(x)       D(x)
  #define VF(x)      DF(x)
  #define VL(x)      DL(x)
  #define VLF(x)     DLF(x)
#else
  #define V(x)
  #define VF(x)
  #define VL(x)
  #define VLF(x)
#endif
