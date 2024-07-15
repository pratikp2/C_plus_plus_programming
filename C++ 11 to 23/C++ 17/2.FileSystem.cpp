#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
	// Path Class Functionalities :
	fs::path p = fs::current_path();
	std::cout << "Current root name is	: " << fs::current_path().root_name() << std::endl;
	std::cout << "The current path		: " << p << std::endl;
	std::cout << "Root directory		: " << p.root_directory() << std::endl;
	std::cout << "Relative path			: " << p.relative_path() << std::endl;
	std::cout << "File name				: " << fs::path("/foo/bar.txt").filename() << std::endl;
	std::cout << "File Extesion			: " << fs::path("/foo/bar.txt").extension() << std::endl;

	// Directory and File Creation :
	fs::create_directories("C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc");
	std::ofstream{ "C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc\\file1.txt" };
	std::ofstream{ "C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc\\file2.txt" };

	// Directory and File Iteration : 
	for (const fs::directory_entry& entry : fs::directory_iterator{ "C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc" })
		std::cout << entry << '\n';

	// Directory and File Copy
	fs::create_directories("C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc2");
	fs::copy("C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc\\file1.txt", "C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc2\\file3.txt"); // copy file
	//fs::copy("C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc2", "C:\\Users\\pratik.patil2\\Desktop\\ABC\\abc2"); // copy directory (non-recursive)

	// Space Info :
	fs::space_info devi = fs::space("C:\\Users\\pratik.patil2\\Desktop\\");
	std::cout << "Capacity Available : " << devi.capacity << std::endl;
	std::cout << "Capacity Free : " << devi.free << std::endl;

	// Directory and File removal : 
	fs::remove_all("C:\\Users\\pratik.patil2\\Desktop\\ABC");


	return 0;
}