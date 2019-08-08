#include <iostream>
#include <memory>
#include <optional>
#include <string>

class JSObject {
   protected:
   public:
    JSObject() {}

    template <class T>
    T cast() {
        return *reinterpret_cast<T *>(this);
    }
    virtual ~JSObject() = default;
};

class : public JSObject{
    protected :
        public :

} window;

class : public JSObject {
   protected:
   public:
    template <class T>
    static T getElementById(std::string const id) {
        return T(id);
    }
} document;

class HTMLElement : public JSObject {
   protected:
    std::string query;

   public:
    HTMLElement(std::string const query) : query(query) {}
};

class HTMLCanvasElement : public HTMLElement {
    class CanvasRenderingContext2D {
        std::string canvasId;

       public:
        CanvasRenderingContext2D(std::string const canvasId) : canvasId(canvasId) {}

        // might not even need canvasid?
        // what should be stored in query: a query or id or... identifier
    };
    std::optional<CanvasRenderingContext2D> ctx;

   public:
    HTMLCanvasElement(std::string const query) : HTMLElement(query) {}
    HTMLCanvasElement(HTMLCanvasElement const &e) : HTMLCanvasElement(e.query) {}

    CanvasRenderingContext2D getContext(std::string const contextType) {
        if (!ctx)
            ctx = std::make_optional<CanvasRenderingContext2D>(query);
        return ctx.value();
    }
    std::string getQuery() {
        return query;
    }
};

int main(int argc, char **argv) {
    std::cout << "0" << std::endl;
    JSObject d = document.getElementById<HTMLCanvasElement>("test");
    HTMLCanvasElement c = d.cast<HTMLCanvasElement>();
    std::cout << c.getQuery() << std::endl;
}