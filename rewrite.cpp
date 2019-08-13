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

 protected:
  std::string &getQuery() { return query; }

 public:
  HTMLElement() {}
  HTMLElement(std::string const &query) : query(query) {}
};

class HTMLCanvasElement : public HTMLElement {
 private:
  class CanvasRenderingContext2D : public HTMLElement {
   private:
    CanvasRenderingContext2D() {}

   public:
    static CanvasRenderingContext2D const &current(std::string const &query) {
      static HTMLElement current_(query);
      return current_.cast<CanvasRenderingContext2D>();
    }
    void clearRect(double x, double y, double width, double height) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .clearRect($1, $2, $3, $4);
          },
          getQuery().c_str(), x, y, width, height);
    }
    void fillRect(double x, double y, double width, double height) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .fillRect($1, $2, $3, $4);
          },
          getQuery().c_str(), x, y, width, height);
    }
    void strokeRect(double x, double y, double width, double height) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .strokeRect($1, $2, $3, $4);
          },
          getQuery().c_str(), x, y, width, height);
    }
    void fillText(char const *text, double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .fillText(UTF8ToString($1), $2, $3);
          },
          getQuery().c_str(), text, x, y);
    }
    void fillText(char const *text, double x, double y, double maxWidth) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .fillText(UTF8ToString($1), $2, $3, $4);
          },
          getQuery().c_str(), text, x, y, maxWidth);
    }
    void strokeText(char const *text, double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .strokeText(UTF8ToString($1), $2, $3);
          },
          getQuery().c_str(), text, x, y);
    }
    void strokeText(char const *text, double x, double y, double maxWidth) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .strokeText(UTF8ToString($1), $2, $3, $4);
          },
          getQuery().c_str(), text, x, y, maxWidth);
    }
    void setLineWidth(double value) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .lineWidth = ($1);
          },
          getQuery().c_str(), value);
    }
    double getLineWidth() {
      return EM_ASM_DOUBLE(
          {
            return document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .lineWidth;
          },
          getQuery().c_str());
    }
    void setLineCap(const char *type) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0)).getContext('2d').lineCap =
                UTF8ToString($1);
          },
          getQuery().c_str(), type);
    }
    std::string getLineCap() {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = document.querySelector(UTF8ToString($0))
                             .getContext('2d')
                             .lineCap;
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
    void setLineJoin(char const *type) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0)).getContext('2d').lineJoin =
                UTF8ToString($1);
          },
          getQuery().c_str(), type);
    }
    std::string getLineJoin() {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = document.querySelector(UTF8ToString($0))
                             .getContext('2d')
                             .lineJoin;
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
    std::string getFont() {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string =
                document.querySelector(UTF8ToString($0)).getContext('2d').font;
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
    void setFont(char const *value) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0)).getContext('2d').font =
                UTF8ToString($1);
          },
          getQuery().c_str(), value);
    }
    std::string getTextAlign() {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = document.querySelector(UTF8ToString($0))
                             .getContext('2d')
                             .textAlign;
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
    void setTextAlign(char const *value) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .textAlign = UTF8ToString($1);
          },
          getQuery().c_str(), value);
    }
    std::string getFillStyle() {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = document.querySelector(UTF8ToString($0))
                             .getContext('2d')
                             .fillStyle;
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
    void setFillStyle(char const *value) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .fillStyle = UTF8ToString($1);
          },
          getQuery().c_str(), value);
    }
    std::string getStrokeStyle() {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = document.querySelector(UTF8ToString($0))
                             .getContext('2d')
                             .strokeStyle;
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
    void setStrokeStyle(char const *value) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .strokeStyle = UTF8ToString($1);
          },
          getQuery().c_str(), value);
    }
    void beginPath() {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .beginPath();
          },
          getQuery().c_str());
    }
    void closePath() {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .closePath();
          },
          getQuery().c_str());
    }
    void moveTo(double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .moveTo($1, $2);
          },
          getQuery().c_str(), x, y);
    }
    void lineTo(double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .lineTo($1, $2);
          },
          getQuery().c_str(), x, y);
    }
    void bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y,
                       double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .bezierCurveTo($1, $2, $3, $4, $5, $6);
          },
          getQuery().c_str(), cp1x, cp1y, cp2x, cp2y, x, y);
    }
    void quadraticCurveTo(double cpx, double cpy, double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .quadraticCurveTo($1, $2, $3, $4);
          },
          getQuery().c_str(), cpx, cpy, x, y);
    }
    void arc(double x, double y, double radius, double startAngle,
             double endAngle) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .arc($1, $2, $3, $4, $5);
          },
          getQuery().c_str(), x, y, radius, startAngle, endAngle);
    }
    void arcTo(double x1, double y1, double x2, double y2, double radius) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .arcTo($1, $2, $3, $4, $5);
          },
          getQuery().c_str(), x1, y1, x2, y2, radius);
    }
    void ellipse(double x, double y, double radiusX, double radiusY,
                 double rotation, double startAngle, double endAngle) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .ellipse($1, $2, $3, $4, $5, $6, $7);
          },
          getQuery().c_str(), x, y, radiusX, radiusY, rotation, startAngle,
          endAngle);
    }
    void rect(double x, double y, double width, double height) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .rect($1, $2, $3, $4);
          },
          getQuery().c_str(), x, y, width, height);
    }
    void fill() {
      EM_ASM(
          { document.querySelector(UTF8ToString($0)).getContext('2d').fill(); },
          getQuery().c_str());
    }
    void stroke() {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0)).getContext('2d').stroke();
          },
          getQuery().c_str());
    }
    void clip() {
      EM_ASM(
          { document.querySelector(UTF8ToString($0)).getContext('2d').clip(); },
          getQuery().c_str());
    }
    bool isPointInPath(double x, double y) {
      return EM_ASM_INT(
          {
            return document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .isPointInPath($1, $2);
          },
          getQuery().c_str(), x, y);
    }
    bool isPointInStroke(double x, double y) {
      return EM_ASM_INT(
          {
            return document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .isPointInStroke($1, $2);
          },
          getQuery().c_str(), x, y);
    }
    void rotate(double angle) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .rotate($1);
          },
          getQuery().c_str(), angle);
    }
    void scale(double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .scale($1, $2);
          },
          getQuery().c_str(), x, y);
    }
    void translate(double x, double y) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .translate($1, $2);
          },
          getQuery().c_str(), x, y);
    }
    void transform(double a, double b, double c, double d, double e, double f) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .transform($1, $2, $3, $4, $5, $6);
          },
          getQuery().c_str(), a, b, c, d, e, f);
    }
    void setTransform(double a, double b, double c, double d, double e,
                      double f) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .setTransform($1, $2, $3, $4, $5, $6);
          },
          getQuery().c_str(), a, b, c, d, e, f);
    }
    void resetTransform() {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .resetTransform();
          },
          getQuery().c_str());
    }
    void setGlobalAlpha(double value) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .globalAlpha = $1;
          },
          getQuery().c_str(), value);
    }
    double getGlobalAlpha() {
      return EM_ASM_DOUBLE(
          {
            return document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .globalAlpha;
          },
          getQuery().c_str());
    }
    void setGlobalCompositeOperation(const char *value) {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0))
                .getContext('2d')
                .globalCompositeOperation = $1;
          },
          getQuery().c_str(), value);
    }
    std::string getGlobalCompositeOperation() {
      char *jsString = (char *)EM_ASM_INT(
          {
            var string = document.querySelector(UTF8ToString($0))
                             .getContext('2d')
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
    void save() {
      EM_ASM(
          { document.querySelector(UTF8ToString($0)).getContext('2d').save(); },
          getQuery().c_str());
    }
    void restore() {
      EM_ASM(
          {
            document.querySelector(UTF8ToString($0)).getContext('2d').restore();
          },
          getQuery().c_str());
    }
  };

 public:
  CanvasRenderingContext2D const &getContext(std::string const &contextType) {
    return CanvasRenderingContext2D::current(getQuery());
  }
  int getHeight() {
    return EM_ASM_INT(
        { return document.querySelector(UTF8ToString($0)).height; },
        getQuery().c_str());
  }
  void setHeight(int height) {
    EM_ASM({ document.querySelector(UTF8ToString($0)).height = $1; },
           getQuery().c_str(), height);
  }
  int getWidth() {
    return EM_ASM_INT(
        { return document.querySelector(UTF8ToString($0)).width; },
        getQuery().c_str());
  }
  void setWidth(int width) {
    EM_ASM({ document.querySelector(UTF8ToString($0)).width = $1; },
           getQuery().c_str(), width);
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

  auto window = Window::current();
  canvas.setHeight(window.getInnerHeight());
  canvas.setWidth(window.getInnerWidth());

  std::cout << "H: " << canvas.getHeight() << " W: " << canvas.getWidth()
            << std::endl;

  auto ctx = canvas.getContext("2d");

  ctx.setFillStyle("#AAAFFF");
  ctx.fillRect(0, 0, 60, 60);
}