If you are trying to run lex and yacc in your windows it wont work.
to run these files with extention (.l and .y) do steps given below
1. download virtual machine.
2. install ubuntu in virtual machines.
3. install gcc
**install packages flex and bison with below cmd commands**
    [1]. sudo apt-get update
    [2]. sudo apt-get install flex    (command for installing lex)
    [3]. sudo apt-get install bison   (command for installing yacc)
**To run LEX** -->
    1. lex programName.l
    2. gcc lex.yy.c
    3. ./a.out
**To run YACC** -->
    1. yacc programName.y
    2. gcc y.tab.c
    3. ./a.out
