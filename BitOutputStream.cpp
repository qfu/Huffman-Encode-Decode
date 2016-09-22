/* Sheng Feng A97061648
   Qianran Fu A98100968
Date: Nov 6 2014
 */   
#include "BitOutputStream.hpp"
/*writeBit*/
void BitOutputStream::writeBit(int bit)
{
    if (bufi == 8)
        flush();
    /*get the bit out*/
    buf = buf | (bit << (7 - bufi));
    bufi++;
}
/*flush*/
void BitOutputStream::flush()
{
    out.put(buf);
    /*clear the buffer*/
    out.flush();
    buf = 0;
    bufi = 0;
}
/*writeByte method*/
void BitOutputStream::writeByte(int bit) {
    out.put(char(bit));
}

/*writeInt method*/
void BitOutputStream::writeInt(int itg) {
    out.write((char *)(&itg), 4);
}
