EXE=/home/nicolas/.clion11/system/cmake/generated/d268d9a5/d268d9a5/Debug/Tp-Algo
INPUT=test/test2.in
REF_OUTPUT=test/test2.out
OUTPUT=test/output

$EXE < $INPUT > $OUTPUT

diff $REF_OUTPUT $OUTPUT #| grep "<"
