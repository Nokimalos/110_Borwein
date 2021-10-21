#!/usr/bin/env bash

cyanclair='\e[1;36m'
vertclair='\e[1;32m'
rougefonce='\e[0;31m'
violetclair='\e[1;35m'
rose='\e[1;31m'
bleufonce='\e[0;34m'
bleuclair='\e[1;34m'
grisclair='\e[0;37m'
jaune='\e[1;33m'
blanc='\e[1;37m'
neutre='\e[0;39m'

testargv()
{
    ./110borwein $1 $2 &> saveres
    if [ "$?" -eq $4 ]
    then
        echo -e "${blanc}TEST:  ${cyanclair}$3  \e[32mPASSED\e[39m"
        EXIT=0
    else
        echo -e "${blanc}TEST:  ${cyanclair}$3  \e[91mFAIL\e[39m"
        EXIT=1
    fi
}

testrigor()
{
    ./110borwein $1 &> saveres
    if [ "$?" -eq $3 ]
    then
        echo -e "${blanc}TEST:  ${cyanclair}$2  \e[32mPASSED\e[39m"
        EXIT=0
    else
        echo -e "${blanc}TEST:  ${cyanclair}$2  \e[91mFAIL\e[39m"
        EXIT=1
    fi
}

testbasic()
{
    ./110borwein $1 &> saveres
    if [ "$?" -eq $2 ]
    then
        diff result/$3 saveres &> /dev/null
        if [ "$?" -eq $4 ]
        then
            echo -e "${blanc}TEST:  ${cyanclair}$5  \e[32mPASSED\e[39m"
        else
            echo -e "$?"
            echo -e "${blanc}TEST:  ${cyanclair}$5  \e[91mFAIL\e[39m"
        fi
    fi
}

echo -e "${rose}Debut des tests rigor."
testargv "123" "456" "too much arguments" "84"
testrigor "1" "valid argument if argv[1] = 1" "0"
testrigor "200" "valid argument if argv[1] = 200" "0"
testrigor "aaa" "invalid argument if argv[1] = aaa" "84"
testrigor "-1" "invalid argument if argv[1] = -1" "84"
echo -e "${rose}Fin des tests rigor."
echo -e ""
echo -e "${rose}Debut des tests basic."
testbasic "0" "0" "test_res_0" "0" "test with 0"
testbasic "10" "0" "test_res_10" "0" "test with 10"
testbasic "100" "0" "test_res_100" "0" "test with 100"
echo -e "${rose}Fin des tests basic."
echo -e ""
echo -e "${violetclair}By Noki and Arzuto, enjoy <3"
echo -e "${neutre}"
rm -f saveres

exit $EXIT
