#!/bin/bash
#for i in hello 1 * 2 goodbye 
#do
#  echo "Looping ... i is set to $i"
#done
path=./resources
maps=/maps
players=/players
my_player=./jtaylor\.filler
mkdir results
for j in abanlin carli champely grati hcao superjeannot
do
	for k in map00
		#map01 map02
	do
		for i in 0 1 2 3 4
		do
	#		echo "${path}/filler_vm -f ${path}${maps}/${k} -p2 ${path}${players}/${j} -p1 ${my_player} -q" >> what_will_run
	#		touchresult/result\.${j}\.${k}\.${i}
			if [ $(( ( RANDOM % 2) )) -eq 0 ]
				then
				first_p=\-p1
				secon_p=\-p2
			else
				first_p=\-p2
				secon_p=\-p1
			fi
			#echo "${path}/filler_vm -f ${path}${maps}/${k} ${first_p} ${path}${players}/${j} ${secon_p} ${my_player} -q > results/result\.${j}\.${k}\.${i}"
			${path}/filler_vm -f ${path}${maps}/${k} ${first_p} ${path}${players}/${j}\.filler ${secon_p} ${my_player} -q > results/result\.${j}\.${k}\.${i}
			cat filler.trace >> sum_trace.txt
		done
	done
done
