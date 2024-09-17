
#include "cpu.h" 
#include "log.h"

/**
 * @author Jose G.
 * @brief This class contains all previously defined implementation and logic of the 6502 microprocessor
 * @see cpu.h 
 */

Cpu::Cpu()
{
    bus->cpu = this;
    
    /**
     * @brief power up state
     * @url https://www.nesdev.org/wiki/CPU_power_up_state
     */
    regs = Cpu::Registers {
        .acc = 0x00,
        .x = 0x00,
        .y = 0x00,
        .pc = 0x0000,
        .sp = 0x00,
        .state = 0x00
    };
}

Cpu::~Cpu()
{
    
}

void Cpu::write(U16 addr, U8 value)
{
    bus->write(addr, value);
}
    
uint8_t Cpu::read(U16 addr)
{
    bus->read(addr);
}

/**
 * @brief addressing modes implementation
 */
U8 Cpu::IMM() {
    addr_abs = regs.pc++;
    
    return 0;
}


/**
 * @brief instructions implementation
 */
U8 Cpu::LDA_ins() {
    regs.acc = read(addr_abs);
    return 0;
}

void Cpu::populate()
{   
    for (int i = 0; i < 169; i++) {
        opcodeTable[i] = CpuInstruction{
            .opc = "BLANK",
            .operation = [this] () -> U8 { BLANK_ins(); },
            .addr_mode = [this] () -> U8 { BLANK_ins(); },
            .cycles = 0
        };
    }
    
    opcodeTable[169] = 
        /** 
         * @brief LDA Imediate instruction operation = M -> A, opcode byte = 0xA9, last member is the number of cycles, vector position 169
         */
        { "LDA", [this] () -> U8 { LDA_ins(); },  [this] () -> U8 { IMM(); }, 2 };
    
    
    
}


void Cpu::cpuTick()
{   
    g_cycles++;
    
    despathLog("Cycles: " + std::to_string(g_cycles));
    
    opcode = read(regs.pc);
    
    opcodeTable[opcode].operation();
    opcodeTable[opcode].addr_mode();
    g_cycles += opcodeTable[opcode].cycles;
}

void Cpu::execute()
{
    populate();
    
    while (running) {
        cpuTick();
    }
    
}
