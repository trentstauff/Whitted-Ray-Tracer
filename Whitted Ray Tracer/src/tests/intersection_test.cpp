#include <gtest/gtest.h>

#include <iostream>

#include "../primitives/ray.h"
#include "../helpers.h"
#include "../shapes/sphere.h"
#include "../primitives/intersection.h"
#include "../primitives/intersections.h"


namespace {

	TEST(IntersectionTest, Init)
	{
		auto s = Sphere();
		auto i = Intersection(3.5, &s);

		EXPECT_TRUE(fequals(3.5, i.t()));
		EXPECT_EQ(i.object(), &s);
		
	}

	TEST(IntersectionTest, AggregatingIntersections)
	{
		auto s = Sphere();
		auto i1 = Intersection(1, &s);
		auto i2 = Intersection(2, &s);

		auto xs = Intersections(std::vector<Intersection>{i1, i2});

		EXPECT_EQ(xs.size(), 2);
		
		EXPECT_EQ(xs[0].t(), 1);
		EXPECT_EQ(xs[1].t(), 2);

	}

	TEST(IntersectionTest, HitWhenAllIntersectionsHavePositiveT)
	{
		auto s = Sphere();
		auto i1 = Intersection(1, &s);
		auto i2 = Intersection(2, &s);

		auto xs = Intersections(std::vector<Intersection>{i1, i2});

		auto i = xs.hit().value();

		i1.print();
		i.print();
		
		EXPECT_EQ(&i, &i1);

	}

}
