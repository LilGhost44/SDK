#pragma once

#ifndef SIMPLE_MATH_HPP
#define SIMPLE_MATH_HPP 

#include <cmath>
#include <stdexcept>
#include <iostream>

namespace SimpleMath {


//Basic arithmetic
	inline double add(double a, double b) { return a + b; }
	inline double substract(double a, double b) { return a - b; }
	inline double multiply(double a, double b) { return a * b; }
	inline double divide(double a, double b) {
		if (b == 0.0) throw std::runtime_error("Divide by zero");
		return a / b;
	}

//clamp 
	inline double clamp(double val, double min, double max) {
		return std::max(min, std::min(val, max));
	}

//Linear interpolation
	inline double lerp(double a, double b, double t) {
		return a + t * (b - a);
	}

//2D Vector
	struct Vec2 {
		double x, y;
		Vec2() : x(0), y(0) {}
		Vec2(double _x,double _y):x(_x),y(_y){}

		double magnitude() const {
			return std::sqrt(x * x + y * y);
		}

		Vec2 normalized() const {
			double mag = magnitude();
			if (mag == 0) return Vec2(0, 0);
			return Vec2(x / mag, y / mag);
		}

		double dot(const Vec2& other) const {
			return x * other.x + y * other.y;
		}

		Vec2 operator+(const Vec2& rhs) const { return Vec2(x + rhs.x, y + rhs.y); }
		Vec2 operator-(const Vec2& rhs) const { return Vec2(x - rhs.x, y - rhs.y); }
		Vec2 operator*(double scalar)const { return Vec2(x * scalar, y * scalar); }
	};
	
	struct Vec3 {
		double x, y, z;

		Vec3() : x(0), y(0), z(0) {}
			Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}


			double magnitude() const {
				return std::sqrt(x * x + y * y + z * z);
			}

			Vec3 normalized() const {
				double mag = magnitude();
				if (mag == 0)return Vec3(0, 0, 0);
				return Vec3(x / mag, y / mag, z / mag);
			}

			double dot(const Vec3& other) {
				return x * other.x + y * other.y + z * other.z;
			}

			Vec3 cross(const Vec3& other) const {
				return Vec3(
					y * other.z - z * other.y,
					z * other.x - x * other.z,
					x * other.y - y * other.x
				);
			}

			Vec3 operator+(const Vec3& rhs) const {
				return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
			}
			Vec3 operator-(const Vec3& rhs) const {
				return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
			}
			Vec3 operator*(double scalar) const {
				return Vec3(x *scalar, y *scalar, z *scalar);
			}

	};
	// More types:  Mat2x2, Mat3x3
}




#endif 