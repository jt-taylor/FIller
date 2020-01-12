#!/bin/sh
#for i in hello 1 * 2 goodbye 
#do
#  echo "Looping ... i is set to $i"
#done
path=./resources
maps=/maps
players=/players
my_player=./jtaylor.filler
mkdir results
for j in abanlin carli champely grati hcao superjeannot
do
	for k in map00 map01 map02
	do
		for i in 0 1 2 3 4
		do
	#		echo "${path}/filler_vm -f ${path}${maps}/${k} -p2 ${path}${players}/${j} -p1 ${my_player} -q" >> what_will_run
	#		touch result/result\.${j}\.${k}\.${i}
			${path}/filler_vm -f ${path}${maps}/${k} -p2 ${path}${players}/${j} -p1 ${my_player} -q > results/result\.${j}\.${k}\.${i}
		done
	done
done
