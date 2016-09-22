/* Sheng Feng A97061648
   Qianran Fu A98100968
   Date: Nov 6 2014
*/   
#include "BitInputStream.hpp"
/*ReadBit*/
int BitInputStream::readBit() {


	if(in.eof()){
		return -1;
	}

	if(bufi == 8){
		buf = in.get();
		bufi = 0;
	}
	int value = (buff << (7-bufi)) >> 7;
	bufi++;
	return value;

	/*
	if (in.eof()) {
		return -1;
	}
	if (bufi == 8) {
        buf = in.get();
        bufi = 0;
	}
	int bit = 1 & (buf >> (7 - bufi));
	bufi++;
	return bit;
	*/
}
/*readByte*/
int BitInputStream::readByte() {


	if(in.eof()){
		return -1;
	}
	byte value = in.get();
	return (int)value;
	/*
	if (in.eof()) {
		return -1;
	}
	char byte = in.get();
	return (int)byte;*/
}
/*readInt*/
int BitInputStream::readInt() {

	int temp = 0;
	in.read((char *)&temp, 4);
	if (in.eof()) {
		return -1;
	}
	return temp;
}

