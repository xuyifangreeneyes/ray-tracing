#include "color.h"

void writeColor(std::ostream& os, const Color& color) {
  os << static_cast<int>(MaxColorValue * color.X()) << " "
     << static_cast<int>(MaxColorValue * color.Y()) << " "
     << static_cast<int>(MaxColorValue * color.Z()) << "\n";
}