

learn: main.cpp matrix.cpp matrix.hpp lin_reg.cpp lin_reg.hpp meanstd.h
	g++ -Wall main.cpp lin_reg.cpp matrix.cpp -o learn
