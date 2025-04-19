all: configure install

configure:
	mkdir -p build
	cd build && cmake ..

install:
	cd build && make install

clean:
	rm -rf build
