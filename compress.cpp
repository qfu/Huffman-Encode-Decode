/* Sheng Feng A97061648
   Qianran Fu A98100968
   Nov 6 2014
*/   



#include "HCTree.hpp"
#include <fstream>
#include <iostream>
#include "vector"

using namespace std;

int main(int argc, char** argv ){
    if(argc != 3){
        cerr << "Not enough argument" << endl;
        return -1;
    }
    string input1 = argv[1];
    string input2 = argv[2];
    if(input1 == input2){
        return -1;
    }
    else{

        ifstream in;
        in.open(input1,ios::binary);

        if (!in.good()){
            cerr << "the stream error occurs" << endl;
            return -1;
        }
        //able to use
        std::vector<int> freqs(256,0);

        while(!in.eof()){
            freqs[in.get()]++;
        }
        /*
        for(int value:freqs){
            cout << value;
        }*/

        in.close();

        HCTree newTree;
        newTree.build(freqs);
        
        ofstream out;
        out.open(argv[2],ios::binary);

        if(!out.good()){
            cerr << "the stream error occurs" << endl;
            return -1;
        }

        for(size_t i=0; i < freqs.size(); i++){
            //out.put(freqs[i]);
            out.write(reinterpret_cast<char*>(&freqs[i]), sizeof freqs[i]);
            //out << freqs[i];
        }

        ifstream encode;
        encode.open(argv[1],ios::binary);
        if(!encode.good()){
            cerr << "the stream error occurs" << endl;
            return -1;
        }
        int nextByte;
        while((nextByte=encode.get())!= EOF ){
            byte code = (unsigned char)nextByte;
            if(!encode.good())
                break;
            newTree.encode(code, out);
        }
        //os.flush();
        out.close();
        encode.close();
        return 0;

        /*
        ifstream in;
        in.open(argv[1],ios::binary);
        if(!in.good()){
            cerr << "the stream error occurs" << endl;
            return -1;
        }
        else{
            vector<int> freqs(256, 0);
            int count = 0;
            byte c;
            while(in.good()){
                c = in.get();
                if(in.eof())
                    break;
                freqs[c]++;
                count++;
            }
            in.close();
            HCTree newTree;
            newTree.build(freqs);
            ofstream out;
            BitOutputStream os(out);
            out.open(argv[2],ios::binary);
            if(!out.good()){
                cerr << "the stream error occurs" << endl;
                return -1;
            }
            os.writeInt(count);
            for(size_t i=0; i< freqs.size();i++){
                os.writeInt(freqs[i]);
            }

            ifstream encode;
            encode.open(argv[1],ios::binary);
            if(!encode.good()){
                cerr << "the stream error occurs" << endl;
                return -1;
            }
            byte code;
            for(int i = 0; i < count; i++){
                code = encode.get();
                if(!encode.good())
                    return -1;
                newTree.encode(code, os);
            }
            os.flush();
            out.close();
            encode.close();
            return 0;
         */
        
    }
}
