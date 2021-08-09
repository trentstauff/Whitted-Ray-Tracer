#include <gtest/gtest.h>

#include "../primitives/ray.h"
#include "../helpers.h"
#include "../primitives/tuple.h"
#include "../shapes/sphere.h"

namespace {

	TEST(SphereTest, RaySphereTwoPointIntersection) {

		Ray ray = Ray(Point(0, 0, -5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = intersection(&sphere, ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0].t(), 4.0));
		EXPECT_TRUE(fequals(intersections[1].t(), 6.0));

	}

	TEST(SphereTest, RaySphereTangentIntersection) {

		Ray ray = Ray(Point(0, 1, -5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = intersection(&sphere, ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0].t(), 5.0));
		EXPECT_TRUE(fequals(intersections[1].t(), 5.0));

	}

	TEST(SphereTest, RaySphereNoIntersection) {

		Ray ray = Ray(Point(0, 2, -5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = intersection(&sphere, ray);

		EXPECT_EQ(intersections.size(), 0);

	}

	TEST(SphereTest, RayInsideSphereTwoPointIntersection) {

		Ray ray = Ray(Point(0, 0, 0), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = intersection(&sphere, ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0].t(), -1.0));
		EXPECT_TRUE(fequals(intersections[1].t(), 1.0));

	}

	TEST(SphereTest, RayInfrontOfSphereTwoPointIntersection) {

		Ray ray = Ray(Point(0, 0, 5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = intersection(&sphere, ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_TRUE(fequals(intersections[0].t(), -6.0));
		EXPECT_TRUE(fequals(intersections[1].t(), -4.0));

	}

	TEST(SphereTest, SphereIntersectSetsObject) {

		Ray ray = Ray(Point(0, 0, -5), Vector(0, 0, 1));
		Sphere sphere = Sphere();

		auto intersections = intersection(&sphere, ray);

		EXPECT_EQ(intersections.size(), 2);
		EXPECT_EQ(intersections[0].object(), &sphere);
		EXPECT_EQ(intersections[1].object(), &sphere);

	}

}
