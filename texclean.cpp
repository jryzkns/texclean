#include <iostream>
#include <array>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>

int main()
{
	std::array<std::string, 6> exts{
		".aux", ".fdb_latexmk", ".fls", ".log", ".out", ".synctex.gz" };

	boost::filesystem::path pwd = boost::filesystem::current_path();
	boost::filesystem::directory_iterator itr(pwd);
	while (itr != boost::filesystem::directory_iterator())
	{
		auto f_path = itr->path().string();
		if (std::any_of(exts.begin(), exts.end(), [&](std::string ext)
				{return boost::algorithm::ends_with(f_path, ext); })) {
			std::cout << "Deleting: " << f_path << std::endl;
			boost::filesystem::remove(itr->path());
		}
		++itr;
	}
}
