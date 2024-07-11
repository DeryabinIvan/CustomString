#include <iostream>
#include <vector>
#include <algorithm>

#include "String.h"

bool compare(const String& s1, const String& s2) {
	const char* buf1 = s1.c_str();
	const char* buf2 = s2.c_str();

	char* copybuf1 = new char[s1.len() + 1];
	char* copybuf2 = new char[s2.len() + 1];

	memset(copybuf1, '\0', s1.len() + 1);
	memset(copybuf2, '\0', s2.len() + 1);

	for (size_t i = 0; i < s1.len(); i++) {
		if (buf1[i] >= 'A' && buf1[i] <= 'Z') {
			copybuf1[i] = buf1[i] - 'A' + 'a';
		} else {
			copybuf1[i] = buf1[i];
		}
	}

	for (size_t i = 0; i < s2.len(); i++) {
		if (buf2[i] >= 'A' && buf2[i] <= 'Z') {
			copybuf2[i] = buf2[i] - 'A' + 'a';
		} else {
			copybuf2[i] = buf2[i];
		}
	}

	bool res = strcmp(copybuf1, copybuf2) > 0;

	delete[] copybuf1;
	delete[] copybuf2;

	return res;
}

int main(int argc, char** argv) {
	std::vector<String> v;

	for (int i = 1; i < argc; i++) {
		v.push_back(argv[i]);
	}

	std::sort(v.begin(), v.end(), compare);

	for (const auto& entity : v) {
		std::cout << entity << std::endl;
	}

	return 0;
}