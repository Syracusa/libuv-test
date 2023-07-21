mkdir -p lib
git clone https://github.com/libuv/libuv.git
cd libuv
mkdir -p build
cd build
cmake ..
make
cp libuv.a ../../lib/
cd ..
cp -r include ..
cd ..
rm -rf libuv
