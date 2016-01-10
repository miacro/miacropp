#!/bin/sh
SCRIPTS_DIR=`dirname ${0}`
REAL_PATH=`cd ${SCRIPTS_DIR} && pwd`

CQTHINK_ROOT=${REAL_PATH}/../..
EHR_BIN=${CQTHINK_ROOT}/mpp_install
CQTHINK_LD=${EHR_BIN}/linux:${EHR_BIN}/linux/release:${EHR_BIN}/lib/linux

#export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${CQTHINK_BIN}
echo "export LD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${CQTHINK_LD}" >> ~/.zprofile
echo "export LD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${CQTHINK_LD}" >> ~/.bash_profile
