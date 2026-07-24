#pragma once
#include <string_view>

constexpr std::string_view RESET = "\033[0m";
constexpr std::string_view BOLD = "\033[1m";
constexpr std::string_view UNDERLINE = "\033[4m";
constexpr std::string_view ITALIC = "\033[3m";

constexpr std::string_view GREEN = "\033[32m";
constexpr std::string_view RED = "\033[31m";
constexpr std::string_view CYAN = "\033[36m";

struct RGBStyle {
    bool newLine = true;
    bool isBold = false;
    bool isItalic = false;
    bool isUnderLine = false;
};

void rgb_print(unsigned int r, unsigned int g, unsigned int b,
               std::string_view msg,
               const RGBStyle& style = RGBStyle{});

void logSuccess(std::string_view msg);
void logError(std::string_view msg);
void logInfo(std::string_view msg);
