EXE=/home/nicolas/.clion11/system/cmake/generated/d268d9a5/d268d9a5/Debug/Tp-Algo
INPUT=test/test3.in
REF_OUTPUT=test/test3.out
OUTPUT=test/output

echo "statistique de l'éxécution:"

/usr/bin/time -v $EXE < $INPUT > $OUTPUT

echo ""
echo "Diférences trouvées avec la sortie attandue:"
echo ""

diff $OUTPUT $REF_OUTPUT --report-identical-files --side-by-side --suppress-common-lines
