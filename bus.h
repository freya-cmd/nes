#pragma once
#include <cstdint>
#include <array>
#include "olc6502.h"
#include "olc2C02.h"
#include "Cartridge.h"

class Bus
{
public:
	Bus();
	~Bus();

public: 

	olc6502 cpu;	
	olc2C02 ppu;
	std::shared_ptr<Cartridge> cart;
	uint8_t cpuRam[2048];

public: 
	void    cpuWrite(uint16_t addr, uint8_t data);
	uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

private:

	uint32_t nSystemClockCounter = 0;

public: 

	void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);

	void reset();

	void clock();
};
