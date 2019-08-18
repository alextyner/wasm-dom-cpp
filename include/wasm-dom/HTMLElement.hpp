#ifndef WASM_DOM_HTMLELEMENT_HPP
#define WASM_DOM_HTMLELEMENT_HPP

#include <emscripten.h>
#include <string>
#include "JSObject.hpp"

namespace dom {

class HTMLElement : public JSObject {
 private:
 protected:
  std::string query;
  HTMLElement() {}
  std::string const &getQuery() const { return query; }

 public:
  HTMLElement(std::string const &query) : query(query) {
    EM_ASM(
        {
          if (typeof(Module._wasm_cpp_dict) == 'undefined') {
            Module._wasm_cpp_dict = {};
          }
          var query = UTF8ToString($0);
          Module._wasm_cpp_dict[query] = document.querySelector(query);
        },
        query.c_str());
  }
};

}  // namespace dom
#endif