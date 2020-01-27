#!/bin/sh

# copy
QNAME="Search PageRank"
QPATH="search_engine"
BIN="searchPagerank.out"
OUTPUT_FILE="searchPagerank.txt"
work_path=$(cd "$(dirname "$0")";pwd)
echo ${work_path}
echo "***  Testing $QNAME  ***"

if [[ ! -d tests ]]
then
	echo "No tests directory here. Are you in the right directory?"
	exit 1
fi

cd ${work_path}/source

echo $(cd "$(dirname "$0")";pwd)

make clean
make sp

cd ${work_path}/results

if [[ ! -f ${work_path}/source/${BIN} ]]
then
	echo "No such executable: ${BIN}"
	exit 1
fi

test_dirs=`ls`;

if [[ "$#" -eq 1 ]]
then
	test_dirs="test"$1
fi

# echo ${test_dirs}

for test_dir in ${test_dirs}
do
	cd ${work_path}/results/${test_dir}
	cp ${work_path}/source/${BIN} ${work_path}/results/${test_dir}/

	if [[ ! -f ${BIN} ]]
	then
		echo "No such executable: ${BIN}"
		exit 1
	fi

	if [[ ! -x ${BIN} ]]
	then
		echo "${BIN} is not executable"
		exit 1
	fi

	if [[ -f ${work_path}/results/${test_dir}/testSearchPageRank.sh ]]
	then
		./testSearchPageRank.sh
		rm -rf ${BIN}
	else
		./${BIN} >> ${work_path}/results/${test_dir}/${OUTPUT_FILE}
		rm -rf ${BIN}
	fi
	echo " "
	echo " "
	echo "------------------------------ "
	if cmp -s ${work_path}/tests/${test_dir}/${OUTPUT_FILE} ${work_path}/results/${test_dir}/${OUTPUT_FILE}
	then
		echo "** Passed Test ${test_dir}"
	else
		echo "** Failed Test ${test_dir}"
		echo "> Your output (in results/${test_dir}/${OUTPUT_FILE}: "
		cat  ${work_path}/results/${test_dir}/${OUTPUT_FILE}
		echo " "
		echo " "
		echo "> #### Expected output (in tests/${test_dir}/${OUTPUT_FILE}: "
		cat  ${work_path}/tests/${test_dir}/${OUTPUT_FILE}
		echo "> Compare files results/${test_dir}/${OUTPUT_FILE} and tests/${test_dir}/${OUTPUT_FILE} to see differences"
	fi
	echo "------------------------------ "
done
