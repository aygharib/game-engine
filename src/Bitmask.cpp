#include "Bitmask.h"

Bitmask::Bitmask() : bits(0) {}

auto Bitmask::setMask(Bitmask& other) -> void {
    bits = other.getMask();
}

auto Bitmask::getMask() const -> uint32_t {
    return bits;
}

auto Bitmask::getBit(int position) const -> bool {
    return (bits & (1 << position)) != 0;
}

auto Bitmask::setBit(int position, bool on) -> void {
    on ? setBit(position) : clearBit(position);
}

auto Bitmask::setBit(int position) -> void {
    bits = bits | 1 << position;
}

auto Bitmask::clearBit(int position) -> void {
    bits = bits & ~(1 << position);
}

auto Bitmask::clear() -> void {
    bits = 0;
}