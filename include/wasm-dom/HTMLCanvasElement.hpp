#ifndef WASM_DOM_HTMLCANVASELEMENT_HPP
#define WASM_DOM_HTMLCANVASELEMENT_HPP

#include <emscripten.h>
#include <string>
#include "HTMLElement.hpp"

namespace dom {

class HTMLCanvasElement : public HTMLElement {
 private:
  class CanvasRenderingContext2D : public HTMLElement {
   protected:
    CanvasRenderingContext2D() {}
    CanvasRenderingContext2D(std::string const &query) {
      this->query = std::string(query).append("_CanvasRenderingContext2D");
      EM_ASM(
          {
            if (typeof(Module._wasm_cpp_dict) == 'undefined') {
              Module._wasm_cpp_dict = {};
            }
            var query = UTF8ToString($0);
            Module._wasm_cpp_dict[query + '_CanvasRenderingContext2D'] =
                document.querySelector(query).getContext('2d');
          },
          query.c_str());
    }

   public:
    static CanvasRenderingContext2D const &current(std::string const &query) {
      static CanvasRenderingContext2D current_(query);
      return current_;
    }
    void clearRect(double x, double y, double width, double height) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].clearRect($1, $2, $3, $4);
          },
          getQuery().c_str(), x, y, width, height);
    }
    void fillRect(double x, double y, double width, double height) const {
      EM_ASM(
          { Module._wasm_cpp_dict[UTF8ToString($0)].fillRect($1, $2, $3, $4); },
          getQuery().c_str(), x, y, width, height);
    }
    void strokeRect(double x, double y, double width, double height) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].strokeRect($1, $2, $3, $4);
          },
          getQuery().c_str(), x, y, width, height);
    }
    void fillText(char const *text, double x, double y) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].fillText(UTF8ToString($1),
                                                             $2, $3);
          },
          getQuery().c_str(), text, x, y);
    }
    void fillText(char const *text, double x, double y,
                  double maxWidth) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].fillText(UTF8ToString($1),
                                                             $2, $3, $4);
          },
          getQuery().c_str(), text, x, y, maxWidth);
    }
    void strokeText(char const *text, double x, double y) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].strokeText(UTF8ToString($1),
                                                               $2, $3);
          },
          getQuery().c_str(), text, x, y);
    }
    void strokeText(char const *text, double x, double y,
                    double maxWidth) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].strokeText(UTF8ToString($1),
                                                               $2, $3, $4);
          },
          getQuery().c_str(), text, x, y, maxWidth);
    }
    void setLineWidth(double value) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].lineWidth = ($1); },
             getQuery().c_str(), value);
    }
    double getLineWidth() const {
      return EM_ASM_DOUBLE(
          { return Module._wasm_cpp_dict[UTF8ToString($0)].lineWidth; },
          getQuery().c_str());
    }
    void setLineCap(char const *type) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].lineCap = UTF8ToString($1);
          },
          getQuery().c_str(), type);
    }
    std::string getLineCap() const {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = Module._wasm_cpp_dict[UTF8ToString($0)].lineCap;
            var strlen = lengthBytesUTF8(string) + 1;
            var strptr = _malloc(strlen);
            stringToUTF8(string, strptr, strlen);
            return strptr;
          },
          getQuery().c_str());
      std::string ret(jsString);
      free(jsString);
      return ret;
    }
    void setLineJoin(char const *type) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].lineJoin = UTF8ToString($1);
          },
          getQuery().c_str(), type);
    }
    std::string getLineJoin() const {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = Module._wasm_cpp_dict[UTF8ToString($0)].lineJoin;
            var strlen = lengthBytesUTF8(string) + 1;
            var strptr = _malloc(strlen);
            stringToUTF8(string, strptr, strlen);
            return strptr;
          },
          getQuery().c_str());
      std::string ret(jsString);
      free(jsString);
      return ret;
    }
    std::string getFont() const {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = Module._wasm_cpp_dict[UTF8ToString($0)].font;
            var strlen = lengthBytesUTF8(string) + 1;
            var strptr = _malloc(strlen);
            stringToUTF8(string, strptr, strlen);
            return strptr;
          },
          getQuery().c_str());
      std::string ret(jsString);
      free(jsString);
      return ret;
    }
    void setFont(char const *value) const {
      EM_ASM(
          { Module._wasm_cpp_dict[UTF8ToString($0)].font = UTF8ToString($1); },
          getQuery().c_str(), value);
    }
    std::string getTextAlign() const {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = Module._wasm_cpp_dict[UTF8ToString($0)].textAlign;
            var strlen = lengthBytesUTF8(string) + 1;
            var strptr = _malloc(strlen);
            stringToUTF8(string, strptr, strlen);
            return strptr;
          },
          getQuery().c_str());
      std::string ret(jsString);
      free(jsString);
      return ret;
    }
    void setTextAlign(char const *value) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].textAlign =
                UTF8ToString($1);
          },
          getQuery().c_str(), value);
    }
    std::string getFillStyle() const {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = Module._wasm_cpp_dict[UTF8ToString($0)].fillStyle;
            var strlen = lengthBytesUTF8(string) + 1;
            var strptr = _malloc(strlen);
            stringToUTF8(string, strptr, strlen);
            return strptr;
          },
          getQuery().c_str());
      std::string ret(jsString);
      free(jsString);
      return ret;
    }
    void setFillStyle(char const *value) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].fillStyle =
                UTF8ToString($1);
          },
          getQuery().c_str(), value);
    }
    std::string getStrokeStyle() const {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = Module._wasm_cpp_dict[UTF8ToString($0)].strokeStyle;
            var strlen = lengthBytesUTF8(string) + 1;
            var strptr = _malloc(strlen);
            stringToUTF8(string, strptr, strlen);
            return strptr;
          },
          getQuery().c_str());
      std::string ret(jsString);
      free(jsString);
      return ret;
    }
    void setStrokeStyle(char const *value) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].strokeStyle =
                UTF8ToString($1);
          },
          getQuery().c_str(), value);
    }
    void beginPath() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].beginPath(); },
             getQuery().c_str());
    }
    void closePath() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].closePath(); },
             getQuery().c_str());
    }
    void moveTo(double x, double y) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].moveTo($1, $2); },
             getQuery().c_str(), x, y);
    }
    void lineTo(double x, double y) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].lineTo($1, $2); },
             getQuery().c_str(), x, y);
    }
    void bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y,
                       double x, double y) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].bezierCurveTo($1, $2, $3,
                                                                  $4, $5, $6);
          },
          getQuery().c_str(), cp1x, cp1y, cp2x, cp2y, x, y);
    }
    void quadraticCurveTo(double cpx, double cpy, double x, double y) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].quadraticCurveTo($1, $2, $3,
                                                                     $4);
          },
          getQuery().c_str(), cpx, cpy, x, y);
    }
    void arc(double x, double y, double radius, double startAngle,
             double endAngle) const {
      EM_ASM(
          { Module._wasm_cpp_dict[UTF8ToString($0)].arc($1, $2, $3, $4, $5); },
          getQuery().c_str(), x, y, radius, startAngle, endAngle);
    }
    void arcTo(double x1, double y1, double x2, double y2,
               double radius) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].arcTo($1, $2, $3, $4, $5);
          },
          getQuery().c_str(), x1, y1, x2, y2, radius);
    }
    void ellipse(double x, double y, double radiusX, double radiusY,
                 double rotation, double startAngle, double endAngle) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].ellipse($1, $2, $3, $4, $5,
                                                            $6, $7);
          },
          getQuery().c_str(), x, y, radiusX, radiusY, rotation, startAngle,
          endAngle);
    }
    void rect(double x, double y, double width, double height) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].rect($1, $2, $3, $4); },
             getQuery().c_str(), x, y, width, height);
    }
    void fill() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].fill(); },
             getQuery().c_str());
    }
    void stroke() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].stroke(); },
             getQuery().c_str());
    }
    void clip() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].clip(); },
             getQuery().c_str());
    }
    bool isPointInPath(double x, double y) const {
      return EM_ASM_INT(
          {
            return Module._wasm_cpp_dict[UTF8ToString($0)].isPointInPath($1,
                                                                         $2);
          },
          getQuery().c_str(), x, y);
    }
    bool isPointInStroke(double x, double y) const {
      return EM_ASM_INT(
          {
            return Module._wasm_cpp_dict[UTF8ToString($0)].isPointInStroke($1,
                                                                           $2);
          },
          getQuery().c_str(), x, y);
    }
    void rotate(double angle) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].rotate($1); },
             getQuery().c_str(), angle);
    }
    void scale(double x, double y) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].scale($1, $2); },
             getQuery().c_str(), x, y);
    }
    void translate(double x, double y) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].translate($1, $2); },
             getQuery().c_str(), x, y);
    }
    void transform(double a, double b, double c, double d, double e,
                   double f) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].transform($1, $2, $3, $4,
                                                              $5, $6);
          },
          getQuery().c_str(), a, b, c, d, e, f);
    }
    void setTransform(double a, double b, double c, double d, double e,
                      double f) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].setTransform($1, $2, $3, $4,
                                                                 $5, $6);
          },
          getQuery().c_str(), a, b, c, d, e, f);
    }
    void resetTransform() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].resetTransform(); },
             getQuery().c_str());
    }
    void setGlobalAlpha(double value) const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].globalAlpha = $1; },
             getQuery().c_str(), value);
    }
    double getGlobalAlpha() const {
      return EM_ASM_DOUBLE(
          { return Module._wasm_cpp_dict[UTF8ToString($0)].globalAlpha; },
          getQuery().c_str());
    }
    void setGlobalCompositeOperation(const char *value) const {
      EM_ASM(
          {
            Module._wasm_cpp_dict[UTF8ToString($0)].globalCompositeOperation =
                $1;
          },
          getQuery().c_str(), value);
    }
    std::string getGlobalCompositeOperation() const {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = Module._wasm_cpp_dict[UTF8ToString($0)]
                             .globalCompositeOperation;
            var strlen = lengthBytesUTF8(string) + 1;
            var strptr = _malloc(strlen);
            stringToUTF8(string, strptr, strlen);
            return strptr;
          },
          getQuery().c_str());
      std::string ret(jsString);
      free(jsString);
      return ret;
    }
    void save() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].save(); },
             getQuery().c_str());
    }
    void restore() const {
      EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].restore(); },
             getQuery().c_str());
    }
  };

 public:
  CanvasRenderingContext2D const &getContext(std::string const &contextType) const {
    return CanvasRenderingContext2D::current(getQuery());
  }
  int getHeight() {
    return EM_ASM_INT(
        { return Module._wasm_cpp_dict[UTF8ToString($0)].height; },
        getQuery().c_str());
  }
  void setHeight(int height) {
    EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].height = $1; },
           getQuery().c_str(), height);
  }
  int getWidth() {
    return EM_ASM_INT({ return Module._wasm_cpp_dict[UTF8ToString($0)].width; },
                      getQuery().c_str());
  }
  void setWidth(int width) {
    EM_ASM({ Module._wasm_cpp_dict[UTF8ToString($0)].width = $1; },
           getQuery().c_str(), width);
  }
};

}  // namespace dom
#endif