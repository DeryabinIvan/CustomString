#pragma once

#include <ostream>

class String {
	private:
		char* data = nullptr;
		size_t length = 0;

	public:
		String();
		String(const String& s);
		String(String&& s);
		String(const char* c_str);

		~String();

		String& operator=(const String& s);
		String& operator=(String&& s);
		String& operator=(const char* c_str);

		String& operator+=(const String& s);
		String& operator+=(const char* c_str);

		const char* c_str() const;
		size_t len() const;

		char operator[](int index);

		friend std::ostream& operator<<(std::ostream& os, const String& s);
};

String& operator+(const String& s1, const String& s2);
String& operator+(const String& s, const char* c_str);
