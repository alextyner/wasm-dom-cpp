#include <iostream>
#include <memory>
#include <variant>
#include <string>

class JSObject {
   protected:
   public:
    template <typename T>
    T& cast() {
        return *reinterpret_cast<T*>(this);
    }
    virtual ~JSObject() = default;
};

class HTMLElement : public JSObject {
    private:
    std::string id;
    public:
    HTMLElement() {}
    HTMLElement(std::string const &id) : id(id) {}
};

class HTMLCanvasElement : public HTMLElement {
   private:
    class CanvasRenderingContext2D : public HTMLElement {
       private:
        CanvasRenderingContext2D() {}

       public:
        static CanvasRenderingContext2D const& current() {
            static CanvasRenderingContext2D current_;
            return current_;
        }
    };

   public:
    CanvasRenderingContext2D const& getContext(std::string const& contextType) {
        return CanvasRenderingContext2D::current();
    }
};

class Window : public JSObject {
   private:
    Window() {}

   public:
    static Window const& current() {
        static Window current_;
        return current_;
    }
};

class HTMLDocument : public JSObject {
   private:
    HTMLDocument() {}

   public:
    static HTMLDocument const& current() {
        static HTMLDocument current_;
        return current_;
    }

    HTMLElement getElementById(std::string const& id) {
        return HTMLElement(id);
    }
};

int main(int argc, char** argv) { /*
    std::cout << "0" << std::endl;
    JSObject d = document.getElementById("test");
    HTMLCanvasElement c = d.cast<HTMLCanvasElement>();
    std::cout << c.getQuery() << std::endl;*/
    auto document = HTMLDocument::current();
    auto canvas = document.getElementById("id").cast<HTMLCanvasElement>();
    auto ctx = canvas.getContext("2d");

}