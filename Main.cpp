#include "simple_math.hpp"
#include <iostream>


int main() {
	using namespace SimpleMath;

	std::cout << "Add: " << add(2.0, 3.5) << "\n";
	Vec2 a(3, 4);
	Vec2 b(1, 2);

	auto result = a + b;
	std::cout << "Vec2 Add: (" << result.x << ", " << result.y << ")\n";

	std::cout << "Dot product: " << a.dot(b) << "\n";
	std::cout << "Magnitude of a: " << a.magnitude() << "\n";

	Vec3 v1(1, 2, 3);
	Vec3 v2(4, 5, 6);

	auto sum = v1 + v2;
	std::cout << "Vec3 Add: (" << sum.x << " ," << sum.y << " , " << sum.z << ")\n";

	auto dot = v1.dot(v2);
	std::cout << "Dot: " << dot << "\n";

	auto cross = v1.cross(v2);
	std::cout << "Cross (" << cross.x << " ," << cross.y << " ," << cross.z << ")\n";



	return 0;
}




