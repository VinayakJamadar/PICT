// IMPORTANT NOTE : 
// 1. File Format of input.txt
// label opcode opr1 opr2
// Where
// label --> Either Symbol or empty
// opcode --> always anyone command from OPTAB
// opr1 --> Either Register, ConditionalCode or empty
// opr2 --> Either Symbol, Literal, Expression, Constant or empty

// 2. used "_" as empty

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
        icStr += ("\t("+OPTAB[opcode].first+","+OPTAB[opcode].second+")\t");

        // Below ic of opr1 and opr2 generated. According to Classes

        // Processing IS (Imperative Statements) Class commands
        if(OPTAB[opcode].first == "IS") {
            // Processing opr1 (operand1)
            if(opr1 != empty) {
                // If opr1 is Register
                if(REG[opr1]) icStr += ("("+to_string(REG[opr1])+")\t");
                // else opr1 is ConditionalCode
                else icStr += ("("+to_string(CONDITIONALCODE[opr1])+")\t");
            }
            else icStr += (empty+"\t");

            // Processing opr2 (operand2)
            if(opr2 != empty) {
                // If opr2 is Literal
                if(opr2.substr(0, 2) == "='") {
                    index = getIndex(LITTAB, opr2, poolStart);
                    if(index == -1) LITTAB.push_back({opr2, -1}), index = getIndex(LITTAB, opr2, poolStart);
                    icStr += ("(L,"+to_string(index+1)+")");
                }
                // else opr2 is Symbol
                else {
                    index = getIndex(SYMTAB, opr2);
                    if(index == -1) SYMTAB.push_back({opr2, -1}), index = getIndex(SYMTAB, opr2);
                    icStr += ("(S,"+to_string(index+1)+")");
                }
            }
            else icStr += (empty);

            IC << lc << icStr << endl;
            ++lc;
        }

        // Processing AD (Assembler Directives) Class commands
        else if(OPTAB[opcode].first == "AD") {
            IC << empty;
            icStr += (empty+"\t");
            // Processing START
            if(opcode == "START") {
                if(opr2 != empty) lc = stoi(opr2) ;
                icStr += ("(C,"+to_string(lc)+")");
                IC << icStr << endl;
            }
            // Processing END
            else if(opcode == "END") {
                icStr += empty;
                IC << icStr << endl;

                // Literal processing
                for (int i = poolStart; i < LITTAB.size(); i++)
                {
                    LITTAB[i].second = lc;
                    icStr = "\t(DL,01)\t"+empty+"\t(C,"+LITTAB[i].first.substr(2, LITTAB[i].first.size()-3)+")";
                    IC << lc << icStr << endl;
                    ++lc;
                }
                // Inserting poolStart+1 into POOLTAB
                POOLTAB.push_back(poolStart+1);
                // poolStart is set to sizeOf(LITTAB)
                poolStart = LITTAB.size();
            }
            // Processing ORIGIN and EQU
            else if(opcode == "ORIGIN" or opcode == "EQU") {
                // Evaluating value of opr2 (Expression)

                int start = 0, value = 0;
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
                    // Skips the first delimiter "+". Because we added "0+" to Expression(opr2)
                    if(i) icStr += delimiter[i];
                    if(token[i+1][0] >= '0' and token[i+1][0] <= '9') {
                        icStr += token[i+1];
                        value = evaluate(value, stoi(token[i+1]), delimiter[i]);
                    }
                    else {
                        index = getIndex(SYMTAB, token[i+1]);
                        icStr += ("(S,"+to_string(index+1)+")");
                        value = evaluate(value, SYMTAB[index].second, delimiter[i]);
                    }
                }

                // For ORIGIN --> Updating lc to value
                if(opcode == "ORIGIN") lc = value;
                // For EQU --> Updating Address of label to value
                else {
                    index = getIndex(SYMTAB, label);
                    SYMTAB[index].second = value;
                }

                IC << icStr << endl;
            }
            // Processing LTORG
            else {
                icStr += (empty);
                IC << icStr << endl;

                // Literal processing
                for (int i = poolStart; i < LITTAB.size(); i++)
                {
                    LITTAB[i].second = lc;
                    icStr = "\t(DL,01)\t"+empty+"\t(C,"+LITTAB[i].first.substr(2, LITTAB[i].first.size()-3)+")";
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
            if(opcode == "DC") opr2 = opr2.substr(1, opr2.size()-2);

            icStr += (empty+"\t(C,"+opr2+")");
            index = getIndex(SYMTAB, label);
            if(index == -1) SYMTAB.push_back({label, lc});
            else SYMTAB[index].second = lc;

            IC << lc << icStr << endl;
            // Incrementing value of lc by 1 if opcode is DC
            // Incrementing value of lc by opr2 if opcode is DS
            lc += (opcode == "DS") ? stoi(opr2) : 1;
        }
    }

    string line;
    // Inserting SYMTAB into SymbolTable.txt
    ofstream TABLE;
    TABLE.open("symbolTable.txt");
    for (int i = 0; i < SYMTAB.size(); i++)
    {
        line = SYMTAB[i].first + " " + to_string(SYMTAB[i].second);
        TABLE << line << endl;
    }
    TABLE.close();

    // Inserting LITTAB into literalTable.txt
    TABLE.open("literalTable.txt");
    for (int i = 0; i < LITTAB.size(); i++)
    {
        line = LITTAB[i].first + " " + to_string(LITTAB[i].second);
        TABLE << line << endl;
    }
    TABLE.close();

    // Inserting POOLTAB into poolTable.txt
    TABLE.open("poolTable.txt");
    for (int i = 0; i < POOLTAB.size(); i++)
    {
        TABLE << POOLTAB[i] << endl;
    }
    TABLE.close();

    INPUT.close(), IC.close();
    return 0;
}