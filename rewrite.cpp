#include <iostream>
#include <memory>
#include <string>
#include <variant>
#include "../../includes/emscripten/system/include/emscripten.h"

#define STRCAT(x, y) x.y

class JSObject {
 protected:
 public:
  template <typename T>
  T &cast() {
    return *reinterpret_cast<T *>(this);
  }
  virtual ~JSObject() = default;
};

class HTMLElement : public JSObject {
 private:
  std::string query;

 public:
  HTMLElement() {}
  HTMLElement(std::string const &query) : query(query) {}
  std::string getQuery() { return query; }
};

class HTMLCanvasElement : public HTMLElement {
 private:
  class CanvasRenderingContext2D : public HTMLElement {
   private:
    CanvasRenderingContext2D() {}

   public:
    static CanvasRenderingContext2D const &current() {
      static CanvasRenderingContext2D current_;
      return current_;
    }
  };

 public:
  CanvasRenderingContext2D const &getContext(std::string const &contextType) {
    return CanvasRenderingContext2D::current();
  }
};

class Window : public JSObject {
 private:
  Window() {}

 public:
  static Window const &current() {
    static Window current_;
    return current_;
  }
};

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
};

int main(int argc, char **argv) {
  auto document = HTMLDocument::current();
  auto canvas = document.getElementById("canvas").cast<HTMLCanvasElement>();
  auto ctx = canvas.getContext("2d");
  auto window = Window::current();
  std::cout << canvas.getQuery() << std::endl;
  EM_ASM({
    console.log(document.querySelector(UTF8ToString($0)).getContext('2d').strokeStyle);
  }, canvas.getQuery().c_str());
}