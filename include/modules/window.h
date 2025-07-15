#ifndef MYSTIC_GAMES_WINDOW_H_
#define MYSTIC_GAMES_WINDOW_H_

// Include Standard Library
#include <iostream>
#include <string>

// Include SDL2 Library
#include "SDL2/SDL.h"

// Include Custom Headers
#include "modules/types.h"

namespace mystic {

enum class WindowState {
  SHOW,
  HIDE,
  MAXIMIZED,
  MINIMIZED,
  Unknown
};

class Window {
public:
  // --- Constructors ---
  window();
  window(const std::string& p_title, const i32 p_width, const i32 p_height, const WindowState& p_state);
  
  // --- Destructor ---
  ~window();

  // --- Getters ---
  SDL_Window* get_window_handler() const;
  std::string get_title() const;
  WindowState get_state() const;
  i32 get_width() const;
  i32 get_height() const;

  // Clean up
  void clean_up();

private:
  SDL_Window* m_window_handler;
  std::string m_title;
  WindowState m_state;
  i32 m_width;
  i32 m_heigth;
};

} // namespace mystic

#endif // MYSTIC_GAMES_WINDOW_H_
