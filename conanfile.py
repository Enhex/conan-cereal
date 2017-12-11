from conans import ConanFile, tools
import os


class CerealConan(ConanFile):
	name = "cereal"
	version = "master"
	description = "A C++11 library for serialization"
	# No settings/options are necessary, this is header only

	def source(self):
		self.run("git clone --depth 1 --branch master https://github.com/USCiLab/cereal.git")

	def package(self):
		self.copy("*.h", dst="include", src="cereal/include")
		self.copy("*.hpp", dst="include", src="cereal/include")
