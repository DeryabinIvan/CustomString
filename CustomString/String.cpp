#include "String.h"

#include <memory>

String::String() {
	this->data = new char[1];
	this->data[0] = '\0';

	this->length = 0;
}

String::String(const String& s) {
	this->length = s.length;
	this->data = new char[this->length + 1];

	memcpy(this->data, s.data, sizeof(char) * (this->length + 1));
}

String::String(String&& s) {
	if (this->data != nullptr) {
		delete[] this->data;
	}

	this->length = s.length;
	this->data = s.data;

	s.length = 0;
	s.data = nullptr;
}

String::String(const char* c_str) {
	if (c_str != nullptr) {
		this->length = strlen(c_str);
		this->data = new char[this->length + 1];

		memcpy(this->data, c_str, sizeof(char) * (this->length + 1));
	}
}

String::~String() {
	if (this->data != nullptr) {
		delete[] this->data;
	}
}

String& String::operator=(const String& s) {
	if (&s != this) {
		if (this->data != nullptr) {
			delete[] this->data;
		}

		this->length = s.length;
		this->data = new char[this->length + 1];

		memcpy(this->data, s.data, sizeof(char) * (this->length + 1));
	}

	return *this;
}

String& String::operator=(String&& s) {
	if (&s != this) {
		if (this->data != nullptr) {
			delete[] this->data;
		}

		this->length = s.length;
		this->data = s.data;

		s.length = 0;
		s.data = nullptr;
	}

	return *this;
}

String& String::operator=(const char* c_str) {
	if (c_str != nullptr) {
		if (this->data != nullptr) {
			delete[] this->data;
		}

		this->length = strlen(c_str);
		this->data = new char[this->length + 1];

		memcpy(this->data, c_str, sizeof(char) * (this->length + 1));
	}

	return *this;
}


String& operator+(const String& s1, const String& s2) {
	auto sumlength = s1.len() + s2.len();
	auto sumdata = new char[sumlength + 1];

	memcpy(sumdata, s1.c_str(), sizeof(char) * (s1.len()));
	memcpy(sumdata + s1.len(), s2.c_str(), sizeof(char) * (s2.len() + 1));

	String* sum = new String(sumdata);

	return *sum;
}

String& operator+(const String& s, const char* c_str) {
	auto sumlength = s.len() + strlen(c_str);
	auto sumdata = new char[sumlength + 1];

	memcpy(sumdata, s.c_str(), sizeof(char) * (s.len()));
	memcpy(sumdata + s.len(), c_str, sizeof(char) * (strlen(c_str) + 1));

	String* sum = new String(sumdata);

	return *sum;
}

String& String::operator+=(const String& s) {
	(*this) = *this + s;
	return *this;
}

String& String::operator+=(const char* c_str) {
	(*this) = *this + c_str;
	return *this;
}

const char* String::c_str() const {
	return this->data;
}

size_t String::len() const {
	return this->length;
}

char String::operator[](int index) {
	if (index >= 0 && index <= this->length) {
		return this->data[index];
	}

	return '\0';
}

std::ostream& operator<<(std::ostream& os, const String& s) {
	if (s.length > 0) {
		os << s.data;
	}

	return os;
}
