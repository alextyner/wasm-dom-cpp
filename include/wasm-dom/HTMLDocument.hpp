#ifndef WASM_DOM_HTMLDOCUMENT_HPP
#define WASM_DOM_HTMLDOCUMENT_HPP

#include <emscripten.h>
#include "HTMLElement.hpp"

namespace dom {

class HTMLDocument : public JSObject {
 private:
  HTMLDocument() {}

 public:
  static HTMLDocument const &current() {
    static HTMLDocument current_;
    return current_;
  }

  static HTMLElement getElementById(std::string const &id) {
    return HTMLElement(std::string("#").append(id));
  }

  static HTMLElement querySelector(std::string const &query) {
    return HTMLElement(query);
  }
};

}  // namespace dom
#endif