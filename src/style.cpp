#include <iostream>
#include "../include/style.hpp"

void rgb_print(unsigned int r, unsigned int g, unsigned int b,
               std::string_view msg,
               const RGBStyle& style)
{
    int bold = style.isBold ? 1 : 0;
    int italic = style.isItalic ? 3 : 0;
    int underline = style.isUnderLine ? 4 : 0;

    std::cout << "\033[" << bold << ";" << italic << ";" << underline 
              << ";38;2;" << r << ";" << g << ";" << b << "m" 
              << msg << RESET 
              << (style.newLine ? "\n" : "");
}

void logSuccess(std::string_view msg) {
    std::cout << GREEN << BOLD << "[+] " << msg << RESET << "\n";
}

void logError(std::string_view msg) {
    std::cout << RED << BOLD << "[-] " << msg << RESET << "\n";
}

void logInfo(std::string_view msg) {
    std::cout << CYAN << "[*] " << msg << RESET << "\n";
}
