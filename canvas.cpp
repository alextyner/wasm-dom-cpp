/**
 * Facilitates interaction with HTML5 Canvas elements in a similar
 * manner to JavaScript via the DOM, but from C++ to be compiled with Emscripten.
 * @file canvas.cpp
 * @author Alex Tyner
 */

#include <emscripten.h>
#include <optional>
#include <string>

namespace DOM {

class HTMLCanvasElement {
   private:
    class CanvasRenderingContext2D {
       private:
        std::string canvasId;

       public:
        CanvasRenderingContext2D(const char *canvasId) : canvasId(canvasId) {}

        void clearRect(double x, double y, double width, double height) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').clearRect($1, $2, $3, $4); }, canvasId.c_str(), x, y, width, height);
        }
        void fillRect(double x, double y, double width, double height) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').fillRect($1, $2, $3, $4); }, canvasId.c_str(), x, y, width, height);
        }
        void strokeRect(double x, double y, double width, double height) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').strokeRect($1, $2, $3, $4); }, canvasId.c_str(), x, y, width, height);
        }
        void fillText(char const *text, double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').fillText(UTF8ToString($1), $2, $3); }, canvasId.c_str(), text, x, y);
        }
        void fillText(char const *text, double x, double y, double maxWidth) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').fillText(UTF8ToString($1), $2, $3, $4); }, canvasId.c_str(), text, x, y, maxWidth);
        }
        void strokeText(char const *text, double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').strokeText(UTF8ToString($1), $2, $3); }, canvasId.c_str(), text, x, y);
        }
        void strokeText(char const *text, double x, double y, double maxWidth) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').strokeText(UTF8ToString($1), $2, $3, $4); }, canvasId.c_str(), text, x, y, maxWidth);
        }
        void setLineWidth(double value) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').lineWidth = ($1); }, canvasId.c_str(), value);
        }
        double getLineWidth() {
            return EM_ASM_DOUBLE({ return document.getElementById(UTF8ToString($0)).getContext('2d').lineWidth; }, canvasId.c_str());
        }
        void setLineCap(const char *type) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').lineCap = UTF8ToString($1); }, canvasId.c_str(), type);
        }
        std::string getLineCap() {
            char *jsString = (char *)EM_ASM_INT(
                {
                    var string = document.getElementById(UTF8ToString($0)).getContext('2d').lineCap;
                    var strlen = lengthBytesUTF8(string) + 1;
                    var strptr = _malloc(strlen);
                    stringToUTF8(string, strptr, strlen);
                    return strptr;
                },
                canvasId.c_str());
            std::string ret(jsString);
            free(jsString);
            return ret;
        }
        void setLineJoin(char const *type) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').lineJoin = UTF8ToString($1); }, canvasId.c_str(), type);
        }
        std::string getLineJoin() {
            char *jsString = (char *)EM_ASM_INT(
                {
                    var string = document.getElementById(UTF8ToString($0)).getContext('2d').lineJoin;
                    var strlen = lengthBytesUTF8(string) + 1;
                    var strptr = _malloc(strlen);
                    stringToUTF8(string, strptr, strlen);
                    return strptr;
                },
                canvasId.c_str());
            std::string ret(jsString);
            free(jsString);
            return ret;
        }
        std::string getFont() {
            char *jsString = (char *)EM_ASM_INT(
                {
                    var string = document.getElementById(UTF8ToString($0)).getContext('2d').font;
                    var strlen = lengthBytesUTF8(string) + 1;
                    var strptr = _malloc(strlen);
                    stringToUTF8(string, strptr, strlen);
                    return strptr;
                },
                canvasId.c_str());
            std::string ret(jsString);
            free(jsString);
            return ret;
        }
        void setFont(char const *value) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').font = UTF8ToString($1); }, canvasId.c_str(), value);
        }
        std::string getTextAlign() {
            char *jsString = (char *)EM_ASM_INT(
                {
                    var string = document.getElementById(UTF8ToString($0)).getContext('2d').textAlign;
                    var strlen = lengthBytesUTF8(string) + 1;
                    var strptr = _malloc(strlen);
                    stringToUTF8(string, strptr, strlen);
                    return strptr;
                },
                canvasId.c_str());
            std::string ret(jsString);
            free(jsString);
            return ret;
        }
        void setTextAlign(char const *value) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').textAlign = UTF8ToString($1); }, canvasId.c_str(), value);
        }
        std::string getFillStyle() {
            char *jsString = (char *)EM_ASM_INT(
                {
                    var string = document.getElementById(UTF8ToString($0)).getContext('2d').fillStyle;
                    var strlen = lengthBytesUTF8(string) + 1;
                    var strptr = _malloc(strlen);
                    stringToUTF8(string, strptr, strlen);
                    return strptr;
                },
                canvasId.c_str());
            std::string ret(jsString);
            free(jsString);
            return ret;
        }
        void setFillStyle(char const *value) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').fillStyle = UTF8ToString($1); }, canvasId.c_str(), value);
        }
        std::string getStrokeStyle() {
            char *jsString = (char *)EM_ASM_INT(
                {
                    var string = document.getElementById(UTF8ToString($0)).getContext('2d').strokeStyle;
                    var strlen = lengthBytesUTF8(string) + 1;
                    var strptr = _malloc(strlen);
                    stringToUTF8(string, strptr, strlen);
                    return strptr;
                },
                canvasId.c_str());
            std::string ret(jsString);
            free(jsString);
            return ret;
        }
        void setStrokeStyle(char const *value) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').strokeStyle = UTF8ToString($1); }, canvasId.c_str(), value);
        }
        void beginPath() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').beginPath(); }, canvasId.c_str());
        }
        void closePath() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').closePath(); }, canvasId.c_str());
        }
        void moveTo(double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').moveTo($1, $2); }, canvasId.c_str(), x, y);
        }
        void lineTo(double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').lineTo($1, $2); }, canvasId.c_str(), x, y);
        }
        void bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y, double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').bezierCurveTo($1, $2, $3, $4, $5, $6); }, canvasId.c_str(), cp1x, cp1y, cp2x, cp2y, x, y);
        }
        void quadraticCurveTo(double cpx, double cpy, double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').quadraticCurveTo($1, $2, $3, $4); }, canvasId.c_str(), cpx, cpy, x, y);
        }
        void arc(double x, double y, double radius, double startAngle, double endAngle) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').arc($1, $2, $3, $4, $5); }, canvasId.c_str(), x, y, radius, startAngle, endAngle);
        }
        void arcTo(double x1, double y1, double x2, double y2, double radius) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').arcTo($1, $2, $3, $4, $5); }, canvasId.c_str(), x1, y1, x2, y2, radius);
        }
        void ellipse(double x, double y, double radiusX, double radiusY, double rotation, double startAngle, double endAngle) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').ellipse($1, $2, $3, $4, $5, $6, $7); }, canvasId.c_str(), x, y, radiusX, radiusY, rotation, startAngle, endAngle);
        }
        void rect(double x, double y, double width, double height) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').rect($1, $2, $3, $4); }, canvasId.c_str(), x, y, width, height);
        }
        void fill() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').fill(); }, canvasId.c_str());
        }
        void stroke() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').stroke(); }, canvasId.c_str());
        }
        void clip() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').clip(); }, canvasId.c_str());
        }
        bool isPointInPath(double x, double y) {
            return EM_ASM_INT({ return document.getElementById(UTF8ToString($0)).getContext('2d').isPointInPath($1, $2); }, canvasId.c_str(), x, y);
        }
        bool isPointInStroke(double x, double y) {
            return EM_ASM_INT({ return document.getElementById(UTF8ToString($0)).getContext('2d').isPointInStroke($1, $2); }, canvasId.c_str(), x, y);
        }
        void rotate(double angle) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').rotate($1); }, canvasId.c_str(), angle);
        }
        void scale(double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').scale($1, $2); }, canvasId.c_str(), x, y);
        }
        void translate(double x, double y) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').translate($1, $2); }, canvasId.c_str(), x, y);
        }
        void transform(double a, double b, double c, double d, double e, double f) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').transform($1, $2, $3, $4, $5, $6); }, canvasId.c_str(), a, b, c, d, e, f);
        }
        void setTransform(double a, double b, double c, double d, double e, double f) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').setTransform($1, $2, $3, $4, $5, $6); }, canvasId.c_str(), a, b, c, d, e, f);
        }
        void resetTransform() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').resetTransform(); }, canvasId.c_str());
        }
        void setGlobalAlpha(double value) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').globalAlpha = $1; }, canvasId.c_str(), value);
        }
        double getGlobalAlpha() {
            return EM_ASM_DOUBLE({ return document.getElementById(UTF8ToString($0)).getContext('2d').globalAlpha; }, canvasId.c_str());
        }
        void setGlobalCompositeOperation(const char *value) {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').globalCompositeOperation = $1; }, canvasId.c_str(), value);
        }
        std::string getGlobalCompositeOperation() {
            char *jsString = (char *)EM_ASM_INT(
                {
                    var string = document.getElementById(UTF8ToString($0)).getContext('2d').globalCompositeOperation;
                    var strlen = lengthBytesUTF8(string) + 1;
                    var strptr = _malloc(strlen);
                    stringToUTF8(string, strptr, strlen);
                    return strptr;
                },
                canvasId.c_str());
            std::string ret(jsString);
            free(jsString);
            return ret;
        }
        void save() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').save(); }, canvasId.c_str());
        }
        void restore() {
            EM_ASM({ document.getElementById(UTF8ToString($0)).getContext('2d').restore(); }, canvasId.c_str());
        } /*
        std::shared_ptr<HTMLCanvasElement> const getCanvas() {
            return std::make_shared<HTMLCanvasElement>(canvas);
        }*/
    };

    std::string id;
    std::optional<CanvasRenderingContext2D> ctx2d;

   public:
    HTMLCanvasElement(char const *id) : id(id) {}

    int getWidth() {
        return EM_ASM_INT({ return document.getElementById(UTF8ToString($0)).width; }, id.c_str());
    }
    int getHeight() {
        return EM_ASM_INT({ return document.getElementById(UTF8ToString($0)).height; }, id.c_str());
    }
    void canvas_setWidth(int width) {
        EM_ASM({ document.getElementById(UTF8ToString($0)).width = $1; }, id.c_str(), width);
    }
    void setHeight(int height) {
        EM_ASM({ document.getElementById(UTF8ToString($0)).height = $1; }, id.c_str(), height);
    }
    CanvasRenderingContext2D const &getContext(char const *contextType) {
        // Whether context objects are stored as plain members constructed along with the Canvas,
        // as std::optional constructed on access, or as pointers dynamically allocated on access,
        // their lifetime is limited by the lifetime of the Canvas
        std::string contextTypeString(contextType);
        if (contextTypeString.compare("2d") && contextTypeString.compare("2D"))  // !=
            throw std::invalid_argument("Only 2D rendering context is supported.");
        if (!ctx2d)
            ctx2d = CanvasRenderingContext2D(contextType);
        return ctx2d.value();
    }
};

}  // namespace DOM