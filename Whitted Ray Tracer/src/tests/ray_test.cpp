#include <gtest/gtest.h>

#include <iostream>

#include "../primitives/ray.h"

#include "../helpers.h"
#include "../primitives/tuple.h"
#include "../shapes/sphere.h"

namespace {

	TEST(RayTest, Init) {

		Tuple origin = Point(1, 2, 3);
		Tuple direction = Vector(4, 5, 6);
		
		Ray init = Ray(origin, direction);
		
		EXPECT_TRUE(init.origin() == origin);
		EXPECT_TRUE(init.direction() == direction);

	}

	TEST(RayTest, PointPosition) {

		Tuple origin = Point(2, 3, 4);
		Tuple direction = Vector(1, 0, 0);

		Ray ray = Ray(origin, direction);

		EXPECT_TRUE(ray.position(0) == Point(2, 3, 4));
		EXPECT_TRUE(ray.position(1) == Point(3, 3, 4));
		EXPECT_TRUE(ray.position(-1) == Point(1, 3, 4));
		EXPECT_TRUE(ray.position(2.5) == Point(4.5, 3, 4));

	}

	TEST(RayTest, RaySphereTwoPointIntersection) {

		Ray ray = Ray(Point(0, 0, -5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = sphere.intersection(ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0], 4.0));
		EXPECT_TRUE(fequals(intersections[1], 6.0));

	}

	TEST(RayTest, RaySphereTangentIntersection) {

		Ray ray = Ray(Point(0, 1, -5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = sphere.intersection(ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0], 5.0));
		EXPECT_TRUE(fequals(intersections[1], 5.0));

	}

	TEST(RayTest, RaySphereNoIntersection) {

		Ray ray = Ray(Point(0, 2, -5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = sphere.intersection(ray);

		EXPECT_EQ(intersections.size(), 0);

	}

	TEST(RayTest, RayInsideSphereTwoPointIntersection) {

		Ray ray = Ray(Point(0, 0, 0), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = sphere.intersection(ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0], -1.0));
		EXPECT_TRUE(fequals(intersections[1], 1.0));

	}

	TEST(RayTest, RayInfrontOfSphereTwoPointIntersection) {

		Ray ray = Ray(Point(0, 0, 5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = sphere.intersection(ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0], -6.0));
		EXPECT_TRUE(fequals(intersections[1], -4.0));

	}

}
