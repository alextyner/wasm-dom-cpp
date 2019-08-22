
#include "../../include/wasm-dom.hpp"

constexpr int canvasWidth = 575;
constexpr int canvasHeight = 1080;

constexpr int boxHeight = 100;
constexpr int boxWidth = 250;
constexpr int boxVPad = 50;
constexpr int boxHPad = 25;

using namespace dom;

auto document = HTMLDocument::current();
auto canvas = document.getElementById("testCanvas").cast<HTMLCanvasElement>();
auto ctx = canvas.getContext("2d");

void setUp() {
  canvas.setHeight(canvasHeight);
  canvas.setWidth(canvasWidth);

  ctx.setFillStyle("black");
  ctx.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());

  ctx.setFillStyle("white");
  ctx.setStrokeStyle("white");
  ctx.setFont("18px sans-serif");
  ctx.setLineWidth(2);

  ctx.translate(boxHPad, boxVPad);
}

void testClearRect() {
  ctx.fillText("ctx.clearRect()", 0, 0);
  ctx.clearRect(10, 10, boxWidth - 20, boxHeight - 20);
}

void testFillRect() {
  ctx.fillText("ctx.fillRect()", 0, 0);
  ctx.setFillStyle("green");
  ctx.fillRect(10, 10, boxWidth - 20, boxHeight - 20);
  ctx.setFillStyle("white");
}

void testStrokeRect() {
  ctx.fillText("ctx.strokeRect()", 0, 0);
  ctx.strokeRect(10, 10, boxWidth - 20, boxHeight - 20);
}

void testFillText() {
  ctx.fillText("ctx.fillText()", 0, 0);
  ctx.fillText("Hello World.", 10, boxHeight - 10);
  ctx.fillText("Hello World. Hello World. Hello World.", 10, boxHeight / 2,
               boxWidth - 20);
}

void testStrokeText() {
  ctx.fillText("ctx.strokeText()", 0, 0);
  ctx.strokeText("Hello World.", 10, boxHeight - 10);
  ctx.strokeText("Hello World. Hello World. Hello World.", 10, boxHeight / 2,
                 boxWidth - 20);
}

void testSetLineWidth() {
  ctx.fillText("ctx.setLineWidth()", 0, 0);
  ctx.strokeRect(10, 10, boxWidth - 20, boxHeight - 20);
  ctx.setLineWidth(4.5);
  ctx.strokeRect(20, 20, boxWidth - 40, boxHeight - 40);
  ctx.setLineWidth(8);
  ctx.strokeRect(30, 30, boxWidth - 60, boxHeight - 60);
  ctx.setLineWidth(2);
}

void testGetLineWidth() {
  ctx.fillText("ctx.getLineWidth()", 0, 0);
  ctx.strokeRect(10, 10, boxWidth - 20, boxHeight - 20);
  ctx.fillText(std::to_string(static_cast<int>(ctx.getLineWidth())).c_str(),
               boxWidth / 2 - 60, boxHeight / 2 + 10);
  ctx.setLineWidth(4);
  ctx.strokeRect(20, 20, boxWidth - 40, boxHeight - 40);
  ctx.fillText(std::to_string(static_cast<int>(ctx.getLineWidth())).c_str(),
               boxWidth / 2 - 10, boxHeight / 2 + 10);
  ctx.setLineWidth(8);
  ctx.strokeRect(30, 30, boxWidth - 60, boxHeight - 60);
  ctx.fillText(std::to_string(static_cast<int>(ctx.getLineWidth())).c_str(),
               boxWidth / 2 + 40, boxHeight / 2 + 10);
  ctx.setLineWidth(2);
}

void testSetLineCap() {
  ctx.fillText("ctx.setLineCap()", 0, 0);

  ctx.setLineWidth(8);

  ctx.beginPath();
  ctx.moveTo(10, 40);
  ctx.lineTo(boxWidth - 10, 40);
  ctx.stroke();

  ctx.beginPath();
  ctx.moveTo(10, 60);
  ctx.setLineCap("round");
  ctx.lineTo(boxWidth - 10, 60);
  ctx.stroke();

  ctx.beginPath();
  ctx.moveTo(10, 80);
  ctx.setLineCap("square");
  ctx.lineTo(boxWidth - 10, 80);
  ctx.stroke();

  ctx.setLineWidth(2);
  ctx.setLineCap("butt");
}

void testGetLineCap() {
  ctx.fillText("ctx.getLineCap()", 0, 0);

  ctx.setLineWidth(8);

  ctx.beginPath();
  ctx.moveTo(70, 25);
  ctx.fillText(ctx.getLineCap().c_str(), 10, 30);
  ctx.lineTo(boxWidth - 10, 30);
  ctx.stroke();

  ctx.beginPath();
  ctx.moveTo(70, 55);
  ctx.setLineCap("round");
  ctx.fillText(ctx.getLineCap().c_str(), 10, 60);
  ctx.lineTo(boxWidth - 10, 60);
  ctx.stroke();

  ctx.beginPath();
  ctx.moveTo(70, 85);
  ctx.setLineCap("square");
  ctx.fillText(ctx.getLineCap().c_str(), 10, 90);
  ctx.lineTo(boxWidth - 10, 90);
  ctx.stroke();

  ctx.setLineWidth(2);
  ctx.setLineCap("butt");
}

// TODO: more tests

int main(int argc, char** argv) {
  setUp();

  auto tests = {testClearRect,    testFillRect,   testStrokeRect,
                testFillText,     testStrokeText, testSetLineWidth,
                testGetLineWidth, testSetLineCap, testGetLineCap};

  int cols = 2;
  int rows = tests.size() % 2 ? tests.size() / 2 + 1 : tests.size() / 2;

  auto testPtr = tests.begin();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (testPtr != tests.end()) {
        (*testPtr++)();
      }
      ctx.strokeRect(0, 0, boxWidth, boxHeight);
      ctx.translate(boxWidth + boxHPad, 0);
    }
    ctx.translate(-(cols * (boxWidth + boxHPad)), boxHeight + boxVPad);
  }
  return 0;
}