
#pragma once 

#include "types.h"

#include "cpu.h"

#include <array>

class Cpu;

class Bus {
    public:
    Bus();
    ~Bus();
    
    /**
     * @brief mos 6502 instance
     */
    Cpu* cpu = nullptr; 
    
    /**
     * @brief 
     */
    void write(U16 addr, U8 data);
        
     /**
     * @brief 
     */
    U8 read(U16 addr);
    
    private: // devices on the bus
    /**
     * @brief cpu ram map
     * @url https://www.nesdev.org/wiki/CPU_memory_map
     */
    std::array<U8, 2048> ram{};
        
};