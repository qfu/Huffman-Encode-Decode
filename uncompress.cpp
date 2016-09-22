/* SHeng Feng A97061648
   Qianran Fu A98100968
   Nov 6 2014
*/   


#include "HCTree.hpp"
#include <fstream>
#include <iostream>
#include "vector"

using namespace std;

int main(int argc, char** argv){
    if(argc != 3){
        cerr << "Not enough arguments" << endl;
        return -1;
    }
    else{

        ifstream in(argv[1], ios::binary);
        ofstream out(argv[2],ios::binary);

        if(!in.is_open()){
            cerr << "failed to open file" << endl;
            return -1;
        }


        std::vector<int> freqs(256,0);
        for (size_t i = 0; i< freqs.size(); i++){
            //freqs[i] = in.get();
            in.read(reinterpret_cast<char*>(&freqs[i]), sizeof freqs[i]);
        }

        HCTree tree;
        tree.build(freqs);

        if(!out.good()){
            cerr << "The stream error occrus" << endl;
            return -1;
        }
        int nextByte;
        while((nextByte=in.get())!= EOF ){
            in.unget();
            out.put(tree.decode(in));
        }

        out.close();
        in.close();
        return 0;


    }
}
