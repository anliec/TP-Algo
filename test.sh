EXE=/home/nicolas/.CLion12/system/cmake/generated/d268d9a5/d268d9a5/Debug/Tp-Algo
#EXE=main
INPUT=test/test3.in
REF_OUTPUT=test/test3.out
OUTPUT=test/output

inputList=$(ls test/*.in)
outputList=$(ls test/*.out)

NumberOfInput=$( echo $inputList | wc -w)

for i in `seq 1 $NumberOfInput`
do
	INPUT=$( echo $inputList | awk "{ print \$$i }")
	REF_OUTPUT=$( echo $outputList | awk "{ print \$$i }")

	echo ""
	echo "======================================="
	echo "Éxecution de $INPUT"
	echo "======================================="
	echo ""

	/usr/bin/time -v $EXE < $INPUT > $OUTPUT

	echo ""
	echo "Diférences trouvées avec la sortie attendu:"
	echo ""

	diff $OUTPUT $REF_OUTPUT --report-identical-files --side-by-side --suppress-common-lines
done
