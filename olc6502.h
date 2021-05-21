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

private:
    Bus     *bus = nullptr;
    uint8_t read(uint16_t a);
    void    write(uint16_t a, uint8_t d);

};