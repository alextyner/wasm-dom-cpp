#ifndef WASM_DOM_JSOBJECT_HPP
#define WASM_DOM_JSOBJECT_HPP

namespace dom {

class JSObject {
 protected:
 public:
  template <typename T>
  T &cast() {
    return *reinterpret_cast<T *>(this);
  }
  virtual ~JSObject() = default;
};

}  // namespace dom
#endif