/* Sheng Feng A97061648
   Qianran Fu A98100968
   Nov 6 2014
 */   
#include "HCTree.hpp"
/*helper function for deconstructor*/
void clear(HCNode* node) {
  if (node->c0 != NULL)
    clear(node->c0);
  if( node -> c1 != NULL)
    clear(node->c1);
  delete node;
}




/*deconstructor*/
HCTree::~HCTree(){
  clear(this->root);
}
/*Build the huffman tree*/
void HCTree :: build(const vector<int>& freqs){

  priority_queue<HCNode*,vector<HCNode*>,HCNodePtrComp> pq;
  for(size_t i = 0; i < freqs.size(); i++){
    HCNode* node = new HCNode(freqs[i],i);
    leaves[i] = node;
    pq.push(leaves[i]);
  }
  while(pq.size() != 1){
    HCNode* first_child = pq.top();
    pq.pop();
    HCNode* second_child = pq.top();
    pq.pop();
    HCNode* parent_node = new HCNode(first_child-> count + second_child -> count,
      first_child->symbol,first_child,second_child);
    first_child -> p = parent_node;
    second_child -> p = parent_node;
    pq.push(parent_node);
  }
  this -> root = pq.top();
  pq.pop();

}
/*Encode the input file */
//for final
void HCTree :: encode(byte symbol, BitOutputStream& out) const{ 
 
}

//for checkpoint

void HCTree :: encode(byte symbol, ofstream& out) const{ 
  //Doesn't care about the header

  HCNode* currNode = leaves[symbol];
  stack<char> charStack;
  while (currNode -> p != NULL){
    charStack.push((currNode -> p -> c0 == currNode)?'0':'1');
    currNode = currNode -> p;
  }  

  while(!charStack.empty()){
    out.put(charStack.top());
    charStack.pop();

  }
}
 
/*decode the file */
  
//for final
int HCTree :: decode(BitInputStream& in) const{
    

}
//for checkpoint

int HCTree :: decode(ifstream& in) const{

  HCNode* currNode = this -> root;
  //both childs are NULL
  while (currNode -> c0 !=NULL || currNode -> c1 != NULL){
    
      byte sym = (unsigned char)in.get();
      currNode = (sym =='0')?currNode->c0:currNode->c1;
  }
  return (int)currNode->symbol;
}
 

