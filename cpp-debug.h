#ifndef CPP_DEBUG_H
#define CPP_DEBUG_H

#include <iostream>
#include <sstream>
#include <iomanip>

//
// Return a string with a hex dump representation of the provided bytes
//
std::string hexDump(const unsigned char* data, unsigned int len) {
  std::ostringstream ostr;
  ostr << "===========================================================================\n";
  for (unsigned i = 0; i < len; i += 16) {
    // index
    ostr << std::setw(5) << std::setfill('0') << std::dec << i << "  ";

    // hex representation
    for (int j = 0; j < 16; j++) {
      if (i + j < len) {
        ostr << std::setw(2) << std::hex << std::uppercase << int(data[i + j]) << " ";
      }
      else {
        ostr << "   ";
      }
      if (j == 7) {
        ostr << " ";
      }
    }
    ostr << " ";

    // char representation
    for (int j = 0; j < 16; j++) {
      if (i + j < len) {
        char ch = data[i + j];
        if (ch >= 32 && ch < 127) {
          ostr << ch;
        }
        else {
          ostr << ".";
        }
      }
      else {
        ostr << " ";
      }
      if (j == 7) {
        ostr << "  ";
      }
    }
    ostr << "\n";
  }

  ostr << "Length = " << std::setw(5) << std::dec << len;
  ostr << " ============================================================\n\n";
  return ostr.str();
}

//
// Print a hex dump representation of the given data to stdout.
//
void printHexDump(const unsigned char* data, unsigned int len) {
  std::cout << hexDump(data, len);
}



#endif
