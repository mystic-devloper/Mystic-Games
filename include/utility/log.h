#ifndef MYSTIC_GAMES_LOG_H_
#define MYSTIC_GAMES_LOG_H_

#include <cstdio>   // For snprintf
#include <cstdarg>  // For va_list

namespace mystic {
enum class LogLevel {
  Trace,
  Debug,
  Info,
  Warning,
  Error,
  Fatal
};

// User-defined logging callback. Includes file, line, and function name.
using LogCallback = void(*)(LogLevel level, const char* message, const char* file, int line, const char* func);

static LogCallback s_log_callback = nullptr;

inline void set_log_callback(LogCallback callback) {
  s_log_callback = callback;
}

// === Internal Logging Implementation ===

// Core function: handles formatting and calls the user callback.
inline void _internal_log_impl_va(LogLevel level, const char* file, int line, const char* func, const char* format, va_list args) {
  if (s_log_callback) {
    char buffer[1024];

#ifdef _MSC_VER
    int written = _vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, format, args);
#else
    int written = vsnprintf(buffer, sizeof(buffer), format, args);
#endif

    if (written < 0 || written >= sizeof(buffer)) {
      buffer[sizeof(buffer) - 1] = '\0';
    }

    s_log_callback(level, buffer, file, line, func);
  }
}

// Variadic function called by macros.
// __attribute__ enables compile-time format string checks (for Clang/GCC).
inline void _internal_log_impl(LogLevel level, const char* file, int line, const char* func, const char* format, ...)
    __attribute__((format(printf, 5, 6)));

inline void _internal_log_impl(LogLevel level, const char* file, int line, const char* func, const char* format, ...) {
  va_list args;
  va_start(args, format);
  _internal_log_impl_va(level, file, line, func, format, args);
  va_end(args);
}


// === Logging Macros ===
// Capture __FILE__, __LINE__, and __func__ at the call site.

// LOG: Allows explicit LogLevel specification. 
#define LOG(level, format, ...) mystic::_internal_log_impl(level, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)

// LOG_*: Pre-defined level macros for common use.
#define LOG_TRACE(format, ...) LOG(mystic::LogLevel::Trace, format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...) LOG(mystic::LogLevel::Debug, format, ##__VA_ARGS__)
#define LOG_INFO(format, ...)  LOG(mystic::LogLevel::Info,  format, ##__VA_ARGS__)
#define LOG_WARN(format, ...)  LOG(mystic::LogLevel::Warning, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) LOG(mystic::LogLevel::Error, format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...) LOG(mystic::LogLevel::Fatal, format, ##__VA_ARGS__)


// Default console logger implementation.
inline void default_console_logger(LogLevel level, const char* message, const char* file, int line, const char* func) {
  const char* level_str;
  switch (level) {
    case LogLevel::Trace:   level_str = "TRACE"; break;
    case LogLevel::Debug:   level_str = "DEBUG"; break;
    case LogLevel::Info:    level_str = "INFO"; break;
    case LogLevel::Warning: level_str = "WARN"; break;
    case LogLevel::Error:   level_str = "ERROR"; break;
    case LogLevel::Fatal:   level_str = "FATAL"; break;
    default:                level_str = "UNKNOWN"; break;
  }
  if (level >= LogLevel::Warning) {
    fprintf(stderr, "[Mystic Games %s] %s %s:%d %s - %s\n", level_str, __TIME__, file, line, func, message);
  } else {
    fprintf(stdout, "[Mystic Games %s] %s %s:%d %s - %s\n", level_str, __TIME__, file, line, func, message);
  }
}

#define ASSERT(expr, ...) if (!(expr)) { fprintf(stderr, __VA_ARGS__); exit(1) }

} // namespace mystic

#endif // MYSTIC_GAMES_LOG_H_
