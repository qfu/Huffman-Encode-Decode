/* Sheng Feng A97061648
   Qianran Fu A98100968
   Nov 6 2014
*/   
#include "HCNode.hpp"
bool comp(HCNode* one,HCNode* other){
    return one < other;
}
bool HCNode :: operator<(const HCNode& other){
    if(count != other.count) return  count > other.count;
    return symbol < other.symbol;
}
