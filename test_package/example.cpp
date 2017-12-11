#include <iostream>
#include <cereal/archives/binary.hpp>
#include <fstream>

struct A
{
	int x = 1;
	int y = 2;

	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(x, y);
	}
};

int main()
{
	{
		std::ofstream os("out.cereal", std::ios::binary);
		cereal::BinaryOutputArchive archive(os);

		A a;
		archive(a);
	}
	{
		std::ifstream is("out.cereal", std::ios::binary);
		cereal::BinaryInputArchive archive(is);

		A a;
		archive(a);

		std::cout << a.x << ' ' << a.y << '\n';
	}

	return 0;
}