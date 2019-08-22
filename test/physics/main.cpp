#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "../../include/wasm-dom.hpp"

auto canvas = dom::HTMLDocument::current()
                  .querySelector("#canvas")
                  .cast<dom::HTMLCanvasElement>();
auto ctx = canvas.getContext("2d");

const int height = dom::Window::current().getInnerHeight();
const int width = dom::Window::current().getInnerWidth();

namespace Math {
constexpr double PI = 3.141592653589793238463;
}

class Vector {
 private:
 public:
  double x, y;
  Vector(double x = 0, double y = 0) : x(x), y(y) {}
};

class Ball {
 private:
  Vector pos;
  Vector vel;
  int radius;

 public:
  Vector v;
  Ball(int x = 0, int y = 0, Vector vel = Vector(), int radius = 10)
      : pos(x, y), vel(vel), radius(radius) {}
  void show() {
    ctx.beginPath();
    ctx.arc(pos.x, pos.y, radius, 0, 2 * Math::PI);
    ctx.closePath();
    ctx.fill();
  }
  void update() {
    double &x = pos.x;
    double &y = pos.y;
    x += vel.x;
    y += vel.y;
    if (x >= width || x <= 0) {
      vel.x = -vel.x;
    }
    if (y >= height || y <= 0) {
      vel.y = -vel.y;
    }
  }
};

void update(void *vector) {
  ctx.clearRect(0, 0, width, height);

  for (auto &b : *reinterpret_cast<std::vector<Ball> *>(vector)) {
    b.update();
    b.show();
  }
  static unsigned short counters[3] = {0x00, 0x00, 0x00};
  char style[8];
  snprintf(style, 8, "#%2.2x%2.2x%2.2x", counters[0], counters[1], counters[2]);
  for (int i = 0; i < 3; i++) {
    counters[i] = rand() % 256;
  }
  printf("%ld\n", time(NULL));
  ctx.setFillStyle(style);
}

int main(int argc, char **argv) {
  canvas.setHeight(height);
  canvas.setWidth(width);

  srand(time(NULL));

  static std::vector<Ball>
      balls;  // static, otherwise will leave scope after first update() call
  for (int i = 0; i < 20; i++) {
    balls.push_back(Ball(rand() % width, rand() % height,
                         Vector(rand() % 40 - 20, rand() % 40 - 20), rand() % 35));
  }

  emscripten_set_main_loop_arg(update, &balls, 0, 0);

  return 0;
}