#include "simple_math.hpp"
#include <cassert>
#include <iostream>

using namespace SimpleMath;

void test_add_subtract() {
	assert(add(2, 3) == 5);
	assert(substract(5, 3) == 2);
	assert(multiply(4, 2) == 8);
	assert(divide(10, 2) == 5);
}

void test_clamp() {
	assert(clamp(5, 0, 10) == 5);
	assert(clamp(-1, 0, 10) == 0);
	assert(clamp(20, 0, 10) == 10);
}

void test_lerp() {
	assert(lerp(10, 20, 0.0) == 10);
	assert(lerp(10, 20, 1.0) == 20);
	assert(lerp(10, 20, 0.5) == 15);
}

void test_vec2() {
	Vec2 a(1, 2);
	Vec2 b(3, 4);
	Vec2 c = a + b;
	assert(c.x == 4 && c.y == 6);

	Vec2 norm = Vec2(3, 4).normalized();
	assert(std::abs(norm.x - 0.6) < 1e-6);
	assert(std::abs(norm.y - 0.8) < 1e-6);

	assert(Vec2(1, 0).dot(Vec2(0, 1)) == 0);
}

void test_vec3() {
	Vec3 a(1, 2, 3);
	Vec3 b(4, 5, 6);
	Vec3 c = a + b;
	assert(c.x == 5 && c.y == 7 && c.z == 9);

	Vec3 cross = a.cross(b);
	assert(cross.x == -3 && cross.y == 6 && cross.z == -3);

	assert(a.dot(b) == 32);
}


int main() {
	test_add_subtract();
	test_clamp();
	test_lerp();
	test_vec2();
	test_vec3();

	std::cout << "All tests passed!\n";
	return 0;
}