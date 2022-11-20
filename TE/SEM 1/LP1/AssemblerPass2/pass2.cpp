// IMPORTANT NOTE : Don't keep empty or extra last line in ic.txt, symbolTable.txt and literalTable.txt 
// REASON : Because of using 'endl' their is a empty or extra last line is generated while writing is above listed files.

#include<bits/stdc++.h>
using namespace std;

// This will evaluate the value of (operand1 opertion operand2)
int evaluate(int operand1, int operand2, string operation) {
    if(operation == "+") return operand1+operand2;
    else if(operation == "-") return operand1-operand2;
    else if(operation == "*") return operand1*operand2;
    else if(operation == "/") return operand1/operand2;
}

int main(){
    // DataStructures SYMTAB, LITTAB
    vector<pair<string, int>> SYMTAB, LITTAB;

    // Keeping character empty for SPACEs
    string empty = "_";

    ifstream TABLE, IC;
    ofstream OUTPUT;

    string str;
    int val;
    
    // Generating SYMTAB from symbolTable.txt
    TABLE.open("symbolTable.txt");
    while(TABLE.eof() != 1) {
        TABLE >> str >> val;
        SYMTAB.push_back({str, val});
    }
    TABLE.close();

    // Generating LITTAB from literalTable.txt
    TABLE.open("literalTable.txt");
    while(TABLE.eof() != 1) {
        TABLE >> str >> val;
        LITTAB.push_back({str, val});
    }
    TABLE.close();

    string lc, opcode, opr1, opr2, machineCode;
    IC.open("ic.txt");
    OUTPUT.open("output.txt");

    while(IC.eof() != 1) {
        IC >> lc >> opcode >> opr1 >> opr2;
        
        // if opcode is AD classes commands and DS command --> machineCode = "NO MACHINE CODE"
        if(lc == empty or opcode == "(DL,02)") {
            machineCode = "NO MACHINE CODE";
        }
        // else if DC command --> machineCode = "00" + "0" + constant value of opr2
        else if(opcode == "(DL,01)") {
            machineCode = "+\t00\t0\t"+opr2.substr(3, opr2.size()-4);
        }
        // else --> machineCode = IS class code of opcode + code of Register Or ConditionalCode + evaluated value of opr2 Expression
        else {
            machineCode = "+\t";
            // machineCode for opcode
            machineCode += opcode.substr(4, opcode.size()-5)+"\t";
            // machineCode for opr1
            machineCode += (opr1 != empty ? opr1.substr(1, 1) : "0")+"\t";
            // machineCode for opr2
            if(opr2 != empty) {
                // Evaluating value of opr2 (Expression)

                int start = 0, value = 0, index ;
                // Adding "0+" to Expression(opr2)
                opr2 = "0+" + opr2;

                // Tokenization of Operands(Tokens) and Operators(Delimiters) from Expression
                vector<string> delimiter, token;
                for (int i = 0; i < opr2.size(); i++)
                {
                    if(opr2[i] == '+' or opr2[i] == '-' or opr2[i] == '*' or opr2[i] == '/') {
                        delimiter.push_back(string (1, opr2[i]));
                        token.push_back(opr2.substr(start, i-start));
                        start = i+1;
                    }
                }
                token.push_back(opr2.substr(start, opr2.size()-start));

                // Evaluating value of opr2 from generated Operands(Tokens) and Operators(Delimiters)
                for (int i = 0; i < delimiter.size(); i++)
                {
                    if(token[i+1][0] >= '0' and token[i+1][0] <= '9') {
                        value = evaluate(value, stoi(token[i+1]), delimiter[i]);
                    }
                    else {
                        index = stoi(token[i+1].substr(3, token[i+1].size()-4))-1;
                        value = evaluate(value, (token[i+1][1] == 'S' ? SYMTAB[index].second : LITTAB[index].second), delimiter[i]);
                    }
                }

                // Appending final value of opr2 Expression into machineCode
                machineCode += to_string(value);
            }
            else machineCode += "0";
        }
        // Writing machineCode in output.txt file
        OUTPUT << machineCode << endl;
    }

    TABLE.close(), IC.close(), OUTPUT.close();

    return 0;
}