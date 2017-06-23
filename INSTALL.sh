#! /bin/bash

handleError()
{
    if [ $? != 0 ]; then
        echo -e "${COLOR_3}    ===> $1${NONE}"

        echo -e ""
        echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
        echo -e "${COLOR_1}# ###   ${COLOR_3}Install was not successful${COLOR_1}   ### #${NONE}"
        echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
        echo -e ""

        exit $2
    fi
}

COLOR_1='\033[0;34m'
COLOR_2='\033[1;32m'
COLOR_3='\033[1;3;31m'

NONE='\033[0m'

echo -e ""
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e "${COLOR_1}# ###     ${COLOR_2}Type <Enter> to begin.${COLOR_1}     ### #${NONE}"
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"

read -p ""

echo -e ""
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e "${COLOR_1}# ###     ${COLOR_2}Cleaning Build/ folder${COLOR_1}     ### #${NONE}"
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e ""

cd Build/

    handleError "cd encountered a problem." 1

rm -rf *

    handleError "rm encountered a problem." 2

echo -e ""
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e "${COLOR_1}# ###         ${COLOR_2}CMake building${COLOR_1}         ### #${NONE}"
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e ""

cmake ..

    handleError "cmake encountered a problem." 3

echo -e ""
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e "${COLOR_1}# ###        ${COLOR_2}Compiling Taktix${COLOR_1}        ### #${NONE}"
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e ""

make Taktix -j

    handleError "make encountered a problem." 4

echo -e ""
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e "${COLOR_1}# ###        ${COLOR_2}Launching Taktix${COLOR_1}        ### #${NONE}"
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e ""

./Taktix

    handleError "Taktix encountered a problem." 5

echo -e ""
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e "${COLOR_1}# ###     ${COLOR_2}Install was successful${COLOR_1}     ### #${NONE}"
echo -e "${COLOR_1}# ### ############################## ### #${NONE}"
echo -e ""

exit 0
