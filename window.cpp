/**
 * Interfaces with the browser window in which the program is running, 
 * typically exposed to JavaScript code.
 * @file window.hpp
 * @author Alex Tyner
 */

#include <emscripten.h>
#include <optional>

namespace DOM {

class {
   public:
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
} window;

}