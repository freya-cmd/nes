#pragma once

class Bus;

class olc6502
{
    public: 
        olc6502();
        ~olc6502();

public:
    enum FLAGS6502
    {
        C = (1 << 0),
        Z = (1 << 1).
        I = (1 << 2),
        D = (1 << 3),
        B = (1 << 4),
        U = (1 << 5),
        V = (1 << 6),
        N = (1 << 7),
    };

    uint8_t  a      = 0x00;
	uint8_t  x      = 0x00;
	uint8_t  y      = 0x00;
	uint8_t  stkp   = 0x00;
	uint16_t pc     = 0x0000;
	uint8_t  status = 0x00;		


    void ConnectBus(Bus *n) { bus = n; }

	uint8_t IMP();	uint8_t IMM();	
	uint8_t ZP0();	uint8_t ZPX();	
	uint8_t ZPY();	uint8_t REL();
	uint8_t ABS();	uint8_t ABX();	
	uint8_t ABY();	uint8_t IND();	
	uint8_t IZX();	uint8_t IZY();

private:
    Bus     *bus = nullptr;
    uint8_t read(uint16_t a);
    void    write(uint16_t a, uint8_t d);

    uint8_t GetFlag(FLAG6502 f);
    void    SetFlag(FLAG6502 f, bool v);

};