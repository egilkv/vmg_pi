# vmg_pi
OpenCPN plugin for VMG
======================

License
=======
The plugin is licensed under the terms of GPL v2 or, at your will, later.

Building
========

Follows this pattern on Linux:

	mkdir build
	cd build
	cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr ..
	make
	sudo make install

Without the option, cmake will prepare for installation in /usr/local.
