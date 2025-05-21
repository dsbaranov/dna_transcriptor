#pragma once
#include <algorithm>
#include <string>

namespace validation {
bool IsValidCodoneStringSize(const std::string& codone) {
  return codone.size() == 3u;
}

bool IsValidCodoneString(const std::string& codone) {
  return IsValidCodoneStringSize(codone) &&
         std::all_of(codone.begin(), codone.end(), [](char c) {
           return c == 'A' || c == 'C' || c == 'G' || c == 'T' || c == 'U';
         });
}

bool IsValidDNACodoneString(const std::string& codone) {
  return IsValidCodoneStringSize(codone) &&
         std::all_of(codone.begin(), codone.end(), [](char c) {
           return c == 'A' || c == 'C' || c == 'G' || c == 'T';
         });
}
bool IsValidRNACodoneString(const std::string& codone) {
  return IsValidCodoneStringSize(codone) &&
         std::all_of(codone.begin(), codone.end(), [](char c) {
           return c == 'A' || c == 'C' || c == 'G' || c == 'U';
         });
}

bool IsValidDNAString(const std::string& sequence) {
  return std::all_of(sequence.begin(), sequence.end(), [](char c) {
    return c == 'A' || c == 'C' || c == 'G' || c == 'T' || std::isspace(c);
  });
}

bool IsValidRNAString(const std::string& sequence) {
  return std::all_of(sequence.begin(), sequence.end(), [](char c) {
    return c == 'A' || c == 'C' || c == 'G' || c == 'U' || std::isspace(c);
  });
}
};  // namespace validation
