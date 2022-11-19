#include<bits/stdc++.h>
using namespace std;

// This will Generate OPTAB, REG, CONDITIONALCODE
void generateTABs(auto& OPTAB, auto& REG, auto& CONDITIONALCODE) {
    OPTAB["STOP"] = {"IS", "00"};
    OPTAB["ADD"] = {"IS", "01"};
    OPTAB["SUB"] = {"IS", "02"};
    OPTAB["MULT"] = {"IS", "03"};
    OPTAB["MOVER"] = {"IS", "04"};
    OPTAB["MOVEM"] = {"IS", "05"};
    OPTAB["COMP"] = {"IS", "06"};
    OPTAB["BC"] = {"IS", "07"};
    OPTAB["DIV"] = {"IS", "08"};
    OPTAB["READ"] = {"IS", "09"};
    OPTAB["PRINT"] = {"IS", "10"};
    OPTAB["START"] = {"AD", "01"};
    OPTAB["END"] = {"AD", "02"};
    OPTAB["ORIGIN"] = {"AD", "03"};
    OPTAB["EQU"] = {"AD", "04"};
    OPTAB["LTORG"] = {"AD", "05"};
    OPTAB["DC"] = {"DL", "01"};
    OPTAB["DS"] = {"DL", "02"};

    REG["AREG"] = 1;
    REG["BREG"] = 2;
    REG["CREG"] = 3;
    REG["DREG"] = 4;

    CONDITIONALCODE["LT"] = 1;
    CONDITIONALCODE["LE"] = 2;
    CONDITIONALCODE["EQ"] = 3;
    CONDITIONALCODE["GT"] = 4;
    CONDITIONALCODE["GE"] = 5;
    CONDITIONALCODE["ANY"] = 6;
}

// This will return the Index of Symbol/Literal from SymbolTable/LiteralTable
// return -1 If Symbol/Literal is not present in SymbolTable/LiteralTable
// For SymbolTable start will be 0
// Because we need to check duplicate from Entire SymbolTable
// For LiteralTable start will be assigned from argument of function call
// Because we need to check duplicate within Current Pool of LiteralTable
int getIndex(auto& TABLE, string str, int start = 0) {
    for (int i = start; i < TABLE.size(); i++)
    {
        if(TABLE[i].first == str) {
            return i;
        }
    }
    return -1;
}

// This will evaluate the value of (operand1 opertion operand2)
int evaluate(int operand1, int operand2, string operation) {
    if(operation == "+") return operand1+operand2;
    else if(operation == "-") return operand1-operand2;
    else if(operation == "*") return operand1*operand2;
    else if(operation == "/") return operand1/operand2;
}

