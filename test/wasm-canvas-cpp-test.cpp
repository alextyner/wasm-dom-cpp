#include <memory>
#include "../canvas.cpp"

int main() {
    auto canvas = HTMLCanvasElement("testCanvas");
    auto ctx = canvas.getContext("2d");
    ctx.moveTo(0, 0);
    ctx.lineTo(200, 100);
    ctx.stroke();
}