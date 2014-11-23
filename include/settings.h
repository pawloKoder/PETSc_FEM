#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings {
	Settings();
	~Settings();

public:
	static Settings & self();
	static void init(int argc, char **argv);

private:
	std::string inputFile;
	std::string outDir;
	bool skip;
	
	void init_impl(int argc, char **argv);
};

#endif //SETTINGS_H