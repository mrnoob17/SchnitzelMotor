
#include <stdio.h>

// Aparently works on Windows, Linux and Mac, have not tested on MAC!
#define TEXT_COLOR_BLACK "\x1b[30m"
#define TEXT_COLOR_RED "\x1b[31m"
#define TEXT_COLOR_GREEN "\x1b[32m"
#define TEXT_COLOR_YELLOW "\x1b[33m"
#define TEXT_COLOR_BLUE "\x1b[34m"
#define TEXT_COLOR_MAGENTA "\x1b[35m"
#define TEXT_COLOR_CYAN "\x1b[36m"
#define TEXT_COLOR_WHITE "\x1b[37m"
#define TEXT_COLOR_BRIGHT_BLACK "\x1b[90m"
#define TEXT_COLOR_BRIGHT_RED "\x1b[91m"
#define TEXT_COLOR_BRIGHT_GREEN "\x1b[92m"
#define TEXT_COLOR_BRIGHT_YELLOW "\x1b[93m"
#define TEXT_COLOR_BRIGHT_BLUE "\x1b[94m"
#define TEXT_COLOR_BRIGHT_MAGENTA "\x1b[95m"
#define TEXT_COLOR_BRIGHT_CYAN "\x1b[96m"
#define TEXT_COLOR_BRIGHT_WHITE "\x1b[97m"

#ifdef _WIN32
#define DEBUG_BREAK() __debugbreak()
#elif __linux__
#define DEBUG_BREAK() __asm__ volatile ("int3")
#endif

// TRACE: Update Game took %.02f seconds, time
template <typename... Args>
void _log(char* text, Args... args)
{
  char buffer[8192] = {};
  sprintf(buffer, text, args...);
  puts(buffer);
}

#define SM_TRACE(msg, ...) _log(TEXT_COLOR_GREEN "TRACE: \033[0m" msg, ##__VA_ARGS__);
#define SM_WARN(msg, ...) _log(TEXT_COLOR_YELLOW "WARN: \033[0m" msg, ##__VA_ARGS__);
#define SM_ERROR(msg, ...) _log(TEXT_COLOR_RED "ERROR: \033[0m" msg, ##__VA_ARGS__);

#define SM_ASSERT(x, msg, ...)                                                                    \
{                                                                                                 \
  if(!(x))                                                                                        \
  {                                                                                               \
    _log(TEXT_COLOR_RED "ASSERTION FAILED: Line: %d, File: %s \033[0m" msg, __LINE__, __FILE__);  \
    DEBUG_BREAK();                                                                               \
  }                                                                                               \
}


