#ifndef WASM_DOM_WINDOW_HPP
#define WASM_DOM_WINDOW_HPP

#include <emscripten.h>
#include "JSObject.hpp"

namespace dom {

class Window : public JSObject {
 private:
  Window() {}

 public:
  static Window const &current() {
    static Window current_;
    return current_;
  }
  static int getInnerHeight() {
    return EM_ASM_INT({ return window.innerHeight; });
  }
  static int getInnerWidth() {
    return EM_ASM_INT({ return window.innerWidth; });
  }
  static int getOuterHeight() {
    return EM_ASM_INT({ return window.outerHeight; });
  }
  static int getOuterWidth() {
    return EM_ASM_INT({ return window.outerWidth; });
  }
  static void blur() {
    EM_ASM({ window.blur(); });
  }
};

}  // namespace dom
#endif