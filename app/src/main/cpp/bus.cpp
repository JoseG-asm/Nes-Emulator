
#include "bus.h"

Bus::Bus()
{
    for (auto &i : ram) i = 0x00;
    
    cpu->connectBus(this);
}

Bus::~Bus() 
{
    
}

U8 Bus::read(U16 addr) 
{
    /* Ram mem range */
    if (addr >= 0x0000 && addr <= 0xFFFF) {
        return ram[addr];
    }
    
    return 0x0000;
}

void Bus::write(U16 addr, U8 data) 
{
    /* Ram mem range */
    if (addr >= 0x0000 && addr <= 0xFFFF) {
        ram[addr] = data;
    }
}