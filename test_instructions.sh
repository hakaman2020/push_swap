#!/bin/bash
if [ "$2" = "-v" ]
then
	ARGS=$(./randgen -1000 1000 $1);echo $ARGS;./push_swap $ARGS | wc -l	
else
	ARGS=$(./randgen -1000 1000 $1);./push_swap $ARGS | wc -l	
fi	
