
#pragma once

#include <chrono>
#include <thread>
#include <cstdint>
#include <atomic>
#include <iostream>

#include "bus.h"

class Bus;

class Cpu {
    public:
    Cpu();
    ~Cpu();
    
    void cpuTick();
    
    void reset();
    
    void irq();
    
    void nmi();
    /**
     * @brief 
     */
    void execute();
    
    void stop();
    
    /**
     * @brief 
     */
    U8 read(U16 addr);
    
    /**
     * @brief 
     */
    void write(U16 addr, U8 value);
    
    void connectBus(Bus* i) { bus = i; }
    
    private:
    
    /** 
     * @brief registers of mos 6502
     * @url https://www.nesdev.org/wiki/CPU_registers 
     */
    struct Registers {
        
        U8 acc{};
        U8 x , y{};
        U16 pc{}; // 16-bits program counter
        U8 sp{};
        U8 state;
        
    }; /* struct Registers */
    
    /** 
     * @brief status flags of mos 6502
     * @url https://www.nesdev.org/wiki/Status_flags
     */
    struct Flags {
        int Carry{1 << 0};
        int Zero{1 << 1};
        int InterruptDisable{1 << 2};
        int Decimal{1 << 3};
        int Break{1 << 4};
        int Unused{1 << 5};
        int Overflow{1 << 6};
        int Negative{1 << 7};
    }; /* struct Flags */
    
    
    /** 
     * @brief opcodes functions
     * @url https://www.nesdev.org/wiki/6502_instructions
     */
    U8 LDA_ins();
    U8 BLANK_ins() { }
     
         
    /** 
     * @brief address mode official and unofficial of mos 6502
     * @url https://www.nesdev.org/wiki/CPU_addressing_modes
     */
    U8 IMP();	
    U8 IMM();	
	U8 ZP0();	
    U8 ZPX();	
	U8 ZPY();	
    U8 REL();
	U8 ABS();	
    U8 ABX();	
	U8 ABY();	
    U8 IND();	
	U8 IZX();	
    U8 IZY();
     
    /**
     * @brief cpu instruction implementation
     */
    struct CpuInstruction
    {    
        // opcode 
        std::string opc;
        
        // opcode function
        std::function<U8()> operation = nullptr;
        
        // address mode function
        std::function<U8()> addr_mode = nullptr;
        
        int cycles;
    };
    
    /**
     * @brief this variable store the byte of actual opcode 
     */
    U8 opcode;
        
    
    /**
     * @brief Bus instance
     */
    Bus* bus = nullptr;
    
      
    /**
     * @brief Registers instance
     */
    Registers regs;
    
    /**
     * @brief 
     */
    std::atomic<bool> running{};
    
    /**
     * @brief matrix opcode table
     */
    std::vector<CpuInstruction> opcodeTable;
    
    /**
     * @brief counter opcode remaining cycles
     */
    int r_cycles;
    
    /**
     * @brief counter global cycles
     */
    int g_cycles;
    
    /**
     * @brief end addr
     */
    U16 addr_abs;
    
    /**
     * @brief populate opcode table
     */
    void populate();
     
    /**
     * @brief 
     */
    std::thread cpu_execution_thread{};
};