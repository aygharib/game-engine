#pragma once

#include <cstdint>

class Bitmask {
public:
    Bitmask();
    
	// Overwrites this bitmask
    auto setMask(Bitmask& other) -> void;
	
	// Returns binary representation of the bitmask
    [[nodiscard]] auto getMask() const -> uint32_t;
    
	// Returns true if bit at position = 1, else false
    [[nodiscard]] auto getBit(int position) const -> bool;
   
	// Sets bit at specified position to 1 or 0 (true or false)
    auto setBit(int position, bool on) -> void;
	
	// Sets bit at position to 1
    auto setBit(int position) -> void;
	
	// Sets bit at position to 0
    auto clearBit(int position) -> void;
    
	// Sets all bits to 0
    auto clear() -> void;
    
private:
    uint32_t bits;
};