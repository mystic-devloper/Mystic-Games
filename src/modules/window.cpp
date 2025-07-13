// Definition of "/include/modules/window.h"
#include "modules/window.h"

// Include Standard Library
#include <iostream>
#include <string>

// Include SDL2 Library
#include "SDL2/SDL.h"

// Include Custom Headers
#include "modules/types.h"

namespace mystic {

// --- Constructor ---

// Defualt Constructor
window::window() :
  window_handler(nullptr),
  title("N/A"),
  state(WindowState::Unknown),
  width(0),
  height(0) {

}

} // namespace mystic
