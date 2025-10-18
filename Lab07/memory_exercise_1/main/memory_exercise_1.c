#include "esp_heap_caps.h"

// Memory capability flags
#define MALLOC_CAP_EXEC       (1<<0)   // Memory can execute code
#define MALLOC_CAP_32BIT      (1<<1)   // 32-bit aligned
#define MALLOC_CAP_8BIT       (1<<2)   // 8-bit access allowed  
#define MALLOC_CAP_DMA        (1<<3)   // DMA capable
#define MALLOC_CAP_PID2       (1<<4)   // PID2 memory
#define MALLOC_CAP_PID3       (1<<5)   // PID3 memory
#define MALLOC_CAP_PID4       (1<<6)   // PID4 memory
#define MALLOC_CAP_PID5       (1<<7)   // PID5 memory
#define MALLOC_CAP_PID6       (1<<8)   // PID6 memory
#define MALLOC_CAP_PID7       (1<<9)   // PID7 memory
#define MALLOC_CAP_SPIRAM     (1<<10)  // External SPIRAM
#define MALLOC_CAP_INTERNAL   (1<<11)  // Internal memory
#define MALLOC_CAP_DEFAULT    (1<<12)  // Default allocation

// Convenience combinations
#define MALLOC_CAP_IRAM_8BIT  (MALLOC_CAP_EXEC | MALLOC_CAP_8BIT)
#define MALLOC_CAP_DMA_32BIT  (MALLOC_CAP_DMA | MALLOC_CAP_32BIT)