int main(){
    // DataStructures OPTAB, REG, CONDITIONALCODE, SYMTAB, LITTAB, POOLTAB
    map<string, pair<string, string>> OPTAB;
    map<string, int> REG, CONDITIONALCODE;
    vector<pair<string, int>> SYMTAB, LITTAB;
    vector<int> POOLTAB;

    generateTABs(OPTAB, REG, CONDITIONALCODE);

    // Keeping character empty for SPACEs
    string empty = "_";

    ifstream INPUT;
    INPUT.open("input.txt");
    ofstream IC;
    IC.open("ic.txt");

    int lc = 0, index = 0, poolStart = 0;
    string label, opcode, opr1, opr2;

    while(INPUT.eof() != 1) {
        INPUT >> label >> opcode >> opr1 >> opr2;
        string icStr = "";

        // Processing label
        if(label != "_") {
            if(getIndex(SYMTAB, label) == -1) {
                SYMTAB.push_back({label, lc});
            }
        }

        // Generating ic of opcode
        icStr += ("\t("+OPTAB[opcode].first+", "+OPTAB[opcode].second+")\t");

        // Below we are Generating ic of opr1 and opr2. According to Classes

        // Processing IS (Imperative Statements) Class commands
        if(OPTAB[opcode].first == "IS") {
            // Processing opr1 (operand1)
            if(opr1 != empty) {
                // If opr1 is Register
                if(REG[opr1]) icStr += ("("+to_string(REG[opr1])+")\t");
                // If opr1 is ConditionalCode
                else if(CONDITIONALCODE[opr1]) icStr += ("("+to_string(CONDITIONALCODE[opr1])+")\t");
                // If opr1 is Literal
                else if(opr1.substr(0, 2) == "='") {
                    index = getIndex(LITTAB, opr1, poolStart);
                    if(index == -1) LITTAB.push_back({opr1, -1}), index = getIndex(LITTAB, opr1, poolStart);
                    icStr += ("(L, "+to_string(index+1)+")\t");
                }
                // else opr1 is Symbol
                else {
                    index = getIndex(SYMTAB, opr1);
                    if(index == -1) SYMTAB.push_back({opr1, -1}), index = getIndex(SYMTAB, opr1);
                    icStr += ("(S, "+to_string(index+1)+")\t");
                }
            }
            else icStr += (empty+"\t");

            // Processing opr2 (operand2)
            if(opr2 != empty) {
                // If opr2 is Register
                if(REG[opr2]) icStr += ("("+to_string(REG[opr2])+")");
                // If opr2 is ConditionalCode
                else if(CONDITIONALCODE[opr2]) icStr += ("("+to_string(CONDITIONALCODE[opr2])+")");
                // If opr2 is Literal
                else if(opr2.substr(0, 2) == "='") {
                    index = getIndex(LITTAB, opr2, poolStart);
                    if(index == -1) LITTAB.push_back({opr2, -1}), index = getIndex(LITTAB, opr2, poolStart);
                    icStr += ("(L, "+to_string(index+1)+")");
                }
                // else opr2 is Symbol
                else {
                    index = getIndex(SYMTAB, opr2);
                    if(index == -1) SYMTAB.push_back({opr2, -1}), index = getIndex(SYMTAB, opr2);
                    icStr += ("(S, "+to_string(index+1)+")");
                }
            }
            else icStr += (empty);

            IC << lc << icStr << endl;
            ++lc;
        }

        // Processing AD (Assembler Directives) Class commands
        else if(OPTAB[opcode].first == "AD") {
            IC << empty;
            // Processing START
            if(opcode == "START") {
                if(opr1 != empty) lc = stoi(opr1) ;
                icStr += ("(C, "+to_string(lc)+")\t"+empty);
                IC << icStr << endl;
            }
            // Processing END
            else if(opcode == "END") {
                icStr += (empty+"\t"+empty);
                IC << icStr << endl;

                // Literal processing
                for (int i = poolStart; i < LITTAB.size(); i++)
                {
                    LITTAB[i].second = lc;
                    icStr = "\t(DL, 01)\t(C, "+LITTAB[i].first.substr(2, LITTAB[i].first.size()-3)+")\t"+empty;
                    IC << lc << icStr << endl;
                    ++lc;
                }
                // Inserting poolStart+1 into POOLTAB
                POOLTAB.push_back(poolStart+1);
                // poolStart is set to sizeOf(LITTAB)
                poolStart = LITTAB.size();
            }
            // Processing ORIGIN
            else if(opcode == "ORIGIN") {
                int start = 0;
                // Adding "0+" to Expression(opr1)
                opr1 = "0+" + opr1;
                lc = 0;

                // Tokenization of Operands(Tokens) and Operators(Delimiters) from Expression
                vector<string> delimiter, token;
                for (int i = 0; i < opr1.size(); i++)
                {
                    if(opr1[i] == '+' or opr1[i] == '-' or opr1[i] == '*' or opr1[i] == '/') {
                        delimiter.push_back(string (1, opr1[i]));
                        token.push_back(opr1.substr(start, i-start));
                        start = i+1;
                    }
                }
                token.push_back(opr1.substr(start, opr1.size()-start));

                // Evaluating the value of opr1 from generated Operands(Tokens) and Operators(Delimiters)
                for (int i = 0; i < delimiter.size(); i++)
                {
                    // Skips the first delimiter "+". Because we added "0+" to Expression(opr1) --> Check Line No 177
                    if(i) icStr += delimiter[i];
                    if(token[i+1][0] >= '0' and token[i+1][0] <= '9') {
                        icStr += token[i+1];
                        lc = evaluate(lc, stoi(token[i+1]), delimiter[i]);
                    }
                    else {
                        index = getIndex(SYMTAB, token[i+1]);
                        icStr += ("(S, "+to_string(index+1)+")");
                        lc = evaluate(lc, SYMTAB[index].second, delimiter[i]);
                    }
                }

                icStr += ("\t"+empty);
                IC << icStr << endl;
            }
            // Processing EQU
            else if(opcode == "EQU") {
                index = getIndex(SYMTAB, label);
                SYMTAB[index].second = SYMTAB[getIndex(SYMTAB, opr1)].second;
                icStr += ("(S, "+to_string(index+1)+")\t"+empty);
                IC << icStr << endl;
            }
            // Processing LTORG
            else {
                icStr += (empty+"\t"+empty);
                IC << icStr << endl;

                // Literal processing
                for (int i = poolStart; i < LITTAB.size(); i++)
                {
                    LITTAB[i].second = lc;
                    icStr = "\t(DL, 01)\t(C, "+LITTAB[i].first.substr(2, LITTAB[i].first.size()-3)+")\t"+empty;
                    IC << lc << icStr << endl;
                    ++lc;
                }
                // Inserting poolStart+1 into POOLTAB
                POOLTAB.push_back(poolStart+1);
                // poolStart is set to sizeOf(LITTAB)
                poolStart = LITTAB.size();
            }
        }

        // Processing DL (Declaration Statements) Class commands
        else {
            if(opcode == "DC") opr1 = opr1.substr(1, opr1.size()-2);

            icStr += ("(C, "+opr1+")\t"+empty);
            index = getIndex(SYMTAB, label);
            if(index == -1) SYMTAB.push_back({label, lc});
            else SYMTAB[index].second = lc;

            IC << lc << icStr << endl;
            // Incrementing value of lc by 1 if opcode is DC
            // Incrementing value of lc by opr1 if opcode is DS
            lc += (opcode == "DS") ? stoi(opr1) : 1;
        }
    }

    string line;
    // Inserting SYMTAB into SymbolTable.txt
    ofstream TAB;
    TAB.open("symbolTable.txt");
    for (int i = 0; i < SYMTAB.size(); i++)
    {
        line = SYMTAB[i].first + " " + to_string(SYMTAB[i].second);
        TAB << line << endl;
    }
    TAB.close();

    // Inserting LITTAB into literalTable.txt
    TAB.open("literalTable.txt");
    for (int i = 0; i < LITTAB.size(); i++)
    {
        line = LITTAB[i].first + " " + to_string(LITTAB[i].second);
        TAB << line << endl;
    }
    TAB.close();

    // Inserting POOLTAB into poolTable.txt
    TAB.open("poolTable.txt");
    for (int i = 0; i < POOLTAB.size(); i++)
    {
        TAB << POOLTAB[i] << endl;
    }
    TAB.close();

    INPUT.close(), IC.close();
    return 0;
